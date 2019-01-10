/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do módulo de estatísticas*******************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: função que calcula histograma, funções auxiliares para************/
/***************calcular o histograma e uma struct que representa um histograma*************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../arquivosH/estatistica.h"


/*---------------------Definir intervalo entre barras do histograma-----------------------*/


/*Calcula a largura do gráfico.*/
double dominioGrafico(double inicio, double fim){

    int retorno = 0;
    if(inicio >= 0 && fim >= 0)//Ambos positivos.
        retorno = fim - inicio;

    else if(inicio <= 0 && fim <= 0)//Ambos negativos.
        retorno = inicio - fim;

    else//Sinais diferentes.
        retorno = fim - inicio;

    return retorno;
}


/*Calcula a largura de uma barra do histograma.*/
double larguraBarraHistograma(double inicioGrafico, double fimGrafico, int numBarras){

    int larguraGrafico = dominioGrafico(inicioGrafico, fimGrafico);//Largura do grafico.
    double tamBarra = (double)larguraGrafico/(double)numBarras;//Largura de cada barra.

    return tamBarra;
}


/*Retorna os intervalos entre barras do histograma a ser plotado.*/
double * intervaloBarras(int numBarras, double inicio, double fim){

    double tamBarra = larguraBarraHistograma(inicio, fim, numBarras);
    double * intervalosEntreBarras = alocaMemoriaDouble(numBarras+1);

    int i;
    for(i = 0; i <= numBarras; i++)
        intervalosEntreBarras[i] = (tamBarra * i) + inicio;

    return intervalosEntreBarras;
}


/*---------------------Definir intervalo entre barras do histograma-----------------------*/



/*--------------------------Utiliza a estrutura de histograma----------------------------*/


/*Aloca memória para a struct histograma.*/
histograma * inicializaHistograma(int numPontos, int numBarras){

    histograma * h = (histograma*) malloc(sizeof(histograma));
    h->frequencia = alocaMemoriaDouble(numBarras);
    h->intervalos = alocaMemoriaDouble(numBarras+1);
    h->numPontos = numPontos;
    h->tamanho = numBarras;

    return h;
}


/*Libera memória do ponteiro de histograma.*/
void freeHistograma(histograma * liberar){

    liberaMemoriaDouble(liberar->frequencia);
    liberaMemoriaDouble(liberar->intervalos);
    free(liberar);
}


/*Calcula frequência de pontos entre intervalo de barras.*/
histograma * calculaFrequencia(double * pontos, int numPontos,
                               int numBarras, int inicio, int fim){

    //Inicializa histograma.
    histograma * h = inicializaHistograma(numPontos, numBarras);
    h->intervalos = intervaloBarras(numBarras, inicio, fim);

    int i, j;//Contadores de loop.
    //Calcula frequência dos pontos nos intervalos entre barras.
    for(i = 0; i < numPontos; i++)
        for(j = 0; j < numBarras; j++)

             if(*(pontos+i) >= (h->intervalos)[j] &&
               *(pontos+i) < (h->intervalos)[j+1])

                h->frequencia[j] = h->frequencia[j] + 1;

    return h;
}


/*Calcula a frequência relativa(divide pelo número de pontos)
dos pontos na distribuição.*/
void frequenciaRelativa(histograma * h){

    int i;//contador.
    for(i = 0; i < h->tamanho; i++)
    {//Calcula a frequencia relativa.

        double divisao = (h->frequencia)[i] / h->numPontos;
        (h->frequencia)[i] = divisao;
    }
}


/*--------------------------Utiliza a estrutura de histograma----------------------------*/

