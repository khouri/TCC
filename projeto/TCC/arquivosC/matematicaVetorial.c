/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do módulo matematica vetorial***************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: aplica operações aritméticas simples******************************/
/***************em vetores unidimensionais**************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "../arquivosH/matematicaVetorial.h"

/*Soma dois arrays e retorna um terceiro: c[i] = a[i] + b[i]*/
double * somaDoisArrays(double * a, double * b, int tamanho){

    double * retorno = (double*)malloc(tamanho*sizeof(double));
    int i;//contador.
    for(i = 0; i < tamanho; i++)
        retorno[i] = a[i] + b[i];//*(retorno+i) = *(a+i) + *(b+i);

    return retorno;
}


/*Soma um intervalo de posições do array SUM(array[3-5])*/
double somaPosicoesArray(int inicio, int fim, double * array){

    double soma = 0;
    int i;//contador.
    for(i = inicio; i < fim; i++)
        soma = soma + array[i];//*(array+i);

    return soma;
}



/*----------------------Aplica operações aritméticas escalares em vetores-----------------------*/


/*Aplica em todos os números de um vetor a função exp(x)*/
double * exponenciaNumeroVetor(double numero, double * array, int tamanhoVetor){

    double * retorno = (double*)malloc(tamanhoVetor*sizeof(double));

    int i;
    for(i = 0; i < tamanhoVetor; i++)
        retorno[i] = exp(array[i]);//*(retorno+i) = exp(*(array+i));

    return retorno;
}


/*Multiplica todos os elementos do array por um número.*/
double * multiplicaNumeroVetor(double numero, double * array, int tamanhoVetor){

    double * retorno = (double*)malloc(tamanhoVetor*sizeof(double));

    int i;//contador.
    for(i = 0; i < tamanhoVetor ; i++)
        retorno[i] = array[i] * numero;//*(retorno+i) = *(array+i) * numero;

    return retorno;
}


/*Adiciona a todos os elementos do array um número.*/
double * somaNumeroVetor(double numero, double * array, int tamanhoVetor){

    double * retorno = (double*)malloc(tamanhoVetor*sizeof(double));

    int i;
    for(i = 0; i < tamanhoVetor ; i++)
        retorno[i] = array[i] + numero;//*(retorno+i) = *(array+i) + numero;

    return retorno;
}


/*----------------------Aplica operações aritméticas escalares em vetores-----------------------*/



