/*Calcula frequencia de pontos entre intervalo de barras.*/
histograma * calculaFrequencia(double * pontos, int numPontos,                               
			       int numBarras, int inicio, int fim){

    histograma * h = inicializaHistograma(numPontos, numBarras);
    h->intervalos = intervaloBarras(numBarras, inicio, fim);

    int i, j;
    for(i = 0; i < numPontos; i++)
        for(j = 0; j < numBarras; j++)

             if(*(pontos+i) >= (h->intervalos)[j] &&
               *(pontos+i) < (h->intervalos)[j+1])

                h->frequencia[j] = h->frequencia[j] + 1;

    return h;
}

/*Calcula a frequencia relativa(divide pelo numero de pontos) dos pontos na distribuicao.*/
void frequenciaRelativa(histograma * h){

    int i;
    for(i = 0; i < h->tamanho; i++){

        double divisao = (h->frequencia)[i] / h->numPontos;
        (h->frequencia)[i] = divisao;
    }
}
