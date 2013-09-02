@echo off
gura test-markdown.gura > result.txt
if "%1" == "update" goto update
diff -u result.txt result.sample.txt
goto done
:update
copy result.txt result.sample.txt > nul
:done
