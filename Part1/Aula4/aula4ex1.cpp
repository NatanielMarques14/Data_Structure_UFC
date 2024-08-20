/*
Implementation of a limited set via unordered vector
*/

#include <iostream>
using namespace std;

struct Conjunto
{
    static const int tam = 10;
    int n; //Number of elements.
    char vetor[tam];
};

void inicializar (Conjunto &C)
{
    C.n = 0;
}

bool cheia (Conjunto &C)
{
    return (C.n == C.tam);
}

bool vazia (Conjunto &C)
{
    return (C.n == 0);

}

bool pertence (Conjunto &C, char k)// To look if K is in the set.
{
    for(int i = 0; i <C.n; i++)
    {
        if (C.vetor[i]==k)
        {
            cout<<"o elemento: " << k << " pertence ao conjunto" << endl;
            return true;
        }
    }
return false;
}

bool inserir_novo (Conjunto &C, char k)
{
    if (cheia(C))
    {
        cout << "Conjunto cheio! "<< endl;
        return false;
    }
    C.vetor[C.n] = k;
    ++C.n;
    return true;
}

bool inserir_se_novo (Conjunto &C, char k)//we will only use this one.
{
    if (cheia(C))
    {
        return false;
    }

    if(!pertence(C,k))
    {
        inserir_novo(C,k);
        return true;
    }
    cout << "O elemento ja existe no conjunto" <<endl;
    return false;
}

bool remover(Conjunto &C, char k)
{
    if (vazia(C))
    {
        cout<< "fila vazia, não há nada pra ser removido" << endl;
        return false;
    }
    for (int i = 0; i <C.n; i++)
    {
        if (C.vetor[i] == k)
        {
            C.vetor[i] = C.vetor[C.n-1];//we adress the last one to the one that got eliminated.
            --C.n;
            return true;
        }
    }
    cout<< "Elemento não pertence ao conjunto"<< endl;
    return false;

}

bool mostrar_vetor (Conjunto &C)
{
    for (int i = 0; i < C.n ; i++)
    {
        cout << C.vetor[i]<<endl;
    }
    cout<< "\n";
return true;
}

int main()
{
 Conjunto C;
    inicializar(C);
    inserir_se_novo(C, 'n');
    inserir_se_novo(C, 'a');
    inserir_se_novo(C, 't');
    inserir_se_novo(C, 'a'); //inserir_se_novo will not accept this, it will only show "nat".
    
    mostrar_vetor(C);
    return 0;
}