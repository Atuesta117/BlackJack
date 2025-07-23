#include <gtest/gtest.h>
#include "../src/Crupier.h"
#include "../src/Jugador.h"
using namespace std;

TEST(CrupierTest, DeterminarGanador) {
    Mazo mazo;
    PersonaCasino* jugador = new Jugador("Juan", 500);
    Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);

    PersonaCasino* crupier = new Crupier("Crupier");
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
 

    // Asignar cartas manualmente (requiere métodos en Crupier/Jugador)
    jugador_ptr->pedir_mano(mazo);      

    crupier_ptr->pedir_mano(mazo);   
    string resultado = crupier_ptr->determinar_ganador(jugador_ptr);
    // Verificar empate
    EXPECT_TRUE(resultado== "EL JUGADOR "+ jugador->get_nombre()+" BLACKJACK. EL JUGADOR GANA."||resultado== "EL CRUPIER SE HA PASADO. EL JUGADOR "+ jugador->get_nombre()+" GANA."||resultado== "EL JUGADOR "+ jugador->get_nombre()+" SE HA PASADO. EL CRUPIER GANA."||resultado== "EL CRUPIER Y "+ jugador->get_nombre()+" SACARON BLACKJACK. TENEMOS UN EMPATE."||resultado== "EL CRUPIER Y "+ jugador->get_nombre()+" TIENEN EL MISMO PUNTAJE. TENEMOS UN EMPATE."||resultado== "LA MANO DE "+ jugador->get_nombre()+" ES MENOR, EL CRUPIER GANA."||resultado== "EL JUGADOR "+ jugador->get_nombre()+" TIENE BLACKJACK. EL JUGADOR GANA."||resultado== "EL JUGADOR "+ jugador->get_nombre()+" GANA.");

    
}

