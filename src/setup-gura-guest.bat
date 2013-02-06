@echo off
if exist ..\gura-guest goto update
git --exec-path=.. clone https://github.com/jxg/gura-setup.git
goto setup
:update
git --exec-path=..\gura-guest pull
goto setup
:setup
pushd ..\gura-guest
call setup.bat
popd
