/*
    Implementation of an inverter function using pointers.
*/

#include <iostream>
using namespace std;

void inverter(double *p, int n)
{
    
    for (int i = 0; i<n/2; i++)
    {
        //double *aux;
        //aux = p; 
        //*(p + i)= *(p+ n - 1 - i) ;
        //*(p+ n - 1 - i) = *aux;
        double aux = p[i];
        p[i] = p[(n - 1) - i];
        p[(n - 1) - i] = aux;
    }
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
inverter(vetor, n);
for(int i = 0; i < n; i++)
{
    cout<<vetor[i]<< endl;
}

return 0;
}