// cap26.cpp	DirectShowを使ったキャプチャの応用 ver26
//  ○コンソールアプリケーションで作成すること
//  ○[プロジェクト][設定][C/C++]
//　　[コード生成][ランタイム]にマルチスレッドを設定すること
//　○[プロジェクト][設定][リンク]
//　　[一般][オブジェクト/ライブラリモジュール]に
//　　c:\mssdk\lib\strmiids.lib を追加 8.0sdk
// 　 (c:\mssdkにSDKをインストールした場合)
//    c:\dxsdk\lib\strmiids.lib を追加 8.1sdkの場合
//  ○COMの操作はすべてHRESULTを返すが、プログラムを簡単にするため
//    最低限の吟味しか行っていない。

#include <windows.h>
#include <dshow.h>
#include <stdio.h>
#include <conio.h>
//#include <qedit.h>			// SampleGrabber用
#include <math.h>

// グラフィック用ウィンドウのデータをまとめた構造体
typedef struct{				
	HINSTANCE			hi;
	HWND				hwnd;		// 自分のウィンドウハンドル
	BYTE				*lpBmpData; // BMPのデータ部分
	BITMAPINFOHEADER	bih;
} IMG0;

DWORD th_Proc( void *);
LRESULT CALLBACK grProc( HWND, UINT, WPARAM, LPARAM );
	
IMG0	img00;
IMG0	img01;

