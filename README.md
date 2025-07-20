Nota: PersonaCasino* jugador = new Jugador(nombre_jugador, 0);
	Jugador* jugador_ptr = dynamic_cast<Jugador*>(jugador);
 eso de dynamic_cast es para crear un objeto Jugador que tambien pueda usar sus propios metodos, dado que se usa polimorfismo y herencia pero igual las clases hijas ocupan sus popios metodos

Clase: Carta
Se relaciona con:

No utiliza ninguna otra clase directamente en sus métodos.

- Método: Carta(string casta, string rank, int valor)
Constructor que inicializa una carta con su casta (♥, ♦, ♣, ♠), su rango (A, 2, 3...K) y su valor (por ejemplo A vale 11, J/Q/K valen 10).
Se usa this-> para distinguir entre el atributo y el parámetro del constructor.

- Método: string get_casta_carta()
Devuelve el símbolo de la casta (♥, ♦, ♣, ♠) de la carta.

- Método: int get_valor_carta()
Retorna el valor numérico de la carta (por ejemplo 11 para As, 10 para K, etc.).

- Método: string get_rank_carta()
Devuelve el rango de la carta, que puede ser "A", "2", "3"... hasta "K".

-------------------------------------------------------------------------

Clase: Mazo
Se relaciona con:

Usa la clase Carta para formar el mazo.

- Método: Mazo()
Constructor que inicializa el mazo de cartas usando el método get_new_mazo().

- Método: vector<Carta> get_new_mazo()
Crea y retorna un nuevo vector de 52 cartas.

Se definen los arreglos castas[], ranks[] y valores[].

Se recorren en dos ciclos anidados:

Por cada casta (♥, ♦, ♣, ♠)

Se crean 13 cartas con los respectivos rangos y valores.

Las cartas se agregan al vector usando new_mazo.push_back(...).

Finalmente, se retorna el vector.

- Método: void shuffle()
Revuelve el mazo aleatoriamente.

Usa std::shuffle con un generador de números aleatorios basado en el tiempo actual (time(nullptr)).

- Método: int get_cant_cartas()
Retorna la cantidad de cartas que quedan en el mazo.

- Método: Carta get_carta()
Devuelve la última carta del mazo (con .back()), la elimina del mazo (.pop_back()), y la retorna.

- Método: void reunir_cartas(vector<Carta> cartas_jugador)
Reintegra las cartas jugadas por los jugadores al mazo.

Recorre el vector recibido y las añade al vector cartas.

Luego limpia cartas_jugador (aunque esto no tiene efecto porque es por copia).


-------------------------------------------------------------------------

Clase: Mesa
Se relaciona con:

Jugador: contiene punteros a jugadores en el vector mesa.

PersonaCasino: se usa como objeto asociado a cada jugador.

Mazo: usado para repartir cartas a los jugadores.

- Método: Mesa()
Constructor que inicializa la mesa como inactiva (mesa_activa = false).

- Método: bool get_mesa_activa()
Devuelve false si el vector de jugadores está vacío.
Devuelve true si hay al menos un jugador en la mesa.

- Método: vector<Jugador*> get_jugadores()
Retorna la lista de punteros a jugadores que están sentados en la mesa.

- Método: bool mesa_llena()
Devuelve true si hay 5 jugadores o más en la mesa.
Usa mesa.size() para contar la cantidad de jugadores.

- Método: void agregar_jugador(Jugador* jugador, PersonaCasino* persona)
Agrega un jugador al vector mesa y al mismo tiempo guarda el objeto PersonaCasino correspondiente.

- Método: void eliminar_jugador(int index)
Elimina un jugador según la posición en el vector (ajustando con index-- porque probablemente se ingrese en base 1).

Libera la memoria con delete.

Coloca un nullptr en la posición.

Usa erase para remover el puntero del vector.

- Método: void eliminar_todos_jugadores()
Elimina a todos los jugadores de la mesa.

Llama a eliminar_jugador(i) dentro de un ciclo desde 1 hasta el tamaño de la mesa.

-------------------------------------------------------------------------

Clase: ServicioRecarga
Se relaciona con:

Jugador: modifica el saldo del jugador.

Interfaz: se usa para mostrar mensajes de éxito o error.

