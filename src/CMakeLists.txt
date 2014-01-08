# CMake Configuration for Gura
# Available operations:
#  - Build library and executables
#    $ make
#  - Install files to the system
#    $ sudo make install
#  - Make packages of Debian and RPM
#    $ make package
# When you want to see the detailed process, run "make VERBOSE=1".

cmake_minimum_required(VERSION 2.6)

project(gura)

set(GURA_VERSION_MAJOR	0)
set(GURA_VERSION_MINOR	4)
set(GURA_VERSION_PATCH	0)

set(GURA_VERSION		${GURA_VERSION_MAJOR}.${GURA_VERSION_MINOR}.${GURA_VERSION_PATCH})
set(GURA_VERSION_SO		${GURA_VERSION_MAJOR})

set(GURA_ROOT_SRCDIR	${PROJECT_SOURCE_DIR}/..)
set(GURA_INCLUDE_SRCDIR	${GURA_ROOT_SRCDIR}/include)
set(GURA_SAMPLE_SRCDIR	${GURA_ROOT_SRCDIR}/sample)
set(GURA_MODULE_SRCDIR	${GURA_ROOT_SRCDIR}/module)

set(GURA_BINDIR			${CMAKE_INSTALL_PREFIX}/bin)
set(GURA_PKGDATADIR		${CMAKE_INSTALL_PREFIX}/share/gura/${GURA_VERSION})
set(GURA_PKGLIBDIR		${CMAKE_INSTALL_PREFIX}/lib/gura/${GURA_VERSION})
set(GURA_PKGINCDIR		${CMAKE_INSTALL_PREFIX}/include/gura/${GURA_VERSION})

configure_file(
  ${GURA_ROOT_SRCDIR}/include/gura/Version.h.in
  ${GURA_ROOT_SRCDIR}/include/gura/Version.h)

configure_file(
  ${GURA_ROOT_SRCDIR}/include/gura/config.h.in
  ${GURA_ROOT_SRCDIR}/include/gura/config.h)

configure_file(
  ${PROJECT_SOURCE_DIR}/build-modules.in
  ${PROJECT_SOURCE_DIR}/build-modules)

file(COPY
  ${PROJECT_SOURCE_DIR}/build-modules
  DESTINATION .
  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ)

include_directories(
  ${GURA_ROOT_SRCDIR}/include
  ${PROJECT_SOURCE_DIR}/lib
  ${PROJECT_SOURCE_DIR}/lib/SFMT-src-1.3.3)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(${PROJECT_SOURCE_DIR}/program-gura)
add_subdirectory(${PROJECT_SOURCE_DIR}/program-guri)

install(FILES
  ${GURA_SAMPLE_SRCDIR}/resource/Winter.jpg
  ${GURA_SAMPLE_SRCDIR}/resource/readme.txt
  ${GURA_SAMPLE_SRCDIR}/resource/arrow-green-u.gif
  ${GURA_SAMPLE_SRCDIR}/resource/arrow-green-d.gif
  ${GURA_SAMPLE_SRCDIR}/resource/msnms.ico
  ${GURA_SAMPLE_SRCDIR}/resource/arrow-green-r.gif
  ${GURA_SAMPLE_SRCDIR}/resource/Kaufmann_Bold_BT.ttf
  ${GURA_SAMPLE_SRCDIR}/resource/banner-small.png
  ${GURA_SAMPLE_SRCDIR}/resource/Water_lilies.jpg
  ${GURA_SAMPLE_SRCDIR}/resource/Sunset.jpg
  ${GURA_SAMPLE_SRCDIR}/resource/chicken16.bmp
  ${GURA_SAMPLE_SRCDIR}/resource/chicken-anim.gif
  ${GURA_SAMPLE_SRCDIR}/resource/Blue_hills.jpg
  ${GURA_SAMPLE_SRCDIR}/resource/kangaroo.png
  ${GURA_SAMPLE_SRCDIR}/resource/arrow-green-l.gif
  ${GURA_SAMPLE_SRCDIR}/resource/kangaroo.gif
  ${GURA_SAMPLE_SRCDIR}/resource/zippedfont.zip
  ${GURA_SAMPLE_SRCDIR}/resource/chicken256.bmp
  DESTINATION share/gura/${GURA_VERSION}/sample/resource)

