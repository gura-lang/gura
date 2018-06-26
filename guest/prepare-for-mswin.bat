@echo off
rem ---------------------------------------------------------------------------
rem Main entry
rem ---------------------------------------------------------------------------
:main
set GUESTURL=http://www.gura-lang.org/guest
set BASEDIR=%~dp0
set UNZIP="%BASEDIR%buildtools-mswin\7za920\7za.exe"
set GNUMAKE="%BASEDIR%buildtools-mswin\UnxUtils\make.exe"
set CURL="%BASEDIR%buildtools-mswin\curl\curl.exe"
set FAILEDLIST=
set VCVERSION=2017
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\vsdevcmd.bat" -arch=x86
rem Add include path containing Win32.mak in case vs2015 doesn't include SDK
rem that provides the file.
set INCLUDE=%BASEDIR%include;%INCLUDE%
if not "%1" == "" (
	call :build_%1
	exit /b
)
rem ---------------------------------------------------------------------------
call :download_buildtools
call :download_packages
rem ---------------------------------------------------------------------------
call :build_eigen
call :build_sqlite
call :build_zlib
call :build_bzip2
call :build_jpegsrc
call :build_lpng
call :build_tiff
call :build_yaml
call :build_onig
call :build_expat
rem call :build_tcltk
call :build_wx
call :build_pixman
call :build_freeglut
call :build_glew
call :build_freetype
call :build_cairo
call :build_sdl
call :build_sdl2
call :build_curl
call :build_mpir
call :build_fftw
call :build_liblinear
call :build_libsvm

if not "%FAILEDLIST%" == "" (
	echo ======================================================================
	echo Error occured:%FAILEDLIST%
	echo ======================================================================
)
pause
exit /b

rem ---------------------------------------------------------------------------
rem Download buildtools
rem ---------------------------------------------------------------------------
:download_buildtools
if not exist buildtools-mswin git clone https://github.com/gura-lang/buildtools-mswin.git
%UNZIP% x -y -obuildtools-mswin\curl buildtools-mswin\curl_737_1.zip
%CURL% %GUESTURL%/buildtools-mswin/UnxUpdates.zip -o buildtools-mswin\UnxUpdates.zip
%CURL% %GUESTURL%/buildtools-mswin/wix38-binaries.zip -o buildtools-mswin\wix38-binaries.zip
%UNZIP% x -y -obuildtools-mswin\UnxUtils buildtools-mswin\UnxUpdates.zip
%UNZIP% x -y -obuildtools-mswin\wix38-binaries buildtools-mswin\wix38-binaries.zip
exit /b

rem ---------------------------------------------------------------------------
rem Download packages
rem ---------------------------------------------------------------------------
:download_packages
%CURL% -O %GUESTURL%/bzip2-1.0.6.tar.gz
%CURL% -O %GUESTURL%/cairo-1.12.18.tar.xz
%CURL% -O %GUESTURL%/cairo-1.12.18-gurapatch.zip
%CURL% -O %GUESTURL%/curl-7.38.0.zip
%CURL% -O %GUESTURL%/eigen-eigen-5a0156e40feb.zip
%CURL% -O %GUESTURL%/expat-2.1.0.tar.gz
%CURL% -O %GUESTURL%/expat-2.1.0-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/fftw-3.3.6-pl2.tar.gz
%CURL% -O %GUESTURL%/fftw-3.3.6-pl2-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/fontconfig-2.11.tar.bz2
%CURL% -O %GUESTURL%/freeglut-2.8.1.tar.gz
%CURL% -O %GUESTURL%/freeglut-2.8.1-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/freetype-2.5.3.tar.bz2
%CURL% -O %GUESTURL%/freetype-2.5.3-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/glew-1.13.0.zip
%CURL% -O %GUESTURL%/glew-1.13.0-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/jpegsrc.v9a.tar.gz
%CURL% -O %GUESTURL%/liblinear-2.11.zip
%CURL% -O %GUESTURL%/liblinear-2.11-gurapatch.zip
%CURL% -O %GUESTURL%/libsvm-3.22.zip
%CURL% -O %GUESTURL%/libsvm-3.22-gurapatch.zip
%CURL% -O %GUESTURL%/lpng1520.zip
%CURL% -O %GUESTURL%/lpng1520-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/mpir-2.7.2.tar.bz2
%CURL% -O %GUESTURL%/mpir-2.7.2-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/onig-5.9.5.tar.gz
%CURL% -O %GUESTURL%/pixman-0.32.6.tar.gz
%CURL% -O %GUESTURL%/pixman-0.32.6-gurapatch.zip
%CURL% -O %GUESTURL%/SDL-1.2.15.zip
%CURL% -O %GUESTURL%/SDL-1.2.15-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/SDL2-2.0.4.zip
%CURL% -O %GUESTURL%/SDL2-2.0.4-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/sqlite-amalgamation-201409011821.zip
%CURL% -O %GUESTURL%/tcl868-src.zip
%CURL% -O %GUESTURL%/tiff-3.8.2.zip
%CURL% -O %GUESTURL%/tiff-3.8.2-gurapatch.zip
%CURL% -O %GUESTURL%/tk868-src.zip
%CURL% -O %GUESTURL%/wxWidgets-3.1.1.7z
%CURL% -O %GUESTURL%/wxWidgets-3.1.1-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/yaml-0.1.5.tar.gz
%CURL% -O %GUESTURL%/yaml-0.1.5-gurapatch-vs2017.zip
%CURL% -O %GUESTURL%/zlib127.zip
exit /b

