
#include <iostream>
#include <fstream>
#include <string.h>
#include<iomanip>
#include"Datos.h"
using namespace std;
double notass[100];//arreglo para luego ordenar 
 int contador1=0;//creamos el contador
 int contador2=0;
 int contBase=0;
 int Cnotas;
int Cestudiantes;







//aquie trabajamos la estructura

void ingresar (tLista &lista, tEstudiante estudiante){
  string profe, materia;
  int  validNota, aprovados = 0, reprovados = 0, suspensos = 0;
  double suma = 0,sumat = 0, promedio = 0;
  ofstream Drago,Base,Base_es;
  
  Drago.open("Datos EPN.txt", ios::app);
  Drago << setw(40) << "COLEGIO MEJIA\n";
  Drago << setw(45) << "Reporte de Calificaciones\n\n";
  cin.ignore();
  cout << "Nombre profesor : ";
  getline(cin, profe);
  Base << profe << "\n";
  //Drago << "Nombre del profesor : " << profe <<endl;
  cout << "\nMateria : ";
  cin >> materia;
  Base << materia << "\n";
  Drago << "----------------------------------------------------------------------------"<< endl;
  Drago << "Anio Lectivo : 2020-2021"<< endl;
  Drago << "----------------------------------------------------------------------------"<< endl;
  Drago << "Materia : " << materia <<endl;
  Drago << "----------------------------------------------------------------------------"<< endl;
  cout << "Digite el numero de estudiantes : ";
  cin >> Cestudiantes;

  
  //Drago << "Numero de estudiantes : " << Cestudiantes <<endl;
  cout << "Digite el numero de notas : ";
  cin >> Cnotas;
  
  
  //Drago << "Numero de notas : " << Cnotas <<endl;
  Drago << "|N°-|"<< setw(10)<<left <<"Nombre   |"<< setw(10)<<left <<"Apellido |" <<"Correo"<<  setw(24)<<right << "|"<<" ";
  for (int x =0; x < Cnotas ;x++){
    Drago <<"Nota "<< x+1<<"|";
  }
  Drago << "Total |\n";
  Drago << "----------------------------------------------------------------------------"<< endl;
  for (int i = 0; i < Cestudiantes; i++){
    cout << "\nNombre del estudiante "<< i+1<<" : ";
    cin >> lista.a[i].nombre;
    
    Drago << "|"<< i+1 << "|"<< setw(10)<<left << lista.a[i].nombre << "|";
    cout << "\nApellido del estudiante "<< i+1<<" : ";
    cin >> lista.a[i].apellido;
    
    Drago << setw(10)<<left << lista.a[i].apellido << "|";
    cout << "\nCorreo de estudiante "<< i+1<<" : ";
    cin >> lista.a[i].correo;
    
    Drago << setw(30)<<left << lista.a[i].correo << "|";
    for (int j = 0; j < Cnotas; j++){
      do{

        cout << "\nIngrese nota "<< j+1<<" : ";
        cin >> validNota;

        if (validNota <0 || validNota > 20){
          cout <<"Nota fuera del rango de 0 - 20\n";
        }
        else {
          lista.a[i].notas[j] = validNota;
        }

      }while(validNota <0 || validNota > 20);
      Drago << setw(6)<<left << lista.a[i].notas[j] << "|";
      suma = suma + lista.a[i].notas[j];
    }
    lista.a[i].total = suma / Cnotas;
    if (lista.a[i].total >=14){
      aprovados ++;
    }
    if (lista.a[i].total <14 && lista.a[i].total >= 9){
      suspensos++;
    }
    if (lista.a[i].total <9 && lista.a[i].total >= 0){
      reprovados++;
    }
    //creamos el arreglo 
    notass[contador1]= lista.a[i].total = suma / Cnotas;
    contador1++;
    
    Drago<< setw(6)<<left <<setprecision(3) << lista.a[i].total<< "|";
    
    suma = 0;
    Drago << "\n----------------------------------------------------------------------------"<< endl;
    sumat = sumat + lista.a[i].total;
  }
  promedio = sumat / Cestudiantes;
  Drago << "         Aprovados |\t\t\t "<<aprovados;
  Drago << "\n----------------------------------------------------------------------------"<< endl;
  Drago << "         Suspensos |\t\t\t "<<suspensos;
  Drago << "\n----------------------------------------------------------------------------"<< endl;
  Drago << "         Reprovados|\t\t\t "<< reprovados;
  Drago << "\n----------------------------------------------------------------------------"<< endl;
  Drago << "Promedio del curso |\t\t\t"<<setprecision(3) << promedio<< endl;
  Drago << "\n----------------------------------------------------------------------------"<< endl;
  Drago << "Profesor           |\t\t\t"<< profe;
  Base << endl << -1;

  Drago.close();
 

  

}
///modificado
//opcion 4 donde presenta  los datos del estudiante
void datos(tLista &lista, tEstudiante estudiante){
  int  validNota, aprovados = 0, reprovados = 0, suspensos = 0;
  double suma =0;
  cout<<"\n********************************************\n";
  cout <<"\nLISTA DE ESTUDIANTES\n";
  for (int i = 0; i < Cestudiantes; i++){

    cout << "|"<< i+1 << "|"<<left << lista.a[i].nombre << "|"<< lista.a[i].apellido;
    
    if (lista.a[i].total >=14){
      cout<<setw(15)<<" " <<"A : "<<lista.a[i].total;
     cout<<endl;
    }
    if (lista.a[i].total <14 && lista.a[i].total >= 9){
      cout<<setw(10) <<" "<<"S:"<<lista.a[i].total;
      cout<<endl;
    }
    if (lista.a[i].total <9 && lista.a[i].total >= 0){
      cout<<setw(10)<<" " <<"R"<<lista.a[i].total;
      cout<<endl;
    }
    cout <<"\n";
    
   
    
   
}
cout<<"\n********************************************\n";
}

