#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

namespace AED {

	template <class T>
	class RPN_calc_t{
	private:
		T stack_;

	public:
		RPN_calc_t() {}

		~RPN_calc_t() {}
	
		const int compute(istream& is)
		{

			int operando;
			char operador;
			int resta = 0;

			while(!is.eof()){

				is >> ws;
				int c = is.peek();

				if (!is.eof()) {

					if (isdigit(c)){
						is >> operando;
						stack_.push(operando);
					}
					else {
						is >> operador;
						operate(operador);
						if (operador == '-') resta ++;
					
					}
				}
			}

			const int result = stack_.top();
			stack_.pop();
			cout <<"La cantidad de operadores resta es: "<<resta<<endl;	
			return result;
		}

		private: 
			//FASE II
			void operate(char operador){
				float A=0;
				float B=0;
				float resultado=0;
				

				

				switch (operador)
				{
				case '+':
					B = stack_.top();
					stack_.pop();
					A = stack_.top();
					stack_.pop();
					resultado = A + B;
					stack_.push(resultado);
					cout <<" "<<A <<"+"<<""<<B<<"="<<" "<<resultado<<endl;			
					break;
				case '-':
					
					B = stack_.top();
					stack_.pop();
					A = stack_.top();
					stack_.pop();
					resultado = A - B;
					stack_.push(resultado);
					cout <<" "<<A <<"-"<<""<<B<<"="<<" "<<resultado<<endl;	
					break;
					
				case '*':
					B = stack_.top();
					stack_.pop();
					A = stack_.top();
					stack_.pop();
					resultado = A * B;
					stack_.push(resultado);
					cout <<" "<<A <<"*"<<""<<B<<"="<<" "<<resultado<<endl;			
					break;
					break;
				case '/':
					B = stack_.top();
					stack_.pop();
					A = stack_.top();
					stack_.pop();
					resultado = A / B;
					stack_.push(resultado);
					cout <<" "<<A <<"/"<<""<<B<<"="<<" "<<resultado<<endl;			
					break;

				//FASE 3
				case '^':
					B = stack_.top();
					stack_.pop();
					A = stack_.top();
					stack_.pop();
					resultado = pow(A,B);
					stack_.push(resultado);
					cout <<A <<"^"<<B<<"="<<" "<<resultado<<endl;			
					break;
				case 'r':
					B = stack_.top();
					stack_.pop();
					resultado = sqrt(B);
					stack_.push(resultado);
					cout <<"Raiz cuadrada de "<<B<<"="<<resultado<<endl;			
					break;
				case 'l':
					B = stack_.top();
					stack_.pop();
					resultado = log2(B);
					stack_.push(resultado);
					cout <<"Logaritmo en base 2 de "<<B<<"="<<resultado<<endl;			
					break;
				case 'c':
					B = stack_.top();
					stack_.pop();
					resultado = B*B;
					stack_.push(resultado);
					cout <<"El cuadrado de "<<B<<"="<<resultado<<endl;			
					break;
				
				default:
					cout <<"Ha ocurrido un error";
					break;
				}
				 			
			
			}

       };

}

