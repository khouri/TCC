/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo H do módulo integrais*************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: Solução numérica das integrais************************************/
/***************objetivo do TCC*************************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/




/*Soluciona a equação do artigo lido utilizando
apenas o algoritmo de Euler.*/
double * eulerSolver(int numPontos, double condicaoInicial, double parametroA,
                     double intervaloInfinitesimal, double passoAlgoritmoEuler);


/*Soluciona a EDE com o algoritmo de EM, ruído = sigma.*/
double * eulerMaruyamaSolverRuidoLangevin(int numPontos, double condicaoInicial,
         double parametroA, double passoAlgoritmoEuler, double ruidoLangevin);


/*Soluciona a EDE com o algoritmo de EM, ruído = *X_(n-1)*/
double * eulerMaruyamaSolverRuidoMultiplicativo(int numPontos, double condicaoInicial,
         double parametroA, double passoAlgoritmoEuler, double sigma);


/*Soluciona a EDE com o algoritmo de EM,
ruído = (-2 * XZero) * (XZero - parametroA) * (XZero + parametroA) )*/
double * eulerMaruyamaSolverRuidoRecursivo(int numPontos, double condicaoInicial,
         double parametroA, double passoAlgoritmoEuler, double sigma);













//Outra implementação.
double * eulerMaruyamaSolver2(int inicio, int fim, int parametroA,
                             double incrementoTempo, double posicaoInicial);


double * eulerSolver2(double condicaoInicial, int inicio,
            int fim, double incrementoTempo, double parametroA);


double * movimentoBrowniano2(int inicio, int fim,
                             double incrementoTempo, double posicaoInicial);



double * solucaoExataIntegral(int parametroA, int condicaoinicial,
                              int inicio, int fim, double incrementoTempo);
