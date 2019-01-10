/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do modulo Testes****************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: Funcoes que efetuam testes unitários, verificam se alguma*********/
/***************alteracao no CF estragou outra parte do sistema*****************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "../../arquivosH/testes/testes.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

/*-----------------------------Testes de distribuições-----------------------------*/


/*Testa a distribuição uniforme*/
int rodaUni(){

    //Parametros iniciais da uniforme:{numero ptos, numero de barras do histograma...}
    int numPontos = 1000000, numBarras = 10, inicio = 0, fim = 1;
    char * nomeArquivo = "Uniforme.dat";

    //Cria conjunto de pontos que satisfazem uma distribuição uniforme.
    double * Uni = d_Uniforme(numPontos, seed1);

    //Calcula frequencia dos pontos entre as barras definidas.
    histograma * h = calculaFrequencia(Uni, numPontos, numBarras, inicio, fim);

    //Grava arquivo e plota gráfico.
    gravaPontosGrafico(h->intervalos, h->frequencia, numBarras+1, nomeArquivo);
    plotaHistograma(nomeArquivo);

    //Libera memoria.
    freeHistograma(h);
    free(Uni);
}


/*Testa a distribuição exponencial*/
int rodaExp(){

    //Parametros iniciais da exponencial:{numero ptos, numero de barras do histograma...}
    int numPontos = 1000000, numBarras = 100, inicio = 0, fim = 8;
    double lambda = 2.0;
    char * nomeArquivo = "Exponencial.dat";

    //Cria uma distribuicao exponencial.
    double * Exp = d_Exponencial(numPontos, lambda);
    histograma * h = calculaFrequencia(Exp, numPontos, numBarras, inicio, fim);

    //Grava arquivo e plota gráfico.
    gravaPontosGrafico(h->intervalos, h->frequencia, numBarras, nomeArquivo);
    plotaHistograma(nomeArquivo);

    //Libera memoria.
    freeHistograma(h);
    free(Exp);
}


/*Testa a distribuição Gaussiana*/
int rodaGau(){

    //Parametros iniciais da Gaussiana:{numero ptos, numero de barras do histograma...}
    int numPontos = 1000000, numBarras = 100, inicio = -4, fim = 4;
    char * arquivo = "Gaussiana.dat";

    //Cria uma distribuicao Gaussiana.
    double * Gau = d_Gaussiana(numPontos);
    histograma * h = calculaFrequencia(Gau, numPontos, numBarras, inicio, fim);

    //Grava arquivo e plota gráfico.
    gravaPontosGrafico(h->intervalos, h->frequencia, numBarras, arquivo);
    plotaHistograma(arquivo);

    //Libera memoria.
    freeHistograma(h);
    free(Gau);

    return 1;
}


/*Testa a distribuição uniforme com frequência relativa.*/
int rodaUniFrequenciaRelativa(){

    //Parametros iniciais da uniforme:{numero ptos, numero de barras do histograma...}
    int numPontos = 1000000, numBarras = 10, inicio = 0, fim = 1;
    char * nomeArquivo = "Uniforme.dat";

    //Cria conjunto de pontos que satisfazem uma distribuição uniforme.
    double * Uni = d_Uniforme(numPontos, seed1);

    //Calcula frequência dos pontos entre as barras definidas.
    histograma * h = calculaFrequencia(Uni, numPontos, numBarras, inicio, fim);

    //Calcula a frequência relativa.
    frequenciaRelativa(h);

    //Grava arquivo e plota gráfico.
    gravaPontosGrafico(h->intervalos, h->frequencia, numBarras+1, nomeArquivo);
    plotaHistograma(nomeArquivo);

    //Libera memoria.
    freeHistograma(h);
    free(Uni);
}