install(FILES
  ${GURA_MODULE_SRCDIR}/argopt.gura
  ${GURA_MODULE_SRCDIR}/calendar.gura
  ${GURA_MODULE_SRCDIR}/graph.gura
  ${GURA_MODULE_SRCDIR}/gurcbuild.gura
  ${GURA_MODULE_SRCDIR}/markdown.gura
  ${GURA_MODULE_SRCDIR}/modbuild.gura
  ${GURA_MODULE_SRCDIR}/modgen.gura
  ${GURA_MODULE_SRCDIR}/msxls.gura
  ${GURA_MODULE_SRCDIR}/sed.gura
  ${GURA_MODULE_SRCDIR}/show.gura
  ${GURA_MODULE_SRCDIR}/testutil.gura
  ${GURA_MODULE_SRCDIR}/tk.gura
  ${GURA_MODULE_SRCDIR}/tk.show.gura
  ${GURA_MODULE_SRCDIR}/tokenizer.gura
  ${GURA_MODULE_SRCDIR}/units.gura
  ${GURA_MODULE_SRCDIR}/wx.show.gura
  ${GURA_MODULE_SRCDIR}/xhtml.gura
  DESTINATION lib/gura/${GURA_VERSION}/module)

install(FILES
  ${GURA_INCLUDE_SRCDIR}/gura.h
  DESTINATION ${GURA_PKGINCDIR})

install(FILES
  ${GURA_INCLUDE_SRCDIR}/gura/Algorithm.h
  ${GURA_INCLUDE_SRCDIR}/gura/Audio.h
  ${GURA_INCLUDE_SRCDIR}/gura/Binary.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_args.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_audio.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_binary.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_codec.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_color.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_datetime.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_declaration.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_dict.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_directory.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_environment.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_error.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_expr.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_function.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_help.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_image.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_iterator.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_list.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_matrix.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_operator.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_palette.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_pointer.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_semaphore.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_stream.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_template.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_timedelta.h
  ${GURA_INCLUDE_SRCDIR}/gura/Class_uri.h
  ${GURA_INCLUDE_SRCDIR}/gura/ClassBasic.h
  ${GURA_INCLUDE_SRCDIR}/gura/ClassCustom.h
  ${GURA_INCLUDE_SRCDIR}/gura/ClassOfStruct.h
  ${GURA_INCLUDE_SRCDIR}/gura/Codec.h
  ${GURA_INCLUDE_SRCDIR}/gura/Common.h
  ${GURA_INCLUDE_SRCDIR}/gura/DateTime.h
  ${GURA_INCLUDE_SRCDIR}/gura/Declaration.h
  ${GURA_INCLUDE_SRCDIR}/gura/Directory.h
  ${GURA_INCLUDE_SRCDIR}/gura/Environment.h
  ${GURA_INCLUDE_SRCDIR}/gura/Error.h
  ${GURA_INCLUDE_SRCDIR}/gura/Expr.h
  ${GURA_INCLUDE_SRCDIR}/gura/Formatter.h
  ${GURA_INCLUDE_SRCDIR}/gura/Function.h
  ${GURA_INCLUDE_SRCDIR}/gura/FunctionCustom.h
  ${GURA_INCLUDE_SRCDIR}/gura/Fundamental.h
  ${GURA_INCLUDE_SRCDIR}/gura/Help.h
  ${GURA_INCLUDE_SRCDIR}/gura/Image.h
  ${GURA_INCLUDE_SRCDIR}/gura/Iterator.h
  ${GURA_INCLUDE_SRCDIR}/gura/IteratorBasic.h
  ${GURA_INCLUDE_SRCDIR}/gura/Matrix.h
  ${GURA_INCLUDE_SRCDIR}/gura/Memory.h
  ${GURA_INCLUDE_SRCDIR}/gura/Module.h
  ${GURA_INCLUDE_SRCDIR}/gura/OAL.h
  ${GURA_INCLUDE_SRCDIR}/gura/Operator.h
  ${GURA_INCLUDE_SRCDIR}/gura/Option.h
  ${GURA_INCLUDE_SRCDIR}/gura/PackedNumber.h
  ${GURA_INCLUDE_SRCDIR}/gura/Palette.h
  ${GURA_INCLUDE_SRCDIR}/gura/Parser.h
  ${GURA_INCLUDE_SRCDIR}/gura/PathManager.h
  ${GURA_INCLUDE_SRCDIR}/gura/Processor.h
  ${GURA_INCLUDE_SRCDIR}/gura/Signal.h
  ${GURA_INCLUDE_SRCDIR}/gura/Stream.h
  ${GURA_INCLUDE_SRCDIR}/gura/StreamBasic.h
  ${GURA_INCLUDE_SRCDIR}/gura/String.h
  ${GURA_INCLUDE_SRCDIR}/gura/Symbol.h
  ${GURA_INCLUDE_SRCDIR}/gura/Template.h
  ${GURA_INCLUDE_SRCDIR}/gura/Value.h
  ${GURA_INCLUDE_SRCDIR}/gura/ValueType.h
  ${GURA_INCLUDE_SRCDIR}/gura/Version.h
  DESTINATION ${GURA_PKGINCDIR}/gura)