- Método: ServicioRecarga()
Constructor vacío.

- Método: bool verificar_monto(long monto)
Devuelve false si el monto es menor o igual a cero.
Retorna true si el monto es válido para ser recargado.

- Método: bool realizar_transaccion(bool verificado, Jugador* jugador, long monto)
Realiza la recarga al jugador si el número fue verificado.

Si verificado es true:

Usa jugador->set_dinero(monto) para recargar.

Muestra mensaje exitoso por consola y con interfaz.mensaje_exitoso().

Si no fue verificado:

Muestra error por consola y llama a interfaz.mensaje_error().

Retorna true si se recargó exitosamente, false si falló.

-------------------------------------------------------------------------

Clase: PhoneValidator
Se relaciona con:

Usa la biblioteca externa libcurl y nlohmann::json.

No depende directamente de las demás clases del juego.

- Método: PhoneValidator(const std::string& apiKey)
Constructor que guarda la clave API para futuras peticiones.

- Método: bool esNumeroValido(std::string& numero)
Verifica si un número de teléfono es válido usando la API Veriphone.

Antepone +57 al número ingresado.

Usa libcurl para hacer una petición GET a la URL de Veriphone.

Guarda la respuesta en readBuffer.

Parsea el JSON y revisa si existe el campo "phone_valid" y si es booleano.

Si todo sale bien, retorna el valor booleano de "phone_valid".

Si hay error en curl o en la respuesta, retorna false.

-------------------------------------------------------------------------

Clase: PersonaCasino
Se relaciona con:
Usa la clase carta para formar un vector de cartas que serian la mano, y usa la clase mazo para pedir cartas o la mano

Nota: el atributo contador_as cuenta la cantidad de ases que pasaro de valer 11 a valeer 1

- Metodo: PersonaCasino(const string nombre)
  inicializa la clase, con variable el jugador. Dado que loa idea es que tanto crupier como jugador inicien estando no activos
  a menos que se inicie una partida el valor de la mano es cero, no tendra cartas en el vector, y los atributos de se_panta y
  esta_jugado estan como false, y el contador de as de la mano evitentemente tambien inicia en cero
- Metodos: inicar_partida() | terminar_partida()
  El metodo de iniciar partida pone en true el atributo esta_jugando, y al terminar loa partida el jugador esta inactivo, asi que
  al finalizar partida este atributo se pone en false
- Metodo:pedor_mano(Mazo&mazo)
  Lo que hace este metodo es directamente darle dos cartas al jugador del mazo, haciendo un ciclo for que se recorre dos veces,
  anexando un objeto carta al vector carta llamado mano, despues se verifica los casos en los que una o las dos caertas son un ass
  si hay un as entonces se suma 11 + el valor de la otra carta siendo este el valor de la mano, pero si son dos as, el valor de la mano
  seria de 12 y  dado qye un as paso de valer 11 a 1 (por eso el valor de la mano es 12) el contador de as aumenta en uno
- Metodo:pedir_carta(Mazo& mazo)
  Este lo que hace es tomar una carta del mazo, sumarle su valor y agregarlo al vector directamente, para previamente ver si en la mano del jugador
  hay algun as, ya sea la carta que recibio o un as que acaba de recibir. Para esto recorre el vector de cartas y por cada carta que sea un as le aumenta a un contador 1
  despues de este proceso se compara el contador con el contador de as. SI son diferentes quiere decir que hay un as que no ha pasado a ser 1, entonces se verifica si
  el valor de la mano es mayor de 21, si lo es, se le resta al valor de la mano 10 (asi el as pasa "a valer 1") y el contador de as aumenta, pues se supone que una carta paso a valer 1
  si son iguales quiere decir que, o no tiene as, o el as que tiene ya es 1, asi que no se le cambia nada al valor de la mano
- Metodo:plantarse()
  Pasa a true el atributo de que se planta, acabando el turno de jugador
- set_dinero(const long dinero )
  Le aumenta al dinero total de jugador un valor
- Metodo:verificar_blackjack()
  COmo su nombre lo indica, busca retornar true si el jugador saco blackjack y false si no. Lo que hace es ver que, si la mano del jugador tiene solo dos cartas (es decir identifica si la mano es la inicial)
  y si el valor de esa mano es 21 entonces tiene blackjack, esto aprovecha el hecho de que en este juego solo se puede tener un 21 con dos cartas teniendo un blackjack (as y un 10 o equivalente)
