@echo off
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
set BASEDIR=%~dp0
set UNZIP="%BASEDIR%buildtools-mswin\7za920\7za.exe"
set GNUMAKE="%BASEDIR%buildtools-mswin\UnxUtils\make.exe"
set CURL="%BASEDIR%buildtools-mswin\curl\curl.exe"

goto skip

%UNZIP% x -y -obuildtools-mswin\UnxUtils buildtools-mswin\UnxUpdates.zip
%UNZIP% x -y -obuildtools-mswin\wix38-binaries buildtools-mswin\wix38-binaries.zip
%UNZIP% x -y -obuildtools-mswin\curl buildtools-mswin\curl_737_1.zip
rem ---------------------------------------------------------------------------
set BASEURL=http://www.gura-lang.org/guests
%CURL% -O %BASEURL%/bzip2-1.0.6.tar.gz
%CURL% -O %BASEURL%/cairo-1.12.16.tar.xz
%CURL% -O %BASEURL%/curl-7.38.0.tar.gz2
%CURL% -O %BASEURL%/expat-2.1.0.tar.gz
%CURL% -O %BASEURL%/fontconfig-2.11.tar.bz2
%CURL% -O %BASEURL%/freetype-2.5.3.tar.bz2
%CURL% -O %BASEURL%/jpegsrc.v9a.tar.gz
%CURL% -O %BASEURL%/libpng-1.6.12.tar.gz
%CURL% -O %BASEURL%/mpir-2.6.0.tar.bz2
%CURL% -O %BASEURL%/onig-5.9.5.tar.gz
%CURL% -O %BASEURL%/pixman-0.32.6.tar.gz
%CURL% -O %BASEURL%/SDL-1.2.15.tar.gz
%CURL% -O %BASEURL%/SDL2-2.0.3.tar.gz
%CURL% -O %BASEURL%/sqlite-amalgamation-201409011821.zip
%CURL% -O %BASEURL%/tcl8.5.16-src.tar.gz
%CURL% -O %BASEURL%/tiff-3.8.2.tar.gz
%CURL% -O %BASEURL%/tk8.5.16-src.tar.gz
%CURL% -O %BASEURL%/wxWidgets-3.0.1.tar.bz2
%CURL% -O %BASEURL%/yaml-0.1.5.tar.gz
%CURL% -O %BASEURL%/zlib-1.2.8.tar.gz
rem ---------------------------------------------------------------------------

:skip

%UNZIP% x -y -osqlite-amalgamation sqlite-amalgamation-201409011821.zip
rem ---------------------------------------------------------------------------
%UNZIP% x -y zlib127.zip
pushd zlib127
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

goto done

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
%UNZIP% x -y -owxWidgets-3.0.1 wxWidgets-3.0.1.7z
msbuild wxWidgets-3.0.1\build\msw\wx_vc10.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32 /m
rem ---------------------------------------------------------------------------
%UNZIP% x -y pixman-0.28.2.tar.gz
%UNZIP% x -y pixman-0.28.2.tar
%UNZIP% x -y pixman-0.28.2-gurapatch.zip
del pixman-0.28.2.tar
pushd pixman-0.28.2\pixman
if not exist release mkdir release
%GNUMAKE% -f Makefile.win32 CFG=release
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y freetype-2.4.11.tar.gz
%UNZIP% x -y freetype-2.4.11.tar
del freetype-2.4.11.tar
msbuild freetype-2.4.11\builds\win32\vc2010\freetype.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
rem ---------------------------------------------------------------------------
%UNZIP% x -y cairo-1.12.12.tar.xz
%UNZIP% x -y cairo-1.12.12.tar
%UNZIP% x -y cairo-1.12.12-gurapatch.zip
del cairo-1.12.12.tar
pushd cairo-1.12.12\src
if not exist release mkdir release
if not exist release\win32 mkdir release\win32
%GNUMAKE% -f Makefile.win32 CFG=release
popd
rem ---------------------------------------------------------------------------
%UNZIP% x -y SDL-1.2.15.zip
%UNZIP% x -y SDL-1.2.15-gurapatch.zip
msbuild SDL-1.2.15\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
copy SDL-1.2.15\VisualC\SDL\Release\SDL.dll bin-x86
rem ---------------------------------------------------------------------------
%UNZIP% x -y SDL2-2.0.3.zip
%UNZIP% x -y SDL2-2.0.3-gurapatch.zip
msbuild SDL2-2.0.3\VisualC\SDL_VS2010.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
copy SDL2-2.0.3\VisualC\SDL\Win32\Release\SDL2.dll bin-x86
rem ---------------------------------------------------------------------------
mkdir deps
mkdir deps\lib
mkdir deps\include
mkdir deps\bin
copy zlib-1.2.7\*.h deps\include
copy zlib-1.2.7\zlib.lib deps\lib\zlib_a.lib
%UNZIP% x -y curl-7.30.0.zip
pushd curl-7.30.0\winbuild
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
