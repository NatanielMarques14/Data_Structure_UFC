#include <iostream>
using namespace std;

int rmv_recorrencias(double *vetor, int n, double x)
{
    int novo_tam =n;
    for(int i = 0; i < n; i++)
    {
        
        if(vetor[i] == x)
        {
            for (int j = i; j < novo_tam - 1; j++)
            {
                vetor[j] = vetor[j + 1];
            }
            novo_tam--;
            i--;
        }
    }
    return novo_tam;
}

int main()
{
    int n;
    cout<<"digite a quantidade de numeros no vetor, maximo é 10: "<<endl;
    cin>>n;
    double vetor[n];
    
    for(int i = 0; i < n; i++)
    {
    cout<<"digite um numero pra colocar no vetor" <<endl;
    cin>>vetor[i];
    }

    
    double x;
    cout << "digito pra remover do vetor: ";
    cin >> x;

    int novo_tam = rmv_recorrencias(vetor, n, x);
    
    for (int i = 0; i < novo_tam; i++) 
    {
        cout << vetor[i] << " ";
    }
    cout<< endl;

}