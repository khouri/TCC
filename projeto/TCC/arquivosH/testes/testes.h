/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo h do modulo Testes****************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: Funcoes que efetuam testes unitários, verificam se alguma*********/
/***************alteracao no CF estragou outra parte do sistema*****************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

/*Importa os módulos a serem testados.*/
#include "../estatistica.h"
#include "../distribuicoes.h"
#include "../Integrais/estocastico.h"
#include "../UI/InterfaceUsuario.h"
#include <stdio.h>


/*-----------------------------Testes de distribuições-----------------------------*/


/*Testa a distribuição uniforme, basicamente executa os métodos e
plota um gráfico com a saída.*/
int rodaUni();


/*Testa a distribuição exponencial, basicamente executa os métodos e
plota um gráfico com a saída.*/
int rodaExp();


/*Testa a distribuição Gaussiana, basicamente executa os métodos e
plota um gráfico com a saída.*/
int rodaGau();


/*Testa a distribuição uniforme com a frequência relativa, basicamente
executa os métodos e plota um gráfico com a saída.*/
int rodaUniFrequenciaRelativa();

/*-----------------------------Testes de distribuições-----------------------------*/



/*---------------------------Testes de Comandos em Bash----------------------------*/


/*Testa a criação de diretórios por meio de comando em
Bash invocados pelo programa em C*/
int rodaCriarDiretorios();


/*Testa a deleção de diretórios por meio de comando em
Bash invocados pelo programa em C*/
int rodaDeletaDiretorios();


/*---------------------------Testes de Comandos em Bash----------------------------*/



/*-------------------------Testes de Alocação de Memória---------------------------*/


/*Testa a função de alocação de memória.*/
int rodaAlocacaoDouble();


/*-------------------------Testes de Alocação de Memória---------------------------*/



/*Executa a solução exata da EDO.*/
int rodaSolucaoExataEDO();












//Daqui para baixo falta organizar......


/*Testa a distribuição Exponencial, basicamente executa os métodos e
plota um gráfico com a saída.*/
int rodaMovBrow();


/*Testa todas as distribuições e o movimento Browniano,
basicamente executa os métodos e plota gráficos com as saídas.*/
int bateriaDeTestes();

int tokenizer();


double converteStrDouble();


int testaFuncoes();


int testaCriarIncremento();


int testeArredondar(int a, int b, double dt);


int testaEulerSolver2();


int testaBrow2();


int testaSolucaoExata();
