
#include <iostream>
#include <cmath>
#include "rational_t.hpp"

using namespace std;

// FASE III: función de búsqueda
bool search(const rational_t* v, const int n, const rational_t& x){

    for(int i=0; i<n; i++){
       //Se llama a la funcion equal para saber si nuestro objeto se encuentra dentro del vector v
       if(v[i].equal(x)){ return true;
       }
    }
       return false;
      
}
int main()
{ rational_t a(1, 4), b(3), c; //Creacion de objetos
  //Imprime el valor de las fracciones
  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  //FASE II
  //Comprobar si dos numeros son iguales
  if (a.equal(b)==true){
    cout<<"a y b son iguales"<<endl;
  }
  else {
    cout<<"a y b son diferentes"<<endl;
  }
  //Comprobacion si el primer numero es mayor al segundo
  if (a.greater(b)==true){
      cout<<"a es mayor que b"<<endl;
  }
  else{
      cout<<"a no es mayor que b"<<endl;
  }
  //Comprobacion si el primer numero es menor al segundo    
  if (a.less(b)==true){
      cout<<"a es menor que b"<<endl;
  }
  else{
      cout<<"a no es menor que b"<<endl;
  }
  //Comprobacion si el numero es igual a 0
  if (a.zero()==true){
      cout<<"a es igual a 0"<<endl;
  }
  else{
      cout<<"a no es igual a 0"<<endl;
  }
  //Calcular el opuesto de un numero
  cout << "Opuesto de a: ";
  a.opposite().write();
  //Calcular el reciproco o inverso de un numero
  cout << "Recíproco de b: ";
  b.reciprocal().write();

  //FASE III
  int n;
  //Se almacena el tamanyo de nuestro vector
  cout<<"Introduce el numero de objetos: "; 
  cin>>n;
  //Creacion del vector de n objetos
  rational_t *v= new rational_t[n];   
    
    //Almacenamiento de los datos dentro del vector
    for (int i = 0; i < n; i++) { 
    v[i] = rational_t(1, pow(2, i));
    v[i].write();
    }
      //Se verifica si se ha encontrado el objeto dentro del vector
      if(search(v,n,a)){ cout<<"Se ha encontrado el valor "<<a.value()<<endl;
      }
      else{ cout<<"No se ha encontrado el valor "<<a.value()<<endl;
      }
      //Se elimina el vector dinamico
      delete[] v;

  // FASE IV
  //Calcular la suma de dos numeros
  cout << "a + b: ";
  a.add(b).write();
  
  //Calcular la resta de dos numeros
  cout << "b - a: ";
  b.substract(a).write();

  //Calcular el producto entre dos numeros
  cout << "a * b: ";
  a.multiply(b).write();
  
  //Calcular la division entre dos numeros
  cout << "a / b: ";
  a.divide(b).write();

  //MODIFICACION EN CLASES
  if(a.esentero()==true){
      cout<<"Es entero"<<endl;
  }
  else{
      cout<<"No es entero"<<endl;
  }
  return 0;
  
}