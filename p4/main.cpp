#include <cstdio>
#include <iostream>

#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "sparse_matrix.hpp"

#define MAX_DIM 5

using namespace std;

int main(void)
{
	matrix_t<rational_t> A(MAX_DIM,MAX_DIM);
	matrix_t<rational_t> RESULTADO(MAX_DIM,MAX_DIM);
	

	for(int i = 1; i <= MAX_DIM; i++)
		A(i,i) = rational_t(1,i + 1);

	A(1,2) = rational_t(5);
	A(3,4) = rational_t(3,2);
		
	A.write(cout);
	cout << endl;

	{
	//Matriz dispersa A con configuracion por columnas
	cout<<"---Matriz con configuracion por columnas---"<<endl;
	sparse_matrix_t SA(A, 1E-2, COL_CONF); 
	SA.write(cout);
	cout << endl;
	cout<<"La suma de los elementos de la primera columna es: "<< SA.suma_nz(1)<< endl<<endl;
	}

	{
	//Matriz dispersa A con configuracion por filas
	cout<<"---Matriz con configuracion por filas---"<<endl;
	sparse_matrix_t SA(A, 1E-2, ROW_CONF);
	SA.write(cout);
	SA.multi(A,RESULTADO);
	cout<< endl;
	RESULTADO.write(cout);
	}
}

	