install(FILES
  ${GURA_INCLUDE_SRCDIR}/gura/helper/BZLibHelper.h
  ${GURA_INCLUDE_SRCDIR}/gura/helper/ZLibHelper.h
  DESTINATION ${GURA_PKGINCDIR}/gura/helper)

set(CPACK_GENERATOR "DEB;RPM")
set(CPACK_SET_DESTDIR true)
SET(CPACK_PACKAGE_RELOCATABLE false)

set(CPACK_PACKAGE_NAME					"gura")
set(CPACK_PACKAGE_CONTACT				"Yutaka Saito <ypsitau@nifty.com>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY	"Gura Programming Language")
set(CPACK_PACKAGE_VERSION_MAJOR			${GURA_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR			${GURA_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH			${GURA_VERSION_PATCH})

SET(CPACK_DEBIAN_PACKAGE_NAME			${CPACK_PACKAGE_NAME})
SET(CPACK_DEBIAN_PACKAGE_PRIORITY		"optional")
SET(CPACK_DEBIAN_PACKAGE_SECTION		"interpreters")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER		${CPACK_PACKAGE_CONTACT})
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE	"i386")
SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION	${CPACK_PACKAGE_DESCRIPTION_SUMMARY})
SET(CPACK_DEBIAN_PACKAGE_VERSION		${CPACK_PACKAGE_VERSION})
SET(CPACK_DEBIAN_PACKAGE_DEPENDS		"libc6 (>= 2.3), libreadline6 (>= 6.0)")

SET(CPACK_RPM_PACKAGE_NAME				${CPACK_PACKAGE_NAME})
SET(CPACK_RPM_PACKAGE_DESCRIPTION		${CPACK_PACKAGE_DESCRIPTION_SUMMARY})
SET(CPACK_RPM_PACKAGE_VERSION			${CPACK_PACKAGE_VERSION})
SET(CPACK_RPM_PACKAGE_VENDOR			${CPACK_PACKAGE_CONTACT})
SET(CPACK_RPM_PACKAGE_ARCHITECTURE		"i386")
SET(CPACK_RPM_PACKAGE_REQUIRES			"glibc >= 2.3, readline >= 6.0")

include(CPack)
