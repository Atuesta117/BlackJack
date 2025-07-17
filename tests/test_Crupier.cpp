#include <gtest/gtest.h>
#include "../src/Crupier.h"
#include "../src/Jugador.h"

TEST(CrupierTest, DeterminarGanador) {
    Mazo mazo;
    Crupier crupier("Casa", mazo);
    Jugador jugador("Carlos", 1000);

    // Simular manos (necesitarías inyectar cartas específicas).
    // Ejemplo si ambos tienen 18: empate.
    // EXPECT_EQ(crupier.determinar_ganador(&jugador), "Empate");

    // Caso donde crupier gana:
    // jugador.set_valor_mano(17);
    // crupier.set_valor_mano(20);
    // EXPECT_EQ(crupier.determinar_ganador(&jugador), "Crupier gana");
}

TEST(CrupierTest, MostrarManoParcial) {
    Mazo mazo;
    Crupier crupier("Casa", mazo);
    // Verificar que solo muestra 1 carta inicial (depende de tu implementación).
    // testing::internal::CaptureStdout();
    // crupier.mostrar_mano_parcial();
    // std::string output = testing::internal::GetCapturedStdout();
    // EXPECT_TRUE(output.find("[Carta oculta]") != std::string::npos);
}
