/*Gera um conjunto de numeros satisfazendo uma dist. Gaussiana*/
double * d_Gaussiana(int numPontos){

    //Define duas dist. uniformes auxiliares.
    double * U1 = d_Uniforme(numPontos, seed1);
    double * U2 = d_Uniforme(numPontos, seed2);

    //Vetor de doubles com a distribuicao Gaussiana.
    double * gau = alocaMemoriaDouble(numPontos);

    int i;
    for(i = 0; i < numPontos; i++)
    {
        double cosseno = cos( U2[i] * 2 * PI);//cos(U2)*2*PI.
        double ln = sqrt(-2 * log(U1[i]) );//sqrt(-2log(U1)*2*PI).
        gau[i] = cosseno * ln; //sqrt(-2log(U1)*2*PI) * cos(U2)*2*PI
    }

    //Libera a memoria das dist. auxiliares.
    liberaMemoriaDouble(U1);
    liberaMemoriaDouble(U2);

    return gau;
}
