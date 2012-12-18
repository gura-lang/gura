MYSQLDIR = ..\..\extra\mysql-connector-c-noinstall-6.0.2-win32

.cpp.obj:
	bcc32 -I$(MYSQLDIR)\include -c $<

test.exe: test.obj
	bcc32 -L$(MYSQLDIR)\lib -e$@ $** ws2_32.lib libmysql.bcc.lib
