/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo H do modulo Helper****************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: funções que auxiliam a lógica da aplicação************************/
/***************mas que não se relacionam com a lógica diretamente, alguns******************/
/***************exemplos: alocar memória, dividir strings...********************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


/*-------------------------Alocação de Memória---------------------------*/


/*Aloca uma quantidade de memória para doubles*/
double * alocaMemoriaDouble(int tamanhoAlocar);


/*Libera memória de vetor de double.*/
void liberaMemoriaDouble(double * liberar);


/*-------------------------Alocação de Memória---------------------------*/



/*-------------------------Impressão no console---------------------------*/


/*Imprime array de inteiros.*/
void printArrayInt(int * arrayToPrint, int sizeArray);


/*Imprime array de doubles.*/
void printArray(double * arrayToPrint, int sizeArray);


/*Pula uma linha na hora de printar na tela*/
void pulaLinha();


/*-------------------------Impressão no console---------------------------*/


/*Gerador de numeros pseudo aleatorios.*/
void geraAleatorios(int n);



/*-------------------------------Strings----------------------------------*/


char * concatenaStrings(char * a, char * b);


/*-------------------------------Strings----------------------------------*/


