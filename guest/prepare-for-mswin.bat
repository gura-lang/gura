@echo off
set GUESTURL=http://www.gura-lang.org/guest
set BASEDIR=%~dp0
set UNZIP="%BASEDIR%buildtools-mswin\7za920\7za.exe"
set GNUMAKE="%BASEDIR%buildtools-mswin\UnxUtils\make.exe"
set CURL="%BASEDIR%buildtools-mswin\curl\curl.exe"
rem ---------------------------------------------------------------------------
set VCVARSALL="C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="D:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="E:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="F:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="G:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="D:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="E:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="F:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% set VCVARSALL="G:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
if not exist %VCVARSALL% goto err_vcvarsall_not_found
call %VCVARSALL%
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
%CURL% -O %GUESTURL%/expat-2.1.0-gurapatch.zip
%CURL% -O %GUESTURL%/fontconfig-2.11.tar.bz2
%CURL% -O %GUESTURL%/freetype-2.5.3.tar.bz2
%CURL% -O %GUESTURL%/jpegsrc.v9a.tar.gz
%CURL% -O %GUESTURL%/lpng1520.zip
%CURL% -O %GUESTURL%/lpng1520-gurapatch.zip
%CURL% -O %GUESTURL%/mpir-2.6.0.tar.bz2
%CURL% -O %GUESTURL%/onig-5.9.5.tar.gz
%CURL% -O %GUESTURL%/pixman-0.32.6.tar.gz
%CURL% -O %GUESTURL%/SDL-1.2.15.zip
%CURL% -O %GUESTURL%/SDL-1.2.15-gurapatch.zip
%CURL% -O %GUESTURL%/SDL2-2.0.3.zip
%CURL% -O %GUESTURL%/SDL2-2.0.3-gurapatch.zip
%CURL% -O %GUESTURL%/sqlite-amalgamation-201409011821.zip
%CURL% -O %GUESTURL%/tcl8516-src.zip
%CURL% -O %GUESTURL%/tiff-3.8.2.zip
%CURL% -O %GUESTURL%/tiff-3.8.2-gurapatch.zip
%CURL% -O %GUESTURL%/tk8516-src.zip
%CURL% -O %GUESTURL%/wxWidgets-3.0.1.7z
%CURL% -O %GUESTURL%/yaml-0.1.5.tar.gz
%CURL% -O %GUESTURL%/yaml-0.1.5-gurapatch.zip
%CURL% -O %GUESTURL%/zlib127.zip
rem ---------------------------------------------------------------------------
%UNZIP% x -y -osqlite-amalgamation sqlite-amalgamation-201409011821.zip
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
%UNZIP% x -y jpegsrc.v9a.tar.gz
%UNZIP% x -y jpegsrc.v9a.tar
del jpegsrc.v9a.tar
pushd jpeg-9a
copy jconfig.vc jconfig.h
nmake -f makefile.vc nodebug=1
popd
rem ---------------------------------------------------------------------------
rem You cannot build source code in libpng-x.x.x.tar.gz properly under Windows.
%UNZIP% x -y lpng1520.zip
%UNZIP% x -y lpng1520-gurapatch.zip
msbuild lpng1520\projects\vstudio\vstudio.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release Library" /p:Platform=win32
rem ---------------------------------------------------------------------------
rem You cannot build source code in tiff-3.8.2.tar.gz properly under Windows.
%UNZIP% x -y tiff-3.8.2.zip
%UNZIP% x -y tiff-3.8.2-gurapatch.zip
pushd tiff-3.8.2
nmake -f Makefile.vc lib
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y yaml-0.1.5.tar.gz
%UNZIP% x -y yaml-0.1.5.tar
%UNZIP% x -y yaml-0.1.5-gurapatch.zip
del yaml-0.1.5.tar
msbuild yaml-0.1.5\win32\vs2010\yaml.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y onig-5.9.5.tar.gz
%UNZIP% x -y onig-5.9.5.tar
del onig-5.9.5.tar
pushd onig-5.9.5
copy win32\Makefile Makefile
copy win32\config.h config.h
nmake
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y expat-2.1.0.tar.gz
%UNZIP% x -y expat-2.1.0.tar
%UNZIP% x -y expat-2.1.0-gurapatch.zip
del expat-2.1.0.tar
msbuild expat-2.1.0\lib\expat_static.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y tcl8516-src.zip -otcl
%UNZIP% x -y tk8516-src.zip -otcl
pushd tcl\tcl8.5.16\win
nmake -f makefile.vc release
nmake -f makefile.vc install INSTALLDIR=..\..
popd
pushd tcl\tk8.5.16\win
nmake -f makefile.vc release TCLDIR=..\..\tcl8.5.16
nmake -f makefile.vc install INSTALLDIR=..\..
popd
rem ---------------------------------------------------------------------------
rem Building wxWidgets library using /m option doesn't produce correct results.
%UNZIP% x -y -owxWidgets-3.0.1 wxWidgets-3.0.1.7z
msbuild wxWidgets-3.0.1\build\msw\wx_vc10.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y pixman-0.32.6.tar.gz
%UNZIP% x -y pixman-0.32.6.tar
%UNZIP% x -y pixman-0.32.6-gurapatch.zip
del pixman-0.32.6.tar
pushd pixman-0.32.6\pixman
if not exist release mkdir release
%GNUMAKE% -f Makefile.win32 CFG=release
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y freetype-2.5.3.tar.bz2
%UNZIP% x -y freetype-2.5.3.tar
del freetype-2.5.3.tar
msbuild freetype-2.5.3\builds\windows\vc2010\freetype.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y cairo-1.12.18.tar.xz
%UNZIP% x -y cairo-1.12.18.tar
%UNZIP% x -y cairo-1.12.18-gurapatch.zip
del cairo-1.12.18.tar
pushd cairo-1.12.18\src
%GNUMAKE% -f Makefile.win32 CFG=release
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y SDL-1.2.15.zip
%UNZIP% x -y SDL-1.2.15-gurapatch.zip
msbuild SDL-1.2.15\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
copy SDL-1.2.15\VisualC\SDL\Release\SDL.dll dylib
rem ---------------------------------------------------------------------------
%UNZIP% x -y SDL2-2.0.3.zip
%UNZIP% x -y SDL2-2.0.3-gurapatch.zip
msbuild SDL2-2.0.3\VisualC\SDL_VS2010.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
copy SDL2-2.0.3\VisualC\SDL\Win32\Release\SDL2.dll dylib
rem ---------------------------------------------------------------------------
mkdir deps
mkdir deps\lib
mkdir deps\include
mkdir deps\bin
copy zlib-1.2.7\*.h deps\include
copy zlib-1.2.7\zlib.lib deps\lib\zlib_a.lib
%UNZIP% x -y curl-7.38.0.zip
pushd curl-7.38.0\winbuild
nmake -f Makefile.vc mode=static WITH_ZLIB=static
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y mpir-2.6.0.tar.bz2
%UNZIP% x -y mpir-2.6.0.tar
del mpir-2.6.0.tar
msbuild mpir-2.6.0\build.vc10\lib_mpir_gc\lib_mpir_gc.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
msbuild mpir-2.6.0\build.vc10\lib_mpir_cxx\lib_mpir_cxx.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
copy mpir-2.6.0\build.vc10\lib_mpir_gc\win32\Release\mpir.lib mpir-2.6.0\lib\win32\Release
copy mpir-2.6.0\build.vc10\lib_mpir_cxx\win32\Release\mpirxx.lib mpir-2.6.0\lib\win32\Release
rem ---------------------------------------------------------------------------
goto done
:err_vcvarsall_not_found
echo cannot find vcvarsall.bat. edit setup.bat and modify VCVARSALL variable.
:done
pause
