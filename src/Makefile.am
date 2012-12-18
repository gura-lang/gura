ACLOCAL_AMFLAGS = -I m4

DIR_SFMT = SFMT-src-1.3.3

bin_PROGRAMS = gura

lib_LTLIBRARIES = libgura.la

INCLUDES = -I$(srcdir)/../include

gura_LDADD = libgura.la
gura_LDFLAGS = -pthread
gura_DEPENDENCIES = libgura.la
gura_SOURCES = \
Program_gura/Main.cpp

BUILT_SOURCES = config_add.h stdafx.h.gch

clean-local:
	-rm -f config_add.h stdafx.h.gch

config_add.h: Makefile
	@echo "#define BINDIR     \"$(bindir)\"" >> $@
	@echo "#define PKGDATADIR \"$(pkgdatadir)\"" >> $@
	@echo "#define PKGLIBDIR  \"$(pkglibdir)\"" >> $@

stdafx.h.gch: stdafx.h
	$(CXXCOMPILE) -x c++-header $<

libgura_la_SOURCES = \
Common.cpp Parser.cpp Expr.cpp Value.cpp Iterator.cpp \
Symbol.cpp String.cpp Binary.cpp Environment.cpp Signal.cpp Formatter.cpp Option.cpp \
Function.cpp Operator.cpp Declaration.cpp \
Algorithm.cpp Codec.cpp \
Stream.cpp Directory.cpp DateTime.cpp Image.cpp OAL.cpp \
$(DIR_SFMT)/SFMT.c \
Object.cpp \
Object_function.cpp \
Object_string.cpp \
Object_binary.cpp \
Object_list.cpp \
Object_matrix.cpp \
Object_dict.cpp \
Object_stream.cpp \
Object_datetime.cpp \
Object_timedelta.cpp \
Object_expr.cpp \
Object_environment.cpp \
Object_error.cpp \
Object_uri.cpp \
Object_iterator.cpp \
Object_semaphore.cpp \
Object_codec.cpp \
Object_image.cpp \
Object_palette.cpp \
Object_color.cpp \
Object_audio.cpp \
Object_args.cpp \
StructObject.cpp \
CustomClass.cpp \
Module.cpp \
Module_basement.cpp \
Module_sys.cpp \
Module_codecs_basic/Module_codecs_basic.cpp \
Module_codecs_iso8859/Module_codecs_iso8859.cpp \
Module_codecs_japanese/Module_codecs_japanese.cpp \
Module_codecs_japanese/Conv_Japanese.cpp \
Module_base64/Module_base64.cpp \
Module_fs/Module_fs.cpp \
Module_math/Module_math.cpp \
Module_os/Module_os.cpp \
Module_path/Module_path.cpp \
Module_time/Module_time.cpp

pkglib_DATA = \
../module/calendar.gura \
../module/gltester.gura \
../module/graph.gura \
../module/modbuild.gura \
../module/gurcbuild.gura \
../module/tk.gura \
../module/units.gura \
../module/lets_module.gura

include_HEADERS = \
../include/gura.h

pkginclude_HEADERS = \
../include/gura/Object_iterator.h \
../include/gura/Object_uri.h \
../include/gura/Object_color.h \
../include/gura/Option.h \
../include/gura/Function.h \
../include/gura/Object_list.h \
../include/gura/Object.h \
../include/gura/Object_palette.h \
../include/gura/Declaration.h \
../include/gura/Object_semaphore.h \
../include/gura/Object_datetime.h \
../include/gura/DateTime.h \
../include/gura/Image.h \
../include/gura/Expr.h \
../include/gura/StructObject.h \
../include/gura/Formatter.h \
../include/gura/Directory.h \
../include/gura/Object_audio.h \
../include/gura/Object_matrix.h \
../include/gura/Operator.h \
../include/gura/Object_codec.h \
../include/gura/Object_image.h \
../include/gura/Object_error.h \
../include/gura/Object_string.h \
../include/gura/PackedNumber.h \
../include/gura/String.h \
../include/gura/Binary.h \
../include/gura/Parser.h \
../include/gura/Object_stream.h \
../include/gura/Object_dict.h \
../include/gura/Symbol.h \
../include/gura/Algorithm.h \
../include/gura/Object_timedelta.h \
../include/gura/Environment.h \
../include/gura/Object_function.h \
../include/gura/Module.h \
../include/gura/Signal.h \
../include/gura/Object_environment.h \
../include/gura/Common.h \
../include/gura/Value.h \
../include/gura/Stream.h \
../include/gura/Object_expr.h \
../include/gura/CustomClass.h \
../include/gura/Codec.h \
../include/gura/Object_binary.h \
../include/gura/OAL.h \
../include/gura/Iterator.h \
../include/gura/ZLibHelper.h \
../include/gura/BZLibHelper.h \
../include/gura/Object_args.h \
config.h

