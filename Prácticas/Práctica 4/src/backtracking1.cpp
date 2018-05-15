#include <chrono>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace chrono;

#define NULO 2
#define END -1
#define DEBUG 0

list<vector<int>> lista;

class Solucion {
private:
  vector<int> tuplas;
  vector<int> v;
  int M;
  int GetSuma() const;

public:
  Solucion(int tam, int num_m);
  ~Solucion();
  int size() const;
  int getM() const;
  int getTupla(int i) const;
  bool TodosGenerados(int i) const;
  void InicializaElemento(int i);
  void DecrementaElemento(int i);
  void Aniadir();
  bool SolucionEncontrada();
  bool Factibilidad();
};

Solucion::Solucion(int tam, int num_m) {
  tuplas.resize(tam);
  v.resize(tam);
  M = num_m;

  for (int i = 0; i < tam; i++)
    v[i] = i + 1;
}

Solucion::~Solucion(){};

int Solucion::size() const { return tuplas.size(); }

int Solucion::getM() const { return M; }

int Solucion::getTupla(int i) const { return tuplas[i]; }

bool Solucion::TodosGenerados(int i) const { return tuplas[i] == END; }

void Solucion::InicializaElemento(int i) { tuplas[i] = NULO; }

void Solucion::DecrementaElemento(int i) { tuplas[i]--; }

bool Solucion::SolucionEncontrada() { return GetSuma() == M; }
int Solucion::GetSuma() const {
  int sum_aux = 0, i = 0;
  while (i < tuplas.size()) {
    sum_aux += tuplas[i] * v[i];
    i++;
  }
  return sum_aux;
}

bool Solucion::Factibilidad() { return GetSuma() <= M; }

void Solucion::Aniadir() { lista.push_back(tuplas); }

/******************************************************************************/
//
/*                 ALGORTIMOS (FUERZA BRUTA Y BACKTRACKING)                   */
//
/******************************************************************************/

void Backtracking_sin_info(Solucion &sol, int i) {
  if (i != sol.size()) {       // Si no nos hemos pasado
    sol.InicializaElemento(i); // Pongo tuplas[i]=NULO
    sol.DecrementaElemento(i); // tuplas[i]--

    while (!sol.TodosGenerados(i) &&
           sol.Factibilidad()) { // Mientas no llegue al final y sea factible
      if (sol.SolucionEncontrada())
        sol.Aniadir();
      Backtracking_sin_info(sol, i + 1); // Llamo recursirvamente con el próximo elemento
      sol.DecrementaElemento(i); // tuplas[i]-- (END)
    }
  }
}

ostream &operator<<(ostream &f, const vector<int> &v) {
  for (auto it = v.begin(); it != v.end(); ++it)
    f << *it << " ";
  return f;
}

ostream &operator<<(ostream &f, const list<vector<int>> &lista) {
  for (auto it = lista.begin(); it != lista.end(); ++it)
    f << *it << endl;
  return f;
}
/******************************************************************************/

int main(int argc, char **argv) {
  lista.clear();

  if (argc != 2) {
    cerr << "Uso: " << argv[0] << " <número>" << endl << endl;
    exit(1);
  }

  int num = atoi(argv[1]);

  Solucion sol(num, num);
  int veces = 100;
  double media=0.0;

  for (int i = 0; i < veces; i++) {
    high_resolution_clock::time_point tantes = high_resolution_clock::now();

    Backtracking_sin_info(sol, 0);

    high_resolution_clock::time_point tdespues = high_resolution_clock::now();
    duration<double> total = duration_cast<duration<double>>(tdespues - tantes);
    media+=total.count();
  }
  media/=veces;

  cout << num << "\t" << media << endl;

#if DEBUG
  cout << "Soluciones:" << endl;
  cout << lista << endl;
#endif

  return 0;
}