//tipos de ordenamientos 
void ordenamiento_quik()
{  ofstream ordenamiento;
ordenamiento.open("ordenamiento.txt",ios::app);
  cout <<"\nNotas finales Ordenadas  por Quicksort\n";
  ordenamiento <<"\nNotas finales Ordenadas  por Quicksort\n";
  ordenar(notass,0,contador1-1);
  for (int p=0;p<contador1;p++)
 {
   cout <<"  |  " <<notass[p] << "  |"  ;
   ordenamiento <<"  |  "<< notass[p]<<"  |  " ;
  }
  cout <<endl;
  ordenamiento.close ();
}
void ordenamiento_Heapsort()
{  ofstream ordenamiento;
ordenamiento.open("ordenamiento.txt",ios::app);
  cout <<"\nNotas finales Ordenadas  por HeapSort\n";
  ordenamiento <<"\nNotas finales Ordenadas  por HeapSort\n";
  heapSort(notass,contador1-1);
  for (int p=0;p<contador1;p++)
 {
   cout <<"  |  " <<notass[p] << "  |"  ;
   ordenamiento <<"  |  "<< notass[p]<<"  |  " ;
  }
  cout <<endl;
  ordenamiento.close ();
}

void ordenamiento_Burbuja()///
{  ofstream ordenamiento;
ordenamiento.open("ordenamiento.txt",ios::app);
  cout <<"\nNotas finales Ordenadas  por Burbuja\n";
  ordenamiento <<"\nNotas finales Ordenadas  por Burbuja\n";
  ordenar_burbuja (notass,contador1-1);
  for (int p=0;p<contador1;p++)
 {
   cout <<"  |  " <<notass[p] << "  |"  ;
   ordenamiento <<"  |  "<< notass[p]<<"  |  " ;
  }
  cout <<endl;
  ordenamiento.close ();
}


void ordenamiento_mergesort()
{  ofstream ordenamiento;
ordenamiento.open("ordenamiento.txt",ios::app);
  cout <<"\nNotas finales Ordenadas  por mergesort\n";
  ordenamiento <<"\nNotas finales Ordenadas  por mergesort\n";
  orden_mergesort(notass,0,contador1-1);
  for (int p=0;p<contador1;p++)
 {
   cout <<"  |  " <<notass[p] << "  |"  ;
   ordenamiento <<"  |  "<< notass[p]<<"  |  " ;
  }
  cout <<endl;
  ordenamiento.close ();
}


