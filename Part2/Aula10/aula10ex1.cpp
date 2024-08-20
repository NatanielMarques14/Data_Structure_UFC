/*
Implementation of an stack via linked list.
*/

#include <iostream>
using namespace std;

struct Pilha//we will use a stack to represent the linked list.
{
    struct Noh//a node has an pointer to the next one and a value.
    {
        int elem;
        Noh *prox;
    };

    Noh *topo;/*Since Topo is created within the Pilha structure we don't need to use
               it as an argument in the functions that are already inside Pilha,
               if the struct Pilha didn't exists, this wouldn't work.*/
    Pilha()// : inicio (nullptr) ->lista de in.membros
    {
        topo = nullptr; //it's an node that does not point to anything.
    }

    /*
    lista de inicialização de membros:
    
    class NomeDaClasse {
    public:
    Tipo1 membro1;
    Tipo2 membro2;

    NomeDaClasse(Tipo1 valor1, Tipo2 valor2)
        : membro1(valor1), membro2(valor2) {
        // Corpo do construtor
    }
    };
    
    nesse caso seria Pilha() : topo(nullptr) {}
    */

    void empilhar (int e)
    {
        Noh *novo = new Noh;
        novo->elem = e;
        novo->prox = topo; //the last one should point to the topo always.
        topo = novo; //the fields of top node is updated.

        //topo = new Noh{e, topo}; //new Noh dinamically alocates a new object of the type "Noh" in Heap Memory.
                                  //{e, topo} is an initialization list that initialize this new object 
                                  //the prox field = topo (a pointer to the top) and elem field = e.
    }

    int consultar_topo () //Pre-condition: the stack is not empty.
    {
        return topo->elem;
    }

    void desempilhar () //Pre-condition: the stack is not empty.
    {
        Noh *primeiro = topo;
        topo = topo->prox;
        delete primeiro;
    }

    ~Pilha() // destructor
    {
        while(topo != nullptr)
        {
            desempilhar();
        }
    }


};

int main()
{
    Pilha p;
    p.empilhar(10);
    p.empilhar(20);
    p.empilhar(30);
    cout << "Topo: " << p.consultar_topo() << endl;
    p.desempilhar();
    cout << "Topo após desempilhar: " << p.consultar_topo() << endl;

    return 0;
}