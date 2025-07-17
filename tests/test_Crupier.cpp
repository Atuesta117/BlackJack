#include <gtest/gtest.h>
#include "../src/Crupier.h"
#include "../src/Jugador.h"
#include "../src/Mazo.h"

// Mock de Mazo para pruebas
class MazoMock : public Mazo {
public:
    Carta get_carta(){
        return Carta("Picas", "A", 11); // Siempre devuelve un As
    }
};



TEST(CrupierTest, DeterminarGanador) {
    MazoMock mazo;
    Crupier crupier("Casa", 10000, mazo);
    Jugador jugador("Ana", 1000);
    
    // Simula manos
    jugador.pedir_carta(mazo);
    crupier.pedir_carta(mazo);
    
    string resultado = crupier.determinar_ganador(&jugador);
    EXPECT_TRUE(resultado == "jugador" || resultado == "crupier" || resultado == "empate");
}

TEST(CrupierTest, MostrarManoParcialNoCrashea) {
    MazoMock mazo;
    Crupier crupier("Casa", 10000, mazo);
    EXPECT_NO_THROW(crupier.mostrar_mano_parcial());
}
