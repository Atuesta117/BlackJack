#include "Interfaz.h"
using namespace std;
#include <string>
#include "Carta.h"
#include "Mesa.h"

void Interfaz::esperar_enter() {
    cout << "Presione Enter para continuar...";
    cin.ignore(); // Limpia el buffer si hay algo
    cin.get();    // Espera a que se presione Enter
}
string Interfaz::pedir_nombre(){
    cout << endl;
    cout << R"(
        ╔══════════════════════════╗  
        ║     INGRESE SU NOMBRE    ║  
        ╚══════════════════════════╝ 
        )" << endl;
	
	string nombre_jugador;
	cin >> nombre_jugador;
    return nombre_jugador;
}

void Interfaz::mensaje_exitoso(){
    cout << endl;
    cout << R"(
        ╔═════════════════════════════════════╗  
        ║     PROCESO HECHO EXITOSAMENTE!!    ║  
        ╚═════════════════════════════════════╝ 
        )" << endl;
}

void Interfaz::dibujar_catra(Carta& cartas) {
    string top = "┌─────────┐";
    string bottom = "└─────────┘";
    string side = "│         │"; 
    string rank_right;
    string rank_left;
        if (cartas.get_rank_carta() == "10") {
            rank_right = "10";
            rank_left = "10";
        } else {
            rank_right = cartas.get_rank_carta() + " ";
            rank_left = " " + cartas.get_rank_carta();
        }

        string suit_line = "│    " + cartas.get_casta_carta() + "    │";
        string rank_line_left = "│ " + rank_left + "      │";
        string rank_line_right = "│      " + rank_right + " │";

        cout << top << endl;
        cout << rank_line_left << endl;
        cout << side << endl;
        cout << suit_line << endl;
        cout << side << endl;
        cout << rank_line_right << endl;
        cout << bottom << endl;
        cout << endl;
    
    
}
void Interfaz::dibujar_carta_oculta() {
    string top = "┌─────────┐";
    string bottom = "└─────────┘";
    string side = "│         │"; 
    cout<< top << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< side << endl;
    cout<< bottom << endl;
    cout<< endl;
}



Interfaz::Interfaz(){}
void Interfaz::mostrar_mano(Jugador* jugador) {
    vector<Carta> cartas = jugador->get_cartas();
        cout << R"(
╔════════════════════════════════════════════╗  
            MANO DEL JUGADOR )";
    cout<< jugador->get_nombre()<<endl;
    cout<< R"(╚════════════════════════════════════════════╝ 
    )" <<endl;
    for (size_t i = 0; i < cartas.size(); i++) {
       dibujar_catra(cartas[i]);
       esperar_enter();
}

}

void Interfaz::mostrar_mano(Crupier* crupier) {
   
    vector<Carta> cartas = crupier->get_cartas();
    cout << R"(
        ╔═══════════════════════════════════╗  
        ║          MANO DEL CRUPIER         ║  
        ╚═══════════════════════════════════╝ 
        )" << endl;
    for (size_t i = 0; i < cartas.size(); i++) {
        dibujar_catra(cartas[i]);
    }
}

void Interfaz::mostrar_mano_parcial(Crupier* crupier) {
    imprimir_divicion();
    vector<Carta> cartas = crupier->get_cartas();
    cout << R"(
        ╔═══════════════════════════════════╗  
        ║        MANO PARCIAL CRUPIER       ║  
        ╚═══════════════════════════════════╝ 
        )" << endl;

    dibujar_catra(cartas[0]); // Muestra solo la primera carta del crupier
    dibujar_carta_oculta(); // Muestra la carta oculta
    imprimir_divicion();
    esperar_enter();

}

void Interfaz::mostrar_valor_mano(Jugador* jugador) {
    cout << R"(
╔════════════════════════════════════════════╗  
        VALOR DE LA MANO DE )"<<jugador->get_nombre();
