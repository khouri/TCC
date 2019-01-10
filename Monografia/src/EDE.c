/*teste*/
double solucao(int numPontos, double condicaoInicial, double parametroA, 
               double passoAlgoritmoEuler, double sigma) {

    srand(101);/*Define semente.*/
    double * retorno = alocaMemoriaDouble(numPontos);
    retorno[0] = condicaoInicial;
    double raizDt = sqrt(passoAlgoritmoEuler);

    int i;//Contador.
    for(i = 1; i < numPontos; i++) {
        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + (passoAlgoritmoEuler *
        ((-2 * XZero) * (XZero - parametroA) * (XZero + parametroA))) +
        (cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt * sigma);

        retorno[i] = XUm;//Armazena resultado.
    }
    return retorno;
}
