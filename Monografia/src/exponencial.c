/*Gera um conjunto de numeros satisfazendo uma dist. exponencial.*/
double * d_Exponencial(int numPontos, double lambda){

    //Vetor de doubles com a distribuicao exponencial.
    double * exp = alocaMemoriaDouble(numPontos);
    double * U1 = d_Uniforme(numPontos, 100);

    int i = 0;//contador
    for(i = 0; i < numPontos; i++)
        exp[i] = -1.0/lambda * log((1.- U1[i]));

    //Libera memoria da uniforme auxiliar.
    liberaMemoriaDouble(U1);

    return exp;
}
