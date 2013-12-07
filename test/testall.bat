@echo off
set PROGRAM_GURA=..\bin-x86\gura.exe
set files=
set files=%files% test-application.gura
set files=%files% test-binary.gura
set files=%files% test-block.gura
rem set files=%files% test-canvas.gura
set files=%files% test-codec.gura
set files=%files% test-color.gura
set files=%files% test-complex.gura
set files=%files% test-csv.gura
set files=%files% test-datetime.gura
set files=%files% test-declaration.gura
set files=%files% test-dict.gura
set files=%files% test-diff.gura
set files=%files% test-error.gura
set files=%files% test-expr.gura
set files=%files% test-filter.gura
set files=%files% test-formatter.gura
set files=%files% test-fraction.gura
set files=%files% test-fs.gura
set files=%files% test-function.gura
set files=%files% test-graph.gura
set files=%files% test-hash.gura
set files=%files% test-image.gura
set files=%files% test-list-iterator.gura
set files=%files% test-map.gura
set files=%files% test-markdown.gura
set files=%files% test-matrix.gura
set files=%files% test-math.gura
rem set files=%files% test-midi.gura
set files=%files% test-module.gura
set files=%files% test-object.gura
set files=%files% test-opengl.gura
set files=%files% test-operator.gura
set files=%files% test-optimize.gura
set files=%files% test-path.gura
set files=%files% test-re.gura
set files=%files% test-repeater.gura
set files=%files% test-sqlite3.gura
set files=%files% test-stream.gura
set files=%files% test-string.gura
set files=%files% test-template.gura
set files=%files% test-value.gura
set files=%files% test-xml.gura
set files=%files% test-xhtml.gura
set files=%files% test-yaml.gura

if "%1" == "" goto all
if "%1" == "genscript" goto genscript
if "%1" == "update" goto update
set files=test-%1.gura
rem --------
:all
for %%F in (%files%) do %PROGRAM_GURA% --printcmdline %%F > result\%%~nF.result.txt
for %%F in (%files%) do diff -u result\%%~nF.sample.txt result\%%~nF.result.txt
goto done
rem --------
:genscript
for %%F in (%files%) do %PROGRAM_GURA% --printcmdline genscript.gura --eval %%F > result\%%~nF.result.txt
for %%F in (%files%) do diff -u result\%%~nF.sample.txt result\%%~nF.result.txt
goto done
rem --------
:update
for %%F in (%files%) do %PROGRAM_GURA% --printcmdline %%F > result\%%~nF.sample.txt
goto done
:done
