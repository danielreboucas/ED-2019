#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <new>
using std::nothrow;

template <typename T>
struct Deque
{
    struct Noh
    {
        T elemento;
        Noh *ant;
        Noh *prox;
    };
    Noh *esq, *dir;
    T* v;
    
    void inicializar()
    {
       esq = dir = nullptr;
    }

    bool terminar()
    {
        return delete[] v;
    }
    
    bool vazio()
    {
        return (esq == nullptr && dir == nullptr);
    }

    bool inserir_esq(T e)
    {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr)
        {
            return true;
        }
        (*n).ant = nullptr;         
        (*n).elemento = e;
        (*n).prox = esq;
        if(vazio())
        {
            dir = n;
        }else{
            (*esq).ant = n;
        }
        esq = n;        
        return false;
    }

    bool inserir_dir(Noh n)
    {
        return false;
    }

    T remover_esq()
    {
        Noh *n = esq;
        T e = (*n).elemento;
        esq = (*n).prox;
        if (esq == nullptr)
        {
            dir = nullptr;
        }else{
            (*esq).ant = nullptr;
        }
        delete n;
        return e;
        
        return false;
    }

    T remover_dir()
    {
        return false;
    }
};

#endif DEQUE_HPP