#include <gtest/gtest.h>
#include "../src/Interfaz.h"
#include "../src/Jugador.h"
#include "../src/Crupier.h"
#include "../src/Mazo.h"

TEST(InterfazTest, MostrarManoNoCrashea) {
    Interfaz interfaz;
    Mazo mazo;
    PersonaCasino* jugador = new Jugador("Juan", 500);
    Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);

    PersonaCasino* crupier = new Crupier("Crupier");
	Crupier* crupier_ptr = dynamic_cast<Crupier*>(crupier);
    
    jugador_ptr->pedir_carta(mazo);
    EXPECT_NO_THROW(interfaz.mostrar_mano(jugador_ptr));
    EXPECT_NO_THROW(interfaz.mostrar_mano(crupier_ptr));
}

TEST(InterfazTest, MensajesErrorYExito) {
    Interfaz interfaz;
    EXPECT_NO_THROW(interfaz.mensaje_error());
    EXPECT_NO_THROW(interfaz.mensaje_exitoso());
}

TEST(InterfazTest, MenuInicioDevuelveOpcion) {
    Interfaz interfaz;
    string opcion = interfaz.mostrar_menu_inicio();
    EXPECT_TRUE(opcion == "1" || opcion == "2" || opcion == "3"|| opcion == "4"|| opcion == "5"); // Asume estas opciones
}
