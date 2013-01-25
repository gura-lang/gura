link_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(gura gura.cpp)

target_link_libraries(gura guracore)
