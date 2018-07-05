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
if not defined VCINSTALLDIR call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\vsdevcmd.bat" -arch=x86
rem Add include path containing Win32.mak in case vs2015 doesn't include SDK providing that file.
set INCLUDE=%BASEDIR%include;%INCLUDE%
rem ---------------------------------------------------------------------------
rem Build specified package
rem ---------------------------------------------------------------------------
if not "%1" == "" (
	set PACKAGES=
	call :getinfo_%1
	call :download_packages
	call :clean_%1
	call :build_%1
	exit /b
)
rem ---------------------------------------------------------------------------
rem Register labels of subroutines
rem ---------------------------------------------------------------------------
rem At first, build packages that are used by others.
set LABELS=zlib bzip2 expat freetype pixman libpng
rem Then, build other packages.
set LABELS=%LABELS% cairo curl eigen fftw freeglut glew jpegsrc liblinear libsvm
set LABELS=%LABELS% mpir onig sdl sdl2 sqlite tiff wx yaml
rem ---------------------------------------------------------------------------
rem Download build tools and packages
rem ---------------------------------------------------------------------------
call :download_buildtools
set PACKAGES=
for %%L in (%LABELS%) do call :getinfo_%%L
call :download_packages
rem ---------------------------------------------------------------------------
rem Build packages
rem ---------------------------------------------------------------------------
set FAILEDLIST=
for %%L in (%LABELS%) do call :build_%%L
if not "%FAILEDLIST%" == "" (
	echo ======================================================================
	echo Error occured:%FAILEDLIST%
	echo ======================================================================
)
pause
exit /b

rem ---------------------------------------------------------------------------
rem Download build tools
rem ---------------------------------------------------------------------------
:download_buildtools
if not exist buildtools-mswin (
	git clone https://github.com/gura-lang/buildtools-mswin.git
	%UNZIP% x -y -obuildtools-mswin\curl buildtools-mswin\curl_737_1.zip
	%CURL% %GUESTURL%/buildtools-mswin/UnxUpdates.zip -o buildtools-mswin\UnxUpdates.zip
	%CURL% %GUESTURL%/buildtools-mswin/wix38-binaries.zip -o buildtools-mswin\wix38-binaries.zip
	%UNZIP% x -y -obuildtools-mswin\UnxUtils buildtools-mswin\UnxUpdates.zip
	%UNZIP% x -y -obuildtools-mswin\wix38-binaries buildtools-mswin\wix38-binaries.zip
)
exit /b

rem ---------------------------------------------------------------------------
rem Download packages
rem ---------------------------------------------------------------------------
:download_packages
for %%P in (%PACKAGES%) do (
	echo %%P
	if not exist %%P %CURL% -O %GUESTURL%/%%P
)
exit /b

rem ---------------------------------------------------------------------------
rem Subroutines
rem ---------------------------------------------------------------------------

rem ---------------------------------------------------------------------------
:getinfo_bzip2
set VER_bzip2=1.0.6
set PACKAGES=%PACKAGES% bzip2-%VER_bzip2%.tar.gz
exit /b

:clean_bzip2
rmdir /s /q bzip2-%VER_bzip2%
exit /b

:build_bzip2
%UNZIP% x -y bzip2-%VER_bzip2%.tar.gz
%UNZIP% x -y bzip2-%VER_bzip2%.tar
del bzip2-%VER_bzip2%.tar
pushd bzip2-%VER_bzip2%
nmake -f makefile.msc
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% bzip2
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_cairo
set VER_cairo=1.12.18
set PACKAGES=%PACKAGES% cairo-%VER_cairo%.tar.xz
set PACKAGES=%PACKAGES% cairo-%VER_cairo%-gurapatch.zip
exit /b

:clean_cairo
rmdir /s /q cairo-%VER_cairo%
exit /b

:build_cairo
%UNZIP% x -y cairo-%VER_cairo%.tar.xz
%UNZIP% x -y cairo-%VER_cairo%.tar
%UNZIP% x -y cairo-%VER_cairo%-gurapatch.zip
del cairo-%VER_cairo%.tar
pushd cairo-%VER_cairo%\src
%GNUMAKE% -f Makefile.win32 CFG=release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% cairo
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_curl
set VER_curl=7.38.0
set PACKAGES=%PACKAGES% curl-%VER_curl%.zip
exit /b

