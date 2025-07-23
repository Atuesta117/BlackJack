find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../src)

# Primero crea una librería con TODAS las dependencias base
add_library(juego_base STATIC
    ../src/Carta.cpp
    ../src/Mazo.cpp
    ../src/PersonaCasino.cpp
    ../src/Jugador.cpp
    ../src/Mesa.cpp
    ../src/ServicioRecarga.cpp
    ../src/Interfaz.cpp 
    ../src/Crupier.cpp
)

# Tests individuales (ahora se vinculan con juego_base)
add_executable(test_Jugador test_Jugador.cpp)
target_link_libraries(test_Jugador juego_base GTest::GTest GTest::Main)

add_executable(test_Mazo test_Mazo.cpp)
target_link_libraries(test_Mazo juego_base GTest::GTest GTest::Main)

add_executable(test_Mesa test_Mesa.cpp)
target_link_libraries(test_Mesa juego_base GTest::GTest GTest::Main)

add_executable(test_Crupier test_Crupier.cpp)
target_link_libraries(test_Crupier juego_base GTest::GTest GTest::Main)

add_executable(test_Interfaz test_Interfaz.cpp)
target_link_libraries(test_Interfaz juego_base GTest::GTest GTest::Main)

add_executable(test_PersonaCasino test_PersonaCasino.cpp)
target_link_libraries(test_PersonaCasino juego_base GTest::GTest GTest::Main)

add_executable(test_ServicioRecarga test_ServicioRecarga.cpp)
target_link_libraries(test_ServicioRecarga juego_base GTest::GTest GTest::Main)

add_executable(test_Carta test_Carta.cpp)
target_link_libraries(test_Carta juego_base GTest::GTest GTest::Main)

# Añade pruebas
add_test(NAME JugadorTests COMMAND test_Jugador)
add_test(NAME MazoTests COMMAND test_Mazo)
add_test(NAME MesaTests COMMAND test_Mesa)
add_test(NAME ServicioRecargaTests COMMAND test_ServicioRecarga)
add_test(NAME PersonaCasinoTests COMMAND test_PersonaCasino)
add_test(NAME CartaTests COMMAND test_Carta)
add_test(NAME CrupierTests COMMAND test_Crupier)
add_test(NAME InterfazTests COMMAND test_Interfaz)
