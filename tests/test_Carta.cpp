#include <gtest/gtest.h>
#include "../src/Carta.h"

// Prueba el constructor y los getters básicos
TEST(CartaTest, ConstructorYGetters) {
    Carta carta("Corazones", "A", 11);
    
    EXPECT_EQ(carta.get_casta_carta(), "Corazones");
    EXPECT_EQ(carta.get_rank_carta(), "A");
    EXPECT_EQ(carta.get_valor_carta(), 11);
}



// Prueba valores límite
TEST(CartaTest, ValoresLimite) {
    Carta carta1("Diamantes", "2", 2);
    Carta carta2("Tréboles", "10", 10);
    
    EXPECT_EQ(carta1.get_valor_carta(), 2);
    EXPECT_EQ(carta2.get_valor_carta(), 10);
}
