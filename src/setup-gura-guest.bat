@echo off
rem ==========================================================================
rem Setup libraries necessary to build Gura modules
rem ==========================================================================
if exist ..\gura-guest goto update
pushd ..
git clone https://github.com/jxg/gura-setup.git
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