- Metodo:reinicar_valores()
  EL jugador y el crupier puestan de manera diferente, asi que se aplica polimorfismo en este caso, por eso es un metodo virtual puro

-------------------------------------------------------------------------

Clase: Jugador
Se relaciona con:
Las mismas clase de PersonaCasino, pues es clase hija de esta

Nota: Esta clase aumenta un atributo el cual es apuesta, el cual indica la cantidad de apuesta, pues adiferencia del crupier (que es la casa y solo se encarga de dar o quitar dinero) este tiene que decidir cuanto apostar

-Metodo: Jugador
  Es el contructotr de la clase el cual hereda el nombre de PersonaCasino, y aumenta un numero el cual es la cantidad de dinero del jugador
  Este tambien inicializa toda las variables como en cero o false, dado que el jugador aun no esta activo jugando
- Metodo: apostar
  El jugador ingresa la cantidad de dinero a apostar, y este dinero se le resta a su dinero total
- Metodo: get_apuesta
  Retorna la cantidad apostada
- Metodo: reiniciar_valores
  Este sobreescrbie el metodo puro de la clase padre, lo que hace es reiniciar a cero valores como apuesta,contador as valor_mano y pone como false se_planta y vacia el vector de cartas del jugador
  
-------------------------------------------------------------------------

Clase Crupier
Se relaciona con:
Usa jugador para determinar quien gana, ademas de carta para tener su mano (vector de cartas) 
-Metodo: Crupier
  inicializa las variables de juego al igual que jugador o PersonaCasino
-Metodo: determinar_ganador
  Determina el ganador de la partida segunlos casos que se puedan dar: EL crupier se pasa y el jugador no, el jugador se pasa, ambos tienen blackjack o tienen el mismo puntaje, el crupier gana por mayor puntaje
  el jugador gana por mayor puntaje.
  El metodo retorna un mensaje con el resultado, esto para imprimirlo de forma mas presentable con ayuda de la clase interfaz
-Metodo: reiniciar_valores
  Reinicia los valores importantes del juego, al igual que su clase padre, pero no como el jugador, pues recordemos, el crupier como tal no apuesta dinero
  
-------------------------------------------------------------------------

Clase: Interfaz
Se relaciona con:
Principalmente con Crupier y Jugador para jugar sus turnos y mostrar sus cartas, aunque usa tambien mesa para mostrar la lista de jugadores o elegir un jugador a eliminar

Nota: los metodos privados de dibujar_carta y su variante, como su nombre dice es para dibujar en consola una carta, dada su casta ysa un algoritmo que imprime el rank de la carta en las esquinas y en el centro la casta
otra cosa a tener en cuenta es el uso de R"()" este formato de caracteres nos permite que se muestran saltos de linea de forrma mas facil en consola

- Metodos: mostrar_mano crupier | jugador
  Lo que buscan este metodo es mostrar la mano tanto del crupier o del jugador dependiendo de la entrada del metodo, esto se hace con un ciclo for que recorre el vector de cartas y que imprime cada una de las cartas. previo a esto se
  hace un cuadro con el nombre del jugador para identificarlo
- Metodo: mostrar_mano_parcial
  Es para mostrar una carta boca arriba y otra hacia abajo al inicio de la partida, estas cartas correspondiente a la del crupier, se imprime la primer carta del vector de cartas y luego se imprime una carta como en blanco
- Metodos: mostrar_valor_mano Jugador | Crupier
  COmo su nombre lo indica permite mostrar el valor de la mano de una forma mas linda, en un cuadrado, con ayuda del get nombre y get valor mano
- Metodo mostrar_ganador
  Este con ayuda del metodo determinar_ganador de crupier muestra en pantalla un mensaje con el resultado de cada uno de los jugadores, determinando quien gana
- Metodo mostrar_menu_inicio
  Este muestra el menu de inicio del juego, retornando la opcion elegida por el jugador. Para las opciones se eligio hacer con string para tener un mejor rango a la hora de ver una correcta digitacion de las opciones
