cmake_minimum_required(VERSION 2.6)

project(gura)

set(GURA_VERSION		0.3.1)
set(GURA_VERSION_SO		0)

set(GURA_ROOT_DIR		${PROJECT_SOURCE_DIR}/..)
set(GURA_INCLUDE_DIR	${GURA_ROOT_DIR}/include)
set(GURA_SAMPLE_DIR		${GURA_ROOT_DIR}/sample)
set(GURA_MODULE_DIR		${GURA_ROOT_DIR}/module)

set(BINDIR				${CMAKE_INSTALL_PREFIX}/bin)
set(PKGDATADIR			${CMAKE_INSTALL_PREFIX}/share/gura)
set(PKGLIBDIR			${CMAKE_INSTALL_PREFIX}/lib/gura)

configure_file(
  ${GURA_ROOT_DIR}/include/gura/config.h.in
  ${GURA_ROOT_DIR}/include/gura/config.h)

include_directories(
  ${GURA_ROOT_DIR}/include
  ${PROJECT_SOURCE_DIR}/lib
  ${PROJECT_SOURCE_DIR}/lib/SFMT-src-1.3.3)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(${PROJECT_SOURCE_DIR}/Program_gura)
add_subdirectory(${PROJECT_SOURCE_DIR}/Program_guri)

install(FILES
  ${GURA_SAMPLE_DIR}/resource/Winter.jpg
  ${GURA_SAMPLE_DIR}/resource/readme.txt
  ${GURA_SAMPLE_DIR}/resource/arrow-green-u.gif
  ${GURA_SAMPLE_DIR}/resource/arrow-green-d.gif
  ${GURA_SAMPLE_DIR}/resource/msnms.ico
  ${GURA_SAMPLE_DIR}/resource/arrow-green-r.gif
  ${GURA_SAMPLE_DIR}/resource/Kaufmann_Bold_BT.ttf
  ${GURA_SAMPLE_DIR}/resource/banner-small.png
  ${GURA_SAMPLE_DIR}/resource/Water_lilies.jpg
  ${GURA_SAMPLE_DIR}/resource/Sunset.jpg
  ${GURA_SAMPLE_DIR}/resource/chicken16.bmp
  ${GURA_SAMPLE_DIR}/resource/chicken-anim.gif
  ${GURA_SAMPLE_DIR}/resource/Blue_hills.jpg
  ${GURA_SAMPLE_DIR}/resource/kangaroo.png
  ${GURA_SAMPLE_DIR}/resource/arrow-green-l.gif
  ${GURA_SAMPLE_DIR}/resource/kangaroo.gif
  ${GURA_SAMPLE_DIR}/resource/zippedfont.zip
  ${GURA_SAMPLE_DIR}/resource/chicken256.bmp
  DESTINATION share/gura/sample/resource)
install(FILES
  ${GURA_MODULE_DIR}/calendar.gura
  ${GURA_MODULE_DIR}/graph.gura
  ${GURA_MODULE_DIR}/gurcbuild.gura
  ${GURA_MODULE_DIR}/lets_module.gura
  ${GURA_MODULE_DIR}/modbuild.gura
  ${GURA_MODULE_DIR}/msxls.gura
  ${GURA_MODULE_DIR}/tk.gura
  ${GURA_MODULE_DIR}/tokenizer.gura
  ${GURA_MODULE_DIR}/units.gura
  DESTINATION lib/gura)
install(FILES
  ${GURA_INCLUDE_DIR}/gura.h
  DESTINATION include)
install(FILES
  ${GURA_INCLUDE_DIR}/gura/Algorithm.h
  ${GURA_INCLUDE_DIR}/gura/BZLibHelper.h
  ${GURA_INCLUDE_DIR}/gura/Binary.h
  ${GURA_INCLUDE_DIR}/gura/Codec.h
  ${GURA_INCLUDE_DIR}/gura/Common.h
  ${GURA_INCLUDE_DIR}/gura/CustomClass.h
  ${GURA_INCLUDE_DIR}/gura/DateTime.h
  ${GURA_INCLUDE_DIR}/gura/Declaration.h
  ${GURA_INCLUDE_DIR}/gura/Directory.h
  ${GURA_INCLUDE_DIR}/gura/Environment.h
  ${GURA_INCLUDE_DIR}/gura/Expr.h
  ${GURA_INCLUDE_DIR}/gura/Formatter.h
  ${GURA_INCLUDE_DIR}/gura/Function.h
  ${GURA_INCLUDE_DIR}/gura/Image.h
  ${GURA_INCLUDE_DIR}/gura/Iterator.h
  ${GURA_INCLUDE_DIR}/gura/Module.h
  ${GURA_INCLUDE_DIR}/gura/OAL.h
  ${GURA_INCLUDE_DIR}/gura/Object.h
  ${GURA_INCLUDE_DIR}/gura/Object_args.h
  ${GURA_INCLUDE_DIR}/gura/Object_audio.h
  ${GURA_INCLUDE_DIR}/gura/Object_binary.h
  ${GURA_INCLUDE_DIR}/gura/Object_codec.h
  ${GURA_INCLUDE_DIR}/gura/Object_color.h
  ${GURA_INCLUDE_DIR}/gura/Object_datetime.h
  ${GURA_INCLUDE_DIR}/gura/Object_dict.h
  ${GURA_INCLUDE_DIR}/gura/Object_environment.h
  ${GURA_INCLUDE_DIR}/gura/Object_error.h
  ${GURA_INCLUDE_DIR}/gura/Object_expr.h
  ${GURA_INCLUDE_DIR}/gura/Object_function.h
  ${GURA_INCLUDE_DIR}/gura/Object_image.h
  ${GURA_INCLUDE_DIR}/gura/Object_iterator.h
  ${GURA_INCLUDE_DIR}/gura/Object_list.h
  ${GURA_INCLUDE_DIR}/gura/Object_matrix.h
  ${GURA_INCLUDE_DIR}/gura/Object_palette.h
  ${GURA_INCLUDE_DIR}/gura/Object_semaphore.h
  ${GURA_INCLUDE_DIR}/gura/Object_stream.h
  ${GURA_INCLUDE_DIR}/gura/Object_string.h
  ${GURA_INCLUDE_DIR}/gura/Object_timedelta.h
  ${GURA_INCLUDE_DIR}/gura/Object_uri.h
  ${GURA_INCLUDE_DIR}/gura/Operator.h
  ${GURA_INCLUDE_DIR}/gura/Option.h
  ${GURA_INCLUDE_DIR}/gura/PackedNumber.h
  ${GURA_INCLUDE_DIR}/gura/Parser.h
  ${GURA_INCLUDE_DIR}/gura/Signal.h
  ${GURA_INCLUDE_DIR}/gura/Stream.h
  ${GURA_INCLUDE_DIR}/gura/String.h
  ${GURA_INCLUDE_DIR}/gura/StructObject.h
  ${GURA_INCLUDE_DIR}/gura/Symbol.h
  ${GURA_INCLUDE_DIR}/gura/Value.h
  ${GURA_INCLUDE_DIR}/gura/ZLibHelper.h
  DESTINATION include/gura)