int main()
{
	IGraphBuilder * pGraph = NULL;
	IMediaControl * pMC = NULL;
	ICaptureGraphBuilder2 * pCapture = NULL;
	IBaseFilter     *pF  = NULL;
	IGrabberSample  *pGrab = NULL;		// これらは後で解放すること。

	HRESULT hr;

	BYTE  * buffer;
	BYTE  * buf2;
	BYTE  * buf3;
	AM_MEDIA_TYPE   amt;

	int i;

	CoInitialize(NULL);					// COMの初期化

	// ---- キャプチャフィルタの準備 ----
	// キャプチャデバイスを探す
	IBaseFilter  *pbf = NULL;
	IMoniker * pMoniker = NULL;
    ULONG cFetched;
    // デバイス列挙子を作成
    ICreateDevEnum * pDevEnum =NULL;
    CoCreateInstance( CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC,
					  IID_ICreateDevEnum, (void ** ) &pDevEnum);
    // ビデオキャプチャデバイス列挙子を作成
    IEnumMoniker * pClassEnum = NULL;
    pDevEnum -> CreateClassEnumerator(
					CLSID_VideoInputDeviceCategory, &pClassEnum, 0);
    if (pClassEnum == NULL){
		printf("ビデオキャプチャデバイスは存在しません\n");
		pDevEnum -> Release();
		CoUninitialize();
        return ;
    }
    // 最初に見つかったビデオキャプチャデバイスのオブジェクトの
	// インタフェースを得る
    pClassEnum -> Next(1, &pMoniker, &cFetched);
	pMoniker -> BindToObject( 0, 0, IID_IBaseFilter, (void**)&pbf );
 	
	// ---- フィルタグラフの準備 ----
    // フィルタグラフを作り、インターフェースを得る
    CoCreateInstance( CLSID_FilterGraph, NULL, CLSCTX_INPROC,
					  IID_IGraphBuilder, (void **) &pGraph);
    pGraph -> QueryInterface( IID_IMediaControl, (LPVOID *) &pMC );
	// キャプチャフィルタをフィルタグラフに追加
    pGraph -> AddFilter( pbf, L"Video Capture");
	// 追加を行ったのでキャプチャフィルタの参照をリリース
    pbf -> Release();

	// ---- グラバフィルタの準備 ----
	// グラバフィルタを作る
	CoCreateInstance( CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER, 
                      IID_IBaseFilter, (LPVOID *)&pF);
	pF -> QueryInterface( IID_ISampleGrabber, (void **)&pGrab );
	// グラバフィルタの挿入場所の特定のための設定
	ZeroMemory(&amt, sizeof(AM_MEDIA_TYPE));
	amt.majortype  = MEDIATYPE_Video;
	amt.subtype    = MEDIASUBTYPE_RGB24;
	amt.formattype = FORMAT_VideoInfo; 
	pGrab -> SetMediaType( &amt );
	// グラバフィルタをフィルタグラフに追加
	pGraph -> AddFilter(pF, L"SamGra");

	// ---- キャプチャグラフの準備 ----
	// キャプチャグラフを作る   
	CoCreateInstance( CLSID_CaptureGraphBuilder2 , NULL, CLSCTX_INPROC,
				      IID_ICaptureGraphBuilder2, (void **) &pCapture );
    // フィルタグラフをキャプチャグラフに組み込む
    pCapture -> SetFiltergraph( pGraph );
    // キャプチャグラフの設定、グラバをレンダリング出力に設定
    pCapture -> RenderStream (&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video,
                                pbf, NULL, pF);
  
	// ---- 表示ウィンドウの準備 ----
	// ビットマップ情報の取得	
	pGrab -> GetConnectedMediaType( &amt ); 
	// ビデオ ヘッダーへのポインタを獲得する。
	printf( "amt.lSampleSize = %d \n", amt.lSampleSize );
	VIDEOINFOHEADER *pVideoHeader = (VIDEOINFOHEADER*)amt.pbFormat;
	// ビデオ ヘッダーには、ビットマップ情報が含まれる。
	// ビットマップ情報を BITMAPINFO 構造体にコピーする。
	BITMAPINFO BitmapInfo;
	ZeroMemory( &BitmapInfo, sizeof(BitmapInfo) );
	CopyMemory( &BitmapInfo.bmiHeader, &(pVideoHeader->bmiHeader), 
				sizeof(BITMAPINFOHEADER));
	printf( "BitmapInfo.bmiHeader.biBitCount = %d\n", 
			 BitmapInfo.bmiHeader.biBitCount );
	img01.bih = img00.bih = BitmapInfo.bmiHeader;
 	long n = img00.bih.biSizeImage;
	buffer = (BYTE *)malloc( n );
	buf2 = (BYTE *)malloc( n );
	buf3 = (BYTE *)malloc( n );
	img00.lpBmpData = buffer;
	img01.hi = img00.hi = (HINSTANCE)GetWindowLong( HWND_DESKTOP, GWL_HINSTANCE );

	img01.lpBmpData = buf2;

								// 表示ウィンドウの定義
	WNDCLASSEX	wc;							// 新しくつくるウインドクラス
	memset( &wc, 0, sizeof(WNDCLASSEX) );
	wc.cbSize        = sizeof(WNDCLASSEX);	
	wc.lpfnWndProc   = grProc;				// このクラスの持つウインドプロシージャ
	wc.hInstance     = (HINSTANCE)GetWindowLong( HWND_DESKTOP, GWL_HINSTANCE ); 
	wc.lpszClassName = "GRC0";				// このクラスの名前
	wc.cbWndExtra    = 10;					// 関連する構造体のポインタ用のエリアを確保
	RegisterClassEx( &wc );			// ウィンドクラスの登録
	
	printf( "キャプチャを開始します、どれかキーを押して下さい\n" ); 
	getch();

	// ---- キャプチャ開始 ----
	// 表示ウィンドウを作る
	DWORD tid;

	img00.hwnd = NULL;
	CreateThread( NULL, 0,
				 (LPTHREAD_START_ROUTINE)th_Proc,
				 (void *)&img00, 0, &tid );
												// メッセージループのスレッドを起動	
	while( !(img00.hwnd) );					// ウィンドウが表示されるのを待つ

	pGrab -> SetBufferSamples(TRUE);	// グラブ開始
 	pMC -> Run();						// レンダリング開始
	int nn = 0;							// グラブ回数のカウント、意味はない
	double s = 0.0;
	while(1){
		hr = pGrab -> GetCurrentBuffer( &n, (long *)buffer );
										// グラブ
		s =0.0;
		for( i = 0;i < n ;i++){
			s = s +  (buf2[i]= fabs( buffer[i] - buf3[i] ));
		}
		printf("グラブ hr = %x, n = %f\n", hr, s / n);
		if( s/n > 10 )
			Beep(1000,100);
		InvalidateRect( img00.hwnd, NULL, FALSE);	
		InvalidateRect( img01.hwnd, NULL, FALSE);
		if( kbhit() ){
			getch();					// kbhitで取得したキーの破棄
			hr = pMC -> Pause();
			printf( "グラブ停止：終了 -- q 、再開 -- その他のキー\n" );
			if(getch() == 'q')
					break;
			pMC -> Run();
		}
		CopyMemory( buf3, buffer ,n);
		Sleep(100);
	}
	pMC -> Stop();
	pGrab -> SetBufferSamples( 0 );
	// ---- 終了処理 ---- 
    // インターフェースのリリースj
    pMC -> Release();		
	pDevEnum -> Release();
    pGraph -> Release();
    pCapture -> Release();
	// COMのリリース
	CoUninitialize();
	SendMessage( img00.hwnd, WM_CLOSE, 0, 0 );		// グラフィック画面の終了
	free( buffer );free( buf2);free(buf3);
   
}

