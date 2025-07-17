/**
* @file ServicioRecarga.cpp
* @brief Implementación de la clase ServicioRecarga para el juego de Blackjack.
*
* @details
* Hace la recarga al jugador una vez se ha verificado que el numero de telefono es valido 
*
* @project Blackjack
* @course Fundamentos de Programación Orientada a Objetos (FPOO)
* @institution Universidad del Valle
*
* @authors
* - Juan Jose Atuesta - atuesta.juan@correounivalle.edu.co
* - David Alejandro Garcia - david.grueso@correounivalle.edu.co
* - Sergio Garcia Ramos - sergio.garcia.ramos@correounivalle.edu.co
* - Paula Mariana Murillo - murillo.paula@correounivalle.edu.co
*
* @date Julio 2025
*/
using namespace std;
#include "ServicioRecarga.h"
#include "Jugador.h"
#include "PhoneValidator.h"
#include "Interfaz.h"



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
    Interfaz interfaz;
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
