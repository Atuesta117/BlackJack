#include <gtest/gtest.h>
#include "../src/ServicioRecarga.h"
#include "../src/Jugador.h"
#include "../src/Interfaz.h"

TEST(ServicioRecargaTest, RecargaExitosaAumentaDinero) {
    ServicioRecarga servicio;
    Jugador jugador("Luisa", 200);
    servicio.realizar_transaccion(true, &jugador, 500);
    EXPECT_EQ(jugador.get_dinero(), 700);
}
