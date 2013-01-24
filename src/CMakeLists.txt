set(BINDIR "/usr/local/bin")
set(PKGDATADIR "/usr/local/share/gura")
set(PKGLIBDIR "/usr/local/lib/gura")

include_directories(
"${PROJECT_SOURCE_DIR}/include"
"${PROJECT_SOURCE_DIR}/src"
"${PROJECT_SOURCE_DIR}/src/SFMT-src-1.3.3"
)

configure_file(libgura-config.h.in config_add.h)

add_library(gura-0.3 SHARED
SFMT-src-1.3.3/SFMT.c
OAL.cpp
Algorithm.cpp
Binary.cpp
Codec.cpp
Common.cpp
CustomClass.cpp
DateTime.cpp
Declaration.cpp
Directory.cpp
Environment.cpp
Expr.cpp
Formatter.cpp
Function.cpp
Image.cpp
Iterator.cpp
Module.cpp
Module_basement.cpp
Module_sys.cpp
Module_codecs_basic/Module_codecs_basic.cpp
Module_codecs_iso8859/Module_codecs_iso8859.cpp
Module_codecs_japanese/Module_codecs_japanese.cpp
Module_codecs_japanese/Conv_Japanese.cpp
Module_base64/Module_base64.cpp
Module_fs/Module_fs.cpp
Module_math/Module_math.cpp
Module_os/Module_os.cpp
Module_path/Module_path.cpp
Module_time/Module_time.cpp
Object.cpp
Object_args.cpp
Object_audio.cpp
Object_binary.cpp
Object_codec.cpp
Object_color.cpp
Object_datetime.cpp
Object_dict.cpp
Object_environment.cpp
Object_error.cpp
Object_expr.cpp
Object_function.cpp
Object_image.cpp
Object_iterator.cpp
Object_list.cpp
Object_matrix.cpp
Object_palette.cpp
Object_semaphore.cpp
Object_stream.cpp
Object_string.cpp
Object_timedelta.cpp
Object_uri.cpp
Operator.cpp
Option.cpp
Parser.cpp
Signal.cpp
Stream.cpp
String.cpp
StructObject.cpp
Symbol.cpp
Value.cpp
stdafx.cpp
)

target_link_libraries(gura-0.3 dl pthread)

set_property(TARGET gura-0.3 PROPERTY COMPILE_DEFINITIONS HAVE_CONFIG_H)
set_property(SOURCE SFMT-src-1.3.3/SFMT.c PROPERTY COMPILE_DEFINITIONS MEXP=19937)

install(TARGETS gura-0.3 DESTINATION lib)
