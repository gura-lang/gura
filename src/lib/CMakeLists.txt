# CMake Configuration for libguracore

add_library(guracore SHARED
Algorithm.cpp
Argument.cpp
Array.cpp
ArrayT.cpp
Audio.cpp
Binary.cpp
Callable.cpp
Class.cpp
Class_Class.cpp
Class_Module.cpp
Class_Struct.cpp
Class_any.cpp
Class_argument.cpp
Class_array.cpp
Class_arrayT.cpp
Class_audio.cpp
Class_binary.cpp
Class_boolean.cpp
Class_codec.cpp
Class_color.cpp
Class_complex.cpp
Class_datetime.cpp
Class_declaration.cpp
Class_dict.cpp
Class_directory.cpp
Class_environment.cpp
Class_error.cpp
Class_expr.cpp
Class_formatter.cpp
Class_function.cpp
Class_help.cpp
Class_image.cpp
Class_iterator.cpp
Class_list.cpp
Class_memory.cpp
Class_monitor.cpp
Class_nil.cpp
Class_number.cpp
Class_operator.cpp
Class_optimizer.cpp
Class_palette.cpp
Class_pointer.cpp
Class_propdeclaration.cpp
Class_quote.cpp
Class_rational.cpp
Class_semaphore.cpp
Class_stream.cpp
Class_string.cpp
Class_suffixmgr.cpp
Class_symbol.cpp
Class_template.cpp
Class_timedelta.cpp
Class_token.cpp
Class_trainer.cpp
Class_trainernode.cpp
Class_undefined.cpp
Class_uri.cpp
Class_vertex.cpp
Class_gear.cpp
Class_gear_at_averagepool1d.cpp
Class_gear_at_averagepool2d.cpp
Class_gear_at_averagepool3d.cpp
Class_gear_at_conv1d.cpp
Class_gear_at_conv2d.cpp
Class_gear_at_conv3d.cpp
Class_gear_at_maxpool1d.cpp
Class_gear_at_maxpool2d.cpp
Class_gear_at_maxpool3d.cpp
Class_gear_at_relu.cpp
Class_gear_at_sigmoid.cpp
Class_gear_at_softmax.cpp
Class_gear_at_tanh.cpp
ClassCustom.cpp
Codec.cpp
Color.cpp
Common.cpp
Complex.cpp
DateTime.cpp
Declaration.cpp
Directory.cpp
Error.cpp
Environment.cpp
Expr.cpp
Formatter.cpp
Function.cpp
FunctionCustom.cpp
Fundamental.cpp
Half.cpp
Help.cpp
Image.cpp
Iterator.cpp
IteratorBasic.cpp
Memory.cpp
MemoryPool.cpp
Module.cpp
Monitor.cpp
MonitorBasic.cpp
OAL.cpp
Operator.cpp
OperatorArray.cpp
OperatorBasic.cpp
Option.cpp
Packer.cpp
Palette.cpp
Parser.cpp
PathMgr.cpp
Pointer.cpp
PropDeclaration.cpp
Random.cpp
Rational.cpp
Signal.cpp
Stream.cpp
StreamBasic.cpp
String.cpp
SuffixMgr.cpp
Symbol.cpp
Template.cpp
Token.cpp
Trainer.cpp
Unicode-CP932.cpp
Unicode-CP936.cpp
Unicode-CP949.cpp
Unicode-CP950.cpp
Unicode-EastAsianWidth.cpp
Uri.cpp
Value.cpp
ValueType.cpp
Version.cpp
Vertex.cpp
../module-basement/module-basement.cpp
../module-sys/module-sys.cpp
../module-base64/module-base64.cpp
../module-codecs/module-codecs.cpp
../module-codecs_basic/module-codecs_basic.cpp
../module-codecs_chinese/module-codecs_chinese.cpp
../module-codecs_iso8859/module-codecs_iso8859.cpp
../module-codecs_japanese/module-codecs_japanese.cpp
../module-codecs_korean/module-codecs_korean.cpp
../module-fs/module-fs.cpp
../module-lexer/module-lexer.cpp
../module-math/module-math.cpp
../module-os/module-os.cpp
../module-path/module-path.cpp
../dSFMT-src-2.2.1/dSFMT.c
)

target_link_libraries(guracore dl pthread)

set_property(TARGET guracore PROPERTY
  COMPILE_DEFINITIONS HAVE_CONFIG_H)

set_property(SOURCE Random.cpp ../dSFMT-src-2.2.1/dSFMT.c PROPERTY
  COMPILE_DEFINITIONS DSFMT_MEXP=19937)

set_target_properties(guracore PROPERTIES
  VERSION      ${GURA_VERSION}
  SOVERSION    ${GURA_VERSION_SO}
  BUILD_WITH_INSTALL_RPATH 1
  INSTALL_NAME_DIR "@executable_path/../lib")

install(TARGETS guracore DESTINATION ${GURA_RELDIR_LIBRARY})
