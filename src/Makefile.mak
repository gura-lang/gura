#==============================================================================
# Makefile for Borland C++
#==============================================================================
LIB_GURA_D = ..\lib\libgura.bcc.lib
DLL_GURA = ..\libgura.bcc.dll

SRCS = \
Common.cpp Parser.cpp Expr.cpp Value.cpp Iterator.cpp \
Symbol.cpp String.cpp Environment.cpp Signal.cpp Formatter.cpp Option.cpp \
Function.cpp Operator.cpp Declaration.cpp \
Algorithm.cpp Codec.cpp \
Stream.cpp Directory.cpp DateTime.cpp OAL.cpp DLLMain.cpp

SRCS = $(SRCS) Object.cpp \
Object_Function.cpp Object_String.cpp Object_Binary.cpp \
Object_List.cpp Object_Matrix.cpp Object_Dict.cpp Object_Stream.cpp \
Object_DateTime.cpp Object_TimeDelta.cpp \
Object_Expr.cpp Object_Environment.cpp Object_Error.cpp Object_URI.cpp \
Object_Struct.cpp Object_Custom.cpp Object_Iterator.cpp Object_Semaphore.cpp \
Object_Image.cpp Object_Color.cpp Object_Palette.cpp Object_Audio.cpp Object_Codec.cpp \
Object_Args.cpp Object_Win32Ole.cpp

SRCS = $(SRCS) Module.cpp \
Module_basement.cpp \
Module_sys.cpp \
Module_codecs_basic\Module_codecs_basic.cpp \
Module_codecs_iso8859\Module_codecs_iso8859.cpp \
Module_codecs_japanese\Module_codecs_japanese.cpp \
Module_codecs_japanese\Conv_Japanese.cpp \
Module_fs\Module_fs.cpp \
Module_os\Module_os.cpp \
Module_path\Module_path.cpp \
Module_time\Module_time.cpp \
Module_math\Module_math.cpp

OBJS = $(SRCS:.cpp=.obj)

OBJS_EXTRA = sfmt.obj

SFMTDIR = SFMT-src-1.3.3

LDFLAGS = -tWD -tWM -M -q \
-L$(MAKEDIR)\..\Lib -L$(MAKEDIR)\..\Lib\psdk -lS:10000000

CFLAGS = \
-q -I..\include -I$(MAKEDIR)\..\Include -w-8057 -w-8004 \
-DGURA_EXPORTS

#CFLAGS = $(CFLAGS) -DDEBUG_GURA

.cpp.obj:
	@bcc32 $(CFLAGS) -o$(<R).obj -c $<

all: program module

program: $(LIB_GURA_D)
	@cd Program_gura
	@make
	@cd ..\Program_guraw
	@make
	@cd ..

module: $(LIB_GURA_D)
	@..\gura build_modules.gura install-root

$(LIB_GURA_D): $(DLL_GURA)
	@implib $@ $(DLL_GURA) >nul
	@echo $@ was created

$(DLL_GURA): $(OBJS) $(OBJS_EXTRA)
	@bcc32 $(LDFLAGS) -e$@ $**
	@echo $@ was created

sfmt.obj: $(SFMTDIR)\sfmt.c
	@bcc32 -I$(MAKEDIR)\..\Include -q -w-8027 -c -o$@ $**

clean: clean_module clean_program
	@del $(SRCS:.cpp=.obj)
	@del $(LIB_GURA_D) $(DLL_GURA) $(OBJS_EXTRA)
	@del $(DLL_GURA:.dll=.map) $(DLL_GURA:.dll=.tds)

clean_program:
	@cd Program_gura
	@make clean
	@cd ..\Program_guraw
	@make clean
	@cd ..

clean_module:
	@..\gura build_modules.gura clean
