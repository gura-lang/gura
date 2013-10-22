add_library(guracore SHARED
../dSFMT-src-2.2.1/dSFMT.c
OAL.cpp
Algorithm.cpp
Audio.cpp
Binary.cpp
Codec.cpp
Codec_Japanese.cpp
Common.cpp
CustomClass.cpp
CustomFunction.cpp
DateTime.cpp
Declaration.cpp
Directory.cpp
Environment.cpp
Expr.cpp
Formatter.cpp
Help.cpp
Function.cpp
Image.cpp
Iterator.cpp
Matrix.cpp
Memory.cpp
Operator.cpp
Option.cpp
Palette.cpp
Parser.cpp
Processor.cpp
PathManager.cpp
TemplateEngine.cpp
Error.cpp
Signal.cpp
Stream.cpp
String.cpp
StructObject.cpp
Symbol.cpp
Value.cpp
Fundamental.cpp
Class.cpp
Object.cpp
Object_args.cpp
Object_audio.cpp
Object_binary.cpp
Object_pointer.cpp
Object_codec.cpp
Object_color.cpp
Object_datetime.cpp
Object_dict.cpp
Object_environment.cpp
Object_error.cpp
Object_expr.cpp
Object_help.cpp
Object_function.cpp
Object_operator.cpp
Object_image.cpp
Object_iterator.cpp
Object_list.cpp
Object_matrix.cpp
Object_palette.cpp
Object_semaphore.cpp
Object_stream.cpp
Object_directory.cpp
Object_string.cpp
Object_timedelta.cpp
Object_uri.cpp
Module.cpp
module-basement.cpp
module-sys.cpp
../module-codecs_basic/module-codecs_basic.cpp
../module-codecs_iso8859/module-codecs_iso8859.cpp
../module-codecs_japanese/module-codecs_japanese.cpp
../module-base64/module-base64.cpp
../module-fs/module-fs.cpp
../module-math/module-math.cpp
../module-os/module-os.cpp
../module-path/module-path.cpp
../module-time/module-time.cpp
../module-conio/module-conio.cpp
)

target_link_libraries(guracore dl pthread)

set_property(TARGET guracore PROPERTY COMPILE_DEFINITIONS HAVE_CONFIG_H)
set_property(SOURCE Common.cpp PROPERTY COMPILE_DEFINITIONS DSFMT_MEXP=19937)
set_property(SOURCE ../dSFMT-src-2.2.1/dSFMT.c PROPERTY COMPILE_DEFINITIONS DSFMT_MEXP=19937)

set_target_properties(guracore PROPERTIES
  VERSION ${GURA_VERSION}
  SOVERSION ${GURA_VERSION_SO})

install(TARGETS guracore DESTINATION lib)
