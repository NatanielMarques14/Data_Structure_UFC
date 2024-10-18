#include <exception>
#include <iostream>
using namespace std;

class Matriz
{
    int numlin;
    int numcol;
    double **M;

    public:
    Matriz(int linhas, int colunas)
    {
        numlin = linhas;
        numcol = colunas;
        M = new double *[linhas];
        for(int l = 0; l<linhas; l++)
        {
            M[l] = new double[colunas];
        }
    }

    ~Matriz()
    {
        for(int l = 0; l<numlin; l++)
        {
            delete[]M[l];
        }
        delete[]M;
    }

    double &operator()(int l, int c)
    {
        return M[l][c];
    }
};

int main()
{
try
{
int l;
cout<< "#linhas: ";cin>>l;
int c;
cout<< "#colunas: ";cin>>c;
Matriz M(l,c);
int i = 0;
int j = 0;
double valor = 3.14;
M(i,j) = valor;
cout<< "M["<<i<<"]["<<j<<"]:"<<M(i,j)<<endl;
for(i = 0; i<l; ++i)
{
    cout<< '[';
    for(j = 0; j<c;++j)
    {
        cout<< ' '<< M(i,j);
    }
    cout<< "]\n";

}

}

catch(const exception &e)
{
    cerr<< "exc:" <<e.what()<< '\n';
    return 1;
}
}