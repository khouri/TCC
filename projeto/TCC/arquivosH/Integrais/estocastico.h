/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo header do modulo de estocastico***************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: funcoes que: calculam numericamente uma integral de ITO***********/
/**********calculam a solucao exata de uma integral estocastica, calculam numericamente*****/
/**********atraves do algoritmo de Euler Maruyama a solucao da mesma integral solucionada***/
/**********de maneira exata. Por ultimo uma funcao que calcula o movimento Browniano********/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../Diretorios.h"
#include "../matematicaVetorial.h"


//Funcao que calcula o movimento browniano com o auxilio de uma serie
//de numeros pesudo aleatorios que satisfazem uma gaussiana N(0,1)
//media zero e desvio padrao = 1.
double * movimentoBrowniano(int intervalo, int numeroPontos, double * incrementoWiener,
                            double condicaoInicial, double ruido);


//Calcula numericamente a seguinte equacao diferencial estocastica:
//representada pelo mov Browniano, segundo as regras de ITO(Japa velho)
double integralITO();


//Algoritmo de Euler Maruyama calcula a solucao exata da
//seguinte integral: dX = lambda*X dt + mu*X dW X(0) = 1.
//Calcula a mesma integral utilizando o algoritmo de Euler Maruyama
//plota os dois graficos tornando evidente a diferenca entre eles(erro).
void eulerMaruyama();


double * incrementoDt(int inicio, int fim, double intervalo);


/*Representa a solucao da equacao com
o algoritmo de Euler Maruyama.*/
typedef struct
{
    double * incremento;
    double * W;

}EM;

/*criar struct Mov. Brown*/


/*Soluciona a equacao diferencial
estoastica que eh o objetivo deste trabalho*/
int solucionaEquacao();


double * eulerSolver(int numPontos, double condicaoInicial, double parametroA,
                     double intervaloInfinitesimal, double passoAlgoritmoEuler);


double * criarIncremento(int numPontos, double intervalo);


double * eulerMaruyamaSolver(int numPontos, double condicaoInicial, double parametroA,
                             double intervaloInfinitesimal, double passoAlgoritmoEuler);


double * eulerSolver2(double condicaoInicial, int inicio,
                      int fim, double incrementoTempo, double parametroA);


double * movimentoBrowniano2(int inicio, int fim,
                             double incrementoTempo, double posicaoInicial);


double * eulerMaruyamaSolver2(int inicio, int fim, int parametroA,
                             double incrementoTempo, double posicaoInicial);


double * solucaoExataIntegral(int parametroA, int condicaoinicial,
                              int inicio, int fim, double incrementoTempo);
