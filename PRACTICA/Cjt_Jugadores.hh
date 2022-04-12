/** @file Cjt_Jugadores.hh
    @brief Especificación de la clase Cjt_Jugadores
*/

#ifndef _CJT_JUGADORES_HH
#define _CJT_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

/** @class Conjunto de Jugadores
    @brief Representa el conjunto de los jugadores

Dispone de blablabla...
*/

class Cjt_Jugadores
{
public:
  // Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Conjunto de Jugadores
      \pre <em>Cierto</em>
      \post El resultado es un map vacío, el ranking y una lista vacía, total de jugadores
  */
  Cjt_Jugadores();

  // Modificadoras

  /** @brief Da de alta un Jugador

      \pre El párametro implícito no contiene al Jugador p
      \post Se añade el Jugador p al ranking y a la lista de jugadores
  */
  void anadir_jugador(const Jugador &p);

  /** @brief Da de baja un Jugador

      \pre nombre_jug es un nombre que existe en nuestra lista de jugadores
      \post Se elimina al Jugador con nombre nombre_jug
  */
  void eliminar_jugador(string nombre_jug);

  // Consultoras

  /** @brief Consulta si existe el Jugador

      \pre <em>Cierto</em>
      \post El resultado indica si existe o no el Jugador con nombre nombre_jug
  */
  bool existe_jugador(string nombre_jug) const;

  /** @brief Consulta de un Jugador

      \pre nombre_jug tiene que ser un nombre de un Jugador que esté en la lista
      \post El resultado es el Jugador de nombre nombre_jug
  */
  Jugador consultar_jugador(string nombre_jug) const;

  /** @brief Consulta el total de jugadores en la lista

      \pre <em>Cierto</em>
      \post El resultado es el número de jugadores totales
  */
  static int numero_jugadores_totales();

  // Escritura / Lectura

  /** @brief Operación de lectura de jugadores

      \pre <em>Cierto</em>
      \post Se leen y almacenan los jugadores en la lista de jugadores y ranking
  */
  void leer_jugadores();

  /** @brief Operación de escritura del ranking

      \pre <em>Cierto</em>
      \post Se escribe todo el ranking
  */
  void escribir_ranking() const;

  /** @brief Operación de escritura de la lista de jugadores

      \pre <em>Cierto</em>
      \post Se escribe todos los jugadores, en orden creciente de nombre, con todos sus datos
  */
  void escribir_jugadores() const;


private:
  map<int, Jugador> ranking;
  list<Jugador> lista_jugadores;
  // Ordenar por nombre creciente
  static bool sort_lista_jug(const Jugador &a, const Jugador &b);
};

#endif
