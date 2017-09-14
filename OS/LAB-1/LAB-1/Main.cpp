#include <windows.h>
HWND MainWindowHandle = 0;

bool InitWindowsApp(HINSTANCE instanceHandle, int show);
int Run();

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd){
	if (!InitWindowsApp (hInstance, nShowCmd)){
		::MessageBox(0, L"Init - Failed", 0, MB_OK);
		return 0;
	}
	return Run();
}
bool InitWindowsApp (HINSTANCE instanceHandle, int show){
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = instanceHandle;
	wc.hIcon = ::LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = ::LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(::GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"Hello";
	if (!::RegisterClass (&wc)){
		::MessageBox(0, L"Registerclass - Failed", 0, 0);
		return false;
	}

	MainWindowHandle = ::CreateWindow(
									L"Hello",
									L"Hello",
									WS_OVERLAPPEDWINDOW,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									0,
									0,
									instanceHandle,
									0);
	if(MainWindowHandle == 0){
		::MessageBox(0, L"Createwindow -Failed", 0, 0);
		return false;
	}
	::ShowWindow(MainWindowHandle, show);
	::UpdateWindow(MainWindowHandle);
	return true;
}

int Run (){
	MSG msg;
	::ZeroMemory (&msg, sizeof (MSG));
	while(::GetMessage(&msg, 0, 0, 0)){
		::TranslateMessage (&msg);
		::DispatchMessage (&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND windowHandle,
							UINT msg,
							WPARAM wParam,
							LPARAM lParam){
	switch(msg){
		case WM_LBUTTONDOWN:
			::MessageBox (0, L"Hello, World", L"Hello", MB_OK);
			return 0;

		case WM_KEYDOWN:
			if(wParam == VK_ESCAPE)
				::DestroyWindow (MainWindowHandle);
			return 0;

		case WM_DESTROY:
			::PostQuitMessage(0);
			return 0;
	}
	return ::DefWindowProc(windowHandle, msg, wParam, lParam);
}