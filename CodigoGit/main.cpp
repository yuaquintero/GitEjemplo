#include <iostream>
#include <Nodo.h>
using namespace std;

int main()
{

    cout<<"Este cambio esta en la nueva rama"<<endl;
    pelicula * raiz=nullptr; //crearmos un nodo vacio
    int opcion=1;
    string titulo, genero;
    int anio;

    while(opcion!=0)
    {
        cout<<"************** CATALOGO DE PELICULAS ******************";
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1. Insertar nueva pelicula"<<endl;
        cout<<"2. Buscar pelicula por titulo"<<endl;
        cout<<"3. Mostrar todo el catalogo"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;

        switch(opcion)
        {

        case 1:
            cout<<"Ingrese el nombre de la pelicula:"<<endl;
            cin>>titulo;
            cout<<"Ingrese el genero: "<<endl;
            cin>>genero;
            cout<<"Ingrese el anio: "<<endl;
            cin>>anio;
            raiz=insertarPelicula(raiz, titulo, genero,anio);
            cout<<"pelicula insertada con exito"<<endl;
            break;

        case 2:
        {
            cout<<"Ingrese el nombre de la pelicula a buscar"<<endl;
            cin>>titulo;
            pelicula* peliculaEncontrada=BuscarPelicula(raiz, titulo);
            if(peliculaEncontrada)
                cout<<"Encontrada:  "<<peliculaEncontrada->titulo<<" ("<<peliculaEncontrada->anio<<") -"
                     <<peliculaEncontrada->genero<<endl;
            else
                cout<<"Titulo no encontrado"<<endl;
        }
        break;

        case 3:
        {
            cout<<"\nCatalogo completo: \n"<<endl;
            MostrarCatalogo(raiz);
            break;
        }
        default:
            if(opcion!=0)
                cout <<"Opcion no valida"<<endl;
            break;
        }
    }

    return 0;
}
