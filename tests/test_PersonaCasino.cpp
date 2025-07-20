#include <gtest/gtest.h>
#include "../src/PersonaCasino.h"
#include "../src/Mazo.h"
#include "../src/Crupier.h"

TEST(PersonaCasinoTest, IniciarPartidaCambiaEstado) {
    PersonaCasino* persona = new Crupier("Juan");
    persona->iniciar_partida();
    EXPECT_TRUE(persona->get_esta_jugando()); // Debe estar jugando.
    persona->terminar_partida();
    EXPECT_FALSE(persona->get_esta_jugando()); // Debe terminar.
}

TEST(PersonaCasinoTest, PedirCartaAumentaMano) {
    PersonaCasino* persona = new Crupier("Juan");
    Mazo mazo;
    mazo.shuffle();
    persona->pedir_carta(mazo);
    EXPECT_EQ(persona->get_cartas().size(), 1); // 1 carta añadida.
}


TEST(PersonaCasinoTest, PlantarseDetieneJugada) {
     PersonaCasino* persona = new Crupier("Juan");
    persona->iniciar_partida();
    EXPECT_TRUE(persona->plantarse()); // Devuelve true si estaba jugando.
    EXPECT_TRUE(persona->get_se_planta()); // Verifica estado.
}