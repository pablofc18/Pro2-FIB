/** @file Cjt_Jugadores.cc
    @brief Código de la clase Cjt_Jugadores
*/

#include "Cjt_Jugadores.hh"

Cjt_Jugadores::Cjt_Jugadores()
{
  // vector<Jugador> ranking;
  // map<string, Jugador> cjt_jugadores;
}
// Función para ordenar el vector de ranking
bool comp_rank(const Jugador &p1, const Jugador &p2)
{
  if (p1.consultar_puntos() == p2.consultar_puntos()) {
    return p1.consultar_ranking() < p2.consultar_ranking();
  }
  return p1.consultar_puntos() > p2.consultar_puntos();
}

void Cjt_Jugadores::ordenar_ranking()
{
  sort(ranking.begin(), ranking.end(), comp_rank);

  map<string, Jugador>::iterator it;
  for (int i = 0; i < ranking.size(); ++i) {
    ranking[i].modificar_ranking(i+1);
    it = cjt_Jugadores.find(ranking[i].consultar_nombre());
    it->second.modificar_ranking(i+1);
  }

}

void Cjt_Jugadores::anadir_jugador(string nombre_jug)
{
  // Añadirle el ranking y después añadirlo a las estruct. datos
  Jugador p(nombre_jug);
  p.modificar_ranking(cjt_Jugadores.size() + 1);
  cjt_Jugadores[nombre_jug] = p;
  // Ranking
  ranking.push_back(p);
}

bool Cjt_Jugadores::eliminar_jugador(string nombre_jug)
{
  // Buscamos el jugador si existe
  map<string, Jugador>::iterator it = cjt_Jugadores.find(nombre_jug);
  // Si existe lo borramos y editamos datos
  if (it != cjt_Jugadores.end()) {
    // Guardamos ranking jugador eliminado y borramos jugador del map
    int rank_jug_eliminado = it->second.consultar_ranking();
    cjt_Jugadores.erase(it);

    for (int i = rank_jug_eliminado; i < ranking.size(); ++i) {
      it = cjt_Jugadores.find(ranking[i].consultar_nombre());
      it->second.modificar_ranking(it->second.consultar_ranking() - 1);
      ranking[i].modificar_ranking(ranking[i].consultar_ranking() - 1);
      ranking[i-1] = ranking[i];
    }
    // Borrar el último que estará repetido
    ranking.pop_back();

    return true;
  }
  else return false;
}

void Cjt_Jugadores::modificar_estadisticas_jug(string nombre_jug_a, string nombre_jug_b, string result)
{
  // Todos los datos excepto ranking y puntos y torneo_disp
  map<string, Jugador>::iterator it_a = cjt_Jugadores.find(nombre_jug_a);
  map<string, Jugador>::iterator it_b = cjt_Jugadores.find(nombre_jug_b);

  // Sets
  pair<int,int> sets_jug_a(0,0);
  pair<int,int> sets_jug_b(0,0);
  // Total juegs
  int a = 0, b = 0;
  int result_size = result.size();
  for (int i = 0; i < result_size; ++i) {
    if (i%4 == 0) a += (result[i] - '0');
    else if (i%2 == 0) b += (result[i] - '0');
    // Sets
    if (i == 2) {
      if (result[i] - '0' < result[i-2] - '0') {
        sets_jug_a.first += 1;
        sets_jug_b.second += 1;
      }
      else {
        sets_jug_a.second += 1;
        sets_jug_b.first += 1;
      }
    }
    else if (i == 6) {
      if (result[i] - '0' < result[i-2] - '0') {
        sets_jug_a.first += 1;
        sets_jug_b.second += 1;
      }
      else {
        sets_jug_a.second += 1;
        sets_jug_b.first += 1;
      }
    }
    else if (i == 10) {
      if (result[i] - '0' < result[i-2] - '0') {
        sets_jug_a.first += 1;
        sets_jug_b.second += 1;
      }
      else {
        sets_jug_a.second += 1;
        sets_jug_b.first += 1;
      }
    }
  }
  // Partidos
  pair<int,int> partidos_jug_a;
  pair<int,int> partidos_jug_b;
  if (sets_jug_a.first > sets_jug_a.second) {
    partidos_jug_a = make_pair(1,0);
    partidos_jug_b = make_pair(0,1);
  }
  else {
    partidos_jug_a = make_pair(0,1);
    partidos_jug_b = make_pair(1,0);
  }
  it_a->second.modificar_partidos_jugados(partidos_jug_a);
  it_b->second.modificar_partidos_jugados(partidos_jug_b);

  // Juegos y sets
  if (result_size != 3) {
    // Juegos
    pair<int,int> juegos_jug_a(a, b);
    it_a->second.modificar_juegos_jugados(juegos_jug_a);
    pair<int,int> juegos_jug_b(b, a);
    it_b->second.modificar_juegos_jugados(juegos_jug_b);
    // Sets
    it_a->second.modificar_sets_jugados(sets_jug_a);
    it_b->second.modificar_sets_jugados(sets_jug_b);
  }
}

void Cjt_Jugadores::sumar_puntos_jug(string nombre_jug, int pts)
{
  map<string, Jugador>::iterator it = cjt_Jugadores.find(nombre_jug);
  it->second.modificar_puntos(pts);
  int rank = it->second.consultar_ranking();
  ranking[rank-1].modificar_puntos(pts);
}

void Cjt_Jugadores::restar_puntos_jug(string nombre_jug, int pts)
{
  map<string, Jugador>::iterator it = cjt_Jugadores.find(nombre_jug);
  pts = pts*-1;
  if (it != cjt_Jugadores.end()) {
    it->second.modificar_puntos(pts);
    int rank = it->second.consultar_ranking();
    ranking[rank-1].modificar_puntos(pts);
  }
}

void Cjt_Jugadores::sumar_torneo_disputado(string nombre_jug)
{
  map<string, Jugador>::iterator it = cjt_Jugadores.find(nombre_jug);
  it->second.modificar_torneos_disputados(1);
}

bool Cjt_Jugadores::existe_jugador(string nombre_jug) const
{
  map<string, Jugador>::const_iterator it;
  it = cjt_Jugadores.find(nombre_jug);
  return it != cjt_Jugadores.end();
}

Jugador Cjt_Jugadores::consultar_jugador(string nombre_jug) const
{
  map<string, Jugador>::const_iterator it;
  it = cjt_Jugadores.find(nombre_jug);
  return it->second;
}

Jugador Cjt_Jugadores::consultar_jugador(int rank) const
{
  return ranking[rank-1];
}

int Cjt_Jugadores::numero_jugadores_totales() const
{
  return cjt_Jugadores.size();
}

void Cjt_Jugadores::leer_jugadores()
{
  int num_jugs; cin >> num_jugs;
  for (int i = 0; i < num_jugs; ++i) {
    string nombre_jug; cin >> nombre_jug;
    // Añadirle el ranking y después añadirlo a las estruct. datos
    Jugador p(nombre_jug);
    p.modificar_ranking(i+1);
    cjt_Jugadores[nombre_jug] = p;
    // Ranking
    ranking.push_back(p);
  }
}

void Cjt_Jugadores::escribir_ranking() const
{
  for (int i = 0; i < ranking.size(); ++i) {
    cout << i+1 << ' ' << ranking[i].consultar_nombre() << ' '
         << ranking[i].consultar_puntos() << endl;
  }
}

void Cjt_Jugadores::escribir_jugadores() const
{
  map<string, Jugador>::const_iterator it = cjt_Jugadores.begin();
  while (it != cjt_Jugadores.end()) {
    it->second.escribir_jug();
    ++it;
  }
}
