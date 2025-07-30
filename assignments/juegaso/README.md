Proyecto final.

Carlos Fernando Velázquez Valles
A01384464

Programación Orientada a objetos  (Gpo 851)
Profesor: León Felipe Guevara Chávez

**Introducción**

Este proyecto concistio de un programa de simulación de batallas, 
se programo un juego en el que dos equipos luchan utilizando personajes con habilidades diferentes,
el objetivo del juego es derrotar completamente al equipo rival, son equipos de 5 personajes cada uno
Esto se construyo usando los principios de la programación orientada a objetos, usando conceptos como
herencia, polimorfismo, clases abstractas, sobrecarga de operadores y manejo de excepciones.

**Explicación técnica**

-Herencia
La herencia se aplico ya que la clase base, la cual es Unidad, 
define las propiedades y los comportamientos de todos los personajes(como lo es su nombre, su vida, sua taque y su ulti).
Y de esta clase derivan las clsaes de los personajes (Guerrero, Aruqero, Mago, Tanque, Asesino). 
Estas clases hijas heredan los atributos y metodos de Unidad, y pueden sobreescribir la ulti (con la función usarUltima). 
Esto facilita el manejo de los diferentes personajes con diferentes especificaciones.

-Polimorfismo
Se uso polimorfismo a través de punteros a Unidad, por ejempñlo en el vector<Unidad*>equipo 
se pueden almacenar instancias de cualquier subclase de unidad.
Al usar metodos virtuales como usarUltima() o mostrarInfo(), se llama a la version correcta de acuerdo al tipo del objeto
lo que permite una logica de combate funcional con diferentes clases de personajes

-Clases abstractas
La clase base Unidad es abstracta, ya que contiene un metodo virtual puro, el cual es usarUltima, 
esto obcliga a las clases derivadas a implementar este metodo. lo que garantiza que todas las unidades tengan una ulti, 
y al mismo tiempo permite que cada subclase defina como va a funcionar esta misma

-Sobrecarga de operadores
se sobrecargó el operador << para que se imprima directamente el estado de un personaje (es decir su salud y la carga de la ulti)
lo que hace mas facil la implementacion del metodo mostrarEstado

-Manejo de excepciones
se uso elmanejo de excepciones para el manoje de errores, esto se hizo utilizando try-catch. 
en este caso si el jugador introduce un número inválido al elegir su personaje,se lanza una excepción (invalid_argument)
y el programa la captura para evitar que falle y ofrecer un mensaje de error mas amigable

**Conclusión**

Este proyecto me gusto ya que pude poner en practica lo aprendido en el curso en un proyecto el cual incluia todo
pude enteder mejor en la practica los diferentes conceptos al hacer un sistema funcional. Igual aprendi como la herencia ahorra
pasos al no tener que definir cada clase si no reutilizar atributos/metodos, tambien aprendi como usar las excepciones 
en la entrada de informacion por el usuario para evitar que haya algun error. En general, hacer este proyecto me ayudo a 
reforzar mis conocimientos ya que al poner en practica todo pude experimentar muchas cosas diferentes y ver como funcionaba
lo que me incentivo a seguir estudiando y cambiando el codigo.
