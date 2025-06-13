using namespace std;
#include "ServicioRecarga.h"
#include "Jugador.h"
#include "PhoneValidator.h"
#include "Interfaz.h"

Interfaz interfaz;

ServicioRecarga::ServicioRecarga() {
    // Constructor
}

bool ServicioRecarga::verificar_monto(long monto) {
    if (monto <= 0) {
        return false; // Monto no válido
    }
    else{
        return true; // Monto válido
    }
}
bool ServicioRecarga::realizar_transaccion(bool verificado, Jugador* jugador, long monto) {
    if (verificado){
        jugador->set_dinero(monto);
        interfaz.mensaje_exitoso();
        cout << "Transacción exitosa. Se han depositado " << monto << " a la cuenta de " << jugador->get_nombre() << endl<<"Su nuevo saldo es: " << jugador->get_dinero() << endl;
        return true;
        
    }
    else
    {
        interfaz.mensaje_error();
        cout << "Error:Transacción fallida. El número de cuenta ingresado no es válido." << endl;
        return false;
    }
    
}
