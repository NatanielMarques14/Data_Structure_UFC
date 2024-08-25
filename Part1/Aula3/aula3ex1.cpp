#include <iostream>

using namespace std;

struct Fila
{
    static const int tam = 5;
    char vetor[tam];
    int frente, elem;
};

void inicializar(Fila &F)
{
    F.frente = -1;
    F.elem = 0;
}

bool vazia(Fila &F)
{
    return (F.elem == 0);
}

bool cheia(Fila &F)
{
    return (F.elem == F.tam);
}

bool enfilar(Fila &F, char c)
{
    if(cheia(F))
    {
        return false;
    }
    if(vazia(F))
    {
        F.elem = 1;
        F.frente = 0;
    }
    else
    {
        F.elem++;
    }

    F.vetor[(F.frente + F.elem - 1) % F.tam] = c;
    return true;

}

bool desenfilar(Fila &F)
{
    if (vazia(F))
    {
        return false;
    }

    if (F.elem == 1)
    {
        F.elem = -1;
    }
    else
    {
        F.frente = (F.frente + 1) % F.tam;
    }

    F.elem--;
    return true;
}

char primeiro (Fila &F)
{
    return F.vetor [F.frente];
}

int main()
{
        Fila fila;
    inicializar(fila);

    enfilar(fila, 'A');
    enfilar(fila, 'B');
    enfilar(fila, 'C');
    enfilar(fila, 'D');
    enfilar(fila, 'E');

    cout << "Primeiro elemento: " << primeiro(fila) << endl;

    desenfilar(fila);
    cout << "Primeiro elemento após desenfilar: " << primeiro(fila) << endl;

    return 0;
}