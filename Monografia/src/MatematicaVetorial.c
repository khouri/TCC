/*Multiplica todos os elementos do array por um numero.*/
double * multiplicaNumeroVetor(double numero, double * array, int tamanhoVetor){

    double * retorno = alocaMemoriaDouble(tamanhoVetor);
    int i;//contador.
    for(i = 0; i < tamanhoVetor ; i++)
        retorno[i] = array[i] * numero;

    return retorno;
}

/*Adiciona a todos os elementos do array um numero.*/
double * somaNumeroVetor(double numero, double * array, int tamanhoVetor){

    double * retorno = alocaMemoriaDouble(tamanhoVetor);
    int i;
    for(i = 0; i < tamanhoVetor ; i++)
        retorno[i] = array[i] + numero;

    return retorno;
}

/*Soma um intervalo de posicoes do array SUM(array[3-5])*/
double somaPosicoesArray(int inicio, int fim, double * array){

    double soma = 0;
    int i;//contador.
    for(i = inicio; i < fim; i++)
        soma = soma + array[i];

    return soma;
}
