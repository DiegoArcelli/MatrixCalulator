#ifndef MATRIX_H
#define MATRIX_H

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
    void genera();
    void visualizza();
    void setCella(int i, int j, int x);
    int getCella(int i, int j);
    int getRighe();
    int getColonne();
    Matrix somma(Matrix add);
    int calcolaDeterminanteRicorsiva();

};

#endif /* MATRIX_H */
