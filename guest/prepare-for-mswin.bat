@echo off
set GUESTURL=http://www.gura-lang.org/guest
set BASEDIR=%~dp0
set UNZIP="%BASEDIR%buildtools-mswin\7za920\7za.exe"
set GNUMAKE="%BASEDIR%buildtools-mswin\UnxUtils\make.exe"
set CURL="%BASEDIR%buildtools-mswin\curl\curl.exe"
set FAILEDLIST=
rem ---------------------------------------------------------------------------
set VCVERSION=14.0
set VCVARSALL="C:\Program Files\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="D:\Program Files\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="E:\Program Files\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="F:\Program Files\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="G:\Program Files\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="C:\Program Files (x86)\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="D:\Program Files (x86)\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="E:\Program Files (x86)\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="F:\Program Files (x86)\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="G:\Program Files (x86)\Microsoft Visual Studio %VCVERSION%\VC\vcvarsall.bat"
if not exist %VCVARSALL% goto err_vcvarsall_not_found
call %VCVARSALL%
rem Add include path containing Win32.mak in case vs2015 doesn't include SDK
rem that provides the file.
set INCLUDE=%BASEDIR%include;%INCLUDE%
rem ---------------------------------------------------------------------------
rem goto skip_curl
rem ---------------------------------------------------------------------------
if not exist buildtools-mswin git clone https://github.com/gura-lang/buildtools-mswin.git
%UNZIP% x -y -obuildtools-mswin\curl buildtools-mswin\curl_737_1.zip
%CURL% %GUESTURL%/buildtools-mswin/UnxUpdates.zip -o buildtools-mswin\UnxUpdates.zip
%CURL% %GUESTURL%/buildtools-mswin/wix38-binaries.zip -o buildtools-mswin\wix38-binaries.zip
%UNZIP% x -y -obuildtools-mswin\UnxUtils buildtools-mswin\UnxUpdates.zip
%UNZIP% x -y -obuildtools-mswin\wix38-binaries buildtools-mswin\wix38-binaries.zip
rem ---------------------------------------------------------------------------
%CURL% -O %GUESTURL%/bzip2-1.0.6.tar.gz
%CURL% -O %GUESTURL%/cairo-1.12.18.tar.xz
%CURL% -O %GUESTURL%/cairo-1.12.18-gurapatch.zip
%CURL% -O %GUESTURL%/curl-7.38.0.zip
%CURL% -O %GUESTURL%/expat-2.1.0.tar.gz
%CURL% -O %GUESTURL%/expat-2.1.0-gurapatch-vs2015.zip
%CURL% -O %GUESTURL%/fontconfig-2.11.tar.bz2
%CURL% -O %GUESTURL%/freeglut-2.8.1.tar.gz
%CURL% -O %GUESTURL%/freeglut-2.8.1-gurapatch.zip
%CURL% -O %GUESTURL%/freetype-2.5.3.tar.bz2
%CURL% -O %GUESTURL%/freetype-2.5.3-gurapatch.zip
%CURL% -O %GUESTURL%/glew-1.13.0.zip
%CURL% -O %GUESTURL%/glew-1.13.0-gurapatch.zip
%CURL% -O %GUESTURL%/jpegsrc.v9a.tar.gz
%CURL% -O %GUESTURL%/lpng1520.zip
%CURL% -O %GUESTURL%/lpng1520-gurapatch-vs2015.zip
%CURL% -O %GUESTURL%/mpir-2.7.2.tar.bz2
%CURL% -O %GUESTURL%/onig-5.9.5.tar.gz
%CURL% -O %GUESTURL%/pixman-0.32.6.tar.gz
%CURL% -O %GUESTURL%/pixman-0.32.6-gurapatch.zip
%CURL% -O %GUESTURL%/SDL-1.2.15.zip
%CURL% -O %GUESTURL%/SDL-1.2.15-gurapatch-vs2015.zip
%CURL% -O %GUESTURL%/SDL2-2.0.4.zip
%CURL% -O %GUESTURL%/SDL2-2.0.4-gurapatch.zip
%CURL% -O %GUESTURL%/sqlite-amalgamation-201409011821.zip
%CURL% -O %GUESTURL%/tcl8519-src.zip
%CURL% -O %GUESTURL%/tiff-3.8.2.zip
%CURL% -O %GUESTURL%/tiff-3.8.2-gurapatch.zip
%CURL% -O %GUESTURL%/tk8519-src.zip
%CURL% -O %GUESTURL%/wxWidgets-3.1.0.7z
%CURL% -O %GUESTURL%/yaml-0.1.5.tar.gz
%CURL% -O %GUESTURL%/yaml-0.1.5-gurapatch-vs2015.zip
%CURL% -O %GUESTURL%/zlib127.zip
rem ---------------------------------------------------------------------------
:skip_curl
rem ---------------------------------------------------------------------------
%UNZIP% x -y -osqlite-amalgamation sqlite-amalgamation-201409011821.zip
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y zlib127.zip
pushd zlib-1.2.7
nmake -f win32\Makefile.msc
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% zlib
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y bzip2-1.0.6.tar.gz
%UNZIP% x -y bzip2-1.0.6.tar
del bzip2-1.0.6.tar
pushd bzip2-1.0.6
nmake -f makefile.msc
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% bzip2
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y jpegsrc.v9a.tar.gz
%UNZIP% x -y jpegsrc.v9a.tar
del jpegsrc.v9a.tar
pushd jpeg-9a
copy jconfig.vc jconfig.h
nmake -f makefile.vc nodebug=1
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% jpegsrc
popd
rem ---------------------------------------------------------------------------
rem You cannot build source code in libpng-x.x.x.tar.gz properly under Windows.
rem vs2015 ok
%UNZIP% x -y lpng1520.zip
%UNZIP% x -y lpng1520-gurapatch-vs2015.zip
msbuild lpng1520\projects\vstudio\vstudio.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release Library" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% lpng
rem ---------------------------------------------------------------------------
rem You cannot build source code in tiff-3.8.2.tar.gz properly under Windows.
rem vs2015 ok
%UNZIP% x -y tiff-3.8.2.zip
%UNZIP% x -y tiff-3.8.2-gurapatch.zip
pushd tiff-3.8.2
nmake -f Makefile.vc lib
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tiff
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y yaml-0.1.5.tar.gz
%UNZIP% x -y yaml-0.1.5.tar
%UNZIP% x -y yaml-0.1.5-gurapatch-vs2015.zip
del yaml-0.1.5.tar
msbuild yaml-0.1.5\win32\vs2015\yaml.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% yaml
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y onig-5.9.5.tar.gz
%UNZIP% x -y onig-5.9.5.tar
del onig-5.9.5.tar
pushd onig-5.9.5
copy win32\Makefile Makefile
copy win32\config.h config.h
nmake
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% onig
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y expat-2.1.0.tar.gz
%UNZIP% x -y expat-2.1.0.tar
%UNZIP% x -y expat-2.1.0-gurapatch-vs2015.zip
del expat-2.1.0.tar
msbuild expat-2.1.0\lib\expat_static.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% expat
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y tcl8519-src.zip -otcl
%UNZIP% x -y tk8519-src.zip -otcl
pushd tcl\tcl8.5.19\win
nmake -f makefile.vc release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tcl
nmake -f makefile.vc install INSTALLDIR=..\..
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tcl
popd
pushd tcl\tk8.5.19\win
nmake -f makefile.vc release TCLDIR=..\..\tcl8.5.19
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tk
nmake -f makefile.vc install INSTALLDIR=..\..
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tk
popd
rem ---------------------------------------------------------------------------
rem Building wxWidgets library using /m option doesn't produce correct results.
rem vs2015 ok
%UNZIP% x -y -owxWidgets-3.1.0 wxWidgets-3.1.0.7z
msbuild wxWidgets-3.1.0\build\msw\wx_vc14.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% wxWidgets
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y pixman-0.32.6.tar.gz
%UNZIP% x -y pixman-0.32.6.tar
%UNZIP% x -y pixman-0.32.6-gurapatch.zip
del pixman-0.32.6.tar
pushd pixman-0.32.6\pixman
if not exist release mkdir release
%GNUMAKE% -f Makefile.win32 CFG=release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% pixman
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y freeglut-2.8.1.tar.gz
%UNZIP% x -y freeglut-2.8.1.tar
%UNZIP% x -y freeglut-2.8.1-gurapatch.zip
del freeglut-2.8.1.tar
msbuild freeglut-2.8.1\VisualStudio\2015\freeglut.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release_Static /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% freeglut
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y glew-1.13.0.zip
%UNZIP% x -y glew-1.13.0-gurapatch.zip
msbuild glew-1.13.0\build\vc14\glew.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% glew
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y freetype-2.5.3.tar.bz2
%UNZIP% x -y freetype-2.5.3.tar
%UNZIP% x -y freetype-2.5.3-gurapatch.zip
del freetype-2.5.3.tar
msbuild freetype-2.5.3\builds\windows\vc2015\freetype.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% freetype
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y cairo-1.12.18.tar.xz
%UNZIP% x -y cairo-1.12.18.tar
%UNZIP% x -y cairo-1.12.18-gurapatch.zip
del cairo-1.12.18.tar
pushd cairo-1.12.18\src
%GNUMAKE% -f Makefile.win32 CFG=release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% cairo
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y SDL-1.2.15.zip
%UNZIP% x -y SDL-1.2.15-gurapatch-vs2015.zip
msbuild SDL-1.2.15\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% SDL
copy SDL-1.2.15\VisualC\SDL\Release\SDL.dll dylib
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y SDL2-2.0.4.zip
%UNZIP% x -y SDL2-2.0.4-gurapatch.zip
msbuild SDL2-2.0.4\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% SDL2
copy SDL2-2.0.4\VisualC\Win32\Release\SDL2.dll dylib
rem ---------------------------------------------------------------------------
rem vs2015 ok
mkdir deps
mkdir deps\lib
mkdir deps\include
mkdir deps\bin
copy zlib-1.2.7\*.h deps\include
copy zlib-1.2.7\zlib.lib deps\lib\zlib_a.lib
%UNZIP% x -y curl-7.38.0.zip
pushd curl-7.38.0\winbuild
nmake -f Makefile.vc mode=static WITH_ZLIB=static
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% zlib
popd
rem ---------------------------------------------------------------------------
rem vs2015 ok
%UNZIP% x -y mpir-2.7.2.tar.bz2
%UNZIP% x -y mpir-2.7.2.tar
del mpir-2.7.2.tar
msbuild mpir-2.7.2\build.vc14\lib_mpir_gc\lib_mpir_gc.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% mpir_gc
msbuild mpir-2.7.2\build.vc14\lib_mpir_cxx\lib_mpir_cxx.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% mpir_cxx
rem copy mpir-2.7.2\build.vc14\lib_mpir_gc\win32\Release\mpir.lib mpir-2.7.2\lib\win32\Release
rem copy mpir-2.7.2\build.vc14\lib_mpir_cxx\win32\Release\mpirxx.lib mpir-2.7.2\lib\win32\Release
rem ---------------------------------------------------------------------------
goto done
:err_vcvarsall_not_found
echo cannot find vcvarsall.bat. edit setup.bat and modify VCVARSALL variable.
goto end
:done
if "%FAILEDLIST%"=="" goto end
echo ======================================================================
echo Error occured:%FAILEDLIST%
echo ======================================================================
:end
pause
