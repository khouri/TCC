/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo header do modulo estocastico******************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: Algoritmo de Euler Maruyama, Mov. Browniano***********************/
/***************integral de Ito, incremento no tempo****************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../../arquivosH/distribuicoes.h"
#include "../../arquivosH/matematicaVetorial.h"
#include "../../arquivosH/Integrais/estocastico.h"


double * incrementoDt(int inicio, int fim, double intervalo)
{//Cria um incremento infinitesimal.

    double tamanhoArray = fim/intervalo;
    double * arrayDt = (double*)malloc(tamanhoArray*sizeof(double));
    int aux = intervalo;

    //Inicializa array com intervalos de dt.
    double contador;
    int i = 0;
    for(contador = 0; contador < fim; contador = contador + intervalo)
    {
        //Itera sobre os incrementos dt.
        *(arrayDt+i) = contador;
        i++;
    }

    return arrayDt;
}


//Essa função está duplicada aqui :(, uma delas vai sair.
double * criarIncremento(int numPontos, double intervalo)
{//Cria o incremento em t.

    double * retorno = (double*)malloc(numPontos*sizeof(double));
    retorno[0] = 0;//Condicao inicial.

    int i;
    for(i = 1;  i < numPontos; i++)
        retorno[i] = retorno[i-1] + intervalo;

    return retorno;
}



//Colocar o movimento Browniano aqui.



//Essa está errada num resolve o problema do Tcc.
int solucionaEquacaoEM() {
    //soluciona a equacao problema do tcc. EM

    int intervalo = 1;//Intervalo da integral.
    int numPontos = pow(2,8);//Numero de pontos do movimento browniano.
    double * dW = (double*)malloc(numPontos*sizeof(double));
    double * W = movimentoBrowniano(intervalo, numPontos, dW, 2.1,3.2);

    //Constantes para ajustes.
    int lambda = 2;
    int mi = 1;

    /*Intervalo infinitesimal.*/
    double R = 6;
    double dt = 1/(double)numPontos;
    double R_Dt = R*dt;

    int xZero = 1;//posicao inicial.
    double L = (int)numPontos/R;

    //Solucao aproximada.
    double * Xem = (double*)malloc((numPontos)*sizeof(double));
    double Xtemp = xZero;//Variavel auxiliar.

    int i;
    for(i = 0; i < L ; i++)
    {//Aplica o algoritmo de EM.

        double Winc = somaPosicoesArray( (R*i) , R*(i+1), dW);
        Xtemp = Xtemp + (R_Dt*lambda*Xtemp) + Xtemp*Winc*mi;
        *(Xem+i) = Xtemp;
    }

    //Calcula os incrementos.
    double * dT = incrementoDt(0, R_Dt, intervalo);

    //Nome do arquivo de dados para plotagem.
    char * nome2 = "EM_exp.dat";

    //Grava arquivo de dados e plota.
    gravaPontosGrafico(dT,Xem,(int)L-1,nome2);
    plotaFuncao(nome2);

    //Libera memoria.
    free(Xem);
    free(dT);

    return 1;
}


