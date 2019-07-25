#include "Matrix.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>

Matrix::Matrix(int n){
    this->r = n;
    this->c = n;
    mat = new int*[n];
    for(int i=0;i<n;i++){
        mat[i] = new int[n];
    }
}

Matrix::Matrix(int r, int c){
    this->r = r;
    this->c = c;
    mat = new int*[r];
    for(int i=0;i<r;i++){
        mat[i] = new int[c];
    }
}

void Matrix::genera(){
    srand(time(0));
    for(int i=0;i<this->r;i++){
        for(int j=0;j<this->c;j++){
            mat[i][j]=(rand() % 10);
        }
    }
}

void Matrix::visualizza(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int Matrix::getColonne(){
    return c;
}

int Matrix::getRighe(){
    return r;
}

void Matrix::setCella(int i, int j, int x){
    this->mat[i][j]=x;
}

int Matrix::getCella(int i, int j){
    return mat[i][j];
}

Matrix Matrix::somma(Matrix add){
    if(this->r == add.getRighe() && this->c == add.getColonne()){
        Matrix res(r,c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res.setCella(i,j,this->mat[i][j]+add.getCella(i,j));
            }
        }
        return res;
    } else {
        std::cout << "Le matrici non hanno la stessa dimensione\n";
        return NULL;
    }
}


int** Matrix::riduciMatrice(int** mat, int n, int x, int y){
    int** newMat = new int*[n-1];
    for(int i=0;i<(n-1);i++){
        newMat[i] = new int[n-1];
    }
    int nj=0,ni=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=x && j!=y){
                newMat[ni][nj]=mat[i][j];
                nj++;
            }
        }
        if(i!=x){
            ni++;
        }
        nj=0;
    }
    return newMat;
}

int Matrix::calcolaDeterminanteRicorsiva(int** mat, int n){
    if(n==1){
        return mat[0][0];
    } else {
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=pow(-1,j)*mat[0][j]*calcolaDeterminanteRicorsiva(riduciMatrice(mat,n,0,j),n-1);
        }
        return sum;
    }
}

int Matrix::calcolaDeterminanteRicorsiva(){
    if(r==c)
        return calcolaDeterminanteRicorsiva(mat,r);
    else
        std::cout << "La matrice non è quadrata";
}
