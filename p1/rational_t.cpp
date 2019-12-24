#include "rational_t.hpp"

//Constructor
rational_t::rational_t(const int n, const int d) 
{ assert(d != 0);
  num_ = n,den_ = d;
}

//Devuelve un numero racional(un objeto)
double rational_t::value() const
{ return double(get_num()) / get_den();
}

//Devuelve el opuesto del objeto
rational_t rational_t::opposite() const
{ return rational_t((-1)*get_num(), get_den());
}

//Devuelve el valor reciproco o opuesto del objeto
rational_t rational_t::reciprocal() const
{ return rational_t(get_den(), get_num());
}

//Verifica si dos objetos son iguales
bool rational_t::equal(const rational_t& r, const double precision) const
{ return fabs(value() - r.value()) < precision;

}

//Verifica que un objeto es mayor que otro
bool rational_t::greater(const rational_t& r, const double precision) const
{ return (value() - r.value()) > precision;
}

//Verifica que un objeto es menor al otro
bool rational_t::less(const rational_t& r, const double precision) const
{ return (r.value() - value()) > precision;
}

//Verifica que un objeto es igual a 0
bool rational_t::zero(const double precision) const
{ return fabs(value()) < precision;

}

//Calculo de la suma entre dos objetos
rational_t rational_t::add(const rational_t& r) //ab+bc/bd
{ return rational_t((get_num()*r.get_den())+(r.get_num()*get_den()) , (get_den()*r.get_den())) ;
}

//Calculo de la resta entre dos objetos
rational_t rational_t::substract(const rational_t& r)
{ return rational_t((get_num()*r.get_den())-(r.get_num()*get_den()) , (get_den()*r.get_den()));
}

//Calculo del producto entre dos objetos
rational_t rational_t::multiply(const rational_t& r)
{ return rational_t((get_num()*r.get_num()) , (r.get_den()*get_den()));
}

//Calculo de la division entre dos objetos
rational_t rational_t::divide(const rational_t& r)
{ return rational_t((get_num()*r.get_den()) , (r.get_num()*get_den()));
}

//Imprime el objeto que ha sido llamado
void rational_t::write(ostream& os) const
{ os << get_num() << "/" << get_den() << "=" << value() << endl;
}

//Guarda los valores del objeto que ha sido llamado
void rational_t::read(istream& is)
{ cout << "Numerador: ";
  is >> num_;
  cout << "Denominador: ";
  is >> den_;
  assert(den_ != 0);
}

//MODIFICIACION EN CLASES
//Verificar si un numero es entero
bool rational_t::esentero(const double eps) const
{ 
    if(fabs(round(value()-value()) < eps)){
        return true;
    }
        return false;

}




