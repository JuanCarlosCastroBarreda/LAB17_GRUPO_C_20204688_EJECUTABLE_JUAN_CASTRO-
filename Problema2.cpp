#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

template<typename T>  
class Nodo         
{
private:
    T dato;         
    Nodo<T>* HijoI;    
    Nodo<T>* HijoD;
public:
    Nodo();
    ~Nodo();

    void set_dato(T _dato)
    {
        this->dato = _dato;
    }
    void set_HijoI()
    {
        this->HijoI = new Nodo<T>;
    }
    void set_HijoD()
    {
        this->HijoD = new Nodo<T>;
    }
    T get_dato()
    {
        return this->dato;
    }
    Nodo* get_HijoI()
    {
        return this->HijoI;
    }
    Nodo* get_HijoD()
    {
        return this->HijoD;
    }
};

template<typename T>
Nodo<T>::Nodo()
{
    this->dato = NULL;
    this->HijoD = NULL;
    this->HijoI = NULL;
}

template<typename T>
Nodo<T>::~Nodo()
{
}

template<typename T>
class ArbolBinario 
{
private:
    int n_nodos;
    Nodo<T>* Raiz;
public:
    ArbolBinario();
    ~ArbolBinario();

    void Insertar_Datos(vector<T>& _vector);
    Nodo<T>* buscar_nodo_accesible(T _dato);
    void Imprimir_Arbol(Nodo<T> *nodo);
};

template<typename T>
ArbolBinario<T>::ArbolBinario()
{
    this->Raiz = new Nodo<T>;
}

template<typename T>
ArbolBinario<T>::~ArbolBinario()
{
}

template<typename T>
Nodo<T>* ArbolBinario<T>::buscar_nodo_accesible(T _dato)
{
    Nodo<T>* aux = Raiz;
    while ((aux->get_HijoD()!=NULL) || (aux->get_HijoI()!=NULL))
    {
        if (_dato > aux->get_dato())
        {
            if (aux->get_HijoD()==NULL)
            {
                break;
            }else
            {
                aux = aux->get_HijoD();
            }
        }else if (_dato < aux->get_dato())
        {
            if (aux->get_HijoI()==NULL)
            {
                break;
            }else
            {
                aux = aux->get_HijoI();
            }
        }
    }
    return aux;
}

template<typename T>
void ArbolBinario<T>::Insertar_Datos(vector<T>& _vector){
    if (_vector.size() == 0)
    {
        return;
    }else
    {
        this->Raiz->set_dato(_vector[0]);
        this->n_nodos = 1;
        Nodo<T> *aux;
        for (int i = 1; i < _vector.size(); i++)
        {
            aux = this->buscar_nodo_accesible(_vector[i]);
            if (_vector[i]<aux->get_dato())
            {
                aux->set_HijoI();
                aux->get_HijoI()->set_dato(_vector[i]);
            }else if (_vector[i]>aux->get_dato())
            {
                aux->set_HijoD();
                aux->get_HijoD()->set_dato(_vector[i]);
            }
            (this->n_nodos)++;
        }
        aux->~Nodo();
    }
    this->Imprimir_Arbol(this->Raiz);
}

template<typename T>
void ArbolBinario<T>::Imprimir_Arbol(Nodo<T> *nodo)
{
    cout<<nodo->get_dato();
    if (nodo->get_HijoI() != NULL)
    {
        cout<<"[";
        this->Imprimir_Arbol(nodo->get_HijoI());
        cout<<" , ";
    }else if (nodo->get_HijoD() != NULL)
    {
        cout<<"[ - , ";  
    }else
    {
        return;
    }
    if (nodo->get_HijoD() != NULL)
    {
        this->Imprimir_Arbol(nodo->get_HijoD());
        cout<<"]";
    }else if (nodo->get_HijoI() != NULL)
    {
        cout<<" - ]";
    }
}template<typename T>
void agregar_100(vector<T> &_vector)       //Funcion para agregar 100 neros aleatorios a un vector.
{
    auto n_base = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generador(n_base);
    uniform_int_distribution<int>distrib(-100,100);
    int n_aleatorio=distrib(generador);
    _vector.push_back(n_aleatorio);

    int opcion{0};
    for (int i = 1; i < 100; i++)
    {
        n_aleatorio=distrib(generador);
        for (int j = 0; j < _vector.size(); j++)
        {
            if (n_aleatorio == _vector[j])
            {
                opcion = 1;
                break;
            }
        }
        if (opcion == 0)
        {
            _vector.push_back(n_aleatorio);
        }else if (opcion == 1)
        {
            i--;
            opcion = 0;
        }
    }
}

int main(){

    vector<int> vector1 = {1,2,3,4,5,6,7,8,9};
    vector<int> vector2 = {10,11,12,13,14,15,16,17,18,19,20};
    vector<char> vector3 = {'a','b','c','d','e','f','g'};
    vector<int> vector4;
    ArbolBinario<int> A,B;
    ArbolBinario<char>C;
    ArbolBinario<int> D;

    cout<<"Arbol 1:\n";
    A.Insertar_Datos(vector1);
    cout<<"\nArbol 2:\n";
    B.Insertar_Datos(vector2);
    cout<<"\nArbol 3:\n";
    C.Insertar_Datos(vector3);
    agregar_100(vector4);
    cout<<"\nArbol 4:\n";
    D.Insertar_Datos(vector4);

    return 0;
}