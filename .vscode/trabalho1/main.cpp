#include <iostream>
#include <new>
using std::nothrow;

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
    D.esquerda = D.direita = 0;  
    return false;
}

template  <typename T> void terminar(Deque<T> &D)
{
    delete[] D.v; 
    return ;
}

template  <typename T> bool vazio(Deque<T> &D)
{
    return (D.direita == 0 && D.esquerda == 0); 
}

template  <typename T> bool inserir_esq(Deque<T> &D, T e)
{
    if (vazio(D))
    {
        return true;
    }
    if (D.direita = D.tam_v -1)
    {  
        if (redimensionar(D))
        {
            return true;
        }         
    }
    D.v[D.esquerda] = e;
    --D.esquerda; 
    ++D.tam_v;
    return false; 
}

template  <typename T> bool inserir_dir(Deque<T> &D, T e)
{
    if (D.direita = D.tam_v -1)
    {  
        if (redimensionar(D))
        {
            return true;
        }         
    }

    D.v[D.direita] = e;
    ++D.direita;
    ++D.tam_v;
    return false;
}

template  <typename T> T remover_esq(Deque<T> &D)
{
    ++D.esquerda;
    return D.v[D.esquerda-1];
}

template  <typename T> T remover_dir(Deque<T> &D)
{
    --D.direita;
    return D.v[D.direita]; 
}

template <typename T> bool redimensionar(Deque<T> &D)
{
    T* w = new(nothrow) T[D.tam_v * 2];
    if (w = nullptr)
    {
        return true;
    } 
    for (int i = 0; i < D.direita; i++)
    {
        D.v[i] = w[i];
    }
    delete[] D.v;
    D.tam_v = D.tam_v * 2;
    return false;
}