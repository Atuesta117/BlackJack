#ifndef TRANSACCION_H   
#define TRANSACCION_H
#include <iostream>
#include <string>

using namespace std;
#include "Jugador.h"
#include "PhoneValidator.h"
class ServicioRecarga {
    private:
 
    public:
        ServicioRecarga();
        void realizar_transaccion(bool verificado, Jugador* jugador, long monto);
        bool verificar_monto(long monto);
    };

#endif // TRANSACCION_H