:clean_curl
rmdir /s /q curl-%VER_curl%
exit /b

:build_curl
mkdir deps
mkdir deps\lib
mkdir deps\include
mkdir deps\bin
copy zlib-%VER_zlib%\*.h deps\include
copy zlib-%VER_zlib%\zlib.lib deps\lib\zlib_a.lib
%UNZIP% x -y curl-%VER_curl%.zip
pushd curl-%VER_curl%\winbuild
nmake -f Makefile.vc mode=static WITH_ZLIB=static
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% curl
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_eigen
set VER_eigen=5a0156e40feb
set PACKAGES=%PACKAGES% eigen-eigen-%VER_eigen%.zip
exit /b

:clean_eigen
rmdir /s /q eigen-eigen-%VER_eigen%
exit /b

:build_eigen
%UNZIP% x -y eigen-eigen-%VER_eigen%.zip
move eigen-eigen-%VER_eigen%/Eigen include/Eigen
exit /b

rem ---------------------------------------------------------------------------
:getinfo_expat
set VER_expat=2.1.0
set PACKAGES=%PACKAGES% expat-%VER_expat%.tar.gz
set PACKAGES=%PACKAGES% expat-%VER_expat%-gurapatch-vs2017.zip
exit /b

:clean_expat
rmdir /s /q expat-%VER_expat%
exit /b

:build_expat
%UNZIP% x -y expat-%VER_expat%.tar.gz
%UNZIP% x -y expat-%VER_expat%.tar
%UNZIP% x -y expat-%VER_expat%-gurapatch-vs2017.zip
del expat-%VER_expat%.tar
msbuild expat-%VER_expat%\lib\expat_static.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% expat
exit /b

rem ---------------------------------------------------------------------------
:getinfo_fftw
set VER_fftw=3.3.6-pl2
set VERHEAD_fftw=3.3
set PACKAGES=%PACKAGES% fftw-%VER_fftw%.tar.gz fftw-%VER_fftw%-gurapatch-vs2017.zip
exit /b

:clean_fftw
rmdir /s /q fftw-%VER_fftw%
exit /b

:build_fftw
%UNZIP% x -y fftw-%VER_fftw%.tar.gz
%UNZIP% x -y fftw-%VER_fftw%.tar
%UNZIP% x -y fftw-%VER_fftw%-gurapatch-vs2017.zip
del fftw-%VER_fftw%.tar
msbuild fftw-%VER_fftw%\msw\fftw-%VERHEAD_fftw%-libs.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Static-Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% fftw
exit /b

rem ---------------------------------------------------------------------------
:getinfo_freeglut
set VER_freeglut=2.8.1
set PACKAGES=%PACKAGES% freeglut-%VER_freeglut%.tar.gz
set PACKAGES=%PACKAGES% freeglut-%VER_freeglut%-gurapatch-vs2017.zip
exit /b

:clean_freeglut
rmdir /s /q freeglut-%VER_freeglut%
exit /b

:build_freeglut
%UNZIP% x -y freeglut-%VER_freeglut%.tar.gz
%UNZIP% x -y freeglut-%VER_freeglut%.tar
%UNZIP% x -y freeglut-%VER_freeglut%-gurapatch-vs2017.zip
del freeglut-%VER_freeglut%.tar
msbuild freeglut-%VER_freeglut%\VisualStudio\2017\freeglut.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release_Static /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% freeglut
exit /b

rem ---------------------------------------------------------------------------
:getinfo_freetype
set VER_freetype=2.5.3
set PACKAGES=%PACKAGES% freetype-%VER_freetype%.tar.bz2 freetype-%VER_freetype%-gurapatch-vs2017.zip
exit /b

:clean_freetype
rmdir /s /q freetype-%VER_freetype%
exit /b

