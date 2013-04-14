// cap26.cpp	DirectShow���g�����L���v�`���̉��p ver26
//  ���R���\�[���A�v���P�[�V�����ō쐬���邱��
//  ��[�v���W�F�N�g][�ݒ�][C/C++]
//�@�@[�R�[�h����][�����^�C��]�Ƀ}���`�X���b�h��ݒ肷�邱��
//�@��[�v���W�F�N�g][�ݒ�][�����N]
//�@�@[���][�I�u�W�F�N�g/���C�u�������W���[��]��
//�@�@c:\mssdk\lib\strmiids.lib ��ǉ� 8.0sdk
// �@ (c:\mssdk��SDK���C���X�g�[�������ꍇ)
//    c:\dxsdk\lib\strmiids.lib ��ǉ� 8.1sdk�̏ꍇ
//  ��COM�̑���͂��ׂ�HRESULT��Ԃ����A�v���O�������ȒP�ɂ��邽��
//    �Œ���̋ᖡ�����s���Ă��Ȃ��B

#include <windows.h>
#include <dshow.h>
#include <stdio.h>
#include <conio.h>
//#include <qedit.h>			// SampleGrabber�p
#include <math.h>

// �O���t�B�b�N�p�E�B���h�E�̃f�[�^���܂Ƃ߂��\����
typedef struct{				
	HINSTANCE			hi;
	HWND				hwnd;		// �����̃E�B���h�E�n���h��
	BYTE				*lpBmpData; // BMP�̃f�[�^����
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
	IGrabberSample  *pGrab = NULL;		// �����͌�ŉ�����邱�ƁB

	HRESULT hr;

	BYTE  * buffer;
	BYTE  * buf2;
	BYTE  * buf3;
	AM_MEDIA_TYPE   amt;

	int i;

	CoInitialize(NULL);					// COM�̏�����

	// ---- �L���v�`���t�B���^�̏��� ----
	// �L���v�`���f�o�C�X��T��
	IBaseFilter  *pbf = NULL;
	IMoniker * pMoniker = NULL;
    ULONG cFetched;
    // �f�o�C�X�񋓎q���쐬
    ICreateDevEnum * pDevEnum =NULL;
    CoCreateInstance( CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC,
					  IID_ICreateDevEnum, (void ** ) &pDevEnum);
    // �r�f�I�L���v�`���f�o�C�X�񋓎q���쐬
    IEnumMoniker * pClassEnum = NULL;
    pDevEnum -> CreateClassEnumerator(
					CLSID_VideoInputDeviceCategory, &pClassEnum, 0);
    if (pClassEnum == NULL){
		printf("�r�f�I�L���v�`���f�o�C�X�͑��݂��܂���\n");
		pDevEnum -> Release();
		CoUninitialize();
        return ;
    }
    // �ŏ��Ɍ��������r�f�I�L���v�`���f�o�C�X�̃I�u�W�F�N�g��
	// �C���^�t�F�[�X�𓾂�
    pClassEnum -> Next(1, &pMoniker, &cFetched);
	pMoniker -> BindToObject( 0, 0, IID_IBaseFilter, (void**)&pbf );
 	
	// ---- �t�B���^�O���t�̏��� ----
    // �t�B���^�O���t�����A�C���^�[�t�F�[�X�𓾂�
    CoCreateInstance( CLSID_FilterGraph, NULL, CLSCTX_INPROC,
					  IID_IGraphBuilder, (void **) &pGraph);
    pGraph -> QueryInterface( IID_IMediaControl, (LPVOID *) &pMC );
	// �L���v�`���t�B���^���t�B���^�O���t�ɒǉ�
    pGraph -> AddFilter( pbf, L"Video Capture");
	// �ǉ����s�����̂ŃL���v�`���t�B���^�̎Q�Ƃ������[�X
    pbf -> Release();

	// ---- �O���o�t�B���^�̏��� ----
	// �O���o�t�B���^�����
	CoCreateInstance( CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER, 
                      IID_IBaseFilter, (LPVOID *)&pF);
	pF -> QueryInterface( IID_ISampleGrabber, (void **)&pGrab );
	// �O���o�t�B���^�̑}���ꏊ�̓���̂��߂̐ݒ�
	ZeroMemory(&amt, sizeof(AM_MEDIA_TYPE));
	amt.majortype  = MEDIATYPE_Video;
	amt.subtype    = MEDIASUBTYPE_RGB24;
	amt.formattype = FORMAT_VideoInfo; 
	pGrab -> SetMediaType( &amt );
	// �O���o�t�B���^���t�B���^�O���t�ɒǉ�
	pGraph -> AddFilter(pF, L"SamGra");

	// ---- �L���v�`���O���t�̏��� ----
	// �L���v�`���O���t�����   
	CoCreateInstance( CLSID_CaptureGraphBuilder2 , NULL, CLSCTX_INPROC,
				      IID_ICaptureGraphBuilder2, (void **) &pCapture );
    // �t�B���^�O���t���L���v�`���O���t�ɑg�ݍ���
    pCapture -> SetFiltergraph( pGraph );
    // �L���v�`���O���t�̐ݒ�A�O���o�������_�����O�o�͂ɐݒ�
    pCapture -> RenderStream (&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video,
                                pbf, NULL, pF);
  
	// ---- �\���E�B���h�E�̏��� ----
	// �r�b�g�}�b�v���̎擾	
	pGrab -> GetConnectedMediaType( &amt ); 
	// �r�f�I �w�b�_�[�ւ̃|�C���^���l������B
	printf( "amt.lSampleSize = %d \n", amt.lSampleSize );
	VIDEOINFOHEADER *pVideoHeader = (VIDEOINFOHEADER*)amt.pbFormat;
	// �r�f�I �w�b�_�[�ɂ́A�r�b�g�}�b�v��񂪊܂܂��B
	// �r�b�g�}�b�v���� BITMAPINFO �\���̂ɃR�s�[����B
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

								// �\���E�B���h�E�̒�`
	WNDCLASSEX	wc;							// �V��������E�C���h�N���X
	memset( &wc, 0, sizeof(WNDCLASSEX) );
	wc.cbSize        = sizeof(WNDCLASSEX);	
	wc.lpfnWndProc   = grProc;				// ���̃N���X�̎��E�C���h�v���V�[�W��
	wc.hInstance     = (HINSTANCE)GetWindowLong( HWND_DESKTOP, GWL_HINSTANCE ); 
	wc.lpszClassName = "GRC0";				// ���̃N���X�̖��O
	wc.cbWndExtra    = 10;					// �֘A����\���̂̃|�C���^�p�̃G���A���m��
	RegisterClassEx( &wc );			// �E�B���h�N���X�̓o�^
	
	printf( "�L���v�`�����J�n���܂��A�ǂꂩ�L�[�������ĉ�����\n" ); 
	getch();

	// ---- �L���v�`���J�n ----
	// �\���E�B���h�E�����
	DWORD tid;

	img00.hwnd = NULL;
	CreateThread( NULL, 0,
				 (LPTHREAD_START_ROUTINE)th_Proc,
				 (void *)&img00, 0, &tid );
												// ���b�Z�[�W���[�v�̃X���b�h���N��	
	while( !(img00.hwnd) );					// �E�B���h�E���\�������̂�҂�

	pGrab -> SetBufferSamples(TRUE);	// �O���u�J�n
 	pMC -> Run();						// �����_�����O�J�n
	int nn = 0;							// �O���u�񐔂̃J�E���g�A�Ӗ��͂Ȃ�
	double s = 0.0;
	while(1){
		hr = pGrab -> GetCurrentBuffer( &n, (long *)buffer );
										// �O���u
		s =0.0;
		for( i = 0;i < n ;i++){
			s = s +  (buf2[i]= fabs( buffer[i] - buf3[i] ));
		}
		printf("�O���u hr = %x, n = %f\n", hr, s / n);
		if( s/n > 10 )
			Beep(1000,100);
		InvalidateRect( img00.hwnd, NULL, FALSE);	
		InvalidateRect( img01.hwnd, NULL, FALSE);
		if( kbhit() ){
			getch();					// kbhit�Ŏ擾�����L�[�̔j��
			hr = pMC -> Pause();
			printf( "�O���u��~�F�I�� -- q �A�ĊJ -- ���̑��̃L�[\n" );
			if(getch() == 'q')
					break;
			pMC -> Run();
		}
		CopyMemory( buf3, buffer ,n);
		Sleep(100);
	}
	pMC -> Stop();
	pGrab -> SetBufferSamples( 0 );
	// ---- �I������ ---- 
    // �C���^�[�t�F�[�X�̃����[�Xj
    pMC -> Release();		
	pDevEnum -> Release();
    pGraph -> Release();
    pCapture -> Release();
	// COM�̃����[�X
	CoUninitialize();
	SendMessage( img00.hwnd, WM_CLOSE, 0, 0 );		// �O���t�B�b�N��ʂ̏I��
	free( buffer );free( buf2);free(buf3);
   
}

