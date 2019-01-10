/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do módulo integrais*************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: Solução numérica das integrais************************************/
/***************objetivo do TCC*************************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "../../arquivosH/Integrais/IntegraisTCC.h"
#include "../../arquivosH/matematicaVetorial.h"
#include "../../arquivosH/distribuicoes.h"
#include "../../arquivosH/Integrais/IntegraisArtigo.h"
#define frand() ((double)rand())/(RAND_MAX+1.)


/*TCC*/


//Defasado.
/*Soluciona a EDO com o algoritmo de Euler.*/
double * eulerSolver(int numPontos, double condicaoInicial, double parametroA,
                     double intervaloInfinitesimal, double passoAlgoritmoEuler) {

    double * retorno = (double*)malloc(numPontos*sizeof(double));
    retorno[0] = condicaoInicial;//Condicao incial.

    double * incremento =
        criarIncremento(numPontos, intervaloInfinitesimal);//Incremento no tempo.

    int i;//Contador.
    for(i = 1; i < numPontos; i++)
    {//X(1) = X(0) + passo * (-2 * X(0) * (X(0) - a) * (X(0) + a)); //Euler.

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + passoAlgoritmoEuler *
        ( (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) );

        retorno[i] = XUm;//Armazena resultado.
    }

    //Plota arquivo.
    char * nomeArquivo = "solver.dat";
    gravaPontosGrafico(incremento, retorno, numPontos, nomeArquivo);
    plotaFuncao(nomeArquivo);

    //Libera Memoria.
    free(retorno);
    free(incremento);

    return retorno;
}


/*Soluciona a EDE com o algoritmo de EM, ruído = sigma.*/
double * eulerMaruyamaSolverRuidoLangevin(int numPontos, double condicaoInicial,
                     double parametroA, double passoAlgoritmoEuler, double sigma) {

    srand(101);/*Define semente.*/
    double * retorno = alocaMemoriaDouble(numPontos);//Solucao por EM.
    retorno[0] = condicaoInicial;//Condicao incial.
    double raizDt = sqrt(passoAlgoritmoEuler);/*Num tinha feito.*/

    int i;//Contador.
    for(i = 1; i < numPontos; i++) {

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + (passoAlgoritmoEuler * //Euler
        ((-2 * XZero) * (XZero - parametroA) * (XZero + parametroA))) + //Euler

        (cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt * //N(0,1) * sqrt(Dt)
        sigma);//Ruido Langevin.

        retorno[i] = XUm;//Armazena resultado.
    }

    return retorno;
}


/*Soluciona a EDE com o algoritmo de EM, ruído = *X_(n-1)*/
double * eulerMaruyamaSolverRuidoMultiplicativo(int numPontos, double condicaoInicial,
                    double parametroA, double passoAlgoritmoEuler, double sigma) {

    srand(101);/*Define semente.*/
    double * retorno = alocaMemoriaDouble(numPontos);//Solucao por EM.
    retorno[0] = condicaoInicial;//Condicao incial.
    double raizDt = sqrt(passoAlgoritmoEuler);/*Num tinha feito.*/

    int i;//Contador.
    for(i = 1; i < numPontos; i++) {

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + (passoAlgoritmoEuler *
        ((-2 * XZero) * (XZero - parametroA) * (XZero + parametroA))) +

        (cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt * //N(0,1) * sqrt(Dt)
        sigma *

        XZero);//Ruido Multiplicativo.

        retorno[i] = XUm;//Armazena resultado.
    }

    return retorno;
}


/*Soluciona a EDE com o algoritmo de EM,
ruído = (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) )*/
double * eulerMaruyamaSolverRuidoRecursivo(int numPontos, double condicaoInicial,
                    double parametroA, double passoAlgoritmoEuler, double sigma) {

    srand(101);/*Define semente.*/
    double * retorno = alocaMemoriaDouble(numPontos);//Solucao por EM.
    retorno[0] = condicaoInicial;//Condicao incial.
    double raizDt = sqrt(passoAlgoritmoEuler);/*Num tinha feito.*/

    int i;//Contador.
    for(i = 1; i < numPontos; i++) {

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + (passoAlgoritmoEuler *
        ((-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) )) +
        (cos(frand() * 2 * PI) * sqrt(-2 * log(frand())) * raizDt * //N(0,1) * sqrt(Dt)
        sigma *

        (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA));

        retorno[i] = XUm;//Armazena resultado.
    }

    return retorno;
}



