# Definir a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Pega o nome da pasta onde o CMakeLists.txt está localizado
get_filename_component(PROJECT_DIR_NAME ${CMAKE_SOURCE_DIR} NAME)

# Definir o nome do projeto
project(${PROJECT_DIR_NAME})

# Definir a versão do C++
set(CMAKE_CXX_STANDARD 17)

# Ativar suporte para testes
enable_testing()

# Diretório central para os cabeçalhos
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Definir a variável de diretório do Google Test
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/googletest)

# Baixar e configurar o Google Test se necessário
if (NOT EXISTS ${GTEST_DIR})
  message(STATUS "Google Test não encontrado. Baixando...")
  execute_process(COMMAND git clone https://github.com/google/googletest.git /d/Dev_Projects/c++/Calculadora/googletest)
endif()

# Incluir o diretório do Google Test
add_subdirectory(${GTEST_DIR})

# Variáveis para armazenar os arquivos de código-fonte
set(LIBRARY_SOURCES "")  # Arquivos de bibliotecas
set(TEST_SOURCES "")     # Arquivos de teste
set(MAIN_SOURCE "")      # Arquivo principal

# Buscar arquivos de código-fonte automaticamente (separando por tipo)
file(GLOB_RECURSE SOURCES src/*.cpp)

# Separar os arquivos por tipo
foreach(SOURCE ${SOURCES})
    if(${SOURCE} MATCHES "src/main.cpp")
        set(MAIN_SOURCE ${SOURCE})
    elseif(${SOURCE} MATCHES "test/")
        list(APPEND TEST_SOURCES ${SOURCE})
    else()
        list(APPEND LIBRARY_SOURCES ${SOURCE})
    endif()
endforeach()

# Verificar se há arquivos de teste no diretório test/
file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/test/*.cpp)
if(TEST_FILES)
    list(APPEND TEST_SOURCES ${TEST_FILES})
else()
    message(WARNING "Nenhum arquivo de teste encontrado em test/")
endif()

# Criar a biblioteca, apenas se existirem arquivos .cpp
if (LIBRARY_SOURCES)
    add_library(${PROJECT_NAME}_lib ${LIBRARY_SOURCES})
else()
    message(WARNING "Nenhum arquivo de biblioteca encontrado em src/")
endif()

# Criar o executável principal, apenas se o main.cpp existir
if (MAIN_SOURCE)
    add_executable(${PROJECT_NAME}_main ${MAIN_SOURCE})
    if (LIBRARY_SOURCES)
        target_link_libraries(${PROJECT_NAME}_main ${PROJECT_NAME}_lib)
    endif()
else()
    message(WARNING "Nenhum arquivo main.cpp encontrado em src/")
endif()

# Criar o executável de testes, apenas se arquivos de teste existirem
if (TEST_SOURCES)
    add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})
    target_link_libraries(${PROJECT_NAME}_tests gtest gtest_main)
    if (LIBRARY_SOURCES)
        target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME}_lib)
    endif()
    # Registrar os testes
    # add_test(NAME ${PROJECT_NAME}TestSuite COMMAND ${PROJECT_NAME}_tests)
    foreach(TEST_FILE ${TEST_FILES})
        # Extrai o nome do arquivo sem a extensão
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

        # Criar um executável individual para cada arquivo de teste
        add_executable(${TEST_NAME} ${TEST_FILE})

        # Linkar o Google Test e as bibliotecas do seu projeto
        target_link_libraries(${TEST_NAME} gtest gtest_main)

        if (LIBRARY_SOURCES)
            target_link_libraries(${TEST_NAME} ${PROJECT_NAME}_lib)
        endif()

        # Registra o teste no CTest
        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    endforeach()

    else()
    message(WARNING "Nenhum arquivo de teste encontrado em test/")
endif()

# Configurações adicionais de compilação
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
