#include "Matrix.h"

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
        qDebug()  << "Le matrici non hanno la stessa dimensione\n";
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
        return 0;
}


Matrix Matrix::somma(Matrix add1, Matrix add2){
    if(add1.getColonne()==add2.getColonne() && add1.getRighe()==add2.getRighe()){
        Matrix res(add1.getRighe(),add2.getColonne());
        for(int i=0;i<add1.getRighe();i++){
            for(int j=0;j<add2.getColonne();j++){
                res.setCella(i,j,add1.getCella(i,j)+add2.getCella(i,j));
            }
        }
        return res;
    } else {
        return NULL;
    }
}

Matrix Matrix::prodotto(Matrix mul1, Matrix mul2){
    if(mul1.getColonne()==mul2.getRighe()){
        Matrix res(mul1.getRighe(),mul2.getColonne());
        int sum=0;
        for(int i=0;i<res.getRighe();i++){
            for(int j=0;j<res.getColonne();j++){
                sum=0;
                for(int k=0;k<mul1.getColonne();k++){
                    sum+=mul1.getCella(i,k)*mul2.getCella(k,j);
                }
                res.setCella(i,j,sum);
            }
        }
        return res;
    } else {
        return NULL;
    }
}
