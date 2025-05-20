using namespace std;
#include "ServicioRecarga.h"
#include "Jugador.h"
#include "PhoneValidator.h"

ServicioRecarga::ServicioRecarga() {
    // Constructor
}

bool ServicioRecarga::verificar_monto(long monto) {
    if (monto <= 0) {
        return true; // Monto no válido
    }
    else{
        return false; // Monto válido
    }
}
bool ServicioRecarga::realizar_transaccion(bool verificado, Jugador* jugador, long monto) {
    if (verificado){
        jugador->set_dinero(monto);
        return true;
    }
    else
    {
        return false;
    }
    
}
