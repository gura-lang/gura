cmake_minimum_required(VERSION 2.6)

project(gura)

set(srcdir_include "../include/gura")
set(srcdir_sample "../sample")
set(srcdir_module "../module")

set(BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
set(PKGDATADIR ${CMAKE_INSTALL_PREFIX}/share/gura)
set(PKGLIBDIR ${CMAKE_INSTALL_PREFIX}/lib/gura)

configure_file(config.h.in config.h)

include(CheckLibraryExists)
check_library_exists(readline readline "" HAVE_LIBREADLINE)

include_directories(
"${PROJECT_SOURCE_DIR}"
"${PROJECT_SOURCE_DIR}/../include"
"${PROJECT_SOURCE_DIR}/lib"
"${PROJECT_SOURCE_DIR}/lib/SFMT-src-1.3.3"
)

add_subdirectory(lib)
add_subdirectory(Program_gura)
add_subdirectory(Program_guri)

install(FILES
  ${srcdir_module}/calendar.gura
  ${srcdir_module}/graph.gura
  ${srcdir_module}/gurcbuild.gura
  ${srcdir_module}/lets_module.gura
  ${srcdir_module}/modbuild.gura
  ${srcdir_module}/msxls.gura
  ${srcdir_module}/tk.gura
  ${srcdir_module}/tokenizer.gura
  ${srcdir_module}/units.gura
  DESTINATION lib/gura)
install(FILES ../include/gura.h DESTINATION include)
install(FILES
  ${srcdir_include}/Algorithm.h
  ${srcdir_include}/BZLibHelper.h
  ${srcdir_include}/Binary.h
  ${srcdir_include}/Codec.h
  ${srcdir_include}/Common.h
  ${srcdir_include}/CustomClass.h
  ${srcdir_include}/DateTime.h
  ${srcdir_include}/Declaration.h
  ${srcdir_include}/Directory.h
  ${srcdir_include}/Environment.h
  ${srcdir_include}/Expr.h
  ${srcdir_include}/Formatter.h
  ${srcdir_include}/Function.h
  ${srcdir_include}/Image.h
  ${srcdir_include}/Iterator.h
  ${srcdir_include}/Module.h
  ${srcdir_include}/OAL.h
  ${srcdir_include}/Object.h
  ${srcdir_include}/Object_args.h
  ${srcdir_include}/Object_audio.h
  ${srcdir_include}/Object_binary.h
  ${srcdir_include}/Object_codec.h
  ${srcdir_include}/Object_color.h
  ${srcdir_include}/Object_datetime.h
  ${srcdir_include}/Object_dict.h
  ${srcdir_include}/Object_environment.h
  ${srcdir_include}/Object_error.h
  ${srcdir_include}/Object_expr.h
  ${srcdir_include}/Object_function.h
  ${srcdir_include}/Object_image.h
  ${srcdir_include}/Object_iterator.h
  ${srcdir_include}/Object_list.h
  ${srcdir_include}/Object_matrix.h
  ${srcdir_include}/Object_palette.h
  ${srcdir_include}/Object_semaphore.h
  ${srcdir_include}/Object_stream.h
  ${srcdir_include}/Object_string.h
  ${srcdir_include}/Object_timedelta.h
  ${srcdir_include}/Object_uri.h
  ${srcdir_include}/Operator.h
  ${srcdir_include}/Option.h
  ${srcdir_include}/PackedNumber.h
  ${srcdir_include}/Parser.h
  ${srcdir_include}/Signal.h
  ${srcdir_include}/Stream.h
  ${srcdir_include}/String.h
  ${srcdir_include}/StructObject.h
  ${srcdir_include}/Symbol.h
  ${srcdir_include}/Value.h
  ${srcdir_include}/ZLibHelper.h
  DESTINATION include/gura)