/*Testa a distribuição exponencial com frequência relativa.*/
int rodaExpFrequenciaRelativa(){

    //Parametros iniciais da exponencial:{numero ptos, numero de barras do histograma...}
    int numPontos = 1000000, numBarras = 100, inicio = 0, fim = 8;
    double lambda = 2.0;
    char * nomeArquivo = "Exponencial.dat";

    //Cria uma distribuicao exponencial.
    double * Exp = d_Exponencial(numPontos, lambda);
    histograma * h = calculaFrequencia(Exp, numPontos, numBarras, inicio, fim);

    //Calcula a frequência relativa.
    frequenciaRelativa(h);

    //Grava arquivo e plota gráfico.
    gravaPontosGrafico(h->intervalos, h->frequencia, numBarras, nomeArquivo);
    plotaHistograma(nomeArquivo);

    //Libera memoria.
    freeHistograma(h);
    free(Exp);
}


/*Testa a distribuição Gaussiana com frequência relativa.*/
int rodaGauFrequenciaRelativa(){

    //Parametros iniciais da Gaussiana:{numero ptos, numero de barras do histograma...}
    int numPontos = 1000000, numBarras = 100, inicio = -4, fim = 4;
    char * arquivo = "Gaussiana.dat";

    //Cria uma distribuicao Gaussiana.
    double * Gau = d_Gaussiana(numPontos);
    histograma * h = calculaFrequencia(Gau, numPontos, numBarras, inicio, fim);

    //Calcula a frequência relativa.
    frequenciaRelativa(h);

    //Grava arquivo e plota gráfico.
    gravaPontosGrafico(h->intervalos, h->frequencia, numBarras, arquivo);
    plotaHistograma(arquivo);

    //Libera memoria.
    freeHistograma(h);
    free(Gau);

    return 1;
}


/*-----------------------------Testes de distribuições-----------------------------*/



/*---------------------------Testes de Comandos em Bash----------------------------*/


/*Testa a função de criar diretórios*/
int rodaCriarDiretorios(){

    //Cria 3 diretórios.
    int result = criaDiretorio("plotar");
    int result2 = criaDiretorio("plotar/data");
    int result3 = criaDiretorio("plotar/script");

    //Plota o resultado(sucesso ou fracasso) ao criar diretórios.
    printf("plotar %d \n", result);
    printf("data %d \n", result2);
    printf("script %d \n", result3);

    return 1;
}


/*Testa a função de deletar diretórios*/
int rodaDeletaDiretorios(){

    //Remove um diretório.
    int result = removeDiretorio("plotar");

    //Printa o resultado de tentar remover um diretório.
    printf("plotar %d \n", result);

    return result;
}


/*---------------------------Testes de Comandos em Bash----------------------------*/



/*-------------------------Testes de Alocação de Memória---------------------------*/


/*Testa a função de alocação de memória.*/
int rodaAlocacaoDouble(){

    //Aloca 100 unidades de memoria.
    int tamanhoAlocar = 100;
    double * arrayAlocar = alocaMemoriaDouble(tamanhoAlocar);

    //Tenta utilizar a memoria alocada.
    int i;
    for(i = 0; i < tamanhoAlocar; i++)
        arrayAlocar[i] = 1.111111;

    //Printa a memoria alocada.
    imprimeVetorDoubles(arrayAlocar,tamanhoAlocar);

    //Libera memoria alocada.
    liberaMemoriaDouble(arrayAlocar);
    //free(arrayAlocar);

    //printf("teste %f",arrayAlocar[1]);

    return 1;
}


/*-------------------------Testes de Alocação de Memória---------------------------*/






/*Testa a solução da EDO objetivo do tcc por
meio do algoritmo de Euler.*/
int rodaEulerSolver(){

    int numPontos = 1000000;
    double condicaoInicial = -3,
    parametroA = 1,
    intervaloInfinitesimal = 0.005,
    passoAlgoritmoEuler = 0.005;

    eulerSolver(numPontos, condicaoInicial, parametroA,
                intervaloInfinitesimal, passoAlgoritmoEuler);

    return 1;
}


