// Se incluyen las librerias necesarias entre ellas Video.h para poder usar las clases

#include <iostream>
#include "Video.h"
#include <string>

using namespace std;
//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
// Constructores Video

// Constructor a partir de los valores que se asigne el usuario, se asignara a los atributos
Video::Video(string _type, string _name, string _genre , int _calification, int _year , float _duration){
        typeVideo = _type;
        nameVideo = _name;
        genre = _genre;
        calification = _calification; 
        yearRelease = _year; 
        duration = _duration;      
}

// Cnstructor a partir de los valores que se asigne el usuario, se asignara a los atributos excepto CALIFICACION, la cual se asignara 0
Video::Video(string _type, string _name, string _genre , int _year , float _duration){
        typeVideo = _type;
        nameVideo = _name;
        genre = _genre;
        calification = 0; 
        yearRelease = _year; 
        duration = _duration;   
}

//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
// Constructores Pelicula

// Constructor a partir de los valores que se asigne el usuario, se asignara a los atributos heredados de la clase video, incluyendo el numero de nominaciones
Pelicula::Pelicula(string _type, string _name, string _genre , int _calification, int _year , float _duration,int _nominations):Video(_type,_name,_genre,_calification,_year,_duration){
    nominations = _nominations;
}
// Cnstructor a partir de los valores que se asigne el usuario, se asignara a los atributos heredados de clase video excepto CALIFICACION, la cual se asignara 0
//Pelicula::Pelicula(string _type, string _name, string _genre , int _year , float _duration):Video(_type,_name,_genre,_year,_duration){
//}
//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
// Constructores Serie

// Constructor a partir de los valores que se asigne el usuario, se asignara a los atributos heredados de la clase video, incluyendo el numero de Episodios de la serie
Serie::Serie(string _type, string _name, string _genre , int _calification, int _year , float _duration,int _numEpisodes):Video(_type,_name,_genre,_calification,_year,_duration){
    numEpisodes = _numEpisodes;   
}
// Constructor a partir de los valores que se asigne el usuario, se asignara a los atributos heredados de clase video excepto CALIFICACION, la cual se asignara 0
////Serie::Serie(string _type, string _name, string _genre , int _year , float _duration,int):Video(_type,_name,_genre,_year,_duration){   
//}
//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
// Metodos de la clase Video

// Definimos todas las funciones de getters y setters para nuestros atributos de la Clase Video

string Video::getTypeVideo(){
    return typeVideo;
}
void Video::setTypeVideo(string _type){
    typeVideo = _type;
}
string Video::getNameVideo(){
    return nameVideo;
}
void Video::setNameVideo(string _name){
    nameVideo = _name;
}
string Video::getGenre(){
    return genre;
}
void Video::setGenre(string _genre){
    genre = _genre;
}
int Video::getCalification(){
    return calification;
}
void Video::setCalification(int _calification){
    calification = _calification;
}
int Video::getYearRelease(){
    return yearRelease;
}
void Video::setYearRelease(int _year){
    yearRelease = _year;
}
float Video::getDuration(){
    return duration;
}
void Video::setDuration(int _duration){
    duration = _duration;
}

// Funcion calificar video
// Esta funcion recibe un valor int la cual asignara despues a la funcion de setVideo
void Video::rateVideo(int _rate){
    setCalification(_rate);
}

//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
// Metodos de la clase Pelicula

// Definimos todas las funciones de getters y setters para nuestros atributos de la Clase Pelicula

int Pelicula::getNominations(){
    return nominations;
}
void Pelicula::setNominations(int _nominations){
    nominations = _nominations;
}

//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
// Metodos de la clase Serie

// Definimos todas las funciones de getters y setters para nuestros atributos de la Clase Serie

int Serie::getNumEpisodes(){
    return numEpisodes;
}
void Serie::setNumEpisodes(int _numEpisodes){
    numEpisodes = _numEpisodes;
}


// Funcion mostrar datos clase Video
// Esta funcion imprime la informacion de los videos de la clase base Video
void Video::showData(){
    cout << "Tipo: " << typeVideo << "\nNombre: " << nameVideo << "\nGenero: " << genre << "\nCalificacion: " << calification << "/10" << "\nAnio: " << yearRelease << "\nDuration: " << duration << " minutos" << endl;
}

// Funcion mostrar datos clase Serie
// Esta funcion llama al metodo de la clase base showData y despues imprime la informacion del atributo numEpisodes de la clase derivada Serie
void Serie::showData(){
    Video::showData();
    cout << "Numero de capitulos: " << getNumEpisodes() << endl;
}

// Funcion mostrar datos clase Pelicula
// Esta funcion llama al metodo de la clase base showData y despues imprime la informacion del atributo nominations de la clase derivada Pelicula

void Pelicula::showData(){
    Video::showData();
    cout << "Nominaciones: " << getNominations() << endl;
}



