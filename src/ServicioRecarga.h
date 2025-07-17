/*
	Clase: ServicioRecarga
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

  Información CRC:

  Clase: ServicioRecarga

	Responsabilidades:

    Realizar la transaccion de dinero una vez se ha confirmado su validez

	Colaboradores: PhoneValidator

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Julio 2025
  */
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
        bool realizar_transaccion(bool verificado, Jugador* jugador, long monto);
        bool verificar_monto(long monto);
    };

#endif // TRANSACCION_H