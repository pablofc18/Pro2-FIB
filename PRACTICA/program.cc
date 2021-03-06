/**
 * @mainpage Campeonato de torneos de tenis

Práctica PRO2 donde se construye un circuito de torneos de tenis... Se introducen
las clases <em>Circuito</em>, <em>Torneo</em>, <em>Categoria</em>, <em>Jugador</em>,
<em>Cjt_Categorias</em>, <em>Cjt_Jugadores</em>.

*/

/** @file main.cc
    @brief Programa principal para la práctica de PRO2,  <em>Circuito de torneos de tenis</em>.
*/

#include "Circuito.hh"
// #include "Torneo.hh"
// #include "Categoria.hh"
#include "Cjt_Categorias.hh"
// #include "Jugador.hh"
#include "Cjt_Jugadores.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif


int main() {

  Circuito circ;
  Cjt_Categorias cjt_categ;
  Cjt_Jugadores cjt_jug;

  // Lee número categorias C >= 1 y niveles K >= 4 ambos constantes.
  // Y seguidamente C strings con los nombres asociados a las categorias, orden creciente
  cjt_categ.leer_categorias_niveles();
  // Lee C * K enteros >= 0 que serán los puntos por categoria y nivel ordenados crecientemente (categoria, nivel)
  cjt_categ.leer_puntos_por_categoria_nivel();
  // Lee número inicial de torneos T >= 0 y una secuencia de T pares string, int nombre y categoria
  circ.leer_cjt_torneos();
  // Lee número inicial de jugadores P >= 0 y una secuencia de P strings con los nombres de los jugadores
  cjt_jug.leer_jugadores();

  string opc; cin >> opc;
  while (opc != "fin") {

    // 1
    if (opc == "nuevo_jugador" or opc == "nj") {
      string nombre_jug; cin >> nombre_jug;
      cout << '#' << opc << ' ' << nombre_jug << endl;
      // Si no existe el jugador con ese identificador, añadirlo
      if (not cjt_jug.existe_jugador(nombre_jug)) {
        cjt_jug.anadir_jugador(nombre_jug);
        cout << cjt_jug.numero_jugadores_totales();
        cout << endl;
      }
      else {
        cout << "error: ya existe un jugador con ese nombre" << endl;
      }
    }

    // 2
    else if (opc == "nuevo_torneo" or opc == "nt") {
      string nombre_torneo; cin >> nombre_torneo;
      int id_categ; cin >> id_categ;
      cout << '#' << opc << ' ' << nombre_torneo << ' ' << id_categ << endl;
      // Si la categoria es correcta y no existe ese torneo, añadirlo
      if (cjt_categ.es_correcta_categoria(id_categ)) {
        if (not circ.existe_torneo(nombre_torneo)) {
          Torneo t(nombre_torneo, id_categ);
          circ.anadir_torneo(t);
          cout << circ.numero_torneos_totales();
          cout << endl;
        }
        else {
          cout << "error: ya existe un torneo con ese nombre" << endl;
        }
      }
      else {
        cout << "error: la categoria no existe" << endl;
      }
    }

    // 3
    else if (opc == "baja_jugador" or opc == "bj") {
      string nombre_jug; cin >> nombre_jug;
      cout << '#' << opc << ' ' << nombre_jug << endl;
      // Si existe ese jugador, eliminarlo
      // Al eliminar jugador ya se actualiza el ranking y la lista
      if (cjt_jug.eliminar_jugador(nombre_jug)) {
        // Borrar registro de nombre_jug en todos los torneos que haya disputado
        circ.borrar_registros_jug_de_torneos(nombre_jug);
        cout << cjt_jug.numero_jugadores_totales();
        cout << endl;
      }
      else {
        cout << "error: el jugador no existe" << endl;
      }
    }

    // 4
    else if (opc == "baja_torneo" or opc == "bt") {
      string nombre_torneo; cin >> nombre_torneo;
      cout << '#' << opc << ' ' << nombre_torneo << endl;
      // Si existe el torneo, eliminarlo
      if (circ.eliminar_torneo(nombre_torneo, cjt_jug, cjt_categ)) {
        cout << circ.numero_torneos_totales();
        cout << endl;
      }
      else {
        cout << "error: el torneo no existe" << endl;
      }
    }

    // 5
    else if (opc == "iniciar_torneo" or opc == "it") {
      string nombre_torneo; cin >> nombre_torneo;
      cout << '#' << opc << ' ' << nombre_torneo << endl;
      circ.iniciar_torneo(nombre_torneo, cjt_jug);
    }

    // 6
    else if (opc == "finalizar_torneo" or opc == "ft") {
      string nombre_torneo; cin >> nombre_torneo;
      cout << '#' << opc << ' ' << nombre_torneo << endl;
      circ.finalizar_torneo(nombre_torneo, cjt_jug, cjt_categ);

    }

    // 7
    else if (opc == "listar_ranking" or opc == "lr") {
      cout << '#' << opc << endl;
      cjt_jug.escribir_ranking();
    }

    // 8
    else if (opc == "listar_jugadores" or opc == "lj") {
      cout << '#' << opc << endl;
      cout << cjt_jug.numero_jugadores_totales() << endl;
      cjt_jug.escribir_jugadores();
    }

    // 9
    else if (opc == "consultar_jugador" or opc == "cj") {
      string nombre_jug; cin >> nombre_jug;
      cout << '#' << opc << ' ' << nombre_jug << endl;
      // Si existe el jugador, escribir datos
      if (cjt_jug.existe_jugador(nombre_jug)) {
        cjt_jug.consultar_jugador(nombre_jug).escribir_jug();
      }
      else {
        cout << "error: el jugador no existe" << endl;
      }
    }

    // 10
    else if (opc == "listar_torneos" or opc == "lt") {
      cout << '#' << opc << endl;
      cout << circ.numero_torneos_totales() << endl;
      circ.escribir_torneos(cjt_categ);
    }

    // 11
    else if (opc == "listar_categorias" or opc == "lc") {
      cout << '#' << opc << endl;
      cjt_categ.escribir_categorias_puntos();
    }

    cin >> opc;
  }
}
