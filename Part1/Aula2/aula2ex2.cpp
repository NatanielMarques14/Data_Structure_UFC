/*
Limited stack implementation via vector
*/


#include <iostream>
using namespace std;

struct Pilha
{
    static const int tam = 10;
    int v[tam];
    int n;//just like the basic_set.
};

void inicializar (Pilha &P)
{
    P.n = 0;
}

bool cheia(Pilha &P)
{
    return(P.n==P.tam);
}

bool vazia(Pilha &P)
{
    return (P.n == 0);
}

bool empilhar(Pilha &P, int x)
{
    if (cheia(P))
    {
        return false;
    }

    P.v[P.n] = x;
    P.n++; //you don't need it to be circular.
    return true;
}

void top(Pilha &P)
{
    cout << P.v[P.n-1] << endl;
}

bool desempilhar (Pilha &P)
{
    if (vazia(P))
    {
        return false;
    }
    P.n--;
    return true;
}

void mostrar(Pilha &P)
{
    for(int i = 0; i < P.n; i++)
    {
        cout<<P.v[i];
    }
}

int main()
{
    
}