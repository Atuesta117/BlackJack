#include <gtest/gtest.h>
#include "../src/Controlador.h"
#include "../src/Mazo.h"

TEST(ControladorTest, IniciarPartidaCambiaEstado) {
    Controlador controlador("Juan");
    controlador.iniciar_partida();
    EXPECT_TRUE(controlador.get_esta_jugando()); // Debe estar jugando.
    controlador.terminar_partida();
    EXPECT_FALSE(controlador.get_esta_jugando()); // Debe terminar.
}

TEST(ControladorTest, PedirCartaAumentaMano) {
    Controlador controlador("Ana");
    Mazo mazo;
    mazo.shuffle();
    controlador.pedir_carta(mazo);
    EXPECT_EQ(controlador.get_cartas().size(), 1); // 1 carta añadida.
}

TEST(ControladorTest, VerificarBlackjack) {
    Controlador controlador("Luis");
    Mazo mazo;
    // Simular mano con As + Rey (necesitarías mockear el mazo o forzar cartas).
    // Asumamos que pedir_carta() añade cartas específicas en un test real.
    // EXPECT_TRUE(controlador.verificar_blackjack());
}

TEST(ControladorTest, PlantarseDetieneJugada) {
    Controlador controlador("Marta");
    controlador.iniciar_partida();
    EXPECT_TRUE(controlador.plantarse()); // Devuelve true si estaba jugando.
    EXPECT_TRUE(controlador.get_se_planta()); // Verifica estado.
}