#include <iostream>
#include <new>

using std::cin;
using std::cout;
using std::nothrow;

template <typename T>
struct DoubleStack
{
    T* v;
    double top1, top2;

    bool initialize(int n)
    {
        v = new(nothrow) T[n];
        if (v = nullptr)
        {
            return true;
        }
        top1 = -1;
        top2 = n;
        return false;
    }

    bool stack1(T e)
    {
        if(top1 + 1 == top2)
        {
            return true;
        }
        ++top1;
        v[top1] = e;
        return false;
    }

    T pop1()
    {
        T aux = v[top2];
        --top1;
        return aux;
    }

     bool stack2(T e)
    {
        if(top2 -1 == top1)
        {
            return true;
        }
        --top2;
        v[top2] = e;
        return false;
    }

    T pop2()
    {
        T aux = v[top2];
        ++top2;
        return aux;
    }
};

int main()
{
    DoubleStack<int> D;
    D.initialize(10);
    D.stack1(1);
    D.stack2(2);
    D.pop2();
    for (int i = 0; i < 9; i++)
    {
        cout << D.v[i];
    }
    
}