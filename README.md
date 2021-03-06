# DllIconHandler

This project demonstrates how to create a Shell Icon Handler, that is loaded by *Explorer.exe*. An icon handler can show different icons for the same file type based on some logic.
This implementation shows different icons for 64-bit and 32-bit DLLs.

(This project is used as one of the exercises in my ![COM Programming class](https://github.com/zodiacon/syllabi/blob/main/COMProgramming-3days.pdf).

## Registration

The DLL is loaded and used by Explorer.exe. It must be properly registered, as it's as COM DLL and as a shell icon handler. To register it for all users, open an elevated command window, navigate to the directory where `DllIconHandler.dll` is located and enter the following:

```cmd
regsvr32 DlliconHandler.dll
```

You should be greeted with a successful registration message box.

To register for the current user only, open a normal command window, navigate to the file's location and enter:

```cmd
regsvr32 /n /i:user DllIconhandler.dll
```

You may need to restart explorer for the DLL to take effect. If you open a new explorer window that might work as well.

You can test it by opening an explorer window and navigating to `c:\Windows\System32` and then contrast that with `c:\windows\SysWow64`.

## Building from source

Open the solution file in Visual Studio 2022 and just build. You can also use an older Visual Studio version - just change the project's properties to use the toolset that you have installed.
