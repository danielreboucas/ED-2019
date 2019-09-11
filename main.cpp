#include <iostream>
using std::cin;
using std::cout;
#include <new>

template <typename T>
struct Deque
{
    T* v;
    int esquerda, direita, tam_v;    
};

template <typename T> bool inicializar(Deque<T> &D)
{
    D.v = new(nothrow) T[1];
    if(D.v == nullptr)
    {
        return true;
    }
    
    D.tam_v = 1;
    D.esquerda = -1;
    D.direita = -1;
    
    return false;
}

template  <typename T> void terminar(Deque<T> &D)
{
    delete[] D.v; 
    return ;
}

template  <typename T> bool vazio(Deque<T> &D)
{
    return (D.direita == -1 && D.esquerda == -1); 
}

template  <typename T> bool inserir_esq(Deque<T> &D, T e)
{
    if (D.direita == D.tam_v - 1 && D.esquerda == D.tam_v -1)
    {
        
    }

    D.v[D.esquerda] = e;
    --e; 
    return false; 
}

template  <typename T> bool inserir_dir(Deque<T> &D, T e)
{

    return false;
}

template  <typename T> T remover_esq(Deque<T> &D)
{

    return ;
}

template  <typename T> T remover_dir(Deque<T> &D)
{

    return ; 
};

/*
template <typename T> T redimensionar(Deque<T> &D)
{
    D.v = w
    
    return false;
}
*/

void main()
{
 
};