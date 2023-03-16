//Autor: Daniela Torres Gómez - Nicolás Arciniegas  
//Fecha: 21 de febrero 2023
//Problema: JaveMusic es un programa que permite al usuario manejar y acceder a la música que tiene almacenada, además que le permite adicionar, eliminar y editar las canciones que éste tiene guardadas. Adicionalmente, le permite al usuario realizar búsquedas de sus canciones de múltiples formas, bien sea por su título, artista, género o por el álbum al que está asociada. Finalmente, el sistema permite registrar información adicional para las canciones, como su duración y la clasificación que el usuario le asigna.

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream> //funcion split de string
#include <vector>
#include <algorithm>


using namespace std;


struct JaveMusic{
 string nombreCancion;
 string autor;
 string genero;
 string nombreAlbum;
 string year;
};
struct sub_consulta{
 string nameSong;
 string nameAlbum;
};
struct sub_consulta2{
 string nameAlbum;
 string year;
};

void escribir();
void obtener_canciones(vector<JaveMusic> &lista_canciones); 
void listar_autores(vector<JaveMusic> &lista_canciones);
void listar_canciones_por_autor(vector<JaveMusic> &lista_canciones);
void listar_albumes(vector<JaveMusic> &lista_canciones);
void listar_canciones_por_albumes(vector<JaveMusic> &lista_canciones);
void listar_canciones_y_album(vector<JaveMusic> &lista_canciones);

int main () {
 vector<JaveMusic> lista_canciones;
  obtener_canciones(lista_canciones);
  /*for(int i=0;i<23;i++)
cout<<lista_canciones[i].nombreCancion<<lista_canciones[i].autor<<lista_canciones[i].genero<<lista_canciones[i].nombreAlbum<<lista_canciones[i].year<<endl; */ // DEBUGEO
//Lamado de la función "escribir"
// escribir();
//Creación del menú de opciones para el usuario 

  int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Listar todos los autores presentes, ordenados alfabéticamente" << endl;
        cout << "2. Dado un autor, listar todas sus canciones alfabéticamente" << endl;
        cout << "3. Listar todos los álbumes presentes, ordenados cronológicamente " << endl;
        cout << "4. Dado un álbum, listar todas las canciones ordenadas alfabéticamente" << endl;
        cout << "5. Listar todas las canciones y su álbum, ordenadas alfabéticamente primero por el álbum y después por el nombre de la canción" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // Lista de instrucciones de la opción 1
                listar_autores(lista_canciones);
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                // Lista de instrucciones de la opción 2  
                listar_canciones_por_autor(lista_canciones);
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                // Lista de instrucciones de la opción 3
                listar_albumes(lista_canciones);
                system("pause>nul"); // Pausa            
                break;
                
            case 4:
                // Lista de instrucciones de la opción 4    
                listar_canciones_por_albumes(lista_canciones);
                system("pause>nul"); // Pausa                
                break;
            case 5:
                // Lista de instrucciones de la opción 5 
                listar_canciones_y_album(lista_canciones);
                system("pause>nul"); // Pausa                
                break;
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
	 
    return 0;



  return 0; 
}

void escribir(){
  ofstream fichero;

  fichero.open("canciones.txt",ios::out);
  if(fichero.fail()){
    cout<<"No se pudo abrir el archivo";
    
  }
  fichero<<"";
}


void obtener_canciones(vector<JaveMusic> &lista_canciones){
ifstream fichero ("example5P.txt"); 
fstream fichero_aux("otro_auxiliar.txt");
  string aux, line, linea_aux, linea_aux2;
  int Ncanciones;
  int aux2=0;
  vector<string> vector_aux;
  vector<string> vector_aux2;
  JaveMusic auxiliar3;
  if (fichero.is_open()) {
    getline(fichero,aux);
    Ncanciones= stoi(aux);
  //  cout<<Ncanciones<<endl;

    while ( getline (fichero,line) ) {//sacar todas las demas canciones
      vector_aux.push_back(line);
      
  }
    
  //  for(vector< string >::iterator it = vector_aux.begin( );it != vector_aux.end( );it++)
  //    cout<<*it<<endl;
      //hasta aca bien
    
    for(int i=0;i<Ncanciones;i++){
      linea_aux=vector_aux[i];
      stringstream cancion(linea_aux); 
      while (getline(cancion, linea_aux2, '|')){
        vector_aux2.push_back(linea_aux2);
      }
      auxiliar3.nombreCancion=vector_aux2[0];
      auxiliar3.autor=vector_aux2[1];
      auxiliar3.genero=vector_aux2[2];
      auxiliar3.nombreAlbum=vector_aux2[3];
      auxiliar3.year=vector_aux2[4];
  //    cout<<vector_aux2[0]<<" "<<vector_aux2[1]<<" "<<vector_aux2[2]<<" "<<vector_aux2[3]<<" "<<vector_aux2[4]<<endl;
      lista_canciones.push_back(auxiliar3);
      vector_aux2.clear();
      }  
fichero.close(); }
  
else cout <<"Unable to open file";
  
};
void listar_autores(vector<JaveMusic> &lista_canciones){
  bool repetido=false;
  vector<string> Lista_autores;
  for (JaveMusic autores: lista_canciones){
    repetido=false;
    for(vector< string >::iterator it = Lista_autores.begin( );it != Lista_autores.end( );it++){
     if(autores.autor==*it) repetido=true;
    }
    if(repetido==false) Lista_autores.push_back(autores.autor);
    }  
  sort(Lista_autores.begin(),Lista_autores.end()); 
  for(string autt:Lista_autores)
    cout<<autt<<endl;
};