cout<< R"(:)" << jugador->get_valor_mano()<<endl;
cout<< R"(╚════════════════════════════════════════════╝ 
)" <<endl;
}
void Interfaz::mostrar_valor_mano(Crupier* crupier) {
    cout << R"(
╔════════════════════════════════════════════════════════╗  
        VALOR DE LA MANO DEL CRUPIER )"<<crupier->get_nombre();
cout<< R"(:)" << crupier->get_valor_mano()<<endl;
cout<< R"(╚════════════════════════════════════════════════════════╝ 
)" <<endl;
}

void Interfaz::mostrar_ganador(string mensaje) {
imprimir_divicion();
    cout << R"(
╔══════════════════════════════════════════════════════════════╗ )"<<endl;
cout<<"      "<<mensaje<<endl;
cout<< R"(╚══════════════════════════════════════════════════════════════╝ 
)" <<endl;
}
string Interfaz::mostrar_menu_inicio() {
    imprimir_divicion();
    logo();
    cout << R"(
                              ╔═════════════════════════════╗  
                              ║         MENU GENERAL        ║  
                              ╚═════════════════════════════╝ 
   ╔══════════════════════╗   ╔═════════════════════════════╗   ╔═══════════════════════╗
   ║  1.AGREGAR JUGADOR   ║   ║  2.VER LISTA DE JUGADORES   ║   ║  3.ELIMINAR JUGADOR   ║ 
   ╚══════════════════════╝   ╚═════════════════════════════╝   ╚═══════════════════════╝
        ╔════════════╗                                               ╔════════════╗
        ║  4.JUGAR   ║                                               ║  5.SALIR   ║ 
        ╚════════════╝                                               ╚════════════╝
    )" << endl;
    imprimir_divicion();
    string opcion;
    cin >> opcion;
    while (opcion != "1" && opcion != "2"&& opcion != "3"&& opcion != "4"&& opcion != "5") {
        mensaje_error();
        cout << "Error: Opción invalida ";
        cout << R"(
                              ╔═════════════════════════════╗  
                              ║         MENU GENERAL        ║  
                              ╚═════════════════════════════╝ 
   ╔══════════════════════╗   ╔═════════════════════════════╗   ╔═══════════════════════╗
   ║  1.AGREGAR JUGADOR   ║   ║  2.VER LISTA DE JUGADORES   ║   ║  3.ELIMINAR JUGADOR   ║ 
   ╚══════════════════════╝   ╚═════════════════════════════╝   ╚═══════════════════════╝
        ╔════════════╗                                               ╔════════════╗
        ║  4.JUGAR   ║                                               ║  5.SALIR   ║ 
        ╚════════════╝                                               ╚════════════╝
    )" << endl;
        cin >> opcion;
    }
    return opcion;
}


string Interfaz::mostrar_menu_juego(Jugador* jugador) {
    imprimir_divicion();
    logo();
cout << R"(
                              ╔════════════════════════════════════════════╗  
                                        ACCIONES JUGADOR )"<<jugador->get_nombre()<<endl;

