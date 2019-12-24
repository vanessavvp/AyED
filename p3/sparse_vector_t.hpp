#pragma once

#include "list_pair_t.hpp"
#include "vector_t.hpp"
#include <cmath>

#include <iostream>
#include <iomanip>

#include "vector_t.hpp"

using namespace std;

namespace AED {

class sparse_vector_t{
private:
	list_pair_t   v_;
	int           sz_;

public:
	//FASE II
	sparse_vector_t(const vector_t<double>& v, double eps):
		v_(),
		sz_(v.size()) {
			int contador = 0;
			for(int i=v.size()-1; i>=0; i--){
				if(is_not_zero(v[i],eps)){
					spair_t dato(i,v[i]);
					node_pair_t* nodo = new node_pair_t(dato);
					v_.insert_head(nodo);
					contador++;
				}
			}
			cout<< endl <<"El numero de elementos no nulos es: "<< contador << endl;
	}

	~sparse_vector_t(void){}

	ostream& write(ostream& os) const{

		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}

	//FASE III
	double scal_prod(const vector_t<double>& b) const{
		assert(sz_ == b.size());
		double res = 0;
		node_pair_t* aux = v_.head();
		while(aux != NULL){
			const spair_t data = aux -> get_data();
			const int inx = data.get_inx();
			const double val = data.get_val();
			res = res + b[inx] * val;
			aux = aux -> get_next();
		}
		return res;

	}

	//FASE IV
	double scal_prod(const sparse_vector_t& b) const{
		assert(sz_ == b.sz_);
		double res = 0;
		node_pair_t* aux1 = v_.head();
		node_pair_t* aux2 = b.v_.head();
		while((aux1 != NULL)&&(aux2 != NULL)){
			spair_t dato1 = aux1 -> get_data();
			spair_t dato2 = aux2 -> get_data();
			const int inx1 = dato1.get_inx();
			const int inx2 = dato2.get_inx();
			if(inx1 == inx2){
				res += dato1.get_val() * dato2.get_val();
				aux1 = aux1 -> get_next();
				aux2 = aux2 -> get_next();
			}
			else if(inx1 < inx2){
				aux1 = aux1 -> get_next();
			}
			else{
				aux2 = aux2 -> get_next();
			}
		}
		return res;
	}


	//MODIFICACION PRACTICA: Método que devuelve la cantidad de elementos del vector que sean iguales a un umbral pasado por parametros igualado a 5
	int elemento_umbral( int umbral) const{
		node_pair_t* aux = v_.head();
		int cnt = 0;
		while(aux != NULL){
			const spair_t dato = aux -> get_data();
			const double val = dato.get_val();
			if(val == umbral){
				cnt ++;
			}
			aux = aux -> get_next();
		}
		return cnt;
	}



private:
	bool is_not_zero(double val, double eps){ return fabs(val) > eps;}

};


}
