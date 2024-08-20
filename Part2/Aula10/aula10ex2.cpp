/*
Implementation of an queue via linked list.
*/

#include<iostream>
using namespace std;

struct Fila
{
    struct Noh
    {
        int valor;
        Noh *prox;
    };

    Noh*primeiro;
    Noh*ultimo;

    Fila() //constructor.
    {
        primeiro = nullptr;
        ultimo = nullptr;
    }

    void enfileirar(int e)
    {
        Noh *novo = new Noh;
        novo->valor = e;
        novo->prox = nullptr;//the new node will be the last, the prox field should be nullptr.
        
        if(ultimo != nullptr)//not empty.
        {
            ultimo->prox = novo;
        }
        
        ultimo = novo;

        if (primeiro == nullptr)
        {
            primeiro = novo;
        }
         
        
    }

    void desinfileirar()
    {
        if (primeiro == nullptr)
        {
            cout << "fila vazia" << endl;
            return;
        }
        
        Noh*temp = primeiro; //temp now has the adress of primeiro.
        primeiro = primeiro->prox; //primeiro has a new adress.
        if(primeiro == nullptr)
        {
            ultimo = nullptr;
        }
        
        delete temp;
    }
    
    
    int consultar_primeiro()
    {
        return primeiro->valor;
    }
};

int main()
{

}

