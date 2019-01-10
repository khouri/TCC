/*Soluciona a EDE com o algoritmo de EM.*/
double * EulerMaruyamaRecursivo(int numPontos, double condicaoInicial,
                    double parametroA, double passoAlgoritmoEuler, double sigma) {

    srand(101);/*Define semente.*/
    double * retorno = alocaMemoriaDouble(numPontos);//Solucao por EM.
    retorno[0] = condicaoInicial;//Condicao incial.
    double raizDt = sqrt(passoAlgoritmoEuler);

    int i;
    for(i = 1; i < numPontos; i++) {

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + (passoAlgoritmoEuler *
        ((-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) )) +
        (cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt * //N(0,1) * sqrt(Dt)
        sigma *
        (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA));

        retorno[i] = XUm;
    }
    return retorno;
}
