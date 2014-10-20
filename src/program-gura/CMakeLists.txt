add_executable(gura gura.cpp)

set_property(TARGET gura PROPERTY COMPILE_DEFINITIONS)

find_library(LIBREADLINE readline REQUIRED)

target_link_libraries(gura guracore ${LIBREADLINE})

install(TARGETS gura DESTINATION ${GURA_RELDIR_BINARY})
