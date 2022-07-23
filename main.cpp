/**
 * @file main.cpp
 * @Faustino Vazquez Gabino  (a01369023@tec.mx)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Incluimos las librerias necesarias

#include <iostream>
#include "Video.h"
#include <conio.h>

using namespace std;



int main(){
    // Array con el nombre peliculas que almacenara los constructores de las peliculas a partir de la clase base Video 
    Video *peliculas[3];
    // Array con el nombre series que almacenara los constructores de las peliculas a partir de la clase base Video 
    Video *series[2];
    // Creamos nuestros constructores de las peliculas que quedaran almancenadas en el array peliculas a partir del operador new, especificando que es de la clase derivada Pelicula
    peliculas[0] = new Pelicula("Pelicula","Great Gatsby","Drama",9,2013,122,86);
    peliculas[1] = new Pelicula("Pelicula","Maze Runner","Accion",8,2012,110,12);
    peliculas[2] = new Pelicula("Pelicula","Narnia","Ciencia Ficcion",8,2005,110,46);
    // Creamos nuestros constructores de las series que quedaran almancenadas en el array series a partir del operador new, especificando que es de la clase derivada Serie
    series[0] = new Serie("Serie","Game of Thrones","Ciencia Ficcion",9,2011,55,73);
    series[1] = new Serie("Serie","Breaking Bad","Drama",9,2008,65,62);
    // Creamos un variable int que servira para saber el tamaño de nuestra array de Peliculas 
    int sizeMovies = sizeof(peliculas)/sizeof(peliculas[0]);
    // Creamos un variable int que servira para saber el tamaño de nuestra array de Series 
    int sizeSeries = sizeof(series)/sizeof(series[0]);
    // Variable de tipo int que recibira el valor que el usuario digite dependiendo de la opcion que desee hacer
    int opt;
    // Creamos un ciclo do-while que mostrara el menu hasta que el usuario eliga 3
    do{
        cout << "\n===============================================\n";
        // Le mostramos al usuario las opciones del menu para preguntarle que accion desea hacer
        cout << "Bienvenido al menu de tu servicio de streaming.\nQue desea hacer?\n1)Consultar videos \t2)Calificar video \t3)Salir" << endl; cin >> opt;
        // Sentencia switch que dependiendo del numero escogido, sera la accion que realice 
        switch(opt){
        // Variable que el usuario asignara al numero de serie o video que desee consultar
        int _videoNumber;
        // Variable de tipo int que servira para una sentencia switch para determinar si el usuario desea consultar peliculas o videos
        int serMov;
            // En caso de que opt == 1, se desplegara la opcion de consultar videos
            case 1:
                // Se pregunta al usuario si desea ver series o peliculas, y el valor se usara para la sentencia switch
                cout << "Que tipo de videos desea consultar?\n1)Series\t2)Peliculas\t3)Todos los videos" << endl;cin >> serMov;
                int calification,all;
                switch(serMov){
                    // En caso de que serMov se desplegaran los videos a partir de un ciclo for
                    case 1:
                        // Ciclo for que desplagara la informacion de las series a partir del metodo showData
                        cout << "\nQue series desea consultar? \t1)Todas las series \t2)Series con cierta calificacion" << endl; cin >> all;
                        switch(all){
                            case 1:
                                cout << "\n===========================\nSeries\n==========================\n" << endl;
                                for(int i = 0; i < sizeSeries ; i++){
                                    cout << "\n---------------------------\nSerie " << i + 1 <<" \n---------------------------\n" << endl;
                                    series[i]->showData();
                                }
                                break;
                            case 2:
                                cout << "\nCual es la calificacion de las series que desea consultar?" << endl; cin >> calification;
                                cout << "\n===========================\nSeries\n==========================\n" << endl;
                                for(int i = 0; i < sizeSeries;i++){
                                    if (series[i]->getCalification() == calification){
                                        cout << "\n---------------------------\nSerie " << i + 1 <<" \n---------------------------\n" << endl;
                                        series[i]->showData();
                                    }
                                }
                                break;
                 
                            default:
                                cout << "Opcion no disponible" << endl;
                                break;
                        }
                        break;
                    case 2:
                        cout << "\nQue pelicula desea consultar? \t1)Todas las peliculas \t2)Peliculas con cierta calificacion" << endl; cin >> all;
                        switch(all){
                            case 1:
                                cout << "\n===========================\nPeliculas\n==========================\n" << endl;
                                for(int i = 0; i < sizeMovies ; i++){
                                    cout << "\n---------------------------\nPelicula " << i + 1 <<" \n---------------------------\n" << endl;
                                    peliculas[i]->showData();
                                }
                                break;
                            case 2:
                                cout << "\nCual es la calificacion de las peliculas que desea consultar?" << endl; cin >> calification;
                                cout << "\n===========================\nPeliculas\n==========================\n" << endl;
                                for(int i = 0; i < sizeMovies;i++){
                                    if (peliculas[i]->getCalification() == calification){
                                        cout << "\n---------------------------\nPelicula " << i + 1 <<" \n---------------------------\n" << endl;
                                        peliculas[i]->showData();
                                    }
                                }
                                break;
                            default:
                                cout << "Opcion no disponible" << endl;
                                break;
                        }
                        break;
                        case 3:
                            cout << "\n===========================\nSeries\n==========================\n" << endl;
                            for(int i = 0; i < sizeSeries ; i++){
                                cout << "\n---------------------------\nSerie " << i + 1 <<" \n---------------------------\n" << endl;
                                series[i]->showData();
                            }
                            cout << "\n===========================\nPeliculas\n==========================\n" << endl;
                            for(int i = 0; i < sizeMovies ; i++){
                                cout << "\n---------------------------\nPelicula " << i + 1 <<" \n---------------------------\n" << endl;
                                peliculas[i]->showData();
                                }
                            break;
                    default:
                        // En caso de que digite un numero que no sea 1 o 2 mostrar un mensaje que diga que no existe esa opcion
                        cout << "Opcion no disponible" << endl;
                        break;                                             
                }
                break;
            // Variable int que recibira el valor que el usuario asigne a la calificaccion
            int _rate;
            // En caso de que opt == 2, se desplegara la opcion de calificar videos
            case 2:
                // Se le pedira al usuario que tipo de video desea calificar para despues pasar a la sentencia switch
                cout << "Que tipo de videos desea calificar?\n1)Series\t2)Peliculas" << endl;cin >> serMov;
                switch(serMov){
                    // En caso de que el usuario digite 1, a partir de un ciclo if se mostraran las posibles opciones de series
                    case 1:
                    cout << "\nQue serie desea calificar?" << endl;
                        for(int i = 0; i < sizeSeries ; i++){
                            cout << i + 1 <<")"<< series[i]->getNameVideo() << endl;
                        }
                        // Dependiendo del numero que el usuario digite se cambiara la calificacion que el usuario le asigno 
                        cin >> _videoNumber;
                        cout << "La serie "<< series[_videoNumber-1]->getNameVideo() << " tiene una calificacion de " << series[_videoNumber-1]->getCalification();
                        cout << "\nQue calificacion le desea dar?(1-10)"<< endl; cin >> _rate;
                        // Con un condicional if se revisa si el numero que dio el usuario esta entre 1 y 10, de no ser asi, mostrara un mensaje 
                        if(_rate >= 1 && _rate <= 10){
                            series[_videoNumber-1]->setCalification(_rate);
                            cout << "Ahora la serie " << series[_videoNumber-1]->getNameVideo() << " cuenta con una calificacion de " << _rate << "/10" << endl;
                        }
                        else{
                            cout << "No es un numero entre 1 y 10" << endl;
                        }                        
                        break;
                    // En caso de que el usuario digite 1, a partir de un ciclo if se mostraran las posibles opciones de peliculas
                    case 2:
                    cout << "\nQue pelicula desea calificar?" << endl;
                        for(int i = 0; i < sizeMovies ; i++){
                            cout << i + 1 <<")"<< peliculas[i]->getNameVideo() << endl;
                        }
                        // Dependiendo del numero que el usuario digite se cambiara la calificacion que el usuario le asigno 
                        cin >> _videoNumber;
                        cout << "La pelicula "<< peliculas[_videoNumber-1]->getNameVideo() << " tiene una calificacion de " << peliculas[_videoNumber-1]->getCalification();
                        cout << "\nQue calificacion le desea dar?(1-10)"<< endl; cin >> _rate;
                        // Con un condicional if se revisa si el numero que dio el usuario esta entre 1 y 10, de no ser asi, mostrara un mensaje 
                        if(_rate >= 1 && _rate <= 10){
                            peliculas[_videoNumber-1]->setCalification(_rate);
                            cout << "Ahora la pelicula " << peliculas[_videoNumber-1]->getNameVideo() << " cuenta con una calificacion de " << _rate << "/10" << endl;
                        }

                        else{
                            cout << "No es un numero entre 1 y 10" << endl;
                        }                            
                        break;
                    default:
                        cout << "Opcion no disponible" << endl;
                        break;   
                }
                break;
            case 3:
                break;
            default:
                cout << "Opcion no disponible" << endl;
                break;   
        }
    } while(opt != 3);

    //getch();
    return 0;
}