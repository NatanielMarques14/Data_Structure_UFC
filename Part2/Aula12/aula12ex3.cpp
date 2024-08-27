/*
Set implementation using doubly linked list and sentinel node
*/
#include <iostream>
using namespace std;

class Conjunto
{
    struct Noh 
    {
        Noh *ant;
        double valor;
        Noh *prox;
    };
    
    Noh sentinela;

    /*
    
    Noh *sentinela;

    public:
    Conjunto()
    {
         sentinela = new Noh;
        sentinela->ant = sentinela;
        sentinela->prox = sentinela;
    }
    */

    public:
    Conjunto() 
    {
        sentinela.ant = &sentinela;
        sentinela.prox = &sentinela; //we don't use -> if sentinela is not an node.
    }

    bool consultar(double valor)
    {
        sentinela.valor = valor;
        Noh *aux = sentinela.prox;
        while(aux->valor !=valor)
        {
            aux = aux->prox;
        }
        if(aux == &sentinela)
        {
            return false;
        }
        return true;
    }

    void inserir (double valor)
    {
        //Noh *novo = new Noh{&sentinela, valor, sentinela.prox};
        Noh *novo = new Noh;
        novo->ant = &sentinela;
        novo->valor = valor;
        novo->prox = sentinela.prox;
        sentinela.prox = novo;
        novo->prox->ant = novo;
    }

    void inserir_se_novo(double valor)
    {
        if(consultar(valor) == false)
        {
            inserir(valor);
        }
    }

    void remover (double valor)
    {
        sentinela.valor = valor;
        Noh *aux = sentinela.prox;
        while(aux->valor != valor && aux!=&sentinela)
        {
            aux = aux->prox;
        }
        if(aux == &sentinela)
        {
            return;
        }

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        delete aux;
    }

    ~Conjunto()
    {
        while(sentinela.prox != &sentinela)
        {
            double valor = sentinela.prox->valor;
            remover(valor);
        }
    }

};

int main() {
    Conjunto c;
    c.inserir(10.5);
    c.inserir(20.3);
    c.inserir_se_novo(10.5);
    c.remover(20.3);
    return 0;
}