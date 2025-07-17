#include <gtest/gtest.h>
#include "../src/Mesa.h"
#include "../src/Jugador.h"
#include "../src/Mazo.h"

TEST(MesaTest, AgregarJugadorAumentaTamanio) {
    Mesa mesa;
    Jugador jugador("Ana", 1000);
    mesa.agregar_jugador(&jugador, &jugador);
    EXPECT_EQ(mesa.get_jugadores().size(), 1);
}

TEST(MesaTest, EliminarJugadorPorIndice) {
    Mesa mesa;
    Jugador jugador("Pedro", 500);
    mesa.agregar_jugador(&jugador, &jugador);
    mesa.eliminar_jugador(0);
    EXPECT_TRUE(mesa.get_jugadores().empty());
}
