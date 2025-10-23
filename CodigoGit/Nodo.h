#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>

using namespace std;


//representa el nodo de tipo
struct pelicula {
    string titulo;
    string genero;
    int anio;
    pelicula* izquierda;
    pelicula* derecha;
};
//crea una nodo de tipo de pelicula
pelicula* crearNodo(string titulo, string genero, int anio){
    pelicula* nueva= new pelicula();
    nueva->titulo=titulo;
    nueva->genero=genero;
    nueva->anio=anio;
    nueva->izquierda=nullptr;
    nueva->derecha=nullptr;

    return nueva;
}
//inserta un nuevo nodo en el arbol tomando la decision si es izquierda o derecha
pelicula* insertarPelicula(pelicula* raiz,string titulo, string genero, int anio)
{
    if(raiz==nullptr)
        return crearNodo(titulo,genero, anio);
    else{
        if(titulo<raiz->titulo)
            raiz->izquierda=insertarPelicula(raiz->izquierda,titulo,genero, anio);
        else
            raiz->derecha=insertarPelicula(raiz->derecha,titulo,genero, anio);

        return raiz;
    }

}
//buscar la pelicula por el titulo, realizando llamados recursivos de la función BuscarPelicula
pelicula* BuscarPelicula(pelicula* raiz, string titulo){

    if(raiz==nullptr || raiz->titulo==titulo)
        return raiz;
    if(titulo<raiz->titulo)
        return BuscarPelicula(raiz->izquierda, titulo);
    else
        return BuscarPelicula(raiz->derecha, titulo);
}

//recorrido inorden (recorrido del arbol)
void MostrarCatalogo(pelicula* raiz)
{
    if(raiz!=nullptr){
        MostrarCatalogo(raiz->izquierda);
        cout<<raiz->titulo<<" ("<<raiz->anio<<") - "<<raiz->genero<<endl;
        MostrarCatalogo(raiz->derecha);
    }
}

#endif // NODO_H
