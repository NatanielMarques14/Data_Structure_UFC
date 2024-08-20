
#include <iostream>
using namespace std;

struct Noh
{
    double elem;
    Noh *prox;
};

struct Lista
{
    Noh *primeiro;
};

void inserir(Lista&L, double e, int p)
{
    Noh *novo = new Noh();
    novo->elem = e;
    novo->prox = nullptr;
    
    
    if(L.primeiro == nullptr)//começa com o primeiro sendo nullptr
    {
        L.primeiro = novo;//agora o primeiro aponta pro novo
        return;
    }
    
    if(p==0)//inserir na primeira
    {
        novo->prox = L.primeiro;
        L.primeiro = novo;
        return;
    }
    
    int contador = 0;
    Noh *conta = L.primeiro;
    
    while(conta != nullptr)//conta quantos nos temos atualmente
    {
        conta = conta->prox;
        contador++;
    }
    
    
    if(p>=contador)//se a posicao desejada for maior que a quantidade de nos
    {
        Noh *atual = L.primeiro;
        while(atual->prox != nullptr)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
        return;
    }
    else
    {
    Noh *aux = L.primeiro;
    for(int i = 0; i < p-1; i++)
    {
        aux = aux->prox;
    }
    
    novo->prox = aux->prox;// o prox do novo agora eh o proximo do aux
    aux->prox = novo;
    }
    
}

int main()
{
    Lista lista;
    lista.primeiro = nullptr;

    inserir(lista, 10.5, 0);
    inserir(lista, 20.5, 1);
    inserir(lista, 30.5, 1);
    inserir(lista, 40.5, 10); // Tentativa de inserção em uma posição maior que o tamanho da lista

    Noh *atual = lista.primeiro;
    while (atual != nullptr)
    {
        cout << atual->elem << " ";
        atual = atual->prox;
    }

    return 0;
}