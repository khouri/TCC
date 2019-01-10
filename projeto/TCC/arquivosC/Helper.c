/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do modulo Helper****************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: funções que auxiliam a lógica da aplicação************************/
/***************mas que não se relacionam com a lógica diretamente, alguns******************/
/***************exemplos: alocar memória, dividir strings...********************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "../arquivosH/Helper.h"


/*-------------------------Alocação de Memória---------------------------*/


/*Aloca uma quantidade de memória para doubles.*/
double * alocaMemoriaDouble(int tamanhoAlocar){

    return (double*)malloc(tamanhoAlocar*sizeof(double));
}


/*Libera memória do vetor de double.*/
void liberaMemoriaDouble(double * liberar){

    free(liberar);
}


/*-------------------------Alocação de Memória---------------------------*/



/*-------------------------Impressão no console---------------------------*/


/*Imprime um vetor de inteiros.*/
void imprimeVetorInteiros(int * imprimir, int tamanhoVetor){

    pulaLinha();

    int i;//contador.
    for(i = 0; i < tamanhoVetor; i++)
        printf("%d  ",*(imprimir+i));

}


/*Imprime um vetor de double.*/
void imprimeVetorDoubles(double * imprimir, int tamanhoVetor){

   pulaLinha();

    int i;//contador.
    for(i = 0; i < tamanhoVetor; i++)
        printf("%f ",*(imprimir+i));

}


/*Pula uma linha na hora de printar na tela*/
void pulaLinha(){

     printf("\n");
}


/*-------------------------Impressão no console---------------------------*/




/*Implementação de um algoritmo que gera números
pseudo aleatorios entre 0 e c-1:

    //b = 0, gerador multiplicativo.
    //'c' e 'a' sao primos entre si, melhora desempenho.
*/
void geradorDeNumerosAleatorios(int qtdNumeros, int semente){

    int a = 13,
        b = 0,
        c = 997,
        X = 0,//Valor final.
        X0 = semente;//Semente

    int i;//contador.
    for(i = 1; i < qtdNumeros; i++){

        X = ( (X0 * a) + b ) % c;
        X0 = X;
        printf("%d ",X0);
    }
}


/*

void geradorDeNumerosAleatorios(int tam, int seed){

    int a = 13, b = 0, c = 997,
    X = 0, //Valor final.
    X0 = 100;//Semente

    int i;//contador.
    for(i = 1; i < tam; i++){

        X = ( (X0 * a) + b ) % c;
        X0 = X;//Cria a parte recursiva do algoritmo.
    }
}




*/


/*-------------------------String---------------------------*/


/*Concatena duas strings a e b.*/
char * concatenaStrings(char * a, char * b) {

    char result[2000] = "";
    strcat(result, a);
    strcat(result, b);

    return result;
}



/*-------------------------String---------------------------*/