//         ���������������₷�����邽��
//         �R���\�[���A�v���P�[�V�����̌`�Ԃ��Ƃ�
//     �@�@�E�B���h�E�֌W�̏����̓X���b�h�ɔC����
//		�@ ���̂��߂̃X���b�h���A�E�B���h�E�����X�g�@�@	
//  �@�@�@ ����}�V����24bit�J���[�ł��邱��

//�@���b�Z�[�W���[�v�̂��߂̃X���b�h
DWORD th_Proc( void * pp)
{
	MSG msg;

	int sm0 = GetSystemMetrics( SM_CYCAPTION );
	int sm1 = GetSystemMetrics( SM_CXDLGFRAME );	// WS_OVRELAPP�̏ꍇ�A�g�̑�����
	int sm2 = GetSystemMetrics( SM_CYDLGFRAME );	// SM_C?DLGFRAME�ɂȂ�
	// �K���X���b�h�̒��ŃE�B���h�E�����
	((IMG0 *)pp) -> hwnd = CreateWindow( "GRC0",	// �N���X�̖��O
				"...",
				WS_OVERLAPPED | WS_VISIBLE,			// �E�B���h�E�̑���
				100, 100,		// �\���ʒu
				((IMG0 *)pp) -> bih.biWidth  + sm1 * 2, 	// �`��T�C�Y����傫�����v�Z
				((IMG0 *)pp) -> bih.biHeight + sm0 + sm2 * 2,
				HWND_DESKTOP,						// �e�̓f�B�X�N�g�b�v
				NULL, ((IMG0 *)pp)->hi, NULL 	     );					
	SetWindowLong(((IMG0 *)pp) -> hwnd, 0, (LONG)pp);

	img01.hwnd = CreateWindow( "GRC0",	// �N���X�̖��O
				"...",
				WS_OVERLAPPED | WS_VISIBLE,			// �E�B���h�E�̑���
				480, 100,		// �\���ʒu
				img01.bih.biWidth  + sm1 * 2, 	// �`��T�C�Y����傫�����v�Z
				img01.bih.biHeight + sm0 + sm2 * 2,
				HWND_DESKTOP,						// �e�̓f�B�X�N�g�b�v
				NULL, img01.hi, NULL 	     );		
	SetWindowLong( img01.hwnd, 0, (LONG)&img01 );			

	while( GetMessage( &msg, NULL, 0, 0 ) ){
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return 0;
}

//�@�E�B���h�E�v���V�[�W���C�ĕ`��݂̂��s��
LRESULT CALLBACK grProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{
	IMG0 * pimg;				
	PAINTSTRUCT	ps;

	pimg = (IMG0 * )GetWindowLong( hwnd , 0 );	// �g���E�B���h�E���������
												// ���̃E�B���h�E�p�f�[�^�ւ�
												// �|�C���^�����o��
    switch (msg) {

	case WM_PAINT:								// �r�b�g�}�b�v�̕`��
		BeginPaint( hwnd, &ps );
		SetDIBitsToDevice( ps.hdc, 0, 0,			// �R�s�[��x,y���W
					pimg -> bih.biWidth,			// DIB�̕�
					pimg -> bih.biHeight,			// DIB�̍���
					0, 0,							// DIB�̍��W 
					0,								// ������
					pimg -> bih.biHeight,			// ��������
					pimg -> lpBmpData,
					(BITMAPINFO *)&( pimg -> bih),	// BITMAPINFO�ɃL���X�g
					DIB_RGB_COLORS );
        EndPaint( hwnd, &ps );
		return 0;

	case WM_DESTROY:							// �X���b�h��
		PostQuitMessage( 0 );					// ���b�Z�[�W���[�v���I��������
		break;			

	default:
		return DefWindowProc( hwnd, msg, wp, lp );
	}
	return 0;
	
}

//////////

