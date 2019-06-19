这个模块我们来写一个Windows的小程序.这个程序所做的一切就是产生一个空白的窗口并把它显示出来. 这个第一个程序大概有50行代码,不算空行和注释.这个程序将作为我们的起始点,后续我们还会加上图形,文字,用户输入和其他功能.

这是这个程序的完整代码:
```
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);



            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```
您也可以在这里下载完整的Visual Studio项目:
如果可行的话这里给出对这些代码的简要说明.后续的话题将详细介绍这些代码.
1. wWinMain是程序的入口.程序开始的时候会注册一些关于应用程序窗口的一些行为信息.其中最重要的信息之一是函数的地址,这里叫做WindowProc. 这个函数定义了窗口的行为:外观,如何与用户交互,以及其他.
2. 接下来程序会创建这个窗口,并开始接受用于辨识这个窗口的句柄.
3. 如果窗口成功创建的话程序会进入一个while循环.在用户关闭窗口并退出程序之前程序将保持运行这个循环.
注意程序并没有明确调用WindowProc函数,即使我们说过这是定义的最重要的应用程序逻辑.Windows是通过一系列的消息来与您的程序交流的,这个while循环里面的代码是做这个事情的.程序每次调用DispatchMessage函数的时候会间接让Windows调用WindowProc函数,每次对应一条消息.