rem ---------------------------------------------------------------------------
rem Build packages
rem ---------------------------------------------------------------------------

rem ---------------------------------------------------------------------------
:build_bzip2
%UNZIP% x -y bzip2-1.0.6.tar.gz
%UNZIP% x -y bzip2-1.0.6.tar
del bzip2-1.0.6.tar
pushd bzip2-1.0.6
nmake -f makefile.msc
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% bzip2
popd
exit /b

rem ---------------------------------------------------------------------------
:build_cairo
%UNZIP% x -y cairo-1.12.18.tar.xz
%UNZIP% x -y cairo-1.12.18.tar
%UNZIP% x -y cairo-1.12.18-gurapatch.zip
del cairo-1.12.18.tar
pushd cairo-1.12.18\src
%GNUMAKE% -f Makefile.win32 CFG=release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% cairo
popd
exit /b

rem ---------------------------------------------------------------------------
:build_curl
mkdir deps
mkdir deps\lib
mkdir deps\include
mkdir deps\bin
copy zlib-1.2.7\*.h deps\include
copy zlib-1.2.7\zlib.lib deps\lib\zlib_a.lib
%UNZIP% x -y curl-7.38.0.zip
pushd curl-7.38.0\winbuild
nmake -f Makefile.vc mode=static WITH_ZLIB=static
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% curl
popd
exit /b

rem ---------------------------------------------------------------------------
:build_eigen
%UNZIP% x -y eigen-eigen-5a0156e40feb.zip
move eigen-eigen-5a0156e40feb/Eigen include/Eigen
exit /b

rem ---------------------------------------------------------------------------
:build_expat
%UNZIP% x -y expat-2.1.0.tar.gz
%UNZIP% x -y expat-2.1.0.tar
%UNZIP% x -y expat-2.1.0-gurapatch-vs2017.zip
del expat-2.1.0.tar
msbuild expat-2.1.0\lib\expat_static.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% expat
exit /b

rem ---------------------------------------------------------------------------
:build_fftw
%UNZIP% x -y fftw-3.3.6-pl2.tar.gz
%UNZIP% x -y fftw-3.3.6-pl2.tar
%UNZIP% x -y fftw-3.3.6-pl2-gurapatch-vs2017.zip
del fftw-3.3.6-pl2.tar
msbuild fftw-3.3.6-pl2\msw\fftw-3.3-libs.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Static-Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% fftw
exit /b

rem ---------------------------------------------------------------------------
:build_freeglut
%UNZIP% x -y freeglut-2.8.1.tar.gz
%UNZIP% x -y freeglut-2.8.1.tar
%UNZIP% x -y freeglut-2.8.1-gurapatch-vs2017.zip
del freeglut-2.8.1.tar
msbuild freeglut-2.8.1\VisualStudio\2017\freeglut.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release_Static /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% freeglut
exit /b

rem ---------------------------------------------------------------------------
:build_freetype
%UNZIP% x -y freetype-2.5.3.tar.bz2
%UNZIP% x -y freetype-2.5.3.tar
%UNZIP% x -y freetype-2.5.3-gurapatch-vs2017.zip
del freetype-2.5.3.tar
msbuild freetype-2.5.3\builds\windows\vc2017\freetype.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% freetype
exit /b

rem ---------------------------------------------------------------------------
:build_glew
%UNZIP% x -y glew-1.13.0.zip
%UNZIP% x -y glew-1.13.0-gurapatch-vs2017.zip
msbuild glew-1.13.0\build\vs2017\glew.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% glew
exit /b

rem ---------------------------------------------------------------------------
:build_jpegsrc
%UNZIP% x -y jpegsrc.v9a.tar.gz
%UNZIP% x -y jpegsrc.v9a.tar
del jpegsrc.v9a.tar
pushd jpeg-9a
copy jconfig.vc jconfig.h
nmake -f makefile.vc nodebug=1
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% jpegsrc
popd
exit /b

