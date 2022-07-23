#ifndef _VIDEO_H_
#define _VIDEO_H_

//Incluimos la libreria string para poder utilizar la variable string
#include <string>
#include <vector>

//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------

// Clase base con el nombre "Video", esta sera la clase de la cual saldran las clases derivadas
class Video{
    protected:
        // Atributos
        // Definimos los atributos con los que trabajaremos
        std::string typeVideo;
        std::string nameVideo;
        std::string genre;
        int calification;
        int yearRelease;
        float duration;
    public:
        // Constructores
        // Constructor 1- Este constructor tendra todos los atributos que se definieron
        Video(std::string _type, std::string _name, std::string _genre , int _calification, int _year , float _duration);

        // Constructor 2- Este constructor tendra todos los atributos que se definieron excepto calificacion(Instrucciones de la entrega 1)
        Video(std::string _type, std::string _name, std::string _genre , int _year , float _duration);

        // Definimos los metodos con los que trabajaremos
        // Getters y setter de cada atributo
        std::string getTypeVideo();
        void setTypeVideo(std::string _type);

        std::string getNameVideo();
        void setNameVideo(std::string _name);

        std::string getGenre();
        void setGenre(std::string _genre);

        int getCalification();
        void setCalification(int _calification);

        int getYearRelease();
        void setYearRelease(int _year);

        float getDuration();
        void setDuration(int _duration);

        // Funciones de calificar video y mostrar datos
        void rateVideo(int _rate);
        // Se usa la funcion virtual para hacer poliformismo ya que usaremos una funcion del mismo nombre para las clases derivadas
        virtual void showData();
};
//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------

// Primer clase derivada con el nombre  "Pelicula" para los videos de peliculas
class Pelicula:public Video{
    private:
        int nominations;
    public:
        // Constructores
        // Constructor 1- Este constructor tendra todos los atributos que se definieron en la clase base
        Pelicula(std::string _type, std::string _name, std::string _gender , int _calification, int _year , float _duration,int _nominations);
        // Constructor 2- Este constructor tendra todos los atributos que se definieron en la clase base excepto calificacion(Instrucciones de la entrega 1)
        Pelicula(std::string _type, std::string _name, std::string _gender , int _year , float _duration);

        // Definimos los metodos con los que trabajaremos
        // Getters y setter de cada atributo
        int getNominations();
        void setNominations(int _nominations);

        // Metodo para mostrar la informacion de la clase derivada Pelicula
        void showData();
};

//================================================================================================================================================
//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------

// Segunda clase derivada con el nombre  "Serie"  para los videos de series
class Serie:public Video{
    private:
        int numEpisodes;
    public:
        // Constructores
        // Constructor 1- Este constructor tendra todos los atributos que se definieron en la clase base
        Serie(std::string _type, std::string _name, std::string _gender , int _calification, int _year , float _duration,int _numEpisodes);
        // Constructor 2- Este constructor tendra todos los atributos que se definieron en la clase base excepto calificacion(Instrucciones de la entrega 1)
        Serie(std::string _type, std::string _name, std::string _gender , int _year , float _duration);

        // Definimos los metodos con los que trabajaremos
        // Getters y setter de cada atributo
        int getNumEpisodes();
        void setNumEpisodes(int _numEpisodes);

        // Metodo para mostrar la informacion de la clase derivada Serie
        void showData();

};

#endif