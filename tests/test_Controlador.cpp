#include <gtest/gtest.h>
#include "../src/Controlador.h"
#include "../src/Carta.h"  // Asumiendo que Mazo depende de Carta
#include "../src/Jugador.h"

// Mock básico de Mazo para pruebas
class MazoMock : public Mazo {
public:
    Carta get_carta(){
        return Carta("Picas", "A", 11);  // Siempre devuelve un As de Picas
    }
};

TEST(ControladorTest, IniciarPartida) {
    Controlador* controlador = new Jugador("Ana", 1000);  // Jugador hereda de Controlador
    controlador->iniciar_partida();
    EXPECT_TRUE(controlador->get_esta_jugando());
    delete controlador;
}

TEST(ControladorTest, PedirCartaAjustaAs) {
    Jugador jugador("Carlos", 500);
    MazoMock mazo;
    
    jugador.pedir_carta(mazo);
    EXPECT_EQ(jugador.get_valor_mano(), 11);
    
    // Simulamos que el valor pasa a 21+
    jugador.pedir_carta(mazo);
    if (jugador.get_valor_mano() > 21) {
        EXPECT_EQ(jugador.get_valor_mano(), 12);  // El As se convierte en 1
    }
}

TEST(ControladorTest, VerificarBlackjack) {
    Jugador jugador("Lucía", 800);
    MazoMock mazo;
    
    jugador.pedir_mano(mazo);  // Recibe 2 cartas (según tu implementación)
    EXPECT_TRUE(jugador.verificar_blackjack());
}

TEST(ControladorTest, ReiniciarValores) {
    Jugador jugador("Pedro", 600);
    MazoMock mazo;
    
    jugador.pedir_carta(mazo);
    jugador.reiniciar_valores();
    
    EXPECT_EQ(jugador.get_valor_mano(), 0);
    EXPECT_TRUE(jugador.get_cartas().empty());
}
