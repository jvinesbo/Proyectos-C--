#include<stdio.h>
#include<iostream>
using namespace std;
class Persona{
      public:
      int dni;
      char nombre[20];
      float saldo;
      Persona(){}
      Persona(int clau,char *nom,float euros){
                 dni=clau;
                 sprintf(nombre,nom);
                 saldo=euros;
                 }
      int incrementarSaldo(int cantidad);
      int retirarSaldo(int cantidad);
      };
int main(){
    
    Persona p;
    Persona * ps[5];
    p.dni=200;
    ps[0]=&p;
   	cout << "Persona: " << (*ps[0]).dni << endl;
    }
