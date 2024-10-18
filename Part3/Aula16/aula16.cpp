#include<iostream>
using namespace std;

class ConjABB
{
    struct Noh
    {
        Noh *esq;
        double elem;
        Noh *dir;
    };

    Noh *raiz;

    
     // Função recursiva para percorrer a árvore em ordem
    void imprimirEmOrdemRecursivo(Noh* no){
        if (no != nullptr) {
            imprimirEmOrdemRecursivo(no->esq);  // Primeiro percorre a subárvore esquerda
            cout << no->elem << " ";      // Depois imprime o valor do nó atual
            imprimirEmOrdemRecursivo(no->dir);  // Finalmente percorre a subárvore direita
        }
    }
    
    
    public:
     // Função pública para imprimir a árvore em ordem
    void imprimirEmOrdem(){
        imprimirEmOrdemRecursivo(raiz); // Inicia a impressão a partir da raiz
        cout << endl;         // Nova linha após imprimir todos os elementos
    }

    ConjABB()
    {
        raiz = nullptr;
    }

    bool vazio()
    {
        return (raiz == nullptr);
    }

    void inserir (double e)
    {
        Noh *novo = new Noh{nullptr, e, nullptr};
        if(vazio())
        {
            raiz = novo; //both raiz and novo are pointers to an node.
            return;
        }
        Noh *n = raiz; 
        while(true)//for(;;)
        {
            if(e < n->elem)
            {
                if(n->esq == nullptr)
                {
                    n->esq = novo;
                    return;
                }
                n = n->esq;
            }
            else
            {
                if(n->dir == nullptr)
                {
                    n->dir = novo;
                    return;
                }
                n = n->dir;
            }

        }
    }

    bool pertence (double e)
    {
        Noh* n = raiz;

        while (n != nullptr)
        {
            if(e < n->elem)
            {
                n = n->esq;
            }
            else if(n->elem < e)
            {
                n = n->dir;
            }
            else
            {
                return true;
            }
            return false;
        }
    }

    bool inserir_se_novo(double e)
    {
        if(pertence(e))
        {
            return false;
        }

        inserir(e);
    }

    bool remover (double e)
    {
        if(vazio)
        {
            return true;
        }

        Noh *n = raiz;
        Noh * *cima = &raiz;//& needs an * in the other side of the "="

        while (n != nullptr)
        {
            if (e<n->elem)
            {
                cima = &n->esq; //& of an pointer is an **, just like cima
                n = n->esq;
            }
            else if(n->elem <e)
            {
                cima = &n->dir;
                n = n->dir;
            }
            else
            {
                break;
            }
        }

        if (n == nullptr)
            {
                return; //we didn't found.
            }

            //cases with 1 and 0 children
        if(n->dir == nullptr)
            {
                *cima = n->esq;
            }
         else if (n->esq == nullptr)
            {
                *cima = n->dir;
            }
         else //two children
            {
                Noh *s = n->dir;
                Noh * * cima_s = & n->dir;
                while(s->esq !=nullptr)
                {
                    cima_s = &s->esq;
                    s = s->esq;
                }
                *cima_s = s->dir;
                *cima = s;
                s->esq = n->esq;
                s->dir = n->dir;
            }
        
        delete n;
    }

    /*
    void remover (double e)
    {
        Noh *n = raiz;
        Noh *pai = nullptr;

        while( n != nullptr)
        {
            if (e<n->elem)
            {
                pai = n;
                n = n->esq;
            }
            else if(n->elem < e)
            {
                pai = n;
                n = n->dir;
            }
            else
            {
             break
            }

            }
            if (n == nullptr)
            {
                return;
            }

            if (n->esq ==nullptr and n->dir==nullptr)//to delete an foil
            {
                if(n == raiz)//pai ==nullptr
                {
                    raiz = nullptr;
                }
                else if(n==pai->esq)
                {
                    pai->esq = nullptr;
                }
                else
                {
                    pai->dir = nullptr;
                }
                delete n;
                return;
            }

            if(n->esq == nullptr or n->dir == nullptr)//only 1 children
            {
                if (n->dir == nullptr)//the only chindren are in the left 
                {
                    if (n == raiz)
                    {
                        raiz = n->esq;
                    }

                    else if (n == pai->esq)//n is an pai->esq
                    {
                        pai->esq = n->esq;
                    }
                    else//n is an pai->dir
                    {
                        pai->dir = n->esq;
                    }
                    delete n;
                    return;
                }

                else//the children are in the right  of n
                {
                    if (n == raiz)
                    {
                        raiz = n->dir;
                    }
                    else if(n == pai->esq)
                    {
                        pai->esq = n->dir;
                    }
                    else
                    {
                        pai->dir = n->dir;
                    }
                }
            
            }
            if (n->esq != nullptr && n->dir != nullptr) {
            Noh* sucessor = n->dir;
            Noh* paiSucessor = n;
    
    // Encontrar o menor nó na subárvore direita (sucessor in-order)
        while (sucessor->esq != nullptr) 
        {
        paiSucessor = sucessor;
        sucessor = sucessor->esq;
        }
    
    n->elem = sucessor->elem; // Substitui o valor de n pelo sucessor
    
    // Remove o sucessor (que terá no máximo um filho)
    if (sucessor == paiSucessor->esq) {
        paiSucessor->esq = sucessor->dir;
    } else {
        paiSucessor->dir = sucessor->dir;
    }
    
    delete sucessor; // Libera a memória do sucessor
}

        }
    }
    */

    ~ConjABB()
    {
        while (raiz != nullptr)
        {
            remover (raiz->elem);
        }
    }
};

int main() {
    // Criando o objeto da árvore binária de busca
    ConjABB arvore;

    // Inserindo alguns elementos
    arvore.inserir(50);
    arvore.inserir(30);
    arvore.inserir(70);
    arvore.inserir(20);
    arvore.inserir(40);
    arvore.inserir(60);
    arvore.inserir(80);

    // Exibindo os elementos da árvore (supondo que exista a função imprimirEmOrdem)
    cout << "Árvore antes da remoção:" << std::endl;
    arvore.imprimirEmOrdem();

    // Removendo um elemento
    arvore.remover(30);

    // Exibindo a árvore após a remoção
    cout << "\nÁrvore após a remoção do elemento 30:" << std::endl;
    arvore.imprimirEmOrdem();

    // Finalizando o programa
    // Ao sair do escopo, o destrutor será chamado automaticamente
    cout << "\nDestruindo a árvore..." << std::endl;

    return 0;
}