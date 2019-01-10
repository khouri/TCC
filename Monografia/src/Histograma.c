//Estrutura que representa um histograma
typedef struct
{
    int tamanho;//Tamanho do array.
    double * intervalos;//Intervalos em x entre barras.
    double * frequencia;//Frequencia dos pontos nas barras.
    int numPontos;

}histograma;

/*Aloca memoria para a struct histograma.*/
histograma * inicializaHistograma(int numPontos, int numBarras){

    histograma * h = (histograma*) malloc(sizeof(histograma));
    h->frequencia = alocaMemoriaDouble(numBarras);
    h->intervalos = alocaMemoriaDouble(numBarras+1);
    h->numPontos = numPontos;
    h->tamanho = numBarras;

    return h;
}

/*Libera memoria do ponteiro de histograma.*/
void freeHistograma(histograma * liberar){

    liberaMemoriaDouble(liberar->frequencia);
    liberaMemoriaDouble(liberar->intervalos);
    free(liberar);
}