:build_freetype
%UNZIP% x -y freetype-%VER_freetype%.tar.bz2
%UNZIP% x -y freetype-%VER_freetype%.tar
%UNZIP% x -y freetype-%VER_freetype%-gurapatch-vs2017.zip
del freetype-%VER_freetype%.tar
msbuild freetype-%VER_freetype%\builds\windows\vc2017\freetype.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% freetype
exit /b

rem ---------------------------------------------------------------------------
:getinfo_glew
set VER_glew=1.13.0
set PACKAGES=%PACKAGES% glew-%VER_glew%.zip
set PACKAGES=%PACKAGES% glew-%VER_glew%-gurapatch-vs2017.zip
exit /b

:clean_glew
rmdir /s /q glew-%VER_glew%
exit /b

:build_glew
%UNZIP% x -y glew-%VER_glew%.zip
%UNZIP% x -y glew-%VER_glew%-gurapatch-vs2017.zip
msbuild glew-%VER_glew%\build\vs2017\glew.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% glew
exit /b

rem ---------------------------------------------------------------------------
:getinfo_jpegsrc
set VER_jpegsrc=9a
set PACKAGES=%PACKAGES% jpegsrc.v%VER_jpegsrc%.tar.gz
exit /b

:clean_jpegsrc
rmdir /s /q jpeg-%VER_jpegsrc%
exit /b

:build_jpegsrc
%UNZIP% x -y jpegsrc.v%VER_jpegsrc%.tar.gz
%UNZIP% x -y jpegsrc.v%VER_jpegsrc%.tar
del jpegsrc.v%VER_jpegsrc%.tar
pushd jpeg-%VER_jpegsrc%
copy jconfig.vc jconfig.h
nmake -f makefile.vc nodebug=1
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% jpegsrc
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_liblinear
set VER_liblinear=2.11
set PACKAGES=%PACKAGES% liblinear-%VER_liblinear%.zip
set PACKAGES=%PACKAGES% liblinear-%VER_liblinear%-gurapatch.zip
exit /b

:clean_liblinear
rmdir /s /q liblinear-%VER_liblinear%
exit /b

:build_liblinear
%UNZIP% x -y liblinear-%VER_liblinear%.zip
%UNZIP% x -y liblinear-%VER_liblinear%-gurapatch.zip
pushd liblinear-%VER_liblinear%
nmake -f Makefile.win clean all
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% liblinear
popd
copy liblinear-%VER_liblinear%\windows\liblinear.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:getinfo_libsvm
set VER_libsvm=3.22
set PACKAGES=%PACKAGES% libsvm-%VER_libsvm%.zip libsvm-%VER_libsvm%-gurapatch.zip
exit /b

:clean_libsvm
rmdir /s /q libsvm-%VER_libsvm%
exit /b

:build_libsvm
%UNZIP% x -y libsvm-%VER_libsvm%.zip
%UNZIP% x -y libsvm-%VER_libsvm%-gurapatch.zip
pushd libsvm-%VER_libsvm%
nmake -f Makefile.win clean all
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% libsvm
popd
copy libsvm-%VER_libsvm%\windows\libsvm.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:getinfo_libpng
set VER_libpng=1520
set PACKAGES=%PACKAGES% lpng%VER_libpng%.zip
set PACKAGES=%PACKAGES% lpng%VER_libpng%-gurapatch-vs2017.zip
exit /b

:clean_libpng
rmdir /s /q lpng%VER_libpng%
exit /b

:build_libpng
rem You cannot build source code in libpng-x.x.x.tar.gz properly under Windows.
%UNZIP% x -y lpng%VER_libpng%.zip
%UNZIP% x -y lpng%VER_libpng%-gurapatch-vs2017.zip
msbuild lpng%VER_libpng%\projects\vstudio\vstudio.sln /clp:DisableConsoleColor /t:Build /p:Configuration="Release Library" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% libpng
exit /b

rem ---------------------------------------------------------------------------
:getinfo_mpir
set VER_mpir=2.7.2
set PACKAGES=%PACKAGES% mpir-%VER_mpir%.tar.bz2
set PACKAGES=%PACKAGES% mpir-%VER_mpir%-gurapatch-vs2017.zip
exit /b

:clean_mpir
rmdir /s /q mpir-%VER_mpir%
exit /b

