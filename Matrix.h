#ifndef MATRIX_H
#define MATRIX_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <QDebug>

class Matrix {
private:
    int r;
    int c;
    int **mat;
    int** riduciMatrice(int** mat, int n, int x, int y);
    int calcolaDeterminanteRicorsiva(int** mat, int n);
public:
    Matrix(int n);
    Matrix(int r, int c);
    void setCella(int i, int j, int x);
    int getCella(int i, int j);
    int getRighe();
    int getColonne();
    Matrix somma(Matrix add);
    int calcolaDeterminanteRicorsiva();
    static Matrix somma(Matrix add1, Matrix add2);
    static Matrix prodotto(Matrix mul1, Matrix mul2);

};

#endif /* MATRIX_H */
