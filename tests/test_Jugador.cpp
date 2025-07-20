#include <gtest/gtest.h>
#include "../src/Jugador.h"

TEST(JugadorTest, ApostarReduceDinero) {
    Jugador jugador("Pedro", 1000); // 1000 de saldo inicial.
    jugador.apostar(500);
    EXPECT_EQ(jugador.get_dinero(), 500); // 1000 - 500 = 500.
    EXPECT_EQ(jugador.get_apuesta(), 500); // Apuesta actualizada.
}

TEST(JugadorTest, SetDineroActualizaSaldo) {
    Jugador jugador("Sofía", 200);
    jugador.set_dinero(300);
    EXPECT_EQ(jugador.get_dinero(), 500); // Saldo nuevo = 300.
}