int rodaEMSolverRuidoLangevin(){//Variar CI e R.

    int numPontos = 70000000;
    double  parametroA = 1,
    passoAlgoritmoEuler = 0.0001,
    numeroIteradas = 10000,
    condicaoInicial = 0.7,
    ruido = 2;

    double * ret = eulerMaruyamaSolverRuidoLangevin(numPontos, condicaoInicial,
                   parametroA, passoAlgoritmoEuler, ruido);

    //Plota arquivo.
    char * nomeArquivo = "Euler Maruyama.dat";
    double * incremento = criarIncremento(numPontos, passoAlgoritmoEuler);
    gravaPontosGrafico2(incremento, ret, numeroIteradas, numPontos, nomeArquivo);
    //plotaFuncao(nomeArquivo);

    //Libera Memoria.
    free(ret);
    free(incremento);
}


int rodaEMSolverRuidoMultiplicativo(){

    int numPontos = 70000000;
    double  parametroA = 1,
    passoAlgoritmoEuler = 0.0001,
    numeroIteradas = 10000,
    condicaoInicial = 0.7,
    ruido = 2;

    double * ret = eulerMaruyamaSolverRuidoMultiplicativo(numPontos, condicaoInicial,
                   parametroA, passoAlgoritmoEuler, ruido);

    //Plota arquivo.
    char * nomeArquivo = "solver.dat";
    double * incremento = criarIncremento(numPontos, passoAlgoritmoEuler);
    gravaPontosGrafico2(incremento, ret, numeroIteradas, numPontos, nomeArquivo);
    plotaFuncao(nomeArquivo);

    //Libera Memoria.
    free(ret);
    free(incremento);
}


int rodaEMSolverRuidoRecursivo(){

    int numPontos = 7000000;
    double parametroA = 1,
    passoAlgoritmoEuler = 0.0000005,
    condicaoInicial = 3,
    ruido = 0.0000005;

    double * ret = eulerMaruyamaSolverRuidoRecursivo(numPontos, condicaoInicial,
                   parametroA, passoAlgoritmoEuler, ruido);

    //Plota arquivo.
    char * nomeArquivo = "solver.dat";
    double * incremento = criarIncremento(numPontos, passoAlgoritmoEuler);
    gravaPontosGrafico(incremento, ret, numPontos, nomeArquivo);
    plotaFuncao(nomeArquivo);

    //Libera Memoria.
    free(ret);
    free(incremento);
}


int rodaSolucaoExata(){

    int numPontos = 5000000;
    int inicio = 0,
        fim = 25;

    double condicaoInicial = -4,
    parametroA = -2,
    passoAlgoritmoEuler = 0.0000005,
    ruido = 0.0000005;

    double * ret = solucaoExataIntegral(parametroA, condicaoInicial,
                                        inicio, fim, passoAlgoritmoEuler);

    //Plota arquivo.
    char * nomeArquivo = "exata.dat";
    double * incremento = criarIncremento(numPontos, passoAlgoritmoEuler);
    gravaPontosGrafico(incremento, ret, numPontos, nomeArquivo);
    plotaFuncao(nomeArquivo);


    //Libera Memoria.
    free(ret);
    free(incremento);

}


/*Testa o gerador de numeros aleatorios*/
int rodaGeradorPseudoAleatorio(){

    geradorDeNumerosAleatorios(10, 1);
    return 1;
}








/*Testa o movimento Browniano.*/
int rodaMovBrow(){

    //Parametros iniciais do movimento Browniano.
    int tamanho = 1, numeroPontos = 1000000;
    char * arquivo = "MovBrowniano.dat";

    double * Dt = incrementoDt(0, 10, (double)tamanho/(double)numeroPontos);
    double * incrementoWiener = (double*)malloc(numeroPontos*sizeof(double));
    double * Brown = movimentoBrowniano(tamanho, numeroPontos, incrementoWiener, 2.0, 1.0);

    //Plota movimento Browniano.
    gravaPontosGrafico(Dt, Brown, numeroPontos, arquivo);
    plotaFuncao(arquivo);

    //Libera memoria.
    free(incrementoWiener);
    free(Brown);
    free(Dt);

    return 1;
}


