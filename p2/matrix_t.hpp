#pragma once 

#include <cstdio>
#include <iostream>
#include <iomanip>

#include "vector_t.hpp"


using namespace std;

template <class T>
class matrix_t
{
//Elementos privados de la clase
private:
        //Atributos
        int m_; //filas
        int n_; //columnas
        
        vector_t<T> v_;
        
public:
        matrix_t(void):
        m_(0),
        n_(0),
        v_() {}
        
        matrix_t(int m, int n):
        m_(m),
        n_(n),
        v_(m * n) {}
        
        ~matrix_t(void)
        {}
        
        void resize(int m, int n)
        {
            v_.resize(m * n);
            m_ = m; n_ = n;
        }
        
        T& at (int i, int j)
        {
            return v_.at(pos(i,j));
        }

        const T& at (int i, int j) const
        {
            return v_.at(pos(i,j));
        }   
        
        T& operator()(int i, int j)
        {
            return at(i,j);
        }
        
        const T& operator()(int i, int j) const
        {
            return at(i,j);
        }        
        
        int get_m(void) const 
        {
            return m_;
        }
        
        int get_n(void) const
        {
            return n_;
        }
        
        void write(ostream& os) const
        {
            
             for(int i = 1; i <= m_; i++){
                 for(int j = 1; j <= n_; j++)
                          os << setw(5) << at(i, j) << "  " << setw(2);
                     
                os << endl;
             }      
        }
        
        //Fase IV
        //Producto de matrices
        void multiply(const matrix_t& A, const matrix_t& B)
        {
            assert(A.get_n()== B.get_m());
            resize(A.get_m(), B.get_n());

            for(int i=1; i <= m_; i++){
                for(int j=1; j <= n_; j++){

                    T aux;

                    for(int k=1; k<= A.get_n(); k++){
                        aux = aux + A(i,k) * B(k,j);

                    at(i,j)=aux;
                    }
                }
            }
  
        }

        //Suma de la primera fila de una Matriz
        T addfila(){
          T  sumaf = 0;
          for(int j=1; j <= n_; j++){
                   
                    sumaf = sumaf + at(1,j);         
        }
         return sumaf;
         
        }

        

     
private:

        int pos(int i, int j) const
        {
            return (i -1)* n_ + j - 1;
        }
       
};
