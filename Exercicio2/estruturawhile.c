#include <stdio.h> 
#include <string.h> 


int main() {


int x, soma;
soma = 0;

printf("Digite um valor: ");
scanf("%d", &x);


while (x != 0) //condição caso não for 0 ele vai somando os valores
{
    soma = soma + x;
    printf("Digite outro valor: ");
    scanf("%d", &x);

}
printf("A soma e: %d\n",soma);

return 0;

}