add_executable(guri guri.cpp)

set_property(TARGET guri PROPERTY COMPILE_DEFINITIONS)

target_link_libraries(guri guracore)

install(TARGETS guri DESTINATION ${GURA_RELDIR_BINARY})
