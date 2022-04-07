/**
 * @mainpage Campeonato de torneos de tenis

Práctica PRO2 donde se construye un circuito de torneos de tenis... Se introducen
las clases <em>Circuito</em>, <em>Torneo</em>, <em>Categoria</em>, <em>Jugador</em>.

Solo se documentan los elementos públicos...
*/

/** @file main.cc
    @brief Programa principal para la práctica de PRO2,  <em>Circuito de torneos de tenis</em>.
*/


#include "Circuito.hh"
#include "Torneo.hh"
#include "Categoria.hh"
#include "Jugador.hh"
#include "Cjt_Jugadores.hh"


/** @brief Programa principal para la práctica de PRO2,  <em>Circuito de torneos de tenis</em>.
*/

int main() {

  // Clases: Jugador, Torneo, Categoria, -CIRCUITO-
  Circuito Circ;
  Torneo t;
  Categoria c;
  Cjt_Jugadores cjt_p;
  Jugador p;

  string opc; cin >> opc;
  while (opc != "fin") {
    if (opc == "nuevo_jugador" or opc == "nj") {
      string nombre_jug; cin >> nombre_jug;
      if (not p.existe_jugador(nombre_jug)) { // NO CORRECTO

      }
    }

    else if (opc == "nuevo_torneo" or opc == "nt") {

    }

    else if (opc == "baja_jugador" or opc == "bj") {

    }

    else if (opc == "baja_torneo" or opc == "bt") {

    }

    else if (opc == "iniciar_torneo" or opc == "it") {

    }

    else if (opc == "finalizar_torneo" or opc == "ft") {

    }

    else if (opc == "listar_ranking" or opc == "lr") {

    }

    else if (opc == "listar_jugadores" or opc == "lj") {

    }

    else if (opc == "consultar_jugador" or opc == "cj") {

    }

    else if (opc == "listar_torneos" or opc == "lt") {

    }

    else if (opc == "listar_categorias" or opc == "lc") {

    }

    cin >> opc;
  }
}
