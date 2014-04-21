//GameProgramming2014
//2�̓T���v��HelloWorld
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//�֐��v���g�^�C�v
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);
//�O���[�o���ϐ�
HINSTANCE hinst;
//�萔
const char CLASS_NAME[] = "WinMain";
const char APP_TITLE[] = "Hello World";
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
//===============================
//Windows�A�v���P�[�V�����̊J�n�_
//===============================
int WINAPI WinMain( HINSTANCE hInstance,
				    HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow )
{
	MSG msg;
	//�E�B���h�E�̍쐬
	if(!CreateMainWindow(hInstance,nCmdShow))
	{	return false;	}
	//���C�����[�v
	int done = 0;
	while(!done)
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
			{	done = 1;	}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}
//==================================
//�E�B���h�E�C�x���g�R�[���o�b�N�֐�
//==================================
LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam,LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY://windows�ɂ��̃v���O�������I������悤�ɓ`����
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}
//=================================
//�E�B���h�E�쐬�֐�
//�߂�l�F�G���[�̏ꍇ false
//=================================
bool CreateMainWindow(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcx;
	HWND hwnd;
	//�E�B���h�E�N���X�̍\���̂��A���C���E�B���h�E���L�q����p�����[�^�Őݒ�B
	wcx.cbSize	= sizeof(wcx);
	wcx.style	= CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WinProc;
	wcx.cbClsExtra	=0;
	wcx.cbWndExtra	= 0;
	wcx.hInstance	=hInstance;
	wcx.hIcon	= NULL;
	wcx.hCursor	= LoadCursor(NULL,IDC_ARROW);
	wcx.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcx.lpszMenuName	= NULL;
	wcx.lpszClassName	= CLASS_NAME;
	wcx.hIconSm	= NULL;
	//�E�B���h�E�N���X�̓o�^
	if(RegisterClassEx(&wcx) == 0 )
	{	return false;	}	//�G���[�̏ꍇ
	hwnd = CreateWindow(
		CLASS_NAME,
		APP_TITLE,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		(HWND)NULL,
		(HMENU)NULL,
		hInstance,
		(LPVOID)NULL );
	//�E�B���h�E�쐬�ł̃G���[
	if(!hwnd)
	{	return false;	}
	//�E�B���h�E�̕\��
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	return true;
}