- Metodo mostrar_menu_juego
  Este tambien retorna la opcion del jugador, y es un menu de opciones individual por cada jugador donde se puede apostar (ingresar la apuesta) recargar dinero o salir del juego
- Metodo mostrar_menu_jugador
  Este menu aparece una vez ya se hicieron las apuestas y se repartieron cartas, es para las acciones del jugador durante el juego, como pedir una carta, plantarse, ver sus cartas etc.
  Este al igual que los anteriores metodos retorna la opcion del jugador
- Metodos pedir_nombre | logo | imrpimir_divicion | mensaje_error | mensaje_exitodo | mensaje
  Estos metodos se orientan a mostrar algun tipo de mensaje meramente decorativo en la consola, o en el caso de pedir nombre, una forma mas linda de pedir el nombre del jugador al momento de ingresar uno.
  EN cuanto a mensaje, contiene un arreglo con varios mensajes, la idea es que se ingrese el numero de la posicion del mensaje que se quiere ingresar a consola. Imprimir_divicion es la forma en que se divide la informacion en pantalla
  con barras del tipo ----- de una cantidad estandar
- Metodos esperar_enter|limpiar_consola
  El primero es para que el usuario como su nombre dice, presione enter para continuar, esto con el fin de hacer mas pausado el juego. Ademas limpiar consola nos permite tener una interfaz mas interactiva y limpia durante el juego
- Metodo interfaz_turno Jugador | Crupier
  Este lo que busca es, con ayuda del metodo mostrar_menu_jugador, jugar el turno de un jugador, en otras palabras ejecuta las acciones que muestra el metodo mostrar_menu_jugador. EN el caso de crupier lo que hace es ejecutar la dinamica
  del crupier a la hora de jugar: levantar la carta que tiene oculta, y dependiendo del puntaje va tomando mas cartas o se planta
- Metodo: mostrar_lista_jugadores | elegir_jugador_eleiminar
  Esta es obvia, con ayuda de un ciclo for recorre el vector de jugadores contenido en la clase mesa, para asi imprimir los jugadores activos en la mesa. Ahora bien, este metodo se usa en conjunto con el metodo elegir_jugador_eliminar
  pues la idea es que se muestre la lista y el jugador dijite el numero del jugador a eliminar. Se elimina del vector el numero digitado menos uno, es decir si eligio al jugador uno, se elimina el jugador en la posicion cero del vector
  
-------------------------------------------------------------------------
Clase Juego
Se relaciona con todas las clases basicamente

Nota: en general esta clase bvusca hacer procedimientos generales del proceso del juego, para que el main quede mas limpio y entendible 

- Metodo: recargar
  como su nombre lo indica, recarga dinero que haya digitado el jugador, verificando primero que el monto ingresado es valido y despues con phonevalidator y seriviciorecarga hace la transaccion, retornando true si la transaccion
  se realizo de manera exitosa y false si no
- Metodo: agregar_jugador
  como lo dice el nombre del metodo, este agrega un jugador, esto lo hace creando un objeto PersonaCasino y Jugador, una vez hecho esto se recarga con dinero el objeto jugador con el metodo anteriormente visto y se comprueba si la
  transaccion se realizo de forma exitosa
- Metodo: mostrasr_cartas_jugadores
  Este metodo recorre el vector de jugadores de la mesa y lo que hace es un ciclo for, donde primero sale el nombre del jugador, se le asigna una mano con el metodo pedir mano y despues se imprimen la mano y el valor de la mano de dicho jugador
- Metodo resumen_partida
  Lo que busca este metodo es que, una vez el crupier mostro sus cartas y que tales. Se muestre por ultimas vez la mano final y el valor de la mano de cada jugador junto con la mano y valor de la mano del crupier, esto a modo de resumen
- Metodo: determinar_ganadores
  Este metodo hace un for recorriendo el vector de jugadores, y determinando con el metodo de crupier (deterinar_ganador) para este resultado imprimirlo en consola, y de una verz se reunen las cartas del jugador para devolverlaas al vector de       cartas del mazo, y se reinician los valores de cada jugador por el que pasa el ciclo
- Metodo: eliminar_jugador
  Este como su nombre lo indica permite eliminar el jugador, se muestra una lista y se elimina al jugador con el numero que se haya digitado con ayuda del metodo de la clase interfas (elegir_jugador_eliminar), esto lo que hace es de una vez borrar
  de memoria heap el objeto padre y el hijo
