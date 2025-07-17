cmake_minimum_required(VERSION 3.10)
project(BlackJack)

set(CMAKE_CXX_STANDARD 17)

# Fuentes principales
add_library(juego_lib STATIC
    src/Carta.cpp
    src/Jugador.cpp
    src/Mazo.cpp
    src/Mesa.cpp
    src/ServicioRecarga.cpp
    src/Interfaz.cpp
    src/Crupier.cpp
    src/Controlador.cpp
)

# Pruebas unitarias
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()



