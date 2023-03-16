//Autor: Daniela Torres Gómez - Nicolás Arciniegas
//Fecha: 22 de febrero 2023
//Problema: JaveMusic es un programa que permite al usuario manejar y acceder a la música que tiene almacenada, además que le permite adicionar, eliminar y editar las canciones que éste tiene guardadas. Adicionalmente, le permite al usuario realizar búsquedas de sus canciones de múltiples formas, bien sea por su título, artista, género o por el álbum al que está asociada. Finalmente, el sistema permite registrar información adicional para las canciones, como su duración y la clasificación que el usuario le asigna.

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream> //funcion split de string

using namespace std;


struct JaveMusic{
 int numCanciones[300];
 string nombreCancion;
 string autor;
 string genero;
 string nombreAlbum;
 int year;
};

void escribir();
void obtener_canciones(string *lista_canciones); //funcion de tipo int para que retorne el numero de canciones
void separar_informacion(string *lista_canciones, int num_canciones);
int sacar_num_canciones();
void listar_autores();

int main () {
string *lista_canciones;
int num_canciones;
num_canciones=sacar_num_canciones();
  cout<<num_canciones<<"este es Nico"<<endl;
  lista_canciones = new string[num_canciones];
obtener_canciones(lista_canciones);
  for(int i=0;i<num_canciones;i++)
    cout<<lista_canciones[i];
// separar_informacion(lista_canciones, num_canciones);

  


//list
delete [] lista_canciones;
  return 0; 
}

/*void escribir(){
  ofstream fichero;

  fichero.open("canciones.txt",ios::out);
  if(fichero.fail()){
    cout<<"No se pudo abrir el archivo";
    
  }
  fichero<<"";
}
*/

void obtener_canciones(string *lista_canciones){
  string line, Ncanciones;
  int aux, aux2;
  aux2=0;
ifstream fichero ("example1.txt"); 
  if (fichero.is_open()) {
    getline(fichero,Ncanciones);
    aux= stoi(Ncanciones);
    lista_canciones = new string[aux];
     while ( getline (fichero,line) ) {
      cout << line << "\n";
      *(lista_canciones+aux2)=line;
       cout<<*(lista_canciones+aux2)<<endl;
       aux2=aux2+1;
} // cout<<"fin while"<<endl; //para debugeo manual
   /* for(int i=0;i<aux;i++)
      cout<<lista_canciones[i]<<endl; */ // mas debugeo
fichero.close(); }
else cout <<"Unable to open file";

};

void separar_informacion(string *lista_canciones, int num_canciones){
string line, line_aux;
  // cout<<"prueba2"<<endl;
   cout<<*lista_canciones<<endl;
  for(int i=0;i<num_canciones;i++){
    cout<<*lista_canciones<<endl;
    stringstream info_cancion(lista_canciones[i]);                    // Convertir la cadena a un stream
    while( getline( info_cancion, line,'|')){
      cout<<line<<"  ";}
    cout<<"siguiente cancion"<<endl;
    }

};

int sacar_num_canciones(){
  int Ncanciones;
  string aux;
  ifstream fichero ("example1.txt"); 
  if (fichero.is_open()) {
    getline(fichero,aux);
    Ncanciones= stoi(aux);
    fichero.close();
    }
  else cout <<"Unable to open file";
return Ncanciones;
  };

void listar_autores(){
  
}

/* PARA EVITAR PERDERLA MIENTRAS LA MODIFICO EN EL CODIGO
  std::string line;
std::ifstream fichero ("example1P.txt"); 
  if (fichero.is_open()) {
    while ( getline (fichero,line) ) {
      std::cout << line << "\n";
}
fichero.close(); }
else std::cout <<"Unable to open file";
*/