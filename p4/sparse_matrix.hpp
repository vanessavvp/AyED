#pragma once

#include "vector_t.hpp"
#include "matrix_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "pair_t.hpp"
#include "rational_t.hpp"

enum {COL_CONF, ROW_CONF};

typedef pair_t<rational_t> rpair_t;
typedef dll_node_t<rpair_t> sparse_node_t;
typedef dll_t<rpair_t> sparse_list_t;

class sparse_matrix_t{
	private:
		const int m_; //filas
		const int n_; //columnas
		vector_t<sparse_list_t> v_;
		const int conf_;

	public:
		sparse_matrix_t(const matrix_t<rational_t>& A, double eps, int conf):
		m_(A.get_m()),
		n_(A.get_n()),
		v_(),
		conf_(conf)
		{
			if (conf_ == COL_CONF){ //recorrido de la matriz
				v_.resize(n_);
                for(int j=1; j<= n_; j++){
                    for(int i=1; i<=m_; i++){
                        if (A(i,j).get_num() !=0){
                            v_[j - 1].insert_tail(new sparse_node_t(rpair_t(i, A(i,j))));}
                    }
                 }
			}else if(conf_ == ROW_CONF)
			{	v_.resize(m_);
                for(int i=1; i<= m_; i++){
                    for(int j=1; j<=n_; j++){
                        if (A(i,j).get_num() !=0){
                            v_[i - 1].insert_tail(new sparse_node_t(rpair_t(j,A(i,j))));}
                     }
                }
			}
        }
	~sparse_matrix_t(){}
	void write (ostream& os) const{
        for(int i=0; i< v_.size(); i++){
			v_[i].write(os);
			os << endl;
		}
	}
   
    //FASE III
    void multi(const matrix_t<rational_t>& M1, matrix_t<rational_t>& MR){//MR = Matriz densa con resultado

        assert(M1.get_n() == m_); //Es realmente la columna de la matriz densa M1 igual a la fila de la matriz dispersa invocante?
        MR.resize(M1.get_m(), n_); //Dimensiona la matriz densa que almacena el resultado con el tamanyo de la fila de M1 y la columna de la matriz dispersa
        rational_t res; //resultado de la multiplicacion 

        cout << endl<< "---Multiplicacion entre una matriz dispersa y una densa--- "<< endl;
        for(int i=1; i<=MR.get_m(); i++){
            for(int j=1; j<=MR.get_n(); j++){
                sparse_node_t *aux = v_[i-1].get_head();//Apunta a la cabecera del nodo
                MR(i,j) = 0;
                res = 0;
                for(int k = 1; k <= n_; k++){
                    while(aux){
                        res = res + aux->get_data().get_val() * M1(aux->get_data().get_inx(),j);
                        //cout <<aux->get_data().get_val()<< "*" << M1(aux->get_data().get_inx(),j) << "+";
                        aux = aux -> get_next();
                    }
                }
            MR(i,j) = res; 
            //res.write(cout);
            
            } 
        }
                
    }
    
	//MODIFICACION PE
	//Funcion que retorna el valor de la suma de la columna/fila especificada
	rational_t suma_nz(int i)
	{
		sparse_node_t* aux = v_[i - 1].get_head();  //Apunta a la cabecera del nodo
		rational_t suma = 0;

		while(aux != NULL) {

			pair_t<rational_t> dato = aux->get_data(); //dato apunta al valor del nodo de la dll
			rational_t val = dato.get_val(); //Almacena el valor del par de nodos

			suma = suma + val;

			aux = aux->get_next();
		}

		return suma;
	}

	
};

ostream& operator<<(ostream& os, const pair_t<rational_t>& a)
{
    a.write(os);
    return os;
}