cout<< R"(                              ╚════════════════════════════════════════════╝ 
)" <<endl;
    cout << R"(
    ╔════════════╗                       ╔══════════════════════╗                        ╔═══════════════════════╗ 
    ║  1.APOSTAR ║                       ║  2.INGRESAR DINERO   ║                        ║       3. SALIR        ║ 
    ╚════════════╝                       ╚══════════════════════╝                        ╚═══════════════════════╝
)" << endl;
    imprimir_divicion();
    string opcion;
    cin >> opcion;
    while (opcion != "1" && opcion != "2" && opcion != "3") {
        mensaje_error();
        cin >> opcion;
    }
    while (opcion == "1" && jugador->get_dinero() <= 0) {
        mensaje_error();
        cout << "No tienes dinero suficiente para jugar. Por favor, ingresa dinero." << endl;
        cout << "Opción inválida. Ingrese Alguna de las opciones validas: ";
         cout << R"(
    ╔════════════╗                       ╔══════════════════════╗                        ╔═══════════════════════╗ 
    ║  1.APOSTAR ║                       ║  2.INGRESAR DINERO   ║                        ║       3. SALIR        ║ 
    ╚════════════╝                       ╚══════════════════════╝                        ╚═══════════════════════╝
)" << endl;
    imprimir_divicion();
        cin >> opcion;
    }

    return opcion;
}
string Interfaz::mostrar_menu_jugador() {
    imprimir_divicion();
cout << R"(
                                         ╔══════════════════════════╗  
                                         ║   ACCIONES DISPONIBLES   ║  
                                         ╚══════════════════════════╝  

                    ╔════════════════╗        ╔════════════════╗         ╔════════════════╗                   
                    ║1. PEDIR CARTA  ║        ║ 2. PLANTARSE   ║         ║   3.VER MANO   ║         
                    ╚════════════════╝        ╚════════════════╝         ╚════════════════╝          
                    ╔═════════════════════════╗                 ╔═════════════════════════╗ 
                    ║ 4. VER VALOR DE LA MANO ║                 ║  5.VER MANO CRUPIER     ║
                    ╚═════════════════════════╝                 ╚═════════════════════════╝
                                    )"<<endl;
    imprimir_divicion();
    string opcion;
    cin >> opcion;
    while (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4"&& opcion != "5") {
        mensaje_error();
        cout << "Error: Ingreso una opcion no valida, intente de nuevo"<<endl;
        cout << R"(
                                         ╔══════════════════════════╗  
                                         ║   ACCIONES DISPONIBLES   ║  
                                         ╚══════════════════════════╝  

                    ╔════════════════╗        ╔════════════════╗         ╔════════════════╗                   
                    ║1. PEDIR CARTA  ║        ║ 2. PLANTARSE   ║         ║   3.VER MANO   ║         
                    ╚════════════════╝        ╚════════════════╝         ╚════════════════╝          
                    ╔═════════════════════════╗                 ╔═════════════════════════╗ 
                    ║ 4. VER VALOR DE LA MANO ║                 ║  5.VER MANO CRUPIER     ║
                    ╚═════════════════════════╝                 ╚═════════════════════════╝
                                    )"<<endl;
        cin >> opcion;
    }
    return opcion;
}
void Interfaz::imprimir_divicion() {
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
}

void Interfaz::mensaje_error(){
    cout << R"(
        ╔════════════════════════════╗  
        ║            ERROR           ║  
        ╚════════════════════════════╝ 
        )" << endl;
}
void Interfaz::interfaz_turno(Jugador* jugador, Mazo& mazo, Crupier* crupier) {
    esperar_enter();
    imprimir_divicion();
    cout << R"(
                          ╔══════════════════════════════════════════════╗  
                                TURNO DEL JUGADOR )"<< jugador->get_nombre()<< R"(        
                          ╚══════════════════════════════════════════════╝ 
    )"<< endl;
    if(jugador->verificar_blackjack()){
		jugador->plantarse(); // Si el jugador tiene blackjack, se planta automáticamente
		cout << R"(
        ╔══════════════════════════╗  
        ║     TIENES BLACKJACK     ║  
        ╚══════════════════════════╝ 
        )" << endl;
        imprimir_divicion();
	}

	while (jugador->get_se_planta() == false)
			{
				string opcion = mostrar_menu_jugador();
				if (opcion == "1")
                {
                    jugador->pedir_carta(mazo); // El jugador pide otra carta
                    mostrar_mano(jugador); // Muestra la mano del jugador
                    mostrar_valor_mano(jugador); // Muestra el valor de la mano del jugador
                    imprimir_divicion();
                    esperar_enter();
                    cout << endl;
                    if(jugador->get_valor_mano() >= 21){
                        if(jugador->get_valor_mano() > 21) {
                            imprimir_divicion();
                            cout << R"(
        ╔═══════════════════════════════════════════╗  
        ║     TE PASASTE DE 21! FIN DE TU TURNO     ║  
        ╚═══════════════════════════════════════════╝ 
        )" << endl;
                        } 
                        else {
                            imprimir_divicion();
                            cout << R"(
        ╔═══════════════════════════════════════════╗  
        ║        TIENES 21! FIN DE TU TURNO         ║  
        ╚═══════════════════════════════════════════╝ 
        )" << endl;
                        }
                        jugador->plantarse(); // Cambia el controlador a false para salir del bucle
                    }
                }
                else if (opcion == "2")
                {
                    imprimir_divicion();
                    jugador->plantarse(); // El jugador se planta
                    cout << R"(
        ╔═════════════════════════════╗  
        ║    EL JUGADOR SE PLANTA     ║  
        ╚═════════════════════════════╝ 
        )" << endl;   
                    mostrar_mano(jugador); // Muestra la mano del jugador
                    imprimir_divicion();
                }
                else if (opcion == "3")
                {
                    imprimir_divicion();
                    mostrar_mano(jugador); // Muestra la mano del jugador
                    imprimir_divicion();
                }
                else if (opcion == "4")
                {
                    mostrar_valor_mano(jugador); // Muestra el valor de la mano del jugador
                }
                else if(opcion == "5"){
                    mostrar_mano_parcial(crupier);
                }
                else{
                    imprimir_divicion();
                    mensaje_error();
                    cout<< "Opción inválida. Por favor, ingrese una opción válida."<<endl;
                    imprimir_divicion();
			}
		}
} 

