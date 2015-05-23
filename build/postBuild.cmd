if not exist output mkdir output
copy /Y x64\Debug\ReSoel.Client.dll output
copy /Y Win32\Debug\ReSoel.Client32.dll output
copy /Y ..\external\easyHook\EasyHook32.dll output
copy /Y ..\external\easyHook\EasyHook64.dll output
copy /Y x64\Debug\ReSoel.Server.exe output
