#include <stdio.h>
#include <string.h>


int main() { 

char nome1[50],nome2[50];
int idade1, idade2;
double mediaIdade;


printf("Digite o nome do primeiro participante: ");
gets(nome1);

printf("Digite a idade do primeiro participante: ");
scanf("%d", &idade1);



printf("Digite o nome do segundo participante: ");
fseek(stdin, 0, SEEK_END); //limpar o espaçamento 
gets(nome2);

printf("Digite a idade do primeiro participante: ");
scanf("%d", &idade2);

mediaIdade = (idade1 + idade2)/2.0;

printf("A idade de %s e %d anos, a idade de %s e %d anos. \n A media de idade entre eles e de %lf anos", nome1, idade1, nome2, idade2, mediaIdade);


return 0;
}