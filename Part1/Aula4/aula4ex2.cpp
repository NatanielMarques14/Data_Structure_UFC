/*
limited set via ordered vector, using the binary search algorithm.
*/

#include <iostream>
using namespace std;

struct Conjunto
{
    static const int tam = 10;
    int n;
    int v[tam];
};

void inicializar (Conjunto &C)
{
    C.n = 0;
}

bool vazia (Conjunto &C)
{
    return (C.n == 0);
}

bool cheia (Conjunto &C)
{
    return (C.n == C.tam);
}

//till here, it's almost the same as the aula4ex1, 
//but we will use binary search instead of linear search.

bool pertence (Conjunto &C, int k)
{
    int esq = 0;
    int dir = C.n - 1; //index of the first and the last one
    while(esq<=dir)//the moment that they are equal is the moment that we finally find the k.
    {
    int meio = esq + (dir - esq)/2;
        if (C.v[meio] == k)
        {
            return true;
        }
        else if (C.v[meio] < k)
        {
            esq = meio + 1;
        }
        else
        {
            dir = meio - 1;
        }
    }
return false;
}

int posicao(Conjunto &C, int k)//is the same as the pertence function, but we will return the index instead of return true.
{
     int esq = 0;
    int dir = C.n - 1;
    while(esq<=dir)
    {
    int meio = esq + (dir - esq)/2;
        if (C.v[meio] < k)
        {
            esq = meio + 1;
        }
        else
        {
            dir = meio - 1;
        }
    }
return esq; //or dir, they are equal in the end. excpet in the first addition when esq = 0 and dir = -1 
}


void inserir (Conjunto &C, int k)
{
    if(vazia(C))
    {
        C.v[C.n] = k;
        C.n++;
    }
    
    if(!cheia(C) && !pertence(C,k))
    {
        int pos = posicao(C,k);
        for(int i = C.n; i>pos;i--)
        {
            C.v[i]=C.v[i-1];
        }
        C.v[pos] = k;
        C.n++;
        
    }
}

bool remover(Conjunto &C, int k)
{
    if(vazia(C))
    {
        return false;
    }

    for(int i = 0; i < C.n; i++)
    {
        if(C.v[i] == k)
        {
            for (int j = i; j<C.n-1; j++)
            {
                C.v[j]=C.v[j+1];//moves the data on the right of k one step back.
            }
            C.n--;
            return true;
        }
    }
return false;
}

void mostrar_vetor (Conjunto &C)
{
    for (int i = 0; i < C.n ; i++)
    {
        cout << C.v[i];
    }
    cout<< "\n";
}

int main()
{

}

