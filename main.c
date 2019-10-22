#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int **alocarMatriz(int linha, int coluna){
    int **mat;
    mat = (int**)calloc(linha, sizeof(int*));
    for (int i = 0; i < linha; i++)
        mat[i] = (int*)calloc(coluna, sizeof(int));
    return mat;
}
void printMatriz(int linha, int coluna, int **mat){
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
void povoarMatriz(int linha, int coluna, int **mat){
    for (int i = 0; i < linha; i++)
        for (int j = 0; j < coluna; j++)
            mat[i][j] = rand() % 256;
}

float calcDistania(int x1, int x2, int y1, int y2){
    return (float)sqrt(pow(x2-x1,2.0) + pow(y2-y1,2.0));
}
void calcCirculo(int linha, int coluna, int **mat, int raio){
    float distancia;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            distancia = calcDistania(i, raio, j, raio);
            if (distancia < raio) {
                mat[i][j] = 1;
            }
        }
    }
}
int **liberar(int linha, int coluna, int **mat){
    for(int i = 0; i < linha; i++)
        free(mat[i]);
    free(mat);
    return NULL;
}

int **geraMatMedia(int **mat, int n, int m, int kernel){
    int **newMat = alocarMatriz(n, m);
    int soma, borda = kernel/2;
    for (int i = borda ; i < n-borda; i++) {
        for (int j = borda; j < m-borda; j++) {
            soma = 0;
            for (int l = i - borda; l < i+borda; l++) {
                for (int c = j - borda; c < j+borda; c++) {
                    soma += mat[l][c];
                }
            }
            newMat[i][j] = (int)soma / (kernel*kernel);
        }
    }
    return newMat;
}

int **geraMatMediaCiruclar(int **mat, int n, int m, int kernel){
    int **newMat = alocarMatriz(n, m);
    int soma;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            soma = 0;
            for (int l = i; l < i+kernel; l++) {
                for (int c = j ; c < j+kernel; c++) {
                    soma += mat[l%n][c%m];
                }
            }
            newMat[i][j] = (int)soma / (kernel*kernel);
        }
    }
    return newMat;
}

int main(){
    srand(time(NULL));
    int linha, coluna;
    linha = coluna = 10;
    int **mat, **newMat;
    mat = alocarMatriz(linha, coluna);
    povoarMatriz(linha, coluna, mat);
    printMatriz(linha, coluna, mat);
    printf("\n");
    int kernel = 7;
    newMat = geraMatMediaCiruclar(mat, linha, coluna, kernel);
    printMatriz(linha, coluna, newMat);
    return 0;
}