/*Solução Exata da EDO do TCC.*/
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

        double aux = parametroA/(tmp);
        retorno[i] = aux;
    }

    return retorno;
}



/*TCC*/





















//Outra implementação.
/* Solution EM da equacao do TCC */


double * eulerMaruyamaSolver2(int inicio, int fim, int parametroA,
                             double incrementoTempo, double posicaoInicial)
{
    //Obtem ruido branco(Mov Browniano), estudar ruido branco e defini-lo.
    double * MovBrown = movimentoBrowniano2(inicio,fim,
                        incrementoTempo, posicaoInicial);

    int tam = (fim - inicio)/incrementoTempo;
    double * retorno = (double*)malloc(tam*sizeof(double));
    retorno[0] = posicaoInicial;//Condicao incial.

    int i;//Contador.
    for(i = 1; i < tam; i++)
    {//X(1) = X(0) + passo * (-2 * X(0) * (X(0) - a) * (X(0) + a)) + MovBrowniano; //Euler-Maruyama.

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + incrementoTempo * ( (-2 * XZero) * (XZero - parametroA) *
         (XZero + parametroA) + //termo deterministico.
         MovBrown[i-1]);//termo estocastico

        retorno[i] = XUm;//Armazena resultado.
    }

    return retorno;
}


double * eulerSolver2(double condicaoInicial, int inicio,
            int fim, double incrementoTempo, double parametroA)
{/*Soluciona a EDO com o algoritmo de Euler.*/

    int tam = (fim - inicio)/incrementoTempo;
    //printf(" tam %d ",tam);

    double * retorno = (double*)malloc(tam*sizeof(double));
    retorno[0] = condicaoInicial;//Condicao incial.
    double * incremento =
            criarIncremento(tam, incrementoTempo);//Incremento no tempo.

    int i;//Contador.
    for(i = 1; i < tam; i++)
    {//X(1) = X(0) + passo * (-2 * X(0) * (X(0) - a) * (X(0) + a)); //Euler.

        double XZero = retorno[i-1];//Valor anterior.
        double XUm = XZero + incrementoTempo *
        ( (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) );

        retorno[i] = XUm;//Armazena resultado.
    }

    //Plota arquivo.
    char * nomeArquivo = "solver.dat";
    gravaPontosGrafico(incremento, retorno, tam, nomeArquivo);
    plotaFuncao(nomeArquivo);

    //Libera Memoria.
    free(retorno);
    free(incremento);

    return retorno;
}


double * movimentoBrowniano2(int inicio, int fim,
                             double incrementoTempo, double posicaoInicial)
{//Simula o movimento Browniano.

    double tam = (fim - inicio)/incrementoTempo;//Incremento.
    double * W = (double*)malloc(tam*sizeof(double));//Pontos discretos de Brown.

    //Conjunto de numeros que satisfaz uma dist. Gaussiana.
    double * gaussiana = (double*)malloc((tam)*sizeof(double));
    gaussiana = d_Gaussiana(tam);

    double tmp = posicaoInicial;//*(gaussiana+0) * sqrt(incrementoTempo);
    //atribui os primeiros valores.
    //*(incrementoWiener) = *(gaussiana+0) * sqrt(incrementoTempo);
    *(W)  = tmp;

    int counter;
    for(counter = 1; counter < tam; counter++)
    {
        //*(incrementoWiener+counter) =  *(gaussiana+counter) * sqrt(incrementoTempo);
         tmp = *(gaussiana+counter) * sqrt(incrementoTempo);
        *(W+counter)  =  *(W+(counter-1)) + tmp;
    }

    free(gaussiana);
    return W;
}



/* Solution EM da equacao do TCC */
