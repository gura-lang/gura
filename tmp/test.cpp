#include <stdio.h>

#include <dshow.h>
#include <qedit.h> // SampleGrabber�p

int
main()
{
 IGraphBuilder *pGraphBuilder;
 ICaptureGraphBuilder2 *pCaptureGraphBuilder2;
 IMediaControl *pMediaControl;

 // �⑫���j�p�P��̓��{���
 //   Enumerate : �񋓁A�ꗗ
 //   Moniker   : ������
 ICreateDevEnum *pCreateDevEnum = NULL;
 IEnumMoniker *pEnumMoniker = NULL;
 IMoniker *pMoniker = NULL;

 ULONG nFetched = 0;
 IBaseFilter *pDeviceFilter;

 // COM��������
 CoInitialize(NULL);

 // FilterGraph�𐶐�
 CoCreateInstance(CLSID_FilterGraph,
	NULL,
	CLSCTX_INPROC,
	IID_IGraphBuilder,
	(LPVOID *)&pGraphBuilder);

 //
 // SampleGrabber����
 //

 IBaseFilter *pSampleGrabberFilter;
 ISampleGrabber *pSampleGrabber;
 AM_MEDIA_TYPE am_media_type;

 // SampleGrabber(Filter)�𐶐�
 CoCreateInstance(CLSID_SampleGrabber,
	 NULL,
	 CLSCTX_INPROC,
	 IID_IBaseFilter,
	 (LPVOID *)&pSampleGrabberFilter);

 // Filter����ISampleGrabber�C���^�[�t�F�[�X���擾���܂�
 pSampleGrabberFilter->QueryInterface(IID_ISampleGrabber,
	 (LPVOID *)&pSampleGrabber);

 // SampleGrabber��ڑ�����t�H�[�}�b�g���w��B
 // �������|�C���g�ł��B
 // �����̎w��̎d���ɂ��SampleGrabber�̑}���ӏ���
 // ����ł��܂��B���̃T���v���̂悤�Ȏw��������
 // ��ʏo�͂̐��O�ŃT���v�����擾�ł��܂��B
 ZeroMemory(&am_media_type, sizeof(am_media_type));
 am_media_type.majortype = MEDIATYPE_Video;
 am_media_type.subtype = MEDIASUBTYPE_RGB24;
 am_media_type.formattype = FORMAT_VideoInfo;
 pSampleGrabber->SetMediaType(&am_media_type);

 // Graph��SampleGrabber Filter��ǉ�
 pGraphBuilder->AddFilter(pSampleGrabberFilter,
	 L"Sample Grabber");

 //
 // �L���v�`���p�f�o�C�X�擾
 //

 // CaptureGraphBuilder2�Ƃ����L���v�`���pGraphBuilder�𐶐�����
 CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC, 
   IID_ICaptureGraphBuilder2, 
   (LPVOID *)&pCaptureGraphBuilder2);

 // FilterGraph���Z�b�g����
 pCaptureGraphBuilder2->SetFiltergraph(pGraphBuilder);

 // MediaControl�C���^�[�t�F�[�X�擾
 pGraphBuilder->QueryInterface(IID_IMediaControl,
	(LPVOID *)&pMediaControl);

 // �f�o�C�X��񋓂��邽�߂�CreateDevEnum�𐶐�
 CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER, 
   IID_ICreateDevEnum, (PVOID *)&pCreateDevEnum);

 // VideoInputDevice��񋓂��邽�߂�EnumMoniker�𐶐� 
 pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,
   &pEnumMoniker, 0);
 if (pEnumMoniker == NULL) {
   // �ڑ����ꂽ�f�����̓f�o�C�X����������ꍇ�ɂ͂���if���ɓ���܂�
   printf("no device\n");
   return 0;
 }

 // EnumMoniker��Reset����
 // Reset����ƁA�擪���琔���Ȃ����܂�
 pEnumMoniker->Reset();

 // �ŏ���Moniker���擾
 pEnumMoniker->Next(1, &pMoniker, &nFetched);

 // Monkier��Filter��Bind����
 pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pDeviceFilter );

 // FilterGraph�Ƀf�o�C�X�t�B���^��ǉ�����
 pGraphBuilder->AddFilter(pDeviceFilter, L"Device Filter");

 // ���̎��_��Monkier�n�AEnumerator�n�͗p�ς�
 pMoniker->Release();
 pEnumMoniker->Release();
 pCreateDevEnum->Release();

 // Graph�𐶐�����
 pCaptureGraphBuilder2->RenderStream(&PIN_CATEGORY_PREVIEW,
   NULL, pDeviceFilter, NULL, pSampleGrabberFilter);

 //
 // SampleGrabber��������擾
 //

 // �ڑ����擾�B
 // ���̏�����RenderFile�ɂ��Graph���\�����ꂽ���
 // �s���K�v������܂��B
 pSampleGrabber->GetConnectedMediaType(&am_media_type);
 VIDEOINFOHEADER *pVideoInfoHeader =
     (VIDEOINFOHEADER *)am_media_type.pbFormat;

 // �摜�i�f���j�̕��ƍ�����\��
 // �T���v�����킩��₷�����邽�߂ɕ\�����Ă��邾���Ȃ̂ŁA
 // �K���K�v�Ƃ����킯�ł͂���܂���B
 printf("size = %dx%d\n",
	 pVideoInfoHeader->bmiHeader.biWidth,
	 pVideoInfoHeader->bmiHeader.biHeight);

 // �f�[�^�T�C�Y��\��
 // ����������̂��߂ɕ\�����Ă��܂��B
 printf("sample size = %d\n",
	 am_media_type.lSampleSize);

 // Grab���s������ݒ�
 // SetBufferSamples���s��Ȃ��ƃo�b�t�@����
 // �f�[�^���擾�ł��܂���B
 // �s�K�v�ɕ��ׂ����������Ȃ��ꍇ�ɂ�FALSE�ɂ��Ă����āA
 // �f�[�^���擾�������Ȃ�����ATRUE�ɕς���
 // �Ƃ������@���ł��܂��B
 pSampleGrabber->SetBufferSamples(TRUE);

 // �Đ��J�n
 pMediaControl->Run();

 // OK����������BITMAP��ۑ����܂�
 MessageBox(NULL,
	 "Block Execution", "Block", MB_OK);

 // BITMAP��ۑ�����

 // �o�b�t�@��p��
 long nBufferSize = am_media_type.lSampleSize;
 long *pBuffer = (long *)malloc(nBufferSize);

 // ���ݕ\������Ă���f����Î~��Ƃ��Ď擾
 pSampleGrabber->GetCurrentBuffer(&nBufferSize,
     pBuffer);

 //
 // Bitmap�ɕۑ��B
 // ���̃T���v���ł̓L���v�`�����ʂ����邽�߂�
 // Bitmap�ɕۑ����Ă��܂��B
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

 // ���������
 pSampleGrabber->Release();
 pSampleGrabberFilter->Release();

 // ���������
 pMediaControl->Release();
 pCaptureGraphBuilder2->Release();
 pGraphBuilder->Release();

 // COM�I��
 CoUninitialize();

 return 0;
}

