/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do módulo integrais*************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: Solução numérica das integrais************************************/
/***************apresentadas no artigo do Higham********************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../../arquivosH/Integrais/IntegraisArtigo.h"
#include "../../arquivosH/distribuicoes.h"
#define frand() ((double)rand())/(RAND_MAX+1.)

/*Simula o movimento Browniano*/
/*
double * MB(double dt, int numeroPontos, double condicaoInicial)
{
    double * W = alocaMemoriaDouble(numeroPontos);
    double * incrementoWiener = alocaMemoriaDouble(numeroPontos);

    //Conjunto de numeros que satisfaz uma dist. Gaussiana.
    double * gaussiana = alocaMemoriaDouble(numeroPontos);
    gaussiana = d_Gaussiana(numeroPontos);

    //atribui os primeiros valores.
    *(incrementoWiener) = *(gaussiana+0) * sqrt(dt);
    *(W)  = *(incrementoWiener+0);

    int counter;
    for(counter = 1; counter < numeroPontos; counter++)
    {
        *(incrementoWiener+counter) =  *(gaussiana+counter) * sqrt(dt);
        *(W+counter)  =  *(W+(counter-1)) + *(incrementoWiener+counter);
    }

    liberaMemoriaDouble(gaussiana);
    liberaMemoriaDouble(incrementoWiener);

    return W;
}
*/


double * MB(double dt, int numeroPontos, double condicaoInicial) {

    srand(101);/*Define semente.*/
    double * W = alocaMemoriaDouble(numeroPontos);
    double raizDt = sqrt(dt);/*Num tinha feito.*/

    W[0] = 0;/*Atribui a condicao inicial.*/

    int i;
    for(i = 1; i < numeroPontos; i++)
        /* Xum = Xzero + N(0,1) * sqrt(Dt)*/
        W[i] =  W[i-1] + cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt;

    return W;
}


//Defasado :(
double * movimentoBrowniano(int intervalo, int numeroPontos, double * incrementoWiener,
                            double condicaoInicial, double ruido) {//Simula o movimento Browniano.

    double dt = (double)intervalo/(double)numeroPontos;//Incremento.
    double * W = (double*)malloc(numeroPontos*sizeof(double));//Pontos discretos de Brown.

    //Conjunto de numeros que satisfaz uma dist. Gaussiana.
    double* gaussiana = (double*)malloc((numeroPontos)*sizeof(double));
    gaussiana = d_Gaussiana(numeroPontos);

    //atribui os primeiros valores.
    *(incrementoWiener) = *(gaussiana+0) * sqrt(dt);
    *(W)  = *(incrementoWiener+0);

    int counter;
    for(counter = 1; counter < numeroPontos; counter++)
    {
        *(incrementoWiener+counter) =  *(gaussiana+counter) * sqrt(dt);
        *(W+counter)  =  *(W+(counter-1)) + *(incrementoWiener+counter);
    }

    free(gaussiana);
    return W;
}


double integralITO() {
    //Calcula uma integral de ito.

    int tamanho = 1;
    int pontos = 500;
    double ito = 0;

    //Obtem o incremento do movimento browniano e o valor da var aleatoria browniana.
    double* dW = (double*)malloc(pontos*sizeof(double));
    double* W = movimentoBrowniano(tamanho, pontos, dW, 2.0, 1.2);

    //Calcula a soma das areas cuja base tende a 0(limite)
    //Aqui eh calculada a integral do movimento browniano.
    int counter;
    for(counter = 1; counter < pontos; counter++)
        ito = ito + ( *(W+counter-1) * (*(dW+counter)) );

    //Libera a memoria
    free(dW);
    free(W);

    return ito;
}


//Essa funcao deve ser deletada.
void eulerMaruyama(int EM) {//Para testes.
    //Algoritmo de EM x algoritmo exato.

    printf("cai");
    // Obtem o incremento do movimento
    //browniano e o valor da var aleatoria browniana.
    int tamanho = 1;
    int pontos = pow(2,8);
    double * dW = (double*)malloc(pontos*sizeof(double));
    double * W = movimentoBrowniano(tamanho, pontos, dW, 2.3, 1.2);
    char * nome = "Exactly_exp.dat";
    char * nome2 = "EM_exp.dat";

    int lambda = 2;
    int mi = 1;
    int xZero = 1;
    int T = 1;
    double N = pow(2,8);
    double dt = 1/N;
    int nPontos = (int)T/dt;
    double R = 6;

    double L = (int)N/R;
    double R_Dt = R*dt;
    printf("%d",nPontos);

    int aux = 1;

    if(EM == 1)
    {
        //Metodo aproximado

        double * Xem = (double*)malloc((nPontos)*sizeof(double));//Solucao aproximada.
        double Xtemp = xZero;

        //printf("Valor de L %d \n",L);
        int i;
        for(i = 0; i < L ; i++)
        {
            double Winc = somaPosicoesArray( (R*i) , R*(i+1), dW);
            Xtemp = Xtemp + (R_Dt*lambda*Xtemp) + Xtemp*Winc*mi;
            *(Xem+i) = Xtemp;
        }

        printf("Valor do contador %d \n",i);

        //getchar();
        //Cria o array: ([dt:dt:T])
        double * dT = incrementoDt(0,R_Dt,T);//Ok!

        gravaPontosGrafico(dT,Xem,(int)L-1,nome2);
        plotaFuncao(nome2);

        free(Xem);
        free(dT);
    }


    if(EM == 0)
    {
        //Solucao exata de EM.

        //Retorna um n negativo, faz sentido meu mov
        //browniano(500 pts) esta mais para baixo que p cima.
        //Logo a soma eh negativa.
        double somaW = somaPosicoesArray(0,pontos,W);

        //Calcula Xtrue, que eh a solução exata.
        double * Xtrue = (double*)malloc((nPontos)*sizeof(double));

        //X*lambda
        double lambdaX = lambda-0.5*pow(mi,2);
        //printf("lambdaX %f",lambdaX);//1.5

        //Cria o array: ([dt:dt:T]), que na prática representa o incremento deterministico
        double * dT = incrementoDt(0,dt,T);
        //printArray(dT,nPontos);

        //Multiplica o incremento deterministico pelo lambda
        //Lambda X(t) dt
        double * lambdaXDt = multiplicaNumeroVetor(lambdaX, dT, nPontos);

        //mi*W, representa a constante real mi multiplicando o incremento de wiener
        double * miW = multiplicaNumeroVetor(mi,W,nPontos);
        //printArray(miW,nPontos);

        //Aqui está errado.
        //X+mi*dW
        double * miW_dT = somaDoisArrays(lambdaXDt, miW, nPontos);
        //printArray(miW_dT,nPontos);

        //double * expoente = multiplicaNumeroVetor(lambdaX, miW_dT, nPontos);
        //printArray(expoente,nPontos);

        //eleva tudo a funcao exp();
        double * exponencial = exponenciaNumeroVetor(1,miW_dT,nPontos);

        //printArray(exponencial,nPontos);

        gravaPontosGrafico(dT,exponencial,nPontos-1,nome);
        plotaFuncao(nome);


        //Libera a memoria utilizada
        free(dT);
        free(exponencial);
        free(miW_dT);
        free(W);
        free(dW);
        free(Xtrue);
//        free(expoente);
        free(miW);
    }
}


