/*Soluciona a EDO com o algoritmo de Euler.*/
double * eulerSolver(int numPontos, double condicaoInicial, double parametroA,
       double intervaloInfinitesimal, double passoAlgoritmoEuler) {

    double * retorno = alocaMemoriaDouble(numPontos);
    retorno[0] = condicaoInicial;
    int i;
    for(i = 1; i < numPontos; i++){

        double XZero = retorno[i-1];
        double XUm = XZero + passoAlgoritmoEuler *
        ( (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) );

        retorno[i] = XUm;
    }
    return retorno;
}

/*Solucao Exata da EDO do TCC, entre dois pontos da mesma.*/
double * solucaoExataIntegral(int parametroA, int condicaoinicial,
       int inicio, int fim, double incrementoTempo) {

    int tam = (fim - inicio)/incrementoTempo;
    double * retorno = alocaMemoriaDouble(tam);
    double * incrementoT = criarIncremento(tam,incrementoTempo);

    int i;//Colocar em um laco.
    retorno[0] = condicaoinicial;
    for(i = 1; i < tam; i++) {

        double tmp = sqrt(1 - (1 - 
	(pow(parametroA, 2) / pow(condicaoinicial , 2))) *
         pow(M_E,(-4 * pow(parametroA,2) * incrementoT[i])));

        retorno[i] = parametroA/(tmp);
    }
    return retorno;
}
