#include <string>
#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {

    std::string netbeans{"\"C:\\Program Files\\NetBeans 8.2\\bin\\netbeans64.exe\" "}; //no need for --console suppress    
    std::string params{lpCmdLine}; //expecting: netbeans:///file:line

    params.erase(0, 12); //remove netbeans://
    netbeans += params;

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof (si));
    si.cb = sizeof (si);
    ZeroMemory(&pi, sizeof (pi));
    
    if (CreateProcess(NULL, (char*) netbeans.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

