

#include <iostream>
using namespace std;

struct ResConsulta
{
    bool achou;
    string valor;
};

class Dicio
{
    struct Noh
    {
        Noh *ant;
        int chave;
        string valor;
        Noh *prox;
    };

    Noh *inicio;

    public:

    Dicio()
    {
        inicio = nullptr;
    }

    ResConsulta consultar(int c)
    {
        Noh *aux;
        aux = inicio;
        ResConsulta res; //the initial state of resconsulta.
        res.achou = false;
        res.valor = "não existe";
        while(aux != nullptr)
        {
            if( aux->chave == c)
            {
                res.achou = true;
                res.valor = aux->valor;
                break;
            }
            aux = aux->prox;
        }
        return res;
    }

    void inserir(int c, string v)
    {
        Noh* novo = new Noh;
        novo->ant = nullptr;
        novo->chave = c;
        novo->valor = v;
        novo->prox = inicio;;
        
        if(inicio !=nullptr)
        {
            inicio->ant = novo;
        }

        inicio = novo;
    }

    void inserir_se_novo(int c, string v)
    {
        ResConsulta res = consultar(c);
        if(res.achou == false)
        {
            inserir(c,v);
            return;
        }

    cout<<"a chave já existe no dicionario"<<endl;

    }

    void remover(int c)
    {
        Noh*aux;
        aux = inicio;
        
        if (inicio == nullptr) 
        {
            return;
        }
        if(inicio->chave == c)
        {
            inicio = inicio->prox;
            inicio->ant = nullptr;
            delete aux;
            return;
        }
        
        while(aux != nullptr)
        {
            if(aux->chave == c)
            {
                aux->ant->prox = aux->prox;
                if(aux->prox != nullptr)
                {
                    aux->prox->ant = aux->ant;
                }
                cout<< "removendo: "<<aux->valor<<endl;
                delete aux;
            }
            aux = aux->prox;      
        }
    }

    ~Dicio()
    {
        Noh *aux = inicio;
        while(inicio !=nullptr)
        {
            inicio = inicio->prox;
            delete aux;
            aux = inicio;
        }
    }
};

int main()
{
    Dicio dic;

    dic.inserir(1, "valor 100");
    dic.inserir(2, "valor 200");
    dic.inserir(3, "valor 300");

    ResConsulta res = dic.consultar(2);
    cout << "Consulta chave 2: " << (res.achou ? res.valor : "Não encontrado") << endl;

    dic.remover(2);
    res = dic.consultar(2);
    cout << "Consulta chave 2 após remover: " << (res.achou ? res.valor : "Não encontrado") << endl;

    return 0;
}