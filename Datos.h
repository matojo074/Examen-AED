#ifndef Datos_h
#define Datos_h
#include <iostream>
#include <fstream>
#include <string.h>
#include<iomanip>
using namespace std;




typedef struct {
  string nombre;
  string apellido;
  string correo;
  int notas [10]={0};
  double total;
}tEstudiante;



typedef struct{
  tEstudiante a[50];
}tLista;












void datos(tLista &lista, tEstudiante estudiante);
void ingresar (tLista &lista, tEstudiante estudiante);
void ordenamiento_quik();
void ordenamiento_Heapsort();
void ordenamiento_Burbuja();
void ordenamiento_mergesort();
void ordenar_burbuja(double notas [],int arreglo);
void heapSort(double b[], int n);
void ordenar(double arr[], int pinicial, int pfinal);

double mitad (double arr[], int pinicial,  int pfinal);
void Fucionar(double Elementos[],int pinicial,int pfinal, int medio);
void orden_mergesort(double Elementos[],int inicial,int final);
//Busquedas
int Busqueda_Lineal(tLista lista, int nota);

void Busqueda_Binaria(tLista lista, int nota);

int Bus_Interpo(tLista lista, int nota);

#endif