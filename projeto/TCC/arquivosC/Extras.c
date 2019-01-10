#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap (int *a,int *b);


void Swap (int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}



int * pointerReturn1(){

int * i = malloc(sizeof(int));
*i=10;

return i;
}

int returnMatriz2 (int tamMatriz){


int i;
int* ma = (int*) malloc(tamMatriz*sizeof(int));//Aloca 10 espacos de memoria que comportam 10 inteiros.
for(i=0;i<10;i++) {

ma[i] = 1;
printf("valord da matriz %d \n",ma[i]);
}

return ma;
}






//Retorna sempre o msm numero aletorio.
int NumeroAleatorio(){

srand(100);
return rand();
}

//Retorna sempre o msm numero aletorio.
int NumeroAleatorioHoraPc(){

srand(time(NULL));//Com essa semente ele gera números aleatórios(subentenda-se pseudo) baseado no horário do Pc
return rand();
}


//Retorna msm sequencia de numeros aleatorios.
int NumeroAleatorio2(int incrementaSemente){

srand(100+incrementaSemente);
return rand();
}




//Cada rodada aqui os valores são diferentes pois a hora do pc muda.
void randomComSementeDefinidaPelaHoraDoPc() {

int i;
    /* inicializar o gerador de números aleatórios */
    srand(time(NULL));//Com essa semente ele gera números aleatórios(subentenda-se pseudo) baseado no horário do Pc
    //srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i<50; i++)
    {
          printf("%d ", (rand()%101));//Gera números entre 0 e 100
    }
}

/*
Teria um viés aqui??????
Algum bug????
Alguma incosistencia?????


*/

void geraRangeDeNumerosAleatoriosComDiferenca(int ini, int fim) {

int i;

    /* inicializar o gerador de números aleatórios */
    srand(time(NULL));//Com essa semente ele gera números aleatórios(subentenda-se pseudo) baseado no horário do Pc
    //srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i<1000; i++)
    {
	int aux = (rand()%101)+10;
	if(aux > 100) {

	   aux = aux - 10;
	}

        printf("%d ", aux);//Gera números entre 0 e 100
    }
}

//Funcao qeu retorna um ponteiro de numeros aleatorios.

void funcaomatriz(){

int matriz[10];

int i;
for(i=0;i<10;i++){

matriz[i] = i+1;

//printf(matriz[i]);
printf("Exemplo de Matriz em C: %d \n",matriz[i]);
}


}

void funcaoPonteiro(){

int teste = 90;
int *p;//Ponteiro
p = &teste;

printf("Exemplo de ponteiro em C %d ",*p);
*p = 10;
printf("Exemplo de ponteiro em C %d ",*p);


}

void funcaoPonteiroMalloc(){

int *notas;
int numero;
int i;
printf("entre com o numero total de alunos: ");
scanf("%d",&numero);
//aloca para o vetor uma quantia de memoria proporcional ao numero de alunos digitados pelo usuario.
notas = (int *) malloc(numero* sizeof(int));
for(i=0;i<numero;i++)
{
    printf("Entre com a nota do primeiro aluno %d \n",i+1);
    int a,b;
    scanf("%d",&a);//Le do teclado e armazena no endereco de a o resultado da leitura.
    notas[i] = a;//atribui o valor lido do teclado para o array de notas
    printf("A nota do Aluno %d eh %d \n",i+1,notas[i]);//printa a nota do aluno.

}
 free(notas);//Libera a memoria de notas.
}


void ponteiros(){

int vetor[50];
int *point;
point = vetor;

printf("A primeira nota eh %d",vetor[0]);
printf("\n");
printf("A primeira nota eh %d",*point);
printf("\n");
printf("A decima nota eh %d",vetor[9]);
printf("\n");
printf("A decima nota eh %d",*(point+9));

}

char *RolaMoeda (void) {
    int r;
    r = rand () % 2;
    if (r == 1) return "cara";
    else return "coroa";
}

//Cada rodada os numeros utilizam a semente default == 0; sempre são identicos aos da rodada anterior.
void randomSemSemente() {//Adota zero por default

int i;
    /* inicializar o gerador de números aleatórios */
    for (i=0; i<50; i++)
    {
          printf("%d ", rand()%101);//Gera números entre 0 e 100
    }
    /* printf("DIGITE ENTER: ");
       getchar();

     */
}

//Cada rodada aqui os numeros gerados sao identicos aos da rodada anterior.
void randomComSementeDefinida() {
//RAND_MAX	2147483647

int i;

    printf("\n");
    printf("\n");
    /* inicializar o gerador de números aleatórios */
    srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i<50; i++)
    {
          printf("%d ", rand()%101);//Gera números entre 0 e 100
    }
    /* printf("DIGITE ENTER: ");
       getchar();

     */
    printf("\n");
    printf("\n");

}

//Generate 'tamanhoDaSerie' pseudo random numbers in a Range[startRange,endRange)
double* randomNumberWithSeedAndRange(int tamanhoDaSerie,int startRange, int endRange){
/*
    Pelos calculos do Alexandre, o truque aqui consiste em entender endRange como uma soma
    endRange = startRange + delta; onde delta é o tamanho do intervalo.

*/

int i;
double* pointer = (double*)malloc(2*tamanhoDaSerie*sizeof(double));

    /* inicializar o gerador de números aleatórios */
    srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i < (tamanhoDaSerie*2); i++)
    {
          pointer[i] = ((endRange-startRange)*rand()) + startRange;
          //printf("%f ", *(pointer+i));
    }
    //printf("valor de iterações %d ",i);
    //printf("tamnhao %d",(tamanhoDaSerie*2));
    return pointer;

}



//Generate 'tamanhoDaSerie' pseudo random numbers in a Range[0,tamanhoDaSerie) in points formato
double* randomNumberWithSeed(int tamanhoDaSerie) {
//RAND_MAX	2147483647

int i;
double* pointer = (double*)malloc(2*tamanhoDaSerie*sizeof(double));

    /* inicializar o gerador de números aleatórios */
    srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i < (tamanhoDaSerie*2); i++)
    {
          pointer[i] = rand();
          //printf("%f ", *(pointer+i));
    }
    //printf("valor de iterações %d ",i);
    //printf("tamnhao %d",(tamanhoDaSerie*2));
    return pointer;
}



int ponteiroDePonteiro(double**X, double**Y){

//Y = (double**)malloc(sizeof(double*));
X = (double**)malloc(sizeof(double*));//Diz que o ponteiro X aponta para um ponteiro.
*X = (double*)malloc(sizeof(double));//diz que o ponteiro de *X aponta para um double
**X =12.3456;//Diz que o ponteiro de ponteiro aponta para 12.3456

//
//**Y = (double**)malloc(10*sizeof(double));
//**X = (double**)malloc(10*sizeof(double));

printf("");

return 1;
}
//
//main(){
//
//
//
//    return 1;
//}
