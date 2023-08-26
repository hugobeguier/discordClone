#pragma once

#include <windows.h>

class MyWindow {
public:
    MyWindow();
    ~MyWindow();

    void Show();

private:
    HWND hwnd;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};