/*
Implementation of a limited dictionary via vector
*/

#include <iostream>
#include <string>
using namespace std;

struct Dicionario
{
    static const int tam = 10;
    int chaves[tam];
    int valores[tam];
    int n;
};

void inicializar (Dicionario &D)
{
    D.n = 0;
}

bool existe (Dicionario &D, int chave)
{
    for(int i = 0; i < D.n; i++)
    {
        if(D.chaves[i] == chave)
        {
             return true;
        }

    }
    return false;
}

bool cheia (Dicionario &D)
{
    return (D.n == D.tam);
}

bool inserir (Dicionario &D, int valor, int chave)
{
    if (cheia(D))
    {
        return false;
    }

    if(existe(D, chave))
    {
        return false; //you can't add the same key twice.
    }

    D.chaves[D.n] = chave;
    D.valores[D.n] = valor;

    ++D.n;

    return true;
}

bool remover (Dicionario &D, int chave)
{
    if (!existe(D,chave))
    {
        return false;
    }

    for(int i = 0; i < D.n; i++)
    {
        if (D.chaves[i] == chave)
        {
            D.chaves[i] = D.chaves[D.n-1];
            D.valores[i] = D.valores[D.n-1];
            --D.n;
        }

    }
return true;
}

void consultar (Dicionario &D, int chave)
{
    if (!existe(D,chave))
    {
        cout << "This key don't exist" << endl;
    }

    for(int i = 0; i < D.n; i++)
    {
         if (D.chaves[i] == chave)
         {
            cout << "The value for the key "<< D.chaves[i]<<" is: "<<D.valores[i]<<endl;
         }
    }
}

void mostrar(Dicionario &D)
{
    for (int i = 0; i < D.n; i++)
    {
        cout << "Key: " << D.chaves[i] << ", Value: " << D.valores[i] << endl;
    }
}

int main()
{
    Dicionario D;
    inicializar(D);
    inserir(D, 0, 1);
    inserir(D, 1, 2);
    inserir(D, 2, 3);
    inserir(D, 3, 4);
    inserir(D, 4, 5);
    remover(D, 2);
    mostrar(D);

    return 0;
}