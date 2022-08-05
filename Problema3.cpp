#include <iostream>

template<class T>
class Contenedor
{
    T elemento;
public:
    Contenedor(T arg)
    {
        elemento = arg;
    }
    T add(){return ++elemento;}
};

template<>
class Contenedor<char>
{
    char elemento;
public:
    Contenedor(char arg)
    {
        elemento = arg;
    }
    char uppercarse()
    {
        if ((elemento >= 'a') && (elemento <= 'z'))
        {
            elemento += 'A'-'a';
            return elemento;
        }
    }
};

int main()
{
    Contenedor<int> cint (5);
    Contenedor<char> cchar('t');
    std::cout<<cint.add()<<std::endl;
    std::cout<<cchar.uppercarse()<<std::endl;
    return 0;
}

/*El programa tiene la funcion de aumenta el valor que se ingresa en el contenedor si es numero, si en caso es letra minuscula
pues lo transformara a letra mayuscula para ello se creo un template donde se tiene la clase "Contenedor" que tiene registrado "T elemento"
donde se puso la condicion para ir aumentando el valor del "elemento". En el segundo template de siente la especificacion cuando 
Contenedor sea de tipo char y se agrega una funcion para modificar la letra de minuscula a mayuscula para esto se pone los limites que serian
de "a" hasta "z" y hariamos que el elemento se compare con la version mayuscula para poder cambiar, entonces se retorna el elemento
al final solo se llama a "Contenedor" y se especifica si sera para entero o de tipo char*/