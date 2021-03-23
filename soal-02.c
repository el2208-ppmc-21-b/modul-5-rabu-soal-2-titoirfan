/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul               : 5
*   Soal                : 2
*   Hari dan Tanggal    : 
*   Nama (NIM)          : 
*   Asisten (NIM)       : 
*   Nama File           : soal-02.c
*   Deskripsi           : Deskripsi file ini.
*/

#include <stdio.h>
#include <stdlib.h>

void recursion(int n, int m, int k, int **mat, int i, int j) {
    // Implementasi
}

int **initialize_matrix(int n){
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        mat[i] = (int *)malloc(n * sizeof(int)); 
    }
    return mat;
}

void print_matrix(int **mat, int n) {
    printf("Output matrix:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j != n-1) {
                printf("%d ", mat[i][j]);
            } 
            else {
                printf("%d", mat[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n; 
    int m; 
    int k; 
    int i=0, j=0;
    int **mat;
    
    printf("Input: ");
    scanf("%d %d %d", &n, &m, &k);
    
    mat = initialize_matrix(n);
    recursion(n, m, k, mat, i, j);
    print_matrix(mat, n);
    
    return 0;
}
