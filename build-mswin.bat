@echo off
msbuild gura.sln /clp:DisableConsoleColor /t:Rebuild /p:Configuration="Release" /p:Platform=win32