rem ---------------------------------------------------------------------------
:build_liblinear
%UNZIP% x -y liblinear-2.11.zip
%UNZIP% x -y liblinear-2.11-gurapatch.zip
pushd liblinear-2.11
nmake -f Makefile.win clean all
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% liblinear
popd
copy liblinear-2.11\windows\liblinear.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:build_libsvm
%UNZIP% x -y libsvm-3.22.zip
%UNZIP% x -y libsvm-3.22-gurapatch.zip
pushd libsvm-3.22
nmake -f Makefile.win clean all
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% libsvm
popd
copy libsvm-3.22\windows\libsvm.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:build_lpng
rem You cannot build source code in libpng-x.x.x.tar.gz properly under Windows.
%UNZIP% x -y lpng1520.zip
%UNZIP% x -y lpng1520-gurapatch-vs2017.zip
msbuild lpng1520\projects\vstudio\vstudio.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release Library" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% lpng
exit /b

rem ---------------------------------------------------------------------------
:build_mpir
%UNZIP% x -y mpir-2.7.2.tar.bz2
%UNZIP% x -y mpir-2.7.2.tar
%UNZIP% x -y mpir-2.7.2-gurapatch-vs2017.zip
del mpir-2.7.2.tar
msbuild mpir-2.7.2\build.vc14\lib_mpir_gc\lib_mpir_gc.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% mpir_gc
msbuild mpir-2.7.2\build.vc14\lib_mpir_cxx\lib_mpir_cxx.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% mpir_cxx
rem copy mpir-2.7.2\build.vc14\lib_mpir_gc\win32\Release\mpir.lib mpir-2.7.2\lib\win32\Release
rem copy mpir-2.7.2\build.vc14\lib_mpir_cxx\win32\Release\mpirxx.lib mpir-2.7.2\lib\win32\Release
exit /b

rem ---------------------------------------------------------------------------
:build_onig
%UNZIP% x -y onig-5.9.5.tar.gz
%UNZIP% x -y onig-5.9.5.tar
del onig-5.9.5.tar
pushd onig-5.9.5
copy win32\Makefile Makefile
copy win32\config.h config.h
nmake
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% onig
popd
exit /b

rem ---------------------------------------------------------------------------
:build_pixman
%UNZIP% x -y pixman-0.32.6.tar.gz
%UNZIP% x -y pixman-0.32.6.tar
%UNZIP% x -y pixman-0.32.6-gurapatch.zip
del pixman-0.32.6.tar
pushd pixman-0.32.6\pixman
if not exist release mkdir release
%GNUMAKE% -f Makefile.win32 CFG=release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% pixman
popd
exit /b

rem ---------------------------------------------------------------------------
:build_sdl
%UNZIP% x -y SDL-1.2.15.zip
%UNZIP% x -y SDL-1.2.15-gurapatch-vs2017.zip
msbuild SDL-1.2.15\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% sdl
copy SDL-1.2.15\VisualC\SDL\Release\SDL.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:build_sdl2
%UNZIP% x -y SDL2-2.0.4.zip
%UNZIP% x -y SDL2-2.0.4-gurapatch-vs2017.zip
msbuild SDL2-2.0.4\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% sdl2
copy SDL2-2.0.4\VisualC\Win32\Release\SDL2.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:build_sqlite
%UNZIP% x -y -osqlite-amalgamation sqlite-amalgamation-201409011821.zip
exit /b

rem ---------------------------------------------------------------------------
rem Error occurs during tk compilation
:build_tcltk
%UNZIP% x -y tcl868-src.zip -otcl
%UNZIP% x -y tk868-src.zip -otcl
pushd tcl\tcl8.6.8\win
nmake -f makefile.vc release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tcl
nmake -f makefile.vc install INSTALLDIR=..\..
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tcl
popd
pushd tcl\tk8.6.8\win
nmake -f makefile.vc release TCLDIR=..\..\tcl8.6.8
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tk
nmake -f makefile.vc install INSTALLDIR=..\..
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tk
popd
exit /b

rem ---------------------------------------------------------------------------
:build_tiff
rem You cannot build source code in tiff-3.8.2.tar.gz properly under Windows.
%UNZIP% x -y tiff-3.8.2.zip
%UNZIP% x -y tiff-3.8.2-gurapatch.zip
pushd tiff-3.8.2
nmake -f Makefile.vc lib
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tiff
popd
exit /b

rem ---------------------------------------------------------------------------
:build_wx
rem Building wxWidgets library using /m option doesn't produce correct results.
%UNZIP% x -y -owxWidgets-3.1.1 wxWidgets-3.1.1.7z
%UNZIP% x -y wxWidgets-3.1.1-gurapatch-vs2017.zip
msbuild wxWidgets-3.1.1\build\msw\wx_vc15.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% wx
exit /b

rem ---------------------------------------------------------------------------
:build_yaml
%UNZIP% x -y yaml-0.1.5.tar.gz
%UNZIP% x -y yaml-0.1.5.tar
%UNZIP% x -y yaml-0.1.5-gurapatch-vs2017.zip
del yaml-0.1.5.tar
msbuild yaml-0.1.5\win32\vs2017\yaml.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% yaml
exit /b

rem ---------------------------------------------------------------------------
:build_zlib
%UNZIP% x -y zlib127.zip
pushd zlib-1.2.7
nmake -f win32\Makefile.msc
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% zlib
popd
exit /b
