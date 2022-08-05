#include <iostream>

using namespace std;

template <class T, class U>
class calculadora {
    T x;
    U y;
public:
    calculadora(T _x, U _y);
    ~calculadora();
    void opc();
    auto suma();
    auto resta();
    auto division();
    auto multiplicacion();
};

template<typename T, typename U>
calculadora<T, U>::calculadora(T _x, U _y){
    this->x = _x;
    this->y = _y;
    this->opc();
}

template<typename T, typename U>
calculadora<T, U>::~calculadora()
{
};

template<typename T, typename U>
auto calculadora<T, U>::suma(){
    return this->x + this-> y;
}

template<typename T, typename U>
auto calculadora<T, U>::resta(){
    return this->x - this-> y;
}

template<typename T, typename U>
auto calculadora<T, U>::division(){
    return this->x / this-> y;
}

template<typename T, typename U>
auto calculadora<T, U>::multiplicacion(){
    return this->x * this-> y;
}


template<typename T, typename U>
void calculadora<T, U>::opc(){
    cout<<"Primer numero: "<<this->x<<" Segundo numero: "<<this->y<<endl;
    int opcion{0};
    while(opcion<1||opcion>4){
        cout<<"Ingrese una opcion"<<endl;
        cout<<"1. Suma"<<endl;
        cout<<"2. Resta"<<endl;
        cout<<"3. Division"<<endl;
        cout<<"4. Multiplicacion"<<endl;
        cin>>opcion;
    }
    if(opcion==1){
        cout<<"La respuesta de "<<this->x<<" + "<<this->y<<" es: "<<this->suma()<<endl;
    }
    else if(opcion==2){
        cout<<"La respuesta de "<<this->x<<" - "<<this->y<<" es: "<<this->resta()<<endl;
    }
    else if(opcion==3){
        cout<<"La respuesta de "<<this->x<<" / "<<this->y<<" es: "<<this->division()<<endl;
    }
    else{
        cout<<"La respuesta de "<<this->x<<" * "<<this->y<<" es: "<<this->multiplicacion()<<endl;
    }
    this->~calculadora();
    
}

int main(){
    int x{8},y{2};
    calculadora<int,int> a(x,y);

    return 0;
}