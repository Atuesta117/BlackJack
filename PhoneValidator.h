/*
	Clase: PhoneValidator
	Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
	Universidad del Valle

  Información CRC:

  Clase: PhoneValidator

	Responsabilidades:

	Validar si el numero digitado a la hora de ingresar dinero es valido para Colombia  

	Colaboradores: Ninguno

	Autor: Juan Jose Atuesta, Sergio Garcia Ramos, Paula Mariana Huertas, David Alejandro Garcia 
	Correo: atuesta.juan@correounivalle.edu.co - sergio.garcia.ramos@correounivalle.edu.co - murillo.paula@correounivalle.edu.co - david.grueso@correounivalle.edu.co]
	Fecha: Julio 2025
  */
#pragma once
#include <string>

class PhoneValidator {
public:
    PhoneValidator(const std::string& apiKey);
    bool esNumeroValido(std::string& numero );
private:
    std::string apiKey;
};


