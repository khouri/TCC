/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo H do modulo de distribuições******************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: função que calcula distribuições(expoencial,**********************/
/***************Gaussiana e uniforme), funções auxiliares para calcular*********************/
/***************as distribuições************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

/*Invocando bibliotecas do C e do SO.*/
#include <values.h>//Valores de variáveis em C.
#include <math.h>//Funções matemáticas(e.g. seno, cos...).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dir.h>
#include <sys/time.h>//Funções para tratar o tempo com o SO.
#include <time.h>//Funções para tratar o tempo.
#include <sys/timeb.h>//Funções para tratar o tempo.

/*Invocando bibliotecas internas do projeto.*/
#include "../arquivosH/gravarArquivos.h"
#include "../arquivosH/plotarGraficos.h"
#include "../arquivosH/Diretorios.h"
#include "../arquivosH/Helper.h"


/*Constantes.*/
#define PI M_PI
#define seed1 100
#define seed2 123


/*Gera uma série de números pseudo aleatorios
que satisfazem uma dist. uniforme.*/
double * d_Uniforme(int numPontos, int semente);


/*Gera uma série de números pseudo aleatorios
que satisfazem uma dist. exponencial.*/
double * d_Exponencial(int Npontos, double lambda);


/*Gera uma série de números pseudo aleatorios
 que satisfazem uma dist. gaussiana.
    Fórmula da gaussiana sqrt(-2log(U1)*2*PI)) * cos(U2)*2*PI*/
double* d_Gaussiana(int Npontos);




