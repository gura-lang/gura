@echo off
set PROGRAM_GURA=..\bin-x86\gura.exe
set cases=
set cases=%cases% application
rem set cases=%cases% audio
set cases=%cases% binary
set cases=%cases% block
set cases=%cases% bom
set cases=%cases% gzip-bzip2
rem set cases=%cases% canvas
set cases=%cases% chinese
set cases=%cases% codec
set cases=%cases% color
set cases=%cases% complex
set cases=%cases% csv
set cases=%cases% datetime
set cases=%cases% declaration
set cases=%cases% dict
set cases=%cases% diff
set cases=%cases% encoding-big5
rem set cases=%cases% encoding-euc-kr
set cases=%cases% encoding-gb2312
set cases=%cases% encoding-shift_jis
set cases=%cases% error
set cases=%cases% expr
set cases=%cases% filter
set cases=%cases% formatter
set cases=%cases% fs
set cases=%cases% function
set cases=%cases% gif
set cases=%cases% gmp
set cases=%cases% graph
set cases=%cases% hash
set cases=%cases% image
set cases=%cases% japanese
set cases=%cases% jpeg
set cases=%cases% korean
set cases=%cases% list-iterator
set cases=%cases% map
set cases=%cases% markdown
set cases=%cases% matrix
set cases=%cases% math
rem set cases=%cases% midi
set cases=%cases% module
set cases=%cases% msico
set cases=%cases% object
set cases=%cases% opengl
set cases=%cases% operator
set cases=%cases% optimize
set cases=%cases% path
set cases=%cases% rational
set cases=%cases% re
set cases=%cases% repeater
set cases=%cases% sqlite3
set cases=%cases% stream
set cases=%cases% string
set cases=%cases% suffixmgr
set cases=%cases% template
set cases=%cases% uri
set cases=%cases% value
set cases=%cases% xhtml
set cases=%cases% xml
set cases=%cases% xpm
set cases=%cases% yaml

if "%1" == "" goto usage
if "%1" == "all" goto all
set cases=%1
:all
if "%2" == "genscript" goto genscript
if "%2" == "update" goto update
rem --------
for %%C in (%cases%) do (
	echo %%C
	%PROGRAM_GURA% test-%%C.gura > result\test-%%C.result.txt
	diff -u result\test-%%C.sample.txt result\test-%%C.result.txt
)
goto done
rem --------
:genscript
for %%C in (%cases%) do (
	echo genscript: %%C
	%PROGRAM_GURA% genscript.gura --eval test-%%C.gura > result\test-%%C.result.txt
	diff -u result\test-%%C.sample.txt result\test-%%C.result.txt
)
goto done
rem --------
:update
for %%C in (%cases%) do (
	echo update: %%C
	%PROGRAM_GURA% test-%%C.gura > result\test-%%C.sample.txt
)
goto done
rem --------
:usage
echo usage: tester all/casename [genscript/update]
:done
