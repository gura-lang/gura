@echo off
rem ==========================================================================
rem Setup libraries necessary to build Gura modules
rem ==========================================================================
if exist ..\gura-guest\setup.bat goto update
if exist ..\gura-guest rmdir /s /q ..\gura-guest
pushd ..
git clone https://github.com/ypsitau/gura-guest.git
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
