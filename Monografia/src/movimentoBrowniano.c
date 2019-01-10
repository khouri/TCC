double * movimentoBrowniano(double dt, int numeroPontos, double condicaoInicial){

    srand(101);/*Define semente.*/
    
    double * W = alocaMemoriaDouble(numeroPontos);
    double raizDt = sqrt(dt);//Eficiencia deixa calculado.
    W[0] = 0;/*Atribui a condicao inicial.*/

    int i;
    for(i = 1; i < numeroPontos; i++)/* Xum = Xzero + N(0,1) * sqrt(Dt)*/
        W[i] =  W[i-1] + cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt;

    return W;
}
