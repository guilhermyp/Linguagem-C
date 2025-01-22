#include <stdio.h>
#include <string.h>

int main (){

    double nota1, nota2, notafinal;


    printf("Digite a primeira nota: (0-100) ");
    scanf("%lf", &nota1); 
    printf("Digite a segunda nota: (0-100) ");
    scanf("%lf", &nota2);

    notafinal = (nota1+nota2)/2.0;

    if (notafinal >= 70.0){
    
    printf("APROVADO!\nSua nota final: %.2lf", notafinal);
    }
    else{
         printf("Reprovado!\nSua nota final: %.2lf", notafinal);
    }



    return 0;
}