- Metodo: apostar
  Este metodo le pide al jugador la cantidad de dinero que quiere apostar, verifica que el monto sea valido viendo que no sea mayor a la cantidad del dinero del jugador y llama al metodo del jugador apostar con el monto ingresado
- Metodo: jugador_turnos_jugadores
  Este metodo hace un ciclo for recorriendo a cada uno de los jugadores, permitiendoles jugar su turno en el juego (muestra el menu de opciones al momento de recibir las cartas y todo eso, para mas inform vayan a los metodos de interfaz)

-------------------------------------------------------------------------

Google test
# Pruebas unitarias con Google Test

Este proyecto utiliza **Google Test** para realizar pruebas unitarias sobre las clases del juego Blackjack. A continuación, se explica cómo funciona el sistema de pruebas y qué archivos son necesarios para ello.

## ¿Para qué sirven los archivos `.cpp` de prueba?

Cada archivo `.cpp` de prueba contiene pruebas unitarias para una clase específica del proyecto. Por ejemplo:

- `Carta_test.cpp`: pruebas para la clase `Carta`.
- `Mazo_test.cpp`: pruebas para la clase `Mazo`.
- `Mesa_test.cpp`: pruebas para la clase `Mesa`.

Estos archivos se crean para **verificar que el comportamiento de las clases sea correcto**, por ejemplo, que se inicialicen bien, que las funciones devuelvan lo esperado, que el estado interno se modifique correctamente, etc.

## ¿Qué contiene un archivo de prueba?

Cada archivo de prueba `.cpp` debe tener lo siguiente:

1. **Inclusión de Google Test y la clase a probar**:
```cpp
#include <gtest/gtest.h>
#include "../src/Carta.h"

ejemplo

TEST(CartaTestSimple, ValoresCorrectos) {
    Carta carta(10, "♠");
    EXPECT_EQ(carta.get_valor(), 10);
    EXPECT_EQ(carta.get_simbolo(), "♠");
}
```
Cada prueba ejecuta una parte del código y compara el resultado con lo esperado usando EXPECT_EQ, ASSERT_TRUE, etc.
# Organización general de archivos para pruebas con Google Test

Cuando se estructura un proyecto con Google Test y CMake, suelen organizarse los archivos de configuración y prueba de la siguiente manera. A continuación, se explica qué va en cada uno de ellos y para qué sirve.

---

## 1. `CMakeLists.txt` (principal, en la raíz del proyecto)

Este archivo principal le indica a CMake cómo compilar el proyecto. En él se define el ejecutable principal del proyecto y también se suele incluir la carpeta de pruebas.

Ejemplo general:
```cmake
cmake_minimum_required(VERSION 3.10)
project(BlackJack)

# Incluir carpeta con los headers
include_directories(include)

# Agregar los archivos fuente del proyecto
add_subdirectory(src)

# Incluir las pruebas
enable_testing()
add_subdirectory(tests)
```
2. tests/CMakeLists.txt
Este archivo es específico para la configuración de las pruebas. Aquí se indican los archivos .cpp de prueba que se deben compilar, y se enlazan con Google Test y con la biblioteca del proyecto (blackjack_lib).
# Incluir Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

# Crear ejecutable de pruebas
add_executable(tests
    Carta_test.cpp
    Mazo_test.cpp
    Mesa_test.cpp
    # Agrega aquí más archivos de prueba
)

# Enlazar con GTest y la biblioteca principal
target_link_libraries(tests
    ${GTEST_LIBRARIES}
    pthread
    blackjack_lib
)

# Activar las pruebas
add_test(NAME RunTests COMMAND tests)

3. Archivos .cpp dentro de la carpeta tests/
Aquí van los archivos que contienen las pruebas unitarias para cada clase. Suelen tener un nombre como Clase_test.cpp y cada uno prueba funciones específicas de la clase correspondiente.

#include <gtest/gtest.h>
#include "../include/Carta.h"

TEST(CartaTest, ConstructorCorrecto) {
    Carta carta(1, "♦");
    EXPECT_EQ(carta.get_valor(), 1);
    EXPECT_EQ(carta.get_simbolo(), "♦");
}


