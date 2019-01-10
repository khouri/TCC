/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo header do modulo de Script********************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: funcoes que: geram todas as distribuicoes com numero de pontos****/
/***********e barras definidos para possibilitar analise dos mesmos*************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

//Funcao auxiliar que cria um diretorio com nome
//especificado pelo usuario
int criaDiretorio(char * nomeDiretorio);

//Concatena dois arrays de chars, utilizando o separador definido.
char * concatenaChar(char * a, char * b, char * separador);

//Converte dois inteiros em string e concatena ambos.
char * converteEConcatenaInt(int a, int b);

//Script que gera todas as distribuicoes dentro de diretorios
//criados para possibilitar analise.
void geraDist();
