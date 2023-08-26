#include "MyWindow.h"

// Constructor
MyWindow::MyWindow() {
    WNDCLASSEX wc = {
         sizeof(WNDCLASSEX),
         CS_VREDRAW | CS_HREDRAW,
         WindowProc,
         0, 0,
         GetModuleHandle(nullptr),
         nullptr, nullptr, nullptr,
         nullptr,
         L"MyWindowClass",
         nullptr 
    };

    RegisterClassEx(&wc);

    hwnd = CreateWindow(
        wc.lpszClassName,
        L"My Window",
        WS_OVERLAPPEDWINDOW,
        100, 100,
        1000, 600,
        nullptr,
        nullptr,
        wc.hInstance,
        nullptr
    );
}

// Destructor
MyWindow::~MyWindow() {
    // Clean up any resources if needed
}

// Show and run the window
void MyWindow::Show() {
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

// Window Procedure
LRESULT CALLBACK MyWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
        return 0;

    }
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}