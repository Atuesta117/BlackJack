#include <gtest/gtest.h>
#include "../src/PersonaCasino.h"
#include "../src/Mazo.h"

TEST(PersonaCasinoTest, IniciarPartidaCambiaEstado) {
    PersonaCasino PersonaCasino("Juan");
    PersonaCasino.iniciar_partida();
    EXPECT_TRUE(PersonaCasino.get_esta_jugando()); // Debe estar jugando.
    PersonaCasino.terminar_partida();
    EXPECT_FALSE(PersonaCasino.get_esta_jugando()); // Debe terminar.
}

TEST(PersonaCasinoTest, PedirCartaAumentaMano) {
    PersonaCasino PersonaCasino("Ana");
    Mazo mazo;
    mazo.shuffle();
    PersonaCasino.pedir_carta(mazo);
    EXPECT_EQ(PersonaCasino.get_cartas().size(), 1); // 1 carta añadida.
}

TEST(PersonaCasinoTest, VerificarBlackjack) {
    PersonaCasino PersonaCasino("Luis");
    Mazo mazo;
    // Simular mano con As + Rey (necesitarías mockear el mazo o forzar cartas).
    // Asumamos que pedir_carta() añade cartas específicas en un test real.
    // EXPECT_TRUE(PersonaCasino.verificar_blackjack());
}

TEST(PersonaCasinoTest, PlantarseDetieneJugada) {
    PersonaCasino PersonaCasino("Marta");
    PersonaCasino.iniciar_partida();
    EXPECT_TRUE(PersonaCasino.plantarse()); // Devuelve true si estaba jugando.
    EXPECT_TRUE(PersonaCasino.get_se_planta()); // Verifica estado.
}