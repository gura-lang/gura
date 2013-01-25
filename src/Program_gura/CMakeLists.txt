add_executable(gura gura.cpp)

target_link_libraries(gura guracore)

install(TARGETS gura DESTINATION bin)
