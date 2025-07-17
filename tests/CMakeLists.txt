find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../src)

# Primero crea una librería con TODAS las dependencias base
add_library(juego_base STATIC
    ../src/Carta.cpp
    ../src/Mazo.cpp
    ../src/Controlador.cpp
    ../src/Jugador.cpp
    ../src/Mesa.cpp
    ../src/ServicioRecarga.cpp
    ../src/Interfaz.cpp      # ¡Nuevo! Añade esto
    ../src/Crupier.cpp
)

# Tests individuales (ahora se vinculan con juego_base)
add_executable(test_Jugador test_Jugador.cpp)
target_link_libraries(test_Jugador juego_base GTest::GTest GTest::Main)

add_executable(test_Mazo test_Mazo.cpp)
target_link_libraries(test_Mazo juego_base GTest::GTest GTest::Main)

add_executable(test_Mesa test_Mesa.cpp)
target_link_libraries(test_Mesa juego_base GTest::GTest GTest::Main)

add_executable(test_ServicioRecarga test_ServicioRecarga.cpp)
target_link_libraries(test_ServicioRecarga juego_base GTest::GTest GTest::Main)

# Añade pruebas
add_test(NAME JugadorTests COMMAND test_Jugador)
add_test(NAME MazoTests COMMAND test_Mazo)
add_test(NAME MesaTests COMMAND test_Mesa)
add_test(NAME ServicioRecargaTests COMMAND test_ServicioRecarga)
