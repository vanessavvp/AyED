#pragma once //Para no anyadir varias veces la misma clase

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class rational_t //Nombre de la clase
{
//Elementos privados
private:
  //Atributos de la clase
  int num_;  
  int den_;

//Elementos publicos
public:
  //Constructor por defecto
  rational_t(const int = 0, const int = 1);
  //Destructor  
  ~rational_t()  
  {} 

  //Getters
  //Devuelve el valor del objeto que lo llama
  int get_num() const 
  { return num_; }
  
  int get_den() const
  { return den_; }
  
  //Setters
  //Cambia el valor del objeto que lo llama
  void set_num(const int n)
  { num_ = n; }
  
  void set_den(const int d)
  { assert(d != 0), den_ = d; } //Herramienta de depuracion que obliga a que el termino que estas introduciendo es diferente a 0

  //Metodos
  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  // FASE II
  bool equal(const rational_t& r, const double precision = EPSILON) const;
  bool greater(const rational_t& r, const double precision = EPSILON) const;
  bool less(const rational_t& r, const double precision = EPSILON) const;
  bool zero(const double precision = EPSILON) const;

  // FASE IV
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);

  //MODIFICACION EN CLASES
  bool esentero(const double eps = EPSILON) const;

  //Metodo para escritura a pantalla
  void write(ostream& os = cout) const;
  //Metodo para lectura desde teclado 
  void read(istream& is = cin);
};
