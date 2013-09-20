@echo off
set PROGRAM_GURA=..\bin-x86\gura.exe
set files=test-declaration.gura
set files=%files% test-value.gura
set files=%files% test-map.gura
set files=%files% test-csv.gura
set files=%files% test-dict.gura
set files=%files% test-list-iterator.gura
set files=%files% test-object.gura
set files=%files% test-operator.gura
set files=%files% test-function.gura
set files=%files% test-repeater.gura
set files=%files% test-block.gura
set files=%files% test-re.gura
set files=%files% test-string.gura
set files=%files% test-codec.gura
set files=%files% test-template.gura
set files=%files% test-application.gura
set files=%files% test-error.gura
set files=%files% test-formatter.gura
set files=%files% test-sqlite3.gura
set files=%files% test-filter.gura
set files=%files% test-binary.gura
set files=%files% test-matrix.gura
set files=%files% test-math.gura
set files=%files% test-diff.gura
set files=%files% test-optimize.gura
set files=%files% test-graph.gura
set files=%files% test-image.gura
set files=%files% test-color.gura
set files=%files% test-opengl.gura
set files=%files% test-hash.gura
set files=%files% test-datetime.gura
set files=%files% test-path.gura
set files=%files% test-yaml.gura
set files=%files% test-stream.gura
set files=%files% test-markdown.gura
rem set files=%files% test-module.gura
rem set files=%files% test-canvas.gura
rem set files=%files% test-file.gura

if "%1" == "clean" goto clean
if "%1" == "genscript" goto genscript
for %%F in (%files%) do %PROGRAM_GURA% --printcmdline %%F > result\%%~nF.result.txt
if "%1" == "print" goto print
if "%1" == "update" goto update
goto diff
:print
for %%F in (%files%) do type result\%%~nF.result.txt
goto done
:update
for %%F in (%files%) do copy result\%%~nF.result.txt result\%%~nF.sample.txt >NUL
goto done
:genscript
for %%F in (%files%) do %PROGRAM_GURA% --printcmdline genscript.gura --eval %%F > result\%%~nF.result.txt
goto diff
:clean
for %%F in (%files%) do del result\%%~nF.result.txt
goto done
:diff
for %%F in (%files%) do diff -u result\%%~nF.sample.txt result\%%~nF.result.txt
goto done
:done
