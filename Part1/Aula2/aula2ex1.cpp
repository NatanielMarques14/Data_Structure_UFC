/*
Limited queue implementation via vector
*/

#include <iostream>
using namespace std;

struct Fila
{
    static const int tam = 5; // maximum size of the queue.
    char vetor[tam]; //the queue.
    int p, u; //index of the first and the last.
};

void inicializar (Fila &F)
{
    F.p = -1; //initialize the queue without elements.
}

bool vazia (Fila &F)
{
        return ((F.p == -1)); //if it is empty return true. this function will be useful to make decisions based on the state of the queue.
}

bool cheia (Fila &F)
{
    if (vazia(F))
    {
        return false;
    } //if it is empty, return false.

    return (F.u + 1) % F.tam == F.p; 
}

bool enfilar (Fila &F, char c)
{
    if (cheia(F))//check if it's full.
    {
        cout<< "impossivel enfilar, fila cheia"<<endl;
        return false;
    }
    if(vazia(F))//check if it's empty.
    {
        F.p = F.u = 0;
    }
    else
    {
        F.u = (F.u + 1) % F.tam ; //move the last one circular.
    }
    F.vetor[F.u] = c;//assign the new pointed end with char c.
return true;
}
/*
if we have 2 arrays (ex: 2 with 5 slots), we could use:

if(F.ultimo >= 5)  ---> the F.u moves beyond 4 and the char is stored based on that.
   {
    F.v2[F.ultimo - 5] = c;
   }
   else
   {
    F.v1[F.ultimo] = c;
   }
   return true;

*/

bool desenfilar  (Fila &F) //first in, first out.
{
    if(vazia(F))
    {
        cout << "impossivel desenfilar, fila vazia" << endl;
        return false;
    }

    if (F.u == F.p)
    {
        F.p = -1;
    }

    else 
    {
        F.p = (F.p + 1 ) % F.tam; // move the fist one circular.
    }
    return true;
}

char primeiro (Fila &F)//pre-condition: not empty(F).
{
    return F.vetor[F.p];
}
/*
in the situation with 2 arrays we should check if
 F.p is >4 or not to return F.v1 or F.v2.
*/

int main()
    {
       Fila F;
    inicializar(F);

    for(;;)
    {
        cout << "Digite uma operação, sendo ela a inicial do seu nome maíuscula: ";
        char opcao;
        cin >> opcao;

        if (opcao == 'E')
        {
            cout << "Elemento a inserir: ";
            char elemento;
            cin >> elemento;

            if (enfilar(F,elemento))
            {
                cout << "Enfilado.\n";
            }
            else
            {
                cout << "Cheia.\n";
            }
        }

        else if (opcao == 'D')
        {
            if (vazia(F))
            { 
                cout << "Inviavel, vazia.\n";
            }
            else
            {
                cout << "Vai ser desenfilado: " << primeiro (F) << '\n';
                desenfilar (F);
            }
        }

        else if (opcao == 'P')
        {
            if (vazia(F)) 
            {
                cout << "Inviavel, vazia.\n";
            }
            else
            {
                cout << "Primeiro: " << primeiro(F) << '\n';
            }
        }

         else if (opcao == 'S')
         {
            break;
         }

         else
         {
            cout << "Opção inválida! \n";
         }     
    }

}