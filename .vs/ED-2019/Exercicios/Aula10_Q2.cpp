#include <iostream>
#include <new>

using std::nothrow;

template <typename T>
struct Fila
{
    int inicio, final, tam_v;
    T* v;

    bool inicializar()
    {
        v = new(nothrow) T[1];
        if (v = nullptr)
        {
            return true;
        }
        inicio = final = 0;
        tam_v = 1;
        return false;
    }

    bool enfilar(T e)
    {   
        if(final == tam_v - 1)
        {
            if(redimensionar(tam_v * 2))
            {
                return true;
            }
        }
        v[final] = e;
        return false;
    }

    bool desenfilar()
    {
        ++inicio;
        if (!vazia() && 4*(final + 1) <= tam_v)
        {
            if (redimensionar(tam_v/2))
            {
                return true;
            }
        }
        return false;
    }

    T primeiro()
    {
        return v[inicio];
    } 

    T ultimo()
    {
        return v[final];
    }

    bool vazia()
    {
        return (inicio == final == 0);
    }


    void terminar()
    {
        delete[] v;
    }

    bool redimensionar(int tam_w)
    {
        T* w = new(nothrow) T[tam_w];
        if(w == nullptr)
        {
            return true;
        }

        for (int i = 0; i <= final; i++)
        {
            w[i] = v[i];
        }

        delete[] v;
        v = w;
        tam_v = tam_w;        
        return false;
    }
};

