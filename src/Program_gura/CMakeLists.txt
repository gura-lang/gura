include_directories("${PROJECT_SOURCE_DIR}/../include")

add_executable(gura gura.cpp)

set_property(TARGET gura PROPERTY COMPILE_DEFINITIONS HAVE_CONFIG_H)

target_link_libraries(gura guracore)

install(TARGETS gura DESTINATION bin)
