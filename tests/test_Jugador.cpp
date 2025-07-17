#include <gtest/gtest.h>
#include "../src/Jugador.h"

TEST(JugadorTest, ApostarReduceDinero) {
    Jugador jugador("Ana", 1000);
    jugador.apostar(300);
    EXPECT_EQ(jugador.get_dinero(), 700);
}

TEST(JugadorTest, SetNombreActualizaCorrectamente) {
    Jugador jugador("", 500);
    jugador.set_nombre("Carlos");
    EXPECT_EQ(jugador.get_nombre(), "CARLOS"); // Asume que convierte a mayúsculas
}
