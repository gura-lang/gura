cmake_minimum_required(VERSION 2.6)

project(mod_gura)

add_library(mod_gura SHARED
mod_gura.c
guraif.cpp
)

target_link_libraries(mod_gura dl pthread)

//set_property(TARGET mod_gura PROPERTY COMPILE_DEFINITIONS HAVE_CONFIG_H)

install(TARGETS guracore DESTINATION lib)
