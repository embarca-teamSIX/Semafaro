# Defina o caminho para o SDK do Raspberry Pi Pico
set(PICO_SDK_PATH "<caminho_para_o_sdk_do_pico>")

# Inclua o arquivo principal do SDK
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Agora, defina o ambiente de compilação para o seu projeto
project(meu_projeto)

# Especifique o caminho para o SDK do Raspberry Pi Pico
pico_sdk_init()

# Inclua os diretórios do seu projeto
add_executable(meu_programa
    src/main.cpp  # Ou qualquer que seja o seu arquivo fonte
)

# Vincule a biblioteca do SDK ao seu programa
target_link_libraries(meu_programa pico_stdlib)

# Defina o diretório de saída para o firmware UF2
pico_add_extra_outputs(meu_programa)
