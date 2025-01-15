#include <stdio.h> 
#include <string.h> 



int main(){

int L, C, i, j; //

printf("Digite quantas linhas vai ter a matriz? ");
scanf("%d", &L);

printf("Digite quantas colunas vai ter a matriz? ");
scanf("%d", &C);

int matriz[L][C];

for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
        printf("Elemento [%d, %d]: ", i, j);
        scanf("%d", &matriz[i][j]);
    } 
}
printf("\n MATRIZ: \n");
for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
        printf("%d ", matriz[i][j]);

    }
    printf("\n");
}
return 0;
}