:build_mpir
%UNZIP% x -y mpir-%VER_mpir%.tar.bz2
%UNZIP% x -y mpir-%VER_mpir%.tar
%UNZIP% x -y mpir-%VER_mpir%-gurapatch-vs2017.zip
del mpir-%VER_mpir%.tar
msbuild mpir-%VER_mpir%\build.vc14\lib_mpir_gc\lib_mpir_gc.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% mpir_gc
msbuild mpir-%VER_mpir%\build.vc14\lib_mpir_cxx\lib_mpir_cxx.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% mpir_cxx
rem copy mpir-%VER_mpir%\build.vc14\lib_mpir_gc\win32\Release\mpir.lib mpir-%VER_mpir%\lib\win32\Release
rem copy mpir-%VER_mpir%\build.vc14\lib_mpir_cxx\win32\Release\mpirxx.lib mpir-%VER_mpir%\lib\win32\Release
exit /b

rem ---------------------------------------------------------------------------
:getinfo_onig
set VER_onig=5.9.5
set PACKAGES=%PACKAGES% onig-%VER_onig%.tar.gz
exit /b

:clean_onig
rmdir /s /q onig-%VER_onig%
exit /b

:build_onig
%UNZIP% x -y onig-%VER_onig%.tar.gz
%UNZIP% x -y onig-%VER_onig%.tar
del onig-%VER_onig%.tar
pushd onig-%VER_onig%
copy win32\Makefile Makefile
copy win32\config.h config.h
nmake
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% onig
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_pixman
set VER_pixman=0.32.6
set PACKAGES=%PACKAGES% pixman-%VER_pixman%.tar.gz
set PACKAGES=%PACKAGES% pixman-%VER_pixman%-gurapatch.zip
exit /b

:clean_pixman
rmdir /s /q pixman-%VER_pixman%
exit /b

:build_pixman
%UNZIP% x -y pixman-%VER_pixman%.tar.gz
%UNZIP% x -y pixman-%VER_pixman%.tar
%UNZIP% x -y pixman-%VER_pixman%-gurapatch.zip
del pixman-%VER_pixman%.tar
pushd pixman-%VER_pixman%\pixman
if not exist release mkdir release
%GNUMAKE% -f Makefile.win32 CFG=release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% pixman
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_sdl
set VER_sdl=1.2.15
set PACKAGES=%PACKAGES% SDL-%VER_sdl%.zip
set PACKAGES=%PACKAGES% SDL-%VER_sdl%-gurapatch-vs2017.zip
exit /b

:clean_sdl
rmdir /s /q SDL-%VER_sdl%
exit /b

:build_sdl
%UNZIP% x -y SDL-%VER_sdl%.zip
%UNZIP% x -y SDL-%VER_sdl%-gurapatch-vs2017.zip
msbuild SDL-%VER_sdl%\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% sdl
copy SDL-%VER_sdl%\VisualC\SDL\Release\SDL.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:getinfo_sdl2
set VER_sdl2=2.0.4
set PACKAGES=%PACKAGES% SDL2-%VER_sdl2%.zip
set PACKAGES=%PACKAGES% SDL2-%VER_sdl2%-gurapatch-vs2017.zip
exit /b

:clean_sdl2
rmdir /s /q SDL2-%VER_sdl2%
exit /b

:build_sdl2
%UNZIP% x -y SDL2-%VER_sdl2%.zip
%UNZIP% x -y SDL2-%VER_sdl2%-gurapatch-vs2017.zip
msbuild SDL2-%VER_sdl2%\VisualC\SDL.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% sdl2
copy SDL2-%VER_sdl2%\VisualC\Win32\Release\SDL2.dll dylib
exit /b

rem ---------------------------------------------------------------------------
:getinfo_sqlite
set VER_sqlite=201409011821
set PACKAGES=%PACKAGES% sqlite-amalgamation-%VER_sqlite%.zip
exit /b

:clean_sqlite
rmdir /s /q sqlite-amalgamation
exit /b

:build_sqlite
%UNZIP% x -y -osqlite-amalgamation sqlite-amalgamation-%VER_sqlite%.zip
exit /b

