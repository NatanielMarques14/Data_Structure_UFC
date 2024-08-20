/*
Implementation of an unlimited stack via vector.
*/

#include <iostream>
#include <new>
using namespace std;

struct Pilha
{
    double *vetor;
    int elem;
    int max;

    Pilha()
    {
        try
        {
            vetor = new double[1];
            max = 1;
            elem = 0;
        }
        
        catch(const bad_alloc &e)
        {
            cout << "bad alloc: " << e.what() << endl;
            vetor = nullptr; 
            max = 0;
            elem = 0;
        }
    }

    bool empilhar(double x)
    {
        if(elem == max)
        {
            double *novo;
            
            try
            {
                novo = new double [max * 2];
            }
            catch(const bad_alloc &e)
            {
                cout<< "bad alloc: " << e.what() << endl;
                return false;
            }

            for (int i = 0; i< max; i++)
            {
                novo[i]=vetor[i];
            }

            delete[] vetor;
            vetor = novo;
            max = max * 2;

        }
        
        vetor[elem++] = x;
        return true;
    }

    bool desempilhar()
    {
        if(elem == 0)
        {
            return false;
        }

        elem--;
        return true;
    }

    double ultimo()
    {
         if (elem == 0)
        {
            throw runtime_error("pilha vazia");
        }
        return vetor[elem - 1];
        
    }

    
    ~Pilha()
    {
        delete[]vetor;
    }
};

int main()
{
    Pilha p;
    p.empilhar(1.1);
    p.empilhar(2.2);
    p.empilhar(3.3);

    cout << "Último elemento: " << p.ultimo() << endl;

    p.desempilhar();
    cout << "Último elemento após desempilhar: " << p.ultimo() << endl;

    return 0;
}

