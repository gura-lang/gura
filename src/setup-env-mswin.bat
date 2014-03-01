@echo off
rem ==========================================================================
rem Setup development environment
rem ==========================================================================
pushd ..
if exist gura-doc rmdir /s /q gura-doc
git clone https://github.com/gura-lang/gura-doc.git
popd
if exist ..\gura-guest\setup.bat goto update
pushd ..
if exist gura-guest rmdir /s /q gura-guest
git clone https://github.com/gura-lang/gura-guest.git
popd
pushd ..\gura-guest
goto setup
:update
pushd ..\gura-guest
git pull
goto setup
:setup
call setup.bat
popd