void listar_canciones_por_autor(vector<JaveMusic> &lista_canciones){

    bool repetido=false;
  vector<string> Lista_autores;
  vector<string> cancionesXautor;
  for (JaveMusic autores: lista_canciones){
    repetido=false;
    for(vector< string >::iterator it = Lista_autores.begin( );it != Lista_autores.end( );it++){
     if(autores.autor==*it) repetido=true;
    }
    if(repetido==false) Lista_autores.push_back(autores.autor);
    }  
  sort(Lista_autores.begin(),Lista_autores.end()); 
  for(string autt:Lista_autores){
    cout<<"AUTOR: "<<autt<<endl;
    for(int i=0;i<lista_canciones.size();i++){
      if(autt==lista_canciones[i].autor)
        cancionesXautor.push_back(lista_canciones[i].nombreCancion);
    }
    sort(cancionesXautor.begin(),cancionesXautor.end());
    for(string song:cancionesXautor)
      cout<<"   "<<song<<endl;
    cancionesXautor.clear();
    }
  
};
void listar_albumes(vector<JaveMusic> &lista_canciones){
    bool repetido=false;
    bool repetido2=false;
  vector<string> albumes;
  vector<sub_consulta2> albumXyear;
  sub_consulta2 temporal;
  for (JaveMusic album: lista_canciones){
    repetido=false;
    for(vector< string >::iterator it = albumes.begin( );it != albumes.end( );it++){
     if(album.nombreAlbum==*it) repetido=true;
    }
    if(repetido==false) albumes.push_back(album.nombreAlbum);
    }
  
/*  for (string album:albumes)
    cout<<album<<endl; */
  for (string album:albumes){
    for(JaveMusic canciones: lista_canciones){
      repetido2=false;
      if(album==canciones.nombreAlbum){
        temporal.nameAlbum=album;
        temporal.year=canciones.year;
        for(sub_consulta2 aXy:albumXyear){
          if((aXy.nameAlbum==temporal.nameAlbum)&&(aXy.year==temporal.year))
            repetido2=true;
        }
        if(repetido2!=true) 
        albumXyear.push_back(temporal);
      }
    };
  };
 /* for(sub_consulta2 aXy:albumXyear){
    cout<< aXy.nameAlbum<<" "<<aXy.year<<endl;
    }*/
  for(int i=0;i<albumXyear.size();i++){
    for(int j=0;j<albumXyear.size();j++){
      if(albumXyear[i].year<albumXyear[j].year){
        temporal=albumXyear[i];
        albumXyear[i]=albumXyear[j];
        albumXyear[j]=temporal;
      }
    }
  }
 // cout<<"aca"<<endl;
  for(sub_consulta2 aXy:albumXyear){
    cout<< aXy.nameAlbum<<" "<<aXy.year<<endl;
    }
};


void listar_canciones_por_albumes(vector<JaveMusic> &lista_canciones){
    bool repetido=false;
  vector<string> albumes;
  vector<string> cancionesXalbum;
  for (JaveMusic album: lista_canciones){
    repetido=false;
    for(vector< string >::iterator it = albumes.begin( );it != albumes.end( );it++){
     if(album.nombreAlbum==*it) repetido=true;
    }
    if(repetido==false) albumes.push_back(album.nombreAlbum);
    }
  for(string album: albumes){
    cout<<"ALBUM: "<<album<<endl;
    for(int i=0;i<lista_canciones.size();i++){
      if(album==lista_canciones[i].nombreAlbum)
        cancionesXalbum.push_back(lista_canciones[i].nombreCancion);
    }
    sort(cancionesXalbum.begin(),cancionesXalbum.end());
    for(string cXa: cancionesXalbum)
      cout<<"  "<<cXa<<endl;
    cancionesXalbum.clear();
    
  }
  
};
void listar_canciones_y_album(vector<JaveMusic> &lista_canciones){
  vector<sub_consulta> auxiliar;
  sub_consulta temporal;
  vector<string> albumXnombre;
  string junta;
  for(JaveMusic list:lista_canciones){
    temporal.nameAlbum=list.nombreAlbum;
    temporal.nameSong=list.nombreCancion;
    auxiliar.push_back(temporal);
  }
  for(sub_consulta lst:auxiliar){
    //cout<<lst.nameAlbum<<" "<<lst.nameSong<<endl;
    junta="";
    junta.append(lst.nameAlbum).append(" ").append(lst.nameSong);
    albumXnombre.push_back(junta);
    }
  sort(albumXnombre.begin(),albumXnombre.end());
  for(string aXn: albumXnombre)
    cout<<aXn<<endl;
  
};