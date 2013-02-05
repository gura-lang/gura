@echo off
set REPOS=http://svn.sourceforge.jp/svnroot/gura/guest
set UNZIP="C:\Program Files\7-Zip\7z.exe"
if not exist %UNZIP% set UNZIP="C:\Program Files (x86)\7-Zip\7z.exe"
rem ---------------------------------------------------------------------------
svn export %REPOS% . --force
rem ---------------------------------------------------------------------------
set VCVARSALL="C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
call %VCVARSALL%
rem ---------------------------------------------------------------------------
rem %UNZIP% x -y mysql-connector-c-noinstall-6.0.2-win32-vs2005.zip
rem ---------------------------------------------------------------------------
rem %UNZIP% x -y postgresql-9.1.2-1-windows-binaries.zip
rem ---------------------------------------------------------------------------
%UNZIP% x -y sqlite-amalgamation-3071000.zip
rem ---------------------------------------------------------------------------
%UNZIP% x -y zlib127.zip
pushd zlib-1.2.7
nmake -f win32\Makefile.msc
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y bzip2-1.0.6.tar.gz
%UNZIP% x -y bzip2-1.0.6.tar
del bzip2-1.0.6.tar
pushd bzip2-1.0.6
nmake -f makefile.msc
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y jpegsr8d.zip
pushd jpeg-8d
copy jconfig.vc jconfig.h
nmake -f makefile.vc nodebug=1
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y lpng1510.zip
%UNZIP% x -y lpng1510-gurapatch.zip
msbuild lpng1510\projects\vstudio\vstudio.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release Library" /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y tiff-3.8.2.zip
%UNZIP% x -y tiff-3.8.2-gurapatch.zip
pushd tiff-3.8.2
nmake -f Makefile.vc lib
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y yaml-0.1.4.tar.gz
%UNZIP% x -y yaml-0.1.4.tar
%UNZIP% x -y yaml-0.1.4-gurapatch.zip
del yaml-0.1.4.tar
msbuild yaml-0.1.4\win32\vs2010\yaml.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y onig-5.9.2.tar.gz
%UNZIP% x -y onig-5.9.2.tar
del onig-5.9.2.tar
pushd onig-5.9.2
copy win32\Makefile Makefile
copy win32\config.h config.h
nmake
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y expat-2.0.1.tar.gz
%UNZIP% x -y expat-2.0.1.tar
%UNZIP% x -y expat-2.0.1-gurapatch.zip
del expat-2.0.1.tar
msbuild expat-2.0.1\lib\expat_static.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y tcl8511-src.zip -otcl
%UNZIP% x -y tk8511-src.zip -otcl
pushd tcl\tcl8.5.11\win
nmake -f makefile.vc release
nmake -f makefile.vc install INSTALLDIR=..\..
popd
pushd tcl\tk8.5.11\win
nmake -f makefile.vc release TCLDIR=..\..\tcl8.5.11
nmake -f makefile.vc install INSTALLDIR=..\..
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y wxMSW-2.8.12.zip
%UNZIP% x -y wxMSW-2.8.12-gurapatch.zip
msbuild wxMSW-2.8.12\build\msw\wx.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem msbuild wxMSW-2.8.12\build\msw\wx.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=x64
rem msbuild wxMSW-2.8.12\build\msw\wx.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Debug /p:Platform=win32
rem msbuild wxMSW-2.8.12\build\msw\wx.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Debug /p:Platform=x64
rem ---------------------------------------------------------------------------
rem set WXPACKAGE=wxWidgets-2.9.3
rem %UNZIP% x -y -o%WXPACKAGE% %WXPACKAGE%.zip
rem msbuild %WXPACKAGE%\build\msw\wx.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem if exist %WXPACKAGE%\build\msw\vc_mswu_x86 rmdir /s %WXPACKAGE%\build\msw\vc_mswu_x86
rem if exist %WXPACKAGE%\lib\vc_lib_x86 rmdir /s %WXPACKAGE%\lib\vc_lib_x86
rem move %WXPACKAGE%\build\msw\vc_mswu %WXPACKAGE%\build\msw\vc_mswu_x86
rem move %WXPACKAGE%\lib\vc_lib %WXPACKAGE%\lib\vc_lib_x86
pause
