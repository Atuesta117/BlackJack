#include <gtest/gtest.h>
#include "../src/Interfaz.h"
#include "../src/Jugador.h"
#include "../src/Crupier.h"
#include "../src/Mazo.h"

TEST(InterfazTest, MostrarManoNoCrashea) {
    Interfaz interfaz;
    Mazo mazo;
    Jugador jugador("Ana", 1000);
    Crupier crupier("Casa", mazo);
    
    jugador.pedir_carta(mazo);
    EXPECT_NO_THROW(interfaz.mostrar_mano(&jugador));
    EXPECT_NO_THROW(interfaz.mostrar_mano(&crupier));
}

TEST(InterfazTest, MensajesErrorYExito) {
    Interfaz interfaz;
    EXPECT_NO_THROW(interfaz.mensaje_error());
    EXPECT_NO_THROW(interfaz.mensaje_exitoso());
}

TEST(InterfazTest, MenuInicioDevuelveOpcion) {
    Interfaz interfaz;
    string opcion = interfaz.mostrar_menu_inicio();
    EXPECT_TRUE(opcion == "1" || opcion == "2" || opcion == "3"); // Asume estas opciones
}
