cmake_minimum_required(VERSION 3.13)

# Nome do projeto
project(Semafaro_project)

# Indicar o uso do SDK do Pico
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# Criar executável principal
add_executable(Semafaro
    main.c
)

# Vincular ao SDK
pico_sdk_init()
target_link_libraries(Semafaro pico_stdlib)

# Criar o arquivo UF2 para carregar no Raspberry Pi Pico
pico_add_extra_outputs(Semafaro)