//ordenamiento de Quicksort
double mitad (double arr[], int pinicial,  int pfinal)
{

    return arr[(pinicial+pfinal)/2];


}
void ordenar(double arr[], int pinicial, int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    double temp;
    double piv=mitad(arr,pinicial,pfinal);

    do
    {
        while(arr[i]<piv)
        {
            i++;
        }
        while(arr[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }

    }
    while(i<=j);

    if(pinicial<j)
        ordenar(arr,pinicial,j);
    if(i<pfinal)
        ordenar(arr,i,pfinal);
}




void heapSort(double b[], int n)
{
   int  a;
   double temp,valor;

    for(int i=n; i>0; i--)
    {
        for(int j=1; j<=i; j++)
        {
            valor=b[j];
            a=j/2;
            while(a>0 && b[a]<valor)
            {
                b[j]=b[a];
                j=a;
                a=a/2;
            }
            b[j]=valor;
        }
        temp=b[1];
        b[1]=b[i];
        b[i]=temp;
    }
}

void ordenar_burbuja(double notas [],int arreglo){
  
 int  i, j, aux;
  for ( i=0;i<contador1;i++){
    for (j=i+1;j<contador1;j++){
      if (notas[j]<notas[i]){
        aux =notas[i];
        notas [i]=notas[j];
        notas [j]=aux;
      }
    }
  }

}
/////////////////

void orden_mergesort(double Elementos[],int inicial,int final)
{
  int Mitad;
  if(inicial<final)
  {
    Mitad =(final+inicial)/2;
    orden_mergesort(Elementos, inicial,Mitad);
    orden_mergesort(Elementos, Mitad+1,final);
    Fucionar(Elementos,inicial,final,Mitad);
  }
}
void Fucionar(double Elementos[],int pinicial,int pfinal, int medio)
{
  int i,j;
  int k;
  double temp[pfinal-pinicial+1];
  i=pinicial;
  k=0;
  j=medio+1;

  while(i<=medio && j<=pfinal)
  {
    if(Elementos[i]<Elementos[j])
    {
      temp[k]=Elementos[i];
      k++;
      i++;
    }else
    {
      temp[k]=Elementos[j];
      k++;
      j++;
    }
  }
  while(i<=medio)
  {
    temp[k]=Elementos[i];
    k++;
    i++;
  }
  while(j<=pfinal)
  {
    temp[k]=Elementos[j];
    j++;
    k++;
  }
  for(i=pinicial;i<=pfinal;i++)
  {
    Elementos[i]=temp[i-pinicial];
  }

}

//Imprimir 

//Algoritmos de Busquedas

int Busqueda_Lineal(tLista lista, int nota)
{
 

  for(int i=0;i<50;i++)
  {
    for(int j=0;j<50;j++)
    {
      if(lista.a[i].notas[j]==nota)
    {
      //Imprime la busqueda
      cout << "\n\t\tBusqueda lineal\n_________________________________________\n"; 
       cout << "La calificaicon a buscar fue: " << lista.a[i].notas[j]<< endl;
      cout << "Correspondiente al estudiante:\n";
      cout << lista.a[i].nombre << " " << lista.a[i].apellido << " " << lista.a[i].correo << endl;
      cout << "_________________________________________\n\n";
      if(lista.a[i].total>=14)
      {
        cout << "Promedio Final: " << lista.a[i].total << " Aprovador\n";

      }else if(lista.a[i].total>=9 && lista.a[i].total<14)
      {
        cout << "Promedio Final: " << lista.a[i].total << " Supletorio\n";
      }else if(lista.a[i].total<9)
      {
        cout << "Promedio Final: " << lista.a[i].total << " Reprobado\n";
      }

      cout << "\n_________________________________________\n";

      return 0;

    }
    }

  }
  return -1;
}

//Busqueda Binaria
void ordenamiento_bina(tLista lista,int k )
{
  int temp;
  for(int i=0;i<Cnotas;i++)
  {   
   for (int j=i+1 ; j< Cnotas ; j++)
   {
    if (lista.a[k].notas[i] > lista.a[k].notas[j])
    { temp = lista.a[k].notas[i];
      lista.a[k].notas[i] = lista.a[k].notas[j];
      lista.a[k].notas[j] = temp;}
    }
 
  }

}

void Busqueda_Binaria(tLista lista, int nota)
{


  int n, i,j=0, primero, ultimo, medio;

    primero=0;
    ultimo=Cnotas-1;
    medio = (primero+ultimo)/2;
   for(j=0;j<Cestudiantes;j++)
   {
     ordenamiento_bina(lista,j);

     primero=0;
     ultimo=Cnotas-1;
     medio = (primero+ultimo)/2;
     while (primero<=ultimo)
    {
        
        if (lista.a[j].notas[medio]< nota)
          {
            primero=medio+1;

          }else if (lista.a[j].notas[medio] == nota ) 
          {
            //Imprime la busqueda
            cout << "\n\t\tBusqueda Binaria\n_________________________________________\n"; 
            cout << "La calificaicon a buscar fue: " << lista.a[j].notas[medio]<< endl;
            cout << "Correspondiente al estudiante:\n";
           cout << lista.a[j].nombre << " " << lista.a[j].apellido << " " << lista.a[j].correo << endl;
           cout << "_________________________________________\n\n";
            if(lista.a[i].total>=14)
              {
                cout << "Promedio Final: " << lista.a[j].total << " Aprovador\n";

              }else if(lista.a[j].total>=9 && lista.a[j].total<14)
              {
                cout << "Promedio Final: " << lista.a[j].total << " Supletorio\n";
              }else if(lista.a[j].total<9)
              {
                cout << "Promedio Final: " << lista.a[j].total << " Reprobado\n";
              }

              cout << "\n_________________________________________\n";

            break;
          }
          else {
            ultimo = medio - 1;
          }

          medio = (primero+ultimo)/2;
          
        
        
    }
    }
    if (primero>ultimo)
    {
        cout <<"\tNota no encontrada\n";
    }

    

    
}
//busqueda por interpolacion
int Bus_Interpo(tLista lista, int nota)
{
 
  for(int j=0;j<Cestudiantes;j++)
  {
    int primero = 0;
    int ultimo = Cnotas-1;
    int medio;
    int cont=0; 
    while(lista.a[j].notas[primero] != nota && cont<=7 )
      {
          
       medio = /*0*/primero + ((nota /*9*/- lista.a[j].notas[primero]/*10*/)*(ultimo/*2*/-primero/*0*/))/(lista.a[j].notas[ultimo]/*8*/-lista.a[j].notas[primero]/*10*/);
    

      if(lista.a[j].notas[medio]<nota)
      
          primero = medio +1;
         
      else if(lista.a[j].notas[medio]>nota)
      
          ultimo = medio-1;

      else 
          primero = medio;

       cont++;
 
      }
      //Imprime la busqueda
 if(lista.a[j].notas[primero]== nota){
    cout << "\n\tBusqueda por Interpolacion\n_________________________________________\n"; 
       cout << "La calificaicon a buscar fue: " << lista.a[j].notas[primero]<< endl;
      cout << "Correspondiente al estudiante:\n";
      cout << lista.a[j].nombre << " " << lista.a[j].apellido << " " << lista.a[j].correo << endl;
      cout << "_________________________________________\n\n";
      if(lista.a[j].total>=14)
      {
        cout << "Promedio Final: " << lista.a[j].total << " Aprovador\n";

      }else if(lista.a[j].total>=9 && lista.a[j].total<14)
      {
        cout << "Promedio Final: " << lista.a[j].total << " Supletorio\n";
      }else if(lista.a[j].total<9)
      {
        cout << "Promedio Final: " << lista.a[j].total << " Reprobado\n";
      }

      cout << "\n_________________________________________\n";
}
 
 
}
return 0;
}