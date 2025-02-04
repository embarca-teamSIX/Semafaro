cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(semaforo)

pico_sdk_init()

add_executable(semaforo src/main.c)

target_link_libraries(semaforo pico_stdlib)

pico_add_extra_outputs(semaforo)
