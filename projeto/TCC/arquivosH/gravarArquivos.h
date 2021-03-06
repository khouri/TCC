/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo H do módulo de gravarArquivo******************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: funções que gravam arquivos para serem plotados*******************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include <stdio.h>
#include <stdlib.h>


/*Grava um arquivo texto que representa o gráfico a ser plotado.*/
int gravaPontosGrafico(double * X, double * Y, int tamanho, char * nomeArquivo);


/*Abre um arquivo em modo de escrita.*/
FILE * abreArquivoEscrita(char * nomeArquivo);

