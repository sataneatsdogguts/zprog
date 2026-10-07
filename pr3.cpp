#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <random>

template <size_t Rows, size_t Cols>
void randmtr(double (&A)[Rows][Cols])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    for (int i = 0; i < Rows; i++)
    {
        for (int o = 0; o < Cols; o++)
        {
            A[i][o] = distrib(gen);
        }
    }
}

template <size_t Rows, size_t Cols>
void printmtr(const double (&A)[Rows][Cols])
{

    for (int i = 0; i < Rows; i++)
    {
        for (int o = 0; o < Cols; o++)
        {
            std::cout << A[i][o] << "\t";
        }
        std::cout << "\n";
    }
}

int main()
{

    double B[2][4];
    double C[4][3];
    double A[2][3] = {};

    randmtr(B);
    randmtr(C);
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int Z = 0; Z < 4; Z++)
            {
                A[i][j] += B[i][Z] * C[Z][j];
            }
        }
    }

    std::cout << "матрица B\n";
    printmtr(B);
    std::cout << "матрица C\n";
    printmtr(C);
    std::cout << "матрица A\n";
    printmtr(A);
    return 0;
}