void Interfaz::interfaz_turno(Crupier* crupier, vector<Jugador*> jugadores_activos, Mazo& mazo){
    esperar_enter();
    imprimir_divicion();
    cout << R"(
        ╔═════════════════════════════════╗  
        ║       TURNO DEL CRUPIER!!!      ║  
        ╚═════════════════════════════════╝ 
        )" << endl;  
    imprimir_divicion();
    cout << R"(
        ╔═════════════════════════════╗  
        ║      MANO DEL CRUPIER       ║  
        ╚═════════════════════════════╝ 
        )" << endl;  
    imprimir_divicion();
    mostrar_mano(crupier); // Muestra la mano del crupier
    mostrar_valor_mano(crupier); // Muestra el valor de la mano del crupier
    imprimir_divicion();
    esperar_enter();
    vector<Jugador*> jugadores_perdedores;
    vector<Jugador*> jugadores_restantes;
    for (size_t i = 0; i < jugadores_activos.size(); i++)
    {
        if(jugadores_activos[i]->get_valor_mano()>21){
            jugadores_perdedores.push_back(jugadores_activos[i]); // Agrega al jugador a la lista de perdedores si su mano es mayor a 21
        }
        else{

            jugadores_restantes.push_back(jugadores_activos[i]); // Agrega al jugador a la lista de jugadores restantes si su mano es 21 o menos
        }
    }
    

    if (jugadores_restantes.empty()) {
        imprimir_divicion();
        mostrar_mano(crupier); // Muestra la mano del crupier
        mostrar_valor_mano(crupier); // Muestra el valor de la mano del crupier
        crupier->plantarse(); // El crupier se planta
        cout << R"(
            ╔══════════════════════════════════════════════════════╗  
            ║        EL CRUPIER SE PLANTA // TURNO FINALIZADO      ║  
            ╚══════════════════════════════════════════════════════╝ 
        )" << endl;
        esperar_enter();
        
    }
    else{
        while(crupier->get_valor_mano() < 17) // El crupier pide cartas hasta que su mano sea 17 o más
            {
                imprimir_divicion();
                cout << R"(
        ╔══════════════════════════════════════════╗  
        ║        EL CRUPIER PIDE OTRA CARTA        ║  
        ╚══════════════════════════════════════════╝ 
        )" << endl;
                crupier->pedir_carta(mazo); // El crupier obtiene una carta del mazo
                mostrar_mano(crupier);
                mostrar_valor_mano(crupier);
                imprimir_divicion();
                esperar_enter();
            }
        crupier->plantarse();
        cout << R"(
        ╔══════════════════════════════════════════════════════╗  
        ║        EL CRUPIER SE PLANTA // TURNO FINALIZADO      ║  
        ╚══════════════════════════════════════════════════════╝ 
        )" << endl;
        imprimir_divicion();
        esperar_enter();
    }
}

