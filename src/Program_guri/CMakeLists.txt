add_executable(guri guri.cpp)

target_link_libraries(guri guracore)

install(TARGETS guri DESTINATION bin)
