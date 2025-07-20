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

- Método: void repartir_cartas(Mazo& mazo)
Este método reparte la mano inicial a los jugadores activos.

Recorre el vector mesa con un ciclo for por cada puntero jugador.

Verifica si el jugador está jugando (jugador->get_esta_jugando()).

Si sí, llama a jugador->pedir_mano(mazo), que le da las cartas iniciales desde el mazo.

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
Usa jugador para determinar quien gana, ademas de carta para tener su mano (vector de cartas) y mazo para obtener cartas o su mano inicial y el crupier es quien tiene el mazo, asi que contiene esta clase
  