//         処理部分を書きやすくするため
//         コンソールアプリケーションの形態をとり
//     　　ウィンドウ関係の処理はスレッドに任せる
//		　 そのためのスレッド側、ウィンドウ側リスト　　	
//  　　　 動作マシンは24bitカラーであること

//　メッセージループのためのスレッド
DWORD th_Proc( void * pp)
{
	MSG msg;

	int sm0 = GetSystemMetrics( SM_CYCAPTION );
	int sm1 = GetSystemMetrics( SM_CXDLGFRAME );	// WS_OVRELAPPの場合、枠の太さは
	int sm2 = GetSystemMetrics( SM_CYDLGFRAME );	// SM_C?DLGFRAMEになる
	// 必ずスレッドの中でウィンドウを作る
	((IMG0 *)pp) -> hwnd = CreateWindow( "GRC0",	// クラスの名前
				"...",
				WS_OVERLAPPED | WS_VISIBLE,			// ウィンドウの属性
				100, 100,		// 表示位置
				((IMG0 *)pp) -> bih.biWidth  + sm1 * 2, 	// 描画サイズから大きさを計算
				((IMG0 *)pp) -> bih.biHeight + sm0 + sm2 * 2,
				HWND_DESKTOP,						// 親はディスクトップ
				NULL, ((IMG0 *)pp)->hi, NULL 	     );					
	SetWindowLong(((IMG0 *)pp) -> hwnd, 0, (LONG)pp);

	img01.hwnd = CreateWindow( "GRC0",	// クラスの名前
				"...",
				WS_OVERLAPPED | WS_VISIBLE,			// ウィンドウの属性
				480, 100,		// 表示位置
				img01.bih.biWidth  + sm1 * 2, 	// 描画サイズから大きさを計算
				img01.bih.biHeight + sm0 + sm2 * 2,
				HWND_DESKTOP,						// 親はディスクトップ
				NULL, img01.hi, NULL 	     );		
	SetWindowLong( img01.hwnd, 0, (LONG)&img01 );			

	while( GetMessage( &msg, NULL, 0, 0 ) ){
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return 0;
}

//　ウィンドウプロシージャ，再描画のみを行う
LRESULT CALLBACK grProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{
	IMG0 * pimg;				
	PAINTSTRUCT	ps;

	pimg = (IMG0 * )GetWindowLong( hwnd , 0 );	// 拡張ウィンドウメモリより
												// このウィンドウ用データへの
												// ポインタを取り出す
    switch (msg) {

	case WM_PAINT:								// ビットマップの描画
		BeginPaint( hwnd, &ps );
		SetDIBitsToDevice( ps.hdc, 0, 0,			// コピー先x,y座標
					pimg -> bih.biWidth,			// DIBの幅
					pimg -> bih.biHeight,			// DIBの高さ
					0, 0,							// DIBの座標 
					0,								// 走査線
					pimg -> bih.biHeight,			// 走査線数
					pimg -> lpBmpData,
					(BITMAPINFO *)&( pimg -> bih),	// BITMAPINFOにキャスト
					DIB_RGB_COLORS );
        EndPaint( hwnd, &ps );
		return 0;

	case WM_DESTROY:							// スレッドの
		PostQuitMessage( 0 );					// メッセージループを終了させる
		break;			

	default:
		return DefWindowProc( hwnd, msg, wp, lp );
	}
	return 0;
	
}

//////////

