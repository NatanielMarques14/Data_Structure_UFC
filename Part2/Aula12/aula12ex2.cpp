/*

dictionary implementation using sentinel node and linked list.
*/

#include <iostream>
using namespace std;

class Dicio
{
    struct Noh
    {
        int chave;
        string valor;
        Noh *prox;
    };

    
    Noh *sentinela;
    public:
    struct ResConsulta
    {
        bool achado;
        string valor;
    };
    Dicio() 
    {
    sentinela = new Noh;
    sentinela->prox = sentinela;//the list is empty when the sentinel is pointing to itself.
    }

    

    ResConsulta consultar(int chave)
    {
        sentinela->chave = chave;//we put the key that we are looking for in the chave field of the sentinel.
        Noh *aux = sentinela->prox;//in the end of the search the aux = sentinela.
        //ResConsulta res{false, "chave nao achada"};
        ResConsulta res;
        res.achado = false;
        res.valor = "chave nao achada";

        while (aux->chave != chave)
        {
            aux = aux -> prox;
        }
        if (aux == sentinela)//this is the simplification the sentinel node make.
        {
            return res; //empty list or the key is not on the list. will return the state in line 36
        }

        res.achado = true;
        res.valor = aux->valor;
        return res;    
    }

    void inserir(int chave, string valor)
    {
        //sentinela -> prox = new Noh{chave, valor, sentinela->prox};
        Noh* novo = new Noh;
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = sentinela->prox;
        sentinela->prox = novo;
    }

    void inserir_se_novo(int chave, string valor)
    {
        ResConsulta res = consultar(chave);
        if(res.achado == false)
        {
            inserir(chave, valor);
        }
    }

    void remover(int chave)
    {
        sentinela->chave = chave;
        Noh *aux = sentinela->prox;//similar to consultar.
        if(aux != sentinela and aux->chave == chave)//if it's first.
        {
            Noh *novoaux = aux;
            sentinela->prox = aux->prox;
            delete novoaux;
            return;
        }
        while(aux->prox->chave != chave)
        {
            aux = aux->prox;
        }

        if(aux->prox == sentinela)
        {
            return;
        }
        Noh *novoaux = aux->prox;
        aux->prox = novoaux->prox;
        delete novoaux;
    }

    ~Dicio()
    {
        Noh *aux = sentinela->prox;
        while(aux != sentinela)
        {
            sentinela->prox = aux->prox;
            delete aux;
            aux = sentinela->prox;
        }
        delete sentinela;
    }
};

int main() {
    Dicio dicionario;

    // Inserindo alguns pares chave-valor
    dicionario.inserir(1, "Valor 1");
    dicionario.inserir(2, "Valor 2");
    dicionario.inserir(3, "Valor 3");

    // Consultando um valor
    Dicio::ResConsulta res = dicionario.consultar(2);
    if (res.achado) {
        cout << "Chave 2 encontrada: " << res.valor << endl;
    } else {
        cout << res.valor << endl;
    }

    // Removendo uma chave
    dicionario.remover(2);

    // Tentando consultar a chave removida
    res = dicionario.consultar(2);
    if (res.achado) {
        cout << "Chave 2 encontrada: " << res.valor << endl;
    } else {
        cout << res.valor << endl;
    }

    return 0;
}