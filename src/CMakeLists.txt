cmake_minimum_required(VERSION 2.6)

project(gura)

set(BINDIR "/usr/local/bin")
set(PKGDATADIR "/usr/local/share/gura")
set(PKGLIBDIR "/usr/local/lib/gura")

configure_file(config.h.in config.h)
include(CheckLibraryExists)
check_library_exists(dl dlopen "" HAVE_LIBDL)

add_subdirectory(lib)
add_subdirectory(Program_gura)
