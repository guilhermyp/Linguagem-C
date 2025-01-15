#include <stdio.h> 
#include <string.h> 



int main(){


void limpar_entrada() { 
    char c; 
    while ((c = getchar()) != '\n' && c != EOF) {}  //Se houver uma quebra de linha pendente naentrada padrão, é preciso limpar antes: fseek(stdin,0,SEEK_END); 

}


double C, F;
char resposta;

do{
    printf("Digite a temperatura em Celsius: ");
    scanf("%lf", &C);
    F = 9.0 * C / 5.0 + 32.0;
    printf("Equivalente em Fahrenheit: %.llf\n", F);
    printf("Deseja repetir (s/n)? ");
    limpar_entrada();
    scanf("%c", &resposta);
}
while (resposta == 's');

return 0;
}