rem ---------------------------------------------------------------------------
rem Error occurs during tk compilation
:getinfo_tcltk
set VER_tcltk=8.6.8
set VERPACK_tcltk=868
set PACKAGES=%PACKAGES% tcl%VERPACK_tcltk%-src.zip
set PACKAGES=%PACKAGES% tk%VERPACK_tcltk%-src.zip
exit /b

:clean_tcltk
rmdir /s /q tcl
exit /b

:build_tcltk
%UNZIP% x -y tcl%VERPACK_tcltk%-src.zip -otcl
%UNZIP% x -y tk%VERPACK_tcltk%-src.zip -otcl
pushd tcl\tcl%VER_tcltk%\win
nmake -f makefile.vc release
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tcl
nmake -f makefile.vc install INSTALLDIR=..\..
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tcl
popd
pushd tcl\tk%VER_tcltk%\win
nmake -f makefile.vc release TCLDIR=..\..\tcl%VER_tcltk%
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tk
nmake -f makefile.vc install INSTALLDIR=..\..
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tk
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_tiff
set VER_tiff=3.8.2
set PACKAGES=%PACKAGES% tiff-%VER_tiff%.zip
set PACKAGES=%PACKAGES% tiff-%VER_tiff%-gurapatch.zip
exit /b

:clean_tiff
rmdir /s /q tiff-%VER_tiff%
exit /b

:build_tiff
rem You cannot build source code in tiff-3.8.2.tar.gz properly under Windows.
%UNZIP% x -y tiff-%VER_tiff%.zip
%UNZIP% x -y tiff-%VER_tiff%-gurapatch.zip
pushd tiff-%VER_tiff%
nmake -f Makefile.vc lib
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% tiff
popd
exit /b

rem ---------------------------------------------------------------------------
:getinfo_wx
set VER_wx=3.1.0
set PACKAGES=%PACKAGES% wxWidgets-%VER_wx%.7z
set PACKAGES=%PACKAGES% wxWidgets-%VER_wx%-gurapatch-vs2017.zip
exit /b

:clean_wx
rmdir /s /q wxWidgets-%VER_wx%
exit /b

:build_wx
rem Building wxWidgets library using /m option doesn't produce correct results.
rem It seems that wxWidgets-3.1.1 has some bugs in handling image list.
%UNZIP% x -y -owxWidgets-%VER_wx% wxWidgets-%VER_wx%.7z
%UNZIP% x -y wxWidgets-%VER_wx%-gurapatch-vs2017.zip
msbuild wxWidgets-%VER_wx%\build\msw\wx_vc14.sln /clp:DisableConsoleColor /t:Build /p:Configuration=Release /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% wx
exit /b

rem ---------------------------------------------------------------------------
:getinfo_yaml
set VER_yaml=0.1.5
set PACKAGES=%PACKAGES% yaml-%VER_yaml%.tar.gz
set PACKAGES=%PACKAGES% yaml-%VER_yaml%-gurapatch-vs2017.zip
exit /b

:clean_yaml
rmdir /s /q yaml-%VER_yaml%
exit /b

:build_yaml
%UNZIP% x -y yaml-%VER_yaml%.tar.gz
%UNZIP% x -y yaml-%VER_yaml%.tar
%UNZIP% x -y yaml-%VER_yaml%-gurapatch-vs2017.zip
del yaml-%VER_yaml%.tar
msbuild yaml-%VER_yaml%\win32\vs2017\yaml.vcxproj /clp:DisableConsoleColor /t:Build /p:Configuration="Release" /p:Platform=win32
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% yaml
exit /b

rem ---------------------------------------------------------------------------
:getinfo_zlib
set VER_zlib=1.2.7
set VERPACK_zlib=127
set PACKAGES=%PACKAGES% zlib%VERPACK_zlib%.zip
exit /b

:clean_zlib
rmdir /s /q zlib-%VER_zlib%
exit /b

:build_zlib
%UNZIP% x -y zlib%VERPACK_zlib%.zip
pushd zlib-%VER_zlib%
nmake -f win32\Makefile.msc
if ERRORLEVEL 1 set FAILEDLIST=%FAILEDLIST% zlib
popd
exit /b
