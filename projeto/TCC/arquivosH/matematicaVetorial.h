/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo H do módulo matematica vetorial***************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: aplica operações aritméticas simples******************************/
/***************em vetores unidimensionais**************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


/*Soma todas as posições de dois arrays e retorna um
terceiro array com o resultado de cada soma*/
double * somaDoisArrays(double * a, double * b, int tamanho);


/*Soma todos os valores de cada posição do vetor e
retorna um resultado escalar*/
double somaPosicoesArray(int inicio, int fim, double * array);


/*----------------------Aplica operações aritméticas escalares em vetores-----------------------*/


/*Tira o exp(x) de cada posição do vetor.*/
double * exponenciaNumeroVetor(double numero, double * array, int tamanhoArray);


/*Multiplica cada posição de um vetor por um número.*/
double * multiplicaNumeroVetor(double numero, double * array, int tamanhoArray);


/*Adiciona um número a cada posição do vetor.*/
double * somaNumeroVetor(double numero, double * array, int tamanhoArray);


/*----------------------Aplica operações aritméticas escalares em vetores-----------------------*/

