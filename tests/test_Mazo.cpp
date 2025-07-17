#include <gtest/gtest.h>
#include "../src/Mazo.h"

TEST(MazoTest, GetCartaReduceMazo) {
    Mazo mazo;
    int cartas_iniciales = mazo.get_cant_cartas();
    mazo.get_carta();
    EXPECT_EQ(mazo.get_cant_cartas(), cartas_iniciales - 1);
}

TEST(MazoTest, ShuffleCambiaOrden) {
    Mazo mazo1;
    Mazo mazo2;
    mazo2.shuffle();
    
    // Verifica que al menos una carta sea diferente
    bool iguales = true;
    for (int i = 0; i < 5; ++i) {
        if (mazo1.get_carta().get_rank_carta() != mazo2.get_carta().get_rank_carta()) {
            iguales = false;
            break;
        }
    }
    EXPECT_FALSE(iguales);
}
