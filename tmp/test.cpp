#include <stdio.h>

#include <dshow.h>
#include <qedit.h> // SampleGrabber用

int
main()
{
 IGraphBuilder *pGraphBuilder;
 ICaptureGraphBuilder2 *pCaptureGraphBuilder2;
 IMediaControl *pMediaControl;

 // 補足情報）英単語の日本語訳
 //   Enumerate : 列挙、一覧
 //   Moniker   : あだ名
 ICreateDevEnum *pCreateDevEnum = NULL;
 IEnumMoniker *pEnumMoniker = NULL;
 IMoniker *pMoniker = NULL;

 ULONG nFetched = 0;
 IBaseFilter *pDeviceFilter;

 // COMを初期化
 CoInitialize(NULL);

 // FilterGraphを生成
 CoCreateInstance(CLSID_FilterGraph,
	NULL,
	CLSCTX_INPROC,
	IID_IGraphBuilder,
	(LPVOID *)&pGraphBuilder);

 //
 // SampleGrabber準備
 //

 IBaseFilter *pSampleGrabberFilter;
 ISampleGrabber *pSampleGrabber;
 AM_MEDIA_TYPE am_media_type;

 // SampleGrabber(Filter)を生成
 CoCreateInstance(CLSID_SampleGrabber,
	 NULL,
	 CLSCTX_INPROC,
	 IID_IBaseFilter,
	 (LPVOID *)&pSampleGrabberFilter);

 // FilterからISampleGrabberインターフェースを取得します
 pSampleGrabberFilter->QueryInterface(IID_ISampleGrabber,
	 (LPVOID *)&pSampleGrabber);

 // SampleGrabberを接続するフォーマットを指定。
 // ここがポイントです。
 // ここの指定の仕方によりSampleGrabberの挿入箇所を
 // 決定できます。このサンプルのような指定をすると
 // 画面出力の寸前でサンプルを取得できます。
 ZeroMemory(&am_media_type, sizeof(am_media_type));
 am_media_type.majortype = MEDIATYPE_Video;
 am_media_type.subtype = MEDIASUBTYPE_RGB24;
 am_media_type.formattype = FORMAT_VideoInfo;
 pSampleGrabber->SetMediaType(&am_media_type);

 // GraphにSampleGrabber Filterを追加
 pGraphBuilder->AddFilter(pSampleGrabberFilter,
	 L"Sample Grabber");

 //
 // キャプチャ用デバイス取得
 //

 // CaptureGraphBuilder2というキャプチャ用GraphBuilderを生成する
 CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC, 
   IID_ICaptureGraphBuilder2, 
   (LPVOID *)&pCaptureGraphBuilder2);

 // FilterGraphをセットする
 pCaptureGraphBuilder2->SetFiltergraph(pGraphBuilder);

 // MediaControlインターフェース取得
 pGraphBuilder->QueryInterface(IID_IMediaControl,
	(LPVOID *)&pMediaControl);

 // デバイスを列挙するためのCreateDevEnumを生成
 CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER, 
   IID_ICreateDevEnum, (PVOID *)&pCreateDevEnum);

 // VideoInputDeviceを列挙するためのEnumMonikerを生成 
 pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,
   &pEnumMoniker, 0);
 if (pEnumMoniker == NULL) {
   // 接続された映像入力デバイスが一つも無い場合にはこのif文に入ります
   printf("no device\n");
   return 0;
 }

 // EnumMonikerをResetする
 // Resetすると、先頭から数えなおします
 pEnumMoniker->Reset();

 // 最初のMonikerを取得
 pEnumMoniker->Next(1, &pMoniker, &nFetched);

 // MonkierをFilterにBindする
 pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pDeviceFilter );

 // FilterGraphにデバイスフィルタを追加する
 pGraphBuilder->AddFilter(pDeviceFilter, L"Device Filter");

 // この時点でMonkier系、Enumerator系は用済み
 pMoniker->Release();
 pEnumMoniker->Release();
 pCreateDevEnum->Release();

 // Graphを生成する
 pCaptureGraphBuilder2->RenderStream(&PIN_CATEGORY_PREVIEW,
   NULL, pDeviceFilter, NULL, pSampleGrabberFilter);

 //
 // SampleGrabberから情報を取得
 //

 // 接続情報取得。
 // この処理はRenderFileによりGraphが構成された後に
 // 行う必要があります。
 pSampleGrabber->GetConnectedMediaType(&am_media_type);
 VIDEOINFOHEADER *pVideoInfoHeader =
     (VIDEOINFOHEADER *)am_media_type.pbFormat;

 // 画像（映像）の幅と高さを表示
 // サンプルをわかりやすくするために表示しているだけなので、
 // 必ず必要というわけではありません。
 printf("size = %dx%d\n",
	 pVideoInfoHeader->bmiHeader.biWidth,
	 pVideoInfoHeader->bmiHeader.biHeight);

 // データサイズを表示
 // これも説明のために表示しています。
 printf("sample size = %d\n",
	 am_media_type.lSampleSize);

 // Grabを行う事を設定
 // SetBufferSamplesを行わないとバッファから
 // データを取得できません。
 // 不必要に負荷をかけたくない場合にはFALSEにしておいて、
 // データを取得したくなったら、TRUEに変える
 // という方法もできます。
 pSampleGrabber->SetBufferSamples(TRUE);

 // 再生開始
 pMediaControl->Run();

 // OKが押されるとBITMAPを保存します
 MessageBox(NULL,
	 "Block Execution", "Block", MB_OK);

 // BITMAPを保存する

 // バッファを用意
 long nBufferSize = am_media_type.lSampleSize;
 long *pBuffer = (long *)malloc(nBufferSize);

 // 現在表示されている映像を静止画として取得
 pSampleGrabber->GetCurrentBuffer(&nBufferSize,
     pBuffer);

 //
 // Bitmapに保存。
 // このサンプルではキャプチャ結果を見るために
 // Bitmapに保存しています。
 //
 HANDLE fh;
 BITMAPFILEHEADER bmphdr;
 DWORD nWritten;

 memset(&bmphdr, 0, sizeof(bmphdr));

 bmphdr.bfType = ('M' << 8) | 'B';
 bmphdr.bfSize = sizeof(bmphdr) + sizeof(BITMAPINFOHEADER) + nBufferSize;
 bmphdr.bfOffBits = sizeof(bmphdr) + sizeof(BITMAPINFOHEADER);

 fh = CreateFile("result.bmp",
	 GENERIC_WRITE, 0, NULL,
	 CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
 WriteFile(fh, &bmphdr, sizeof(bmphdr), &nWritten, NULL);
 WriteFile(fh,
     &pVideoInfoHeader->bmiHeader,
     sizeof(BITMAPINFOHEADER), &nWritten, NULL);
 WriteFile(fh, pBuffer, nBufferSize, &nWritten, NULL);
 CloseHandle(fh);

 free(pBuffer);

 // 資源を解放
 pSampleGrabber->Release();
 pSampleGrabberFilter->Release();

 // 資源を解放
 pMediaControl->Release();
 pCaptureGraphBuilder2->Release();
 pGraphBuilder->Release();

 // COM終了
 CoUninitialize();

 return 0;
}

