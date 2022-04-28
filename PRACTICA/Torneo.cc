#include "Torneo.hh"

Torneo::Torneo()
{
  categ = 0;
  disputado = false;
}

Torneo::Torneo(string nombre_torneo, int id_categ)
{
  nombre = nombre_torneo;
  categ = id_categ;
  disputado = false;
}

BinTree<int> Torneo::confeccionar_cuadro_emparejamientos(int n, int val, int potencia2)
{
  if (n < potencia2) {
    if ((val <= potencia2-n and val >= 1) or (val > n)) return BinTree<int>();
    else return BinTree<int>(val);
  }
  else if (n == potencia2) {
    return BinTree<int>(val);
  }
  else {
    BinTree<int> l,r;
    l = confeccionar_cuadro_emparejamientos(n, val, potencia2*2);
    r = confeccionar_cuadro_emparejamientos(n, potencia2*2+1-val, potencia2*2);
    return BinTree<int>(val, l, r);
  }
}

// void Torneo::confeccionar_cuadro_resultados()
// {
// }

string Torneo::consultar_nombre() const
{
  return nombre;
}

bool Torneo::torneo_disputado() const
{
  return disputado;
}

vector<int> Torneo::consultar_jugadores_del_torneo() const
{
  return jugadores_del_torneo;
}

void Torneo::leer_participantes_torneo()
{
  int num_jug_inscritos; cin >> num_jug_inscritos;
  for (int i = 0; i < num_jug_inscritos; ++i) {
    int num_rank; cin >> num_rank;
    jugadores_del_torneo.push_back(num_rank);
  }
}

// void Torneo::leer_resultados()
// {
//
// }

void Torneo::escribir_torneo(const Cjt_Categorias &cjt_cat) const
{
  // nombre torneo y nombre categoria
  cout << nombre << ' ';
  cout << cjt_cat.consultar_nombre_categ(categ) << endl;
}

// void Torneo::escribir_particip_puntos_ganados() const
// {
//
// }

void Torneo::escribir_cuadro_emparejamientos(const BinTree<int> &cuadro_emp, const Cjt_Jugadores &cjt_jug) const
{
  if (cuadro_emp.left().empty()) cout << cuadro_emp.value() << '.' << cjt_jug.consultar_jugador(jugadores_del_torneo[cuadro_emp.value()-1]).consultar_nombre();
  else {
    cout << '(';
    escribir_cuadro_emparejamientos(cuadro_emp.left(), cjt_jug);
    cout << ' ';
    escribir_cuadro_emparejamientos(cuadro_emp.right(), cjt_jug);
    cout << ')';
  }

}

// void Torneo::escribir_resultados_torneo() const
// {
//
// }
