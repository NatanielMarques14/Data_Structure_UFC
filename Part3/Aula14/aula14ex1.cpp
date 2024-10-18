#include <iostream>
#include <string>
using namespace std;

class DicioTD 
{
    struct Noh 
    {
        int chave;
        string valor;
        Noh* prox;
    };

    int m;//table size
    int n;//elements

    Noh **T;
    Noh sent;

    int h(int c)//function
    {
        return c % m;
    }

    void redimen(int novo_tam)//pra que serve isso?
    {
        Noh**U = new Noh *[novo_tam];//explique isso
        int tam_atual = m;
        m = novo_tam;//pra que isso?
        int i;
        for(i=0; i<novo_tam; ++i)
        {
            U[i] = &sent;//o que esta acontecendo aqui? varios sentinelas sendo criados ? pra que? nao entendi?
        }
        for(i=0; i<tam_atual; ++i)
        {
            Noh *n = T[i];//pra que esse n?
            while (n != &sent)//nao entendi esse while
            {
                Noh *p = n->prox;//pra que esse P
                int j = h(n->chave);//o que significa esse j
                n->prox = U[j];//porque
                U[j] = n;//ele acabou de ser atribuido ao proximo de n, porque agora vale n?
                n = p;//porque n = p ?
            }
        }
        delete[]T;
        T = U;
    }
    public:

    DicioTD()
    {
        m = 1;
        n = 0;
        T = new Noh *[m];
        T[0] = &sent;//sent ja nao é um noh assim como T[0]? porque colocamos um &
    }

    ~DicioTD()
    {
        for (int i = 0; i < m; ++i) {
            Noh* atual = T[i];
            while (atual != &sent) {
                Noh* prox = atual->prox;
                delete atual;
                atual = prox;
            }
        }
        delete[] T;
    }

    void inserir(int c, string v)
    {
        if(m=n)
        {
            redimen(2*m);
        }
        int i = h(c);
        T[i] = new Noh {c,v,T[i]};
        ++n;
    }

    /*
     void expandir() {
        if (n >= m) {
            redimen(m * 2);
        }
    }

    void contrair() {
        if (n <= m / 4 && m > 1) {
            redimen(m / 2);
        }
    }

    bool remover(int chave) {
        int i = h(chave);
        Noh* atual = T[i];
        Noh* anterior = nullptr;

        while (atual != &sent) {
            if (atual->chave == chave) {
                if (anterior == nullptr) {
                    T[i] = atual->prox;
                } else {
                    anterior->prox = atual->prox;
                }
                delete atual;
                --n;
                contrair();
                return true;
            }
            anterior = atual;
            atual = atual->prox;
        }
        return false;
    }


    std::string buscar(int chave) {
        int i = h(chave);
        Noh* atual = T[i];
        while (atual != &sent) {
            if (atual->chave == chave) {
                return atual->valor;
            }
            atual = atual->prox;
        }
        return "";
    }
    */
};