int rodaMovBrow2(){

    int inicio = 0;
    int fim = 50;
    double incremento = 0.0001;
    int numPontos = (fim-inicio)/incremento;

    double * Dt = criarIncremento(numPontos,incremento);

    double * Brown = movimentoBrowniano2(inicio, fim, incremento, inicio);

    //Plota movimento Browniano
    char * arquivo = "MovBrowniano.dat";
    gravaPontosGrafico(Dt, Brown, numPontos, arquivo);
    plotaFuncao(arquivo);

    //Libera memoria
    free(Brown);
    free(Dt);

    return 1;
}


int rodaMB(){

    int numPontos = 500;
    double condicaoInicial = -4,
    parametroA = -2,
    intervaloInfinitesimal = 0.00005,
    passoAlgoritmoEuler = 0.00005;

    double * Brown = MB(passoAlgoritmoEuler,numPontos,condicaoInicial);

    //Plota movimento Browniano
    char * arquivo = "MovBrowniano.dat";
    double * Dt = criarIncremento(numPontos,passoAlgoritmoEuler);
    gravaPontosGrafico(Dt, Brown, numPontos, arquivo);
    plotaFuncao(arquivo);


    //Libera memoria
    free(Brown);
    free(Dt);

    return 1;
}


/*-------------------------Testes estocásticos.---------------------------*/










//char* array[], char token
//serve para dividir a strings com um patern.
int tokenizer(){
   char string[] = "asd fasd fasdf asdfads fasdf";
   char *tokenPtr;

   //Aponta para o primeiro token.
   tokenPtr = strtok( string, " " );
   printf("Init token %c ", tokenPtr);

   while ( tokenPtr != NULL )
   {//Percorre array como lista ligada.

      printf( "%s\n", tokenPtr );//Imprime token.
      tokenPtr = strtok( NULL, " " );//Divide.
      getchar();
   }

   return 0;
}


double converteStrDouble(){//Converte uma string para double.

  char str[256];
  char * p;
  double dbl;

  //printf("Variavel global errno: %s \n", strerror(errno));
  printf ("Enter a floating-point value: ");
  gets (str);//Le do teclado

  dbl = strtod (str, &p);
  printf ("Value entered: %lf. Its square: %lf\n", dbl, dbl * dbl);
  printf("Variavel global errno: %s", strerror(errno));

  return 0;
}









//Daqui para baixo falta organizar......


/*Testa todas as distribuições e o movimento Browniano*/
int bateriaDeTestes(){

    rodaUni();
    rodaExp();
    rodaGau();
    rodaMovBrow();

    return 1;
}


int testaFuncoes(){
    //converteStrDouble();
    tokenizer();

    return 1;
}


int testaCriarIncremento(){
    double * save = criarIncremento(1000, 0.0001);
    gravaPontosGrafico(save,save,1000,"testes1");

    free(save);
    return 1;
}


int testaEDOSolver(){
    int numPontos = 10000;
    double condicaoInicial = 2;
    double parametroA = 1;
    double intervaloInfinitesimal = 0.00001;
    double passoEuler = 0.005;

    eulerSolver(numPontos, condicaoInicial, parametroA,
                intervaloInfinitesimal, passoEuler );
}


int testeArredondar(int a, int b, double dt){//Ao efetuar esta operacao ele arredonda.

    return (b-a)/dt;
}


int testaEulerSolver2(){
    //Faz sentido definir o intervalo e o tamanho do intervalo infinitesimal.

    double condicaoInicial = -3;
    int inicio = 0;
    int fim = 5;
    double incrementoTempo = 0.000001;
    double parametroA = 2;

    eulerSolver2(condicaoInicial, inicio, fim, incrementoTempo, parametroA);

    return 1;
}


int testaSolucaoExata(){
    int parametroA = 4;
    int condicaoInicial = 2;
    int inicio = 0;
    int fim = 5;
    double passo = 0.000001;

    solucaoExataIntegral(parametroA, condicaoInicial,
                         inicio, fim, passo);

    return 1;
}


