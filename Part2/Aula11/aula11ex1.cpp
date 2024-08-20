/*
Implementation of an deque via doubly linked list.
*/


#include <iostream>
using namespace std;

class Deque
{
    private:
        struct Noh
        {
            Noh *ant;
            int elem;//noh elem?
            Noh *prox;
        };
    
    public: //info that the user should access.
        Noh *esq, *dir; //pq nao tem new?
    
    Deque() //a constructor.
    {
        esq = dir = nullptr;
    }

    bool vazia()
    {
        return (esq == nullptr and dir == nullptr);
    }

    void enfilar_esq (int c)
    {
        Noh *novo = new Noh{nullptr, c, esq};//the current left is the new node *prox. 
        if(esq == nullptr)
        {
            dir = novo;//esq = novo too, but we put it after the if-else.
        }
        else
        {
            esq->ant = novo;//if an esq already exists we should match its ant field with novo
        }
        esq = novo;

    }

    void enfilar_dir(int c)
    {
        Noh *novo = new Noh{dir, c, nullptr};
        if(dir == nullptr)
        {
            esq = novo;
        }
        else
        {
            dir->prox = novo;
        }

        dir = novo;

    }

    void desenfilar_esq()
    {
        Noh *aux = esq;
        esq = esq->prox;
        if (esq == nullptr)
        {
            dir = nullptr;
        }
        else
        {
            esq->ant = nullptr; //the current esq has an ant field poiting to the original esq
        }
        delete aux; //delete the adress of original esq
    }

    void desenfilar_dir()
    {
        Noh *aux = dir;
        dir = dir->ant;
        if(dir == nullptr)
        {
            esq = nullptr;
        }
        else
        {
            dir->prox = nullptr;
        }
        delete aux;
    
    }

    void consultar_esq()
    {
        if(!vazia())
        {
        cout << "Na esquerda da fila temos:"<< esq->elem<<endl;
        }
        else
        {
        cout << "Deque vazio."<<endl;
        }
    }

    void consultar_dir()
    {
        if(!vazia())
        {
        cout << "Na direita da fila temos:"<< dir->elem<<endl;
        }
        else
        {
        cout << "Deque vazio."<<endl;
        }
    }
    
    ~Deque()
    {
        while(!vazia())
        {
            desenfilar_esq();
        }
    }
};

int main()
{
Deque d;
    d.enfilar_esq(10);
    d.enfilar_esq(20);
    d.enfilar_dir(30);
    d.consultar_esq(); //20
    d.consultar_dir(); //30
    d.desenfilar_esq();
    d.consultar_esq(); //10
    d.desenfilar_dir();
    d.consultar_dir(); //10
    return 0;
}

