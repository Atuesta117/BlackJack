using namespace std;
#include "ServicioRecarga.h"
#include "Jugador.h"
#include "PhoneValidator.h"

ServicioRecarga::ServicioRecarga() {
    // Constructor
}

bool ServicioRecarga::verificar_monto(double monto) {
    if (monto <= 0) {
        return false; // Monto no válido
    }
    else{
        return true; // Monto válido
    }
}
void ServicioRecarga::realizar_transaccion(bool verificado, Jugador* jugador, double monto) {
    if (verificado){
        jugador->set_dinero(monto);
        cout << "Recarga exitosa. Su nuevo saldo es: " << jugador->get_dinero() << endl;
    }
}
