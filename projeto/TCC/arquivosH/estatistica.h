/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo header do módulo de estatisticas**************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: função que calcula histograma, funções auxiliares para************/
/***************calcular o histograma e uma struct que representa um histograma*************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../arquivosH/matematicaVetorial.h"


/*---------------------Definir intervalo entre barras do histograma-----------------------*/


/*Calcula a largura do gráfico*/
double dominioGrafico(double inicio, double fim);


/*Calcula a largura de uma barra do histograma.*/
double larguraBarraHistograma(double inicioGrafico, double fimGrafico, int numBarras);


/*Retorna os intervalos entre barras do histograma a ser plotado.*/
double * intervaloBarras(int NumBarras, double inicioIntervalo, double fimintervalo);


/*---------------------Definir intervalo entre barras do histograma-----------------------*/



/*--------------------------Utiliza a estrutura de histograma----------------------------*/


//Estrutura que representa um histograma
typedef struct
{
    int tamanho;//Tamanho do array.
    double * intervalos;//Intervalos em x entre barras.
    double * frequencia;//Frequencia dos pontos nas barras.
    int numPontos;

}histograma;


/*Aloca memória para a struct histograma.*/
histograma * inicializaHistograma(int numPontos, int numBarras);


/*Libera memória de um histograma.*/
void freeHistograma(histograma * liberar);


/*Função que calcula as frequências dos números de pontos.*/
histograma * calculaFrequencia(double * pontos, int nPontos,
                               int nBarras, int inicio, int fim);


/*Calcula a frequência relativa do histograma.*/
void frequenciaRelativa(histograma * h);


/*--------------------------Utiliza a estrutura de histograma----------------------------*/

