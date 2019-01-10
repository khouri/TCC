/*
Arquivo de Headers, contem a assinatura dos metodos
para evitar conflitos de compilacao.


Author: Adilson Lopes Khouri N°USP 6411994
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <values.h>//Biblioteca matematica com os valores de variavies em C.
#include <math.h>//Biblioteca matematica com muitas funcoes matematicas(e.g. seno, cos, tan).
#define MAX RAND_MAX
#define seed 100
#define PI M_PI
#define TESTE 0
#define EULER 1



//Atribui a dois arrays numeros aleatorios com a mesma semente.
int distribuicaoUniforme(int numerodePontos,double* pontosNoEixoX, double* eixoY);


//Imprime um array de double.
void printArray(double * arrayToPrint, int sizeArray);


//Ordena crescentemente o array
void insertionSort(double* arrayToOrder, int n);


//Numero de intervalos entre o espaco total
double* calculaNumeroDeIntervalos(int NumBarras, double tamTotalIntervalo);


//Calcula o numero de intervalos e suas frequencias
double* CreateHistogram(double NDeBarras, double * pontosNoEixoX,int NDePontosEixoX,
                        double * tamIntervalos, int inicio, int fim);


//grava um arquivo com os pontos a serem plotados
//Formato ptX ptY
int gravaArquivo(int argc,double*X, double*Y,int tamanho);


//Plota um grafico em forma de histograma.
void plotHistogram();


//Plota um grafico em forma de pontos
void plotFunction();


//Gera n numeros aleatorios com a msm semente.
double* randomNumberWithSeedLinear(int tamanhoDaSerie);


//Calcula uma serie de pontos que satisfacam a distribuicao gaussiana(a 'Normal')
double* distribuicaoGaussiana(int Npontos);


//Calcula o modulo de um double.
void modulo(double* converter);


double calculaEspaco(double inicio, double fim);


double* calculaNumeroDeIntervalos2(int NumBarras, double inicioIntervalo, double fimIntervalo);


double * somaDoisArrays(double * a, double * b, int tamanho);


double somaPosicoesArray(int inicio, int fim, double * array);


double * somaNumeroVetor(double numero, double * array, int tamanhoArray);


double * multiplicaNumeroVetor(double numero, double * array, int tamanhoArray);


double* incrementoDt(double inicio, double intervalo, int fim);


double * exponenciaNumeroVetor(double numero, double * array, int tamanhoArray);