nobase_pkgdata_DATA = \
sample/scribble/gl-scribble-clear.gura \
sample/scribble/gl-scribble-cube.gura \
sample/scribble/ggraph.gura \
sample/mswin/mswin-vb.gura \
sample/mswin/mswin-excel.gura \
sample/tk/tk-treeview.guraw \
sample/tk/tk-misc.guraw \
sample/tk/tk-kangaroo.guraw \
sample/tk/tk-progressbar.guraw \
sample/tk/tk-button.guraw \
sample/tk/tk-canvas.guraw \
sample/tk/tk-listbox.guraw \
sample/tk/tk-calc.guraw \
sample/tk/tk-first.guraw \
sample/tk/tk-text.guraw \
sample/tk/tk-slideshow.guraw \
sample/tk/tk-panedwindow.guraw \
sample/tk/tk-notebook.guraw \
sample/tk/tk-stopwatch.guraw \
sample/tk/tk-menu.guraw \
sample/tk/tk-event.guraw \
sample/tk/tk-scrollbar.guraw \
sample/resource/readme.txt \
sample/resource/arrow-green-l.gif \
sample/resource/arrow-green-u.gif \
sample/resource/kangaroo.png \
sample/resource/chicken16.bmp \
sample/resource/Winter.jpg \
sample/resource/Blue_hills.jpg \
sample/resource/Water_lilies.jpg \
sample/resource/Kaufmann_Bold_BT.ttf \
sample/resource/arrow-green-r.gif \
sample/resource/kangaroo.gif \
sample/resource/arrow-green-d.gif \
sample/resource/zippedfont.zip \
sample/resource/chicken-anim.gif \
sample/resource/chicken256.bmp \
sample/resource/Sunset.jpg \
sample/resource/msnms.ico \
sample/opengl/1.rgb \
sample/opengl/2.rgb \
sample/opengl/3.rgb \
sample/opengl/gl-prim.guraw \
sample/opengl/gl-depth.guraw \
sample/opengl/gl-twotextures.guraw \
sample/opengl/gl-star.guraw \
sample/opengl/gl-accum.guraw \
sample/opengl/gl-bitmap1.guraw \
sample/opengl/gl-logo.guraw \
sample/opengl/gl-wave.guraw \
sample/opengl/gl-nurb.guraw \
sample/opengl/gl-teapot.guraw \
sample/opengl/gl-copy.guraw \
sample/opengl/gl-bitmap2.guraw \
sample/opengl/gl-cube.guraw \
sample/opengl/gl-stretch.guraw \
sample/opengl/gl-sphere.guraw \
sample/opengl/gl-teapot-image.gura \
sample/http/http-server.gura \
sample/http/proxy_setting.sample.gura \
sample/http/http-image.gura \
sample/http/http-misc.gura \
sample/http/http-client.gura \
sample/http/http-open.gura \
sample/sdl/sdl-test.guraw \
sample/sdl/sdl-slideshow.guraw \
sample/sdl/sdl-chicken.guraw \
sample/sdl/sdl-dispimg.guraw \
sample/canvas/test-canvas.gura \
sample/freetype/freetype-rotate.guraw \
sample/freetype/freetype-simple.guraw \
sample/freetype/freetype-decoration.guraw \
sample/freetype/freetype-zip.guraw \
sample/freetype/freetype-misc.guraw \
sample/freetype/freetype-http.guraw \
sample/freetype/freetype-cp932.guraw \
sample/freetype/freetype-list.gura \
sample/misc/wc.gura \
sample/misc/sudoku-resolver.gura \
sample/misc/parse-services.gura \
sample/misc/dump.gura \
sample/misc/eightqueen-resolver.gura \
sample/misc/hello.gura \
sample/misc/services \
sample/misc/pentomino-resolver.gura \
sample/misc/standalone-sample.bat \
sample/cairo/cairo-pdf.gura \
sample/cairo/cairo-samples.guraw \
application/getterphoto/getterphoto.guraw \
application/getterphoto/getterphoto.ico \
application/guraplot/guraplot.guraw \
application/makecalc/makecalc.guraw
