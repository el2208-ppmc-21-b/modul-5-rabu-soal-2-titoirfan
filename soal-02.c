#include <stdio.h>
#include <stdlib.h>

// Misal kasus input n=2, m=2, k=1 (untuk penjelasan komentar dibawah)
void recursion(int n, int m, int k, int **mat, int i, int j) {
    // Rules
    if (i == 0 && j == 0){
        mat[i][j] = m;
    } else if (i == j){
        mat[i][j] = mat[i-1][j-1] + k;
    } else if (i > j){
        mat[i][j] = mat[i-1][j] - 1;
    } else if (i < j){
        mat[i][j] = mat[i][j-1] - 1;
    }

    // Rekursi
    // Misal ketika n=2, maka n>1, 
    // Digunakan untuk pemanggilan rekursi untuk pengisian nilai per baris
    if (n>1){
        // update j sebagai position column +1
        // Misal awalnya j=0 menjadi j=j+1=1
        j = j + 1;
        recursion(n-1, m, k, mat, i, j);

    // Misal ketika n=1, maka n<=1, dengan nilai j maksimal yaitu 1
    } else{
        // Update n menjadi n=1+1=2
        n = j + n;
        // Reset j jadi 0
        j = 0;
        // Update i sebagai position row +1
        // Misal awalnya i=0, menjadi i=i+1=1
        i = i + 1;
        // Ketika i<n
        if (i < n){
            recursion(n, m, k, mat, i, j);
        } 
        // else ketika i>=n, misal i=2 dan n=2, maka stop rekursi
    }
}

int **initialize_matrix(int n){
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        mat[i] = (int *)malloc(n * sizeof(int)); 
    }
    return mat;
}

void print_matrix(int **mat, int n){
    printf("Output matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (j != n-1){
                printf("%d ", mat[i][j]);
            } else {
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
