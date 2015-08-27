@echo off
msbuild gura.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
