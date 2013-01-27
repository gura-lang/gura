include_directories("${PROJECT_SOURCE_DIR}/../include")

add_executable(guri guri.cpp)

set_property(TARGET guri PROPERTY COMPILE_DEFINITIONS HAVE_CONFIG_H)

target_link_libraries(guri guracore)

install(TARGETS guri DESTINATION bin)
