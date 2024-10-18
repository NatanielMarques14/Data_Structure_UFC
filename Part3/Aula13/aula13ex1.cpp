#include <iostream>
#include <exception>
using namespace std;

class Matriz
{
    int num_lin;
    int num_col;
    double **M;
    
    public:
    Matriz(int linhas, int colunas)
    {
        num_lin = linhas;
        num_col = colunas;

        M = new double* [linhas];
        for(int l = 0; l < linhas; l++)
        {
            M[l] = new double [colunas];
        }
    }

    /*
    Alternative version:
    class Matriz {
    
    int num_lin, num_col;
    double *vetor;

    public:
    Matriz(int linhas, int colunas) : num_lin{linhas}, num_col{colunas} 
    {
        vetor = new double [linhas * colunas];
    }

    double& operator() (int i, int j) {
        return vetor[(i * num_col) + j];
    }
    */

    ~Matriz()
    {
        for(int i = 0; i<num_lin; i++)
        {
            delete[]M[i];
        }
        delete[]M;
    }

    void atribuir (int l, int c, double valor)
    {
        M[l][c] = valor;
    }
    
    int getLinhas()
    {
        return num_lin;
    }

    int getColunas()
    {
        return num_col;
    }

    double &operator()(int l, int c)
    {
        return M[l][c];
    }

    void imprimir() 
    {
        for (int i = 0; i < num_lin; ++i) 
        {
            for (int j = 0; j < num_col; ++j) 
            {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Matriz somar(Matriz &A, Matriz &B)//a function that receives two arguments of the type Matriz
{
    if(A.getColunas() != B.getColunas() or A.getLinhas() != B.getLinhas())
    {
        throw invalid_argument("As matrizes devem ter as mesmas dimensões para serem somadas.");
    }

    Matriz S(A.getLinhas(), A.getColunas()) ;//create the matrix that will store the result
    
    for (int i = 0; i < A.getLinhas(); ++i)
    {
        for(int j = 0; j < A.getColunas(); j++)
        {
            S(i,j)= A(i, j) + B(i, j);
        }
    }
    return S;  
}

Matriz multiplicar (Matriz &A, Matriz &B)
{
    if (A.getColunas() != B.getLinhas()) 
    {
        throw invalid_argument("O número de colunas da matriz esquerda deve ser igual ao número de linhas da matriz direita.");
    }

    Matriz P(A.getColunas(),B.getLinhas());

    for (int i = 0; i < A.getLinhas(); ++i) 
    {
        for (int j = 0; j < B.getColunas(); ++j) 
        {
            for (int k = 0; k < A.getColunas(); ++k) 
            {
                P(i, j) += A(i, k) * B(k, j);
            }
        }
    }
    
    return P;

}

Matriz transpostar (Matriz &A)
{
    Matriz T(A.getLinhas(), A.getColunas());
    for(int i = 0; i <A.getLinhas(); i++)
    {
        for(int j = 0; j <A.getColunas(); j++)
        {
            T(i,j) = A(j,i);
        }
    }
    return T;
}

int main()
{
try {
        int linhas, colunas;

        // Leitura da primeira matriz
        cout << "Digite o número de linhas e colunas da primeira matriz: ";
        cin >> linhas >> colunas;
        Matriz A(linhas, colunas);
        cout << "Digite os elementos da primeira matriz:" << endl;
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                cin >> A(i, j);
            }
        }

        // Leitura da segunda matriz
        cout << "Digite o número de linhas e colunas da segunda matriz: ";
        cin >> linhas >> colunas;
        Matriz B(linhas, colunas);
        cout << "Digite os elementos da segunda matriz:" << endl;
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                cin >> B(i, j);/*   se fosse 
                
                    double& acessar_ref(int l, int c)
                    {
                    return M[l][c];
                    } 

                    no lugar do double &operator() (int l, int c)

                    a gente tem que usar cin>>B.acessar_ref(l,c)
                    S.acessar_ref(i, j) = A.acessar_ref(i, j) + B.acessar_ref(i, j);



                
                                */
            }
        }

        // Soma das matrizes
        Matriz C = somar(A, B);
        cout << "Soma das matrizes:" << endl;
        C.imprimir();

        // Multiplicação das matrizes
        // Para multiplicação, as dimensões precisam ser compatíveis
        if (A.getColunas() == B.getLinhas()) {
            Matriz D = multiplicar(A, B);
            cout << "Multiplicação das matrizes:" << endl;
            D.imprimir();
        } else {
            cout << "As matrizes não podem ser multiplicadas devido às suas dimensões." << endl;
        }

        // Transposição da primeira matriz
        Matriz T = transpostar(A);
        cout << "Transposta da primeira matriz:" << endl;
        T.imprimir();

    } catch (const exception& e) {
        cerr << "EXCEÇÃO: " << e.what() << endl;
        return 1;
    }

    return 0;

}