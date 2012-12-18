@rem /*
@echo off
if "%OS%" == "Windows_NT" goto WinNT
gura "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
goto end_of_gura
:WinNT
gura standalone-sample.bat %*
goto end_of_gura
rem */
//-----------------------------------------------------------------------------
sys.echo(true)
repeat(100):list { rand(10) }
//-----------------------------------------------------------------------------
/*
:end_of_gura
rem */
