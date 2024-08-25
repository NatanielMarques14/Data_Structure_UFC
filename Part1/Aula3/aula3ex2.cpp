#include <iostream>

using namespace std;

struct Fila
{
    static const int tam = 5;
    int tammax = 2 * tam;
    char vetorFrente[tam], vetorTras[tam];
    int frente, tras;
};

void inicializar(Fila &F)
{
    F.frente = -1;
    F.tras = -1;
}

bool vazia(Fila &F)
{
    return (F.frente == -1);
}

bool cheia(Fila &F)
{
    if (F.frente == 0 && F.tras == (F.tammax - 1))
    {
        return true;
    }
    else if (F.frente == F.tras + 1)
    {
        return true;
    }
    return false;
}

bool enfilar(Fila &F, char c)
{
    if (cheia(F))
    {
        return false;
    }

    if (vazia(F))
    {
        F.frente = 0;
        F.tras = 0;
    }
    else
    {
        F.tras = (F.tras + 1) % F.tammax;
    }

    if (F.tras >= F.tam)
    {
        F.vetorTras[F.tras - F.tam] = c;
    }
    else
    {
        F.vetorFrente[F.tras] = c;
    }
    return true;
}

bool desenfilar(Fila &F)
{
    if (vazia(F))
    {
        return false;
    }

    if (F.frente == F.tras)
    {
        F.frente = -1;
        F.tras = -1;
    }
    else
    {
        F.frente = (F.frente + 1) % F.tammax;
    }
    return true;
}

char primeiro(Fila &F)
{
    if (F.frente >= F.tam)
    {
        return F.vetorTras[F.frente - F.tam];
    }
    return F.vetorFrente[F.frente];
}

int main()
{
    
}