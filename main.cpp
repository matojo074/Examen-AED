#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include"Datos.h"
using namespace std;

const int MAX = 50;


tEstudiante estudiante;
tLista lista;

int menu();
int menuOrdenamiento();
int menuBusqueda();

int main (){
  int opcion;
  opcion=menu();
  while (opcion !=0){

    switch (opcion){

    
    case 1:{
    ingresar(lista, estudiante);
      ofstream ordenamiento;
      ordenamiento.open("ordenamiento.txt",ios::app);
      ordenamiento<<"\n*********COLEGIO MEJIA**********\n";
      ordenamiento<<"****Reporte de calificaciones****\n";
      ordenamiento<<"\nCalificaciones Ordenadas\n";
    break;
    }
    
    case 2:{
      int opcion2;
      opcion2 = menuOrdenamiento();
      while (opcion2!=0){
        switch (opcion2){
          case 1:{
            ordenamiento_quik();
            break;
          }
          case 2:{
             ordenamiento_Heapsort();
            break;
          }
          case 3:{
            ordenamiento_Burbuja();
            break;
          }
          case 4:{
            ordenamiento_mergesort();
            break;
          }
          default:{
            cout << "Opcion no valida! Ingrese la opcion correcta.\n";
          }
        }
        opcion2 = menuOrdenamiento();
      }
    }break;
    case 3:{
      int opcion3;
      opcion3 = menuBusqueda();
      while(opcion3 != 0){
        switch(opcion3){
          case 1:{
            int num;
            cout << "Ingrese la nota a buscar: ";
            cin >> num;
            if(Busqueda_Lineal(lista,num)==-1)
            {
              cout << "Nota no encontrada\n";
            }
          }break;
          case 2:{
            int num;
            cout << "Ingrese la nota a buscar: ";
            cin >> num;
            Busqueda_Binaria(lista,num);
          }break;
          case 3:{
            int num;
            cout << "Ingrese la nota a buscar: ";
            cin >> num;
            if(Bus_Interpo(lista, num)==-1)
            {
              cout << "Nota no encontrada\n";
            }
          }break;
          case 0:
          {
            cout << "Salio del menu de busquedas\n";

            break;

          }
          default:{
            cout << "Opcion no valida. Ingrese la opcion correcta.\n";
          }
        }
        opcion3 = menuBusqueda();
      }
    }
    default:{
      cout << "Opcion no valida. Ingrese la opcion correcta.\n";
    }
    }
    opcion=menu();
  }
}

int menu()
{
  int op = -1;
  cout <<" "<< setfill( '=' )<< setw( 60 )  <<'\n'; 
  cout <<setfill( ' ' )<<"|"<<setw(45)<<"|BIENVENIDO AL SISTEMA DE NOTAS|"<<setw(15)<<"|"<<endl;
  cout<<"|"<<setw(61)<<"*INTEGRANTES:| "<<'\n'<<"|"<<setw(61)<<"Josue Vergara|\n"<<"|"<<setw(61)<<"Mateo Cevallos|\n"<<"|"<<setw(61)<<"Noemi Cumbal|\n"<<"|"<<setw(61)<<"Ivan Fraga|\n"<<"|"<<setw(61)<<"Guillermo Andrade|\n";

  cout <<" "<< setfill( '=' )<< setw( 60 )  <<'\n'<< setfill( ' ' );
  cout <<setw(30)<< "*MENU PRINCIPAL*\n";
  cout<<" "<<setfill('-')<<setw(41)<<'\n'<<setfill(' ');
  cout <<"|"<<"1."<<setw(40)<<right<<"Ingresar los datos al sistema.|\n";
  cout <<"|"<<"2."<<setw(40)<<"Ordenar notas.|\n";
  cout <<"|"<<"3."<<setw(40)<<"Buscar notas.|\n";
  cout <<"|"<<"0."<<setw(40)<<"Terminar.|\n";
  cout<<" "<<setfill('-')<<setw(41)<<'\n'<<setfill(' ');
  cout<<setw(44)<< "*Opcion: \t*";
  cin >> op;
  return op;
}

int menuOrdenamiento()
{
  int op = -1;
  cout <<setw(30)<< "\t|Formas de Ordenacion|\n\t| para notas finales |\n";
  cout<<" "<<setfill('-')<<setw(26)<<'\n'<<setfill(' ');
  cout <<"|"<<"1."<<setw(25)<<right<<"Quicksort.|\n";
  cout <<"|"<<"2."<<setw(25)<<"HeapSort.|\n";
  cout <<"|"<<"3."<<setw(25)<<"Burbuja.|\n";
  cout <<"|"<<"4."<<setw(25)<<"Merge Sort.|\n";
  cout <<"|"<<"0."<<setw(25)<<"Salir..|\n";
  cout<<" "<<setfill('-')<<setw(26)<<'\n'<<setfill(' ');
  cout<<setw(44)<< "*Opcion: \t*";
  cin >> op;
  return op;
}

int menuBusqueda()
{
  int op = -1;
   cout <<setw(30)<< "\t|Formas de Busqueda|\n\t|para la nota final|\n";
  cout<<" "<<setfill('-')<<setw(26)<<'\n'<<setfill(' ');
  cout <<"|"<<"1."<<setw(25)<<right<<"Lineal.|\n";
  cout <<"|"<<"2."<<setw(25)<<"Binaria.|\n";
  cout <<"|"<<"3."<<setw(25)<<"Interpolacion.|\n";
  cout <<"|"<<"0."<<setw(25)<<"Salir..|\n";
  cout<<" "<<setfill('-')<<setw(26)<<'\n'<<setfill(' ');
  cout<<setw(38)<< "*Opcion: \t*";
  cin >> op;
  return op;
}