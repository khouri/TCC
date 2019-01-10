/*Cria incremento infinitesimal no tempo.*/
double * criarIncremento(int numPontos, double intervalo){

    double * retorno = alocaMemoriaDouble(numPontos);
    retorno[0] = 0;//Condicao inicial.

    int i;
    for(i = 1;  i < numPontos; i++)
        retorno[i] = retorno[i-1] + intervalo;

    return retorno;
}

