include <stdio.h>
include <string.h>
include <math.h>
define valorMaximo 100

/* Declaração de Variáveis Globais */

char valorBase[valorMaximo]; // Vetor que armazena o valor convertido
int valorDecimal;

/* Fim da declaração*/

/* Procedimento que inverte as posições do vetor_/
void inverteVetor(char *Vet, int count){
int j= 0, k= 0; // contadores do laço
char aux[valorMaximo]; // variavel auxiliar de troca
j= 0;
k= count-1;
while (j < k) {
aux[j]= Vet[j];
Vet[j]= Vet[k];
Vet[k]= aux[j];
j++;
k--;
}
}
/_ Fim do Procedimento */

/* Função que converte um número decimal para as bases de 2, 8 e 16 /
char decToAll(int decValue, int Base){
int i= 0, value= 0;
while (decValue) {
value= decValue%Base;
/* Caso a base seja menor do que 10 ou o resto menor que 10 (no caso de outras bases maiores do que 10 terem restos maiores que 11)
irá fazer o cálculo normal de resto, acrescentando no vetor o valor convertido
OBS: soma-se +48 (valor na tabela asci cujo valor é 0) pois está sendo acrescentado em um vetor de char, e não de inteiro ou flutuante /
if (Base<= 10 || value< 10) {
valorBase[i]= value+48;
}
/ Se o restor for maior do que 11, ele irá fazer o call na função que converte os restos em letras, e irá acrescentar no vetor /
else {
valorBase[i]= value+55;
}
decValue/= Base;
i++;
}
valorBase[i]= '\0';
inverteVetor(valorBase, i);
return valorBase;
}
/ Fim da função */

/* Função que converte de qualquer base para decimal /
int allToDec(char *Num, int Base){
int tamanho= 0;
tamanho= (int)strlen(Num);
inverteVetor(Num, (int)strlen(Num));
for (int i= 0; i< tamanho; i++) {
/ Se o valor está entre os números na tabela ascii, diminui-se 48 para calcular o valor /
if (Num[i]>= 48 && Num[i]<= 59) {
valorDecimal+= pow(Base, i)(Num[i]-48);
}
/* Caso o valor não seja os números (tabela ascii), subtrai-se 65 valor A e soma-se 10 para calcular o valor /
else {
valorDecimal+= pow(Base, i)(Num[i]-65+10);
}
}
return valorDecimal;
}
/* Fim da função*/

/* Função que escolhe a opção de conversão de base*/
void convertion(int valueOption){
int value= 0, base= 0;
switch (valueOption) {
case 1:
printf("Digite um numero de decimal para converter: ");
scanf("%d", &value);
printf("Digite a base para qual deseja converter (2, 8 e 16): ");
scanf("%d", &base);
printf("O valor convertido e: %s", decToAll(value, base));
break;

    case 2:
        printf("Digite um numero em binario para converter para qualquer base: ");
        scanf("%s", valorBase);
        printf("Digite a base para qual deseja converter (8, 10 e 16): ");
        scanf("%d", &base);
        printf("O valor convertido e: %s", decToAll(allToDec(valorBase, 2), base));
        break;

    case 3:
        printf("Digite um numero em octal converter para qualquer base: ");
        scanf("%s", valorBase);
        printf("Digite a base para qual deseja converter (2, 10 e 16): ");
        scanf("%d", &base);
        printf("O valor convertido e: %s", decToAll(allToDec(valorBase, 8), base));
        break;

    case 4:
        printf("Digite um numero em octal converter para qualquer base: ");
        scanf("%s", valorBase);
        printf("Digite a base para qual deseja converter (2, 8 e 10): ");
        scanf("%d", &base);
        printf("O valor convertido e: %s", decToAll(allToDec(valorBase, 16), base));
        break;

    default:
        break;
}

}
/* Fim do procedimento */

int main(){
int choose= 0, option= 0;

printf("### CONVERSOR DE BASES ###\n");
printf("Digite '1' para acessar o MENU de opcoes: ");
scanf("%d", &choose);
printf("\n");
//Switch que escolhe a opção desejada pelo usuário
switch (choose) {
    case 1:
        printf("Digite um valor de 1 ate 6\n\n");
        printf("1-Decimal para qualquer base.\n");
        printf("2-Binario para qualquer base.\n");
        printf("3-Octal para qualquer base.\n");
        printf("4-Hexadecimal para qualquer base.\n");
        printf("Opcao: ");
        scanf("%d", &option);
        convertion(option);
        break;

    default:
        break;
}

return 0;

}