void Interfaz::logo() {
    cout << R"(
    |-----------------------------------------------------------------------------------|
    |██████╗ ██║      █████╗  ██████╗ ██╗  ██╗          ██╗  █████╗  ██████╗ ██╗  ██╗   |
    |██╔══██╗██║     ██╔══██╗██╔════╝ ██║ ██╔╝          ██║ ██╔══██╗██╔════╝ ██║ ██╔╝   |
    |██████╔╝██║     ███████║██║      █████╔╝           ██║ ███████║██║      █████╔╝    |
    |██╔══██╗██║     ██╔══██║██║      ██╔═██╗     ██    ██║ ██╔══██║██║      ██╔═██╗    |
    |██████╔╝███████╗██║  ██║╚██████╗ ██║  ██╗     ╚█████╔╝ ██║  ██║╚██████╗ ██║  ██╗   |
    |╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝      ╚════╝  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝   |  
    |-----------------------------------------------------------------------------------|
)"<<endl;
}


void Interfaz::mostrar_lista_jugadores(Mesa& mesa){
    vector<Jugador*> jugadores = mesa.get_jugadores();
    
    cout << R"(
        ╔════════════════════════════════╗  
        ║        LISTA DE JUGADORES      ║  
        ╚════════════════════════════════╝ 
        )" << endl;
    cout << R"(
╔════════════════════════════════════════════════╗ )"<< endl;
    for (int i=0; i<jugadores.size();i++){
        cout <<i+1<<")"<<jugadores[i]->get_nombre()<<endl;
    }
    cout << "╚════════════════════════════════════════════════╝ "<<endl;
    imprimir_divicion();
    esperar_enter();
}
int Interfaz::elegir_jugador_eliminar(Mesa& mesa){
    vector<Jugador*> jugadores = mesa.get_jugadores();
    int jugador_eliminar;
    cout<<"Digite el numero del jugador que quiere eliminar o pulse 6 para salir: ";
    cin>>jugador_eliminar;
    
    while(jugador_eliminar > jugadores.size() || jugador_eliminar <= 0 ){
        if(jugador_eliminar==6){
            break;
        }
        else{
            mensaje_error();
            cout <<"Error: Opcion no valida, porfavor intente de nuevo"<<endl;
            cout<<"Digite el numero del jugador que quiere eliminar: ";
            cin>>jugador_eliminar;
        }
    }
    string jugador_eliminar_aux = to_string(jugador_eliminar);
    while (jugador_eliminar_aux != "1" &&jugador_eliminar_aux != "2" &&jugador_eliminar_aux != "3" &&jugador_eliminar_aux != "4" &&jugador_eliminar_aux != "5"&&jugador_eliminar_aux != "6")
    {
        mensaje_error();
        cout <<"Error: Opcion no valida, porfavor intente de nuevo"<<endl;
        cout<<"Digite el numero del jugador que quiere eliminar o 6 para salir: ";
        cin>>jugador_eliminar;
    }
    int index = stoi(jugador_eliminar_aux);
    return index;
    
}

void Interfaz::mensaje(int i){
    vector<string> mensajes = {R"(
        ╔══════════════════════════════════════════════╗  
        ║     SERVICIO DE RECARGA DE DINERO NEQUI      ║  
        ╚══════════════════════════════════════════════╝ 
)" , R"(
		╔════════════════════════════╗  
		║    	SALIO DEL JUEGO      ║  
		╚════════════════════════════╝ 
)", R"(
        ╔═══════════════════════════════════════════════════════════════════════════════════╗  
        ║        “En el juego de Blackjack, como en el juego de la vida, ganar es duro.     ║
        ║		Requiere determinación, preparación y mucha transpiración.”         ║
        ╚═══════════════════════════════════════════════════════════════════════════════════╝ 
)",R"(
	        ╔══════════════════════════════════════════════════════════════╗  
		    ║ 	     RESUMEN DE LA PARTIDA: JUGADORES Y CRUPIER            ║
		    ╚══════════════════════════════════════════════════════════════╝ 
)" };
    cout << mensajes[i];
}