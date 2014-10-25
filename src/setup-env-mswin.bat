@echo off
rem ==========================================================================
rem Setup development environment
rem ==========================================================================
pushd ..
if exist gura-doc rmdir /s /q gura-doc
git clone https://github.com/gura-lang/gura-doc.git
popd
pushd ..\guest
call prepare-for-mswin.bat
popd
