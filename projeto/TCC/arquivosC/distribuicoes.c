/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do modulo de distribuições******************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: funcao que calcula distribuicoes(expoencial,**********************/
/***************gaussiana e uniforme), funcoes auxiliares para calcular as distribuicoes****/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


//Define função em pré-processor, eficiência.
#define frand() ((double)rand())/(RAND_MAX+1.)
#include "../arquivosH/distribuicoes.h"


/*-----------------------------Gera distribuições-----------------------------*/


/*Gera um conjunto de números satisfazendo uma dist. uniforme*/
double * d_Uniforme(int numPontos, int semente){

    //Vetor de doubles com a distribuição uniforme.
    double * uniforme = alocaMemoriaDouble(numPontos);

    //Define semente aleatoria.
    srand(semente);

    int i;//contador.
    for(i = 0; i < numPontos; i++)
        uniforme[i] = frand();

    return uniforme;
}


/*Gera um conjunto de números satisfazendo uma dist. exponencial.*/
double * d_Exponencial(int numPontos, double lambda){

    //Vetor de doubles com a distribuição exponencial.
    double * exp = alocaMemoriaDouble(numPontos);
    double * U1 = d_Uniforme(numPontos, 100);

    int i = 0;//contador
    for(i = 0; i < numPontos; i++)
        exp[i] = -1.0/lambda * log((1.- U1[i]));

    //Libera memoria da uniforme auxiliar.
    liberaMemoriaDouble(U1);

    return exp;
}


/*Gera um conjunto de números satisfazendo uma dist. Gaussiana*/
double * d_Gaussiana(int numPontos){

    //Define duas dist. uniformes auxiliares.
    double * U1 = d_Uniforme(numPontos, seed1);
    double * U2 = d_Uniforme(numPontos, seed2);

    //Vetor de doubles com a distribuição Gaussiana.
    double * gau = alocaMemoriaDouble(numPontos);

    int i;
    for(i = 0; i < numPontos; i++)
    {
        double cosseno = cos( U2[i] * 2 * PI);//cos(U2)*2*PI.
        double ln = sqrt(-2 * log(U1[i]) );//sqrt(-2log(U1)*2*PI).
        gau[i] = cosseno * ln; //sqrt(-2log(U1)*2*PI) * cos(U2)*2*PI
    }

    //Libera a memoria das dist. auxiliares.
    liberaMemoriaDouble(U1);
    liberaMemoriaDouble(U2);

    return gau;
}


/*-----------------------------Gera distribuições-----------------------------*/

