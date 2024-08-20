#include <iostream>
using namespace std;

struct Noh
{
    Noh *ant;
    double elem;
    Noh *prox;
};

struct Lista
{
    Noh *primeiro;
    Noh *ultimo;
};

void mover_ordenado(Lista &L, Noh *n)
{
    if(n->ant == nullptr or n->elem >= n->ant->elem)return;

    if(n == L.ultimo)
    {
        n->ant->prox = nullptr;
        L.ultimo = n->ant;
    }

    else
    {
        n->ant->prox = n->prox;
        n->prox->ant = n->ant;
    }

    Noh *aux = n->ant;
    while(aux != nullptr and aux->elem > n->elem)
    {
        aux=aux->ant;//achamos o menor noh possivel que é maior que o N
    }

    if(aux == nullptr)//se colocarmos no primeiro
    {
    L.primeiro->ant = n;
    n->prox = L.primeiro;
    n->ant = nullptr;
    L.primeiro = n;
    }

    else
    {
        n->prox = aux->prox;
        if (aux->prox != nullptr)
        {
            aux->prox->ant = n;
        }
        n->ant = aux;
        aux->prox = n;
    }

}

int main()
{
    // Exemplo de uso
    Lista lista;
    Noh a, b, c, d;
    a.elem = 1.0;
    b.elem = 3.0;
    c.elem = 4.0;
    d.elem = 2.0;

    lista.primeiro = &a;
    lista.ultimo = &c;
    a.prox = &b;
    b.ant = &a;
    b.prox = &c;
    c.ant = &b;
    c.prox = nullptr;

    mover_ordenado(lista, &d);

    // Impressão da lista para verificação
    Noh *current = lista.primeiro;
    while (current != nullptr)
    {
        cout << current->elem << " ";
        current = current->prox;
    }

    return 0;
}