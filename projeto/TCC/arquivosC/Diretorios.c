/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo Fonte do modulo de Arquivos*******************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: Cria/Lê/Altera , diretórios e verifica****************************/
/***************o resultado dessas operações com funções auxiliares*************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../arquivosH/Diretorios.h"


/*Cria um diretório no local passado como parâmetro.*/
int criaDiretorio(char * nomeDiretorio){

    //Comando sem parametro para criar um diretorio em Linux.
    char comando[9] = {'m','k','d','i','r',' ','-','p',' '};

    char * concatenado[100];//Concatena comando e nome do diretorio.
    sprintf(concatenado, "%s %s ",comando, nomeDiretorio);

    //Executa o comando.
    int resultado = system(concatenado);
    resultado = validaCriacaoDiretorio(resultado);

    return resultado;
}


/*Verifica se o diretório foi criado com sucesso ou
se o fileSystem retornou erros.*/
int validaCriacaoDiretorio(int resultado){

    int retorno = -1;
    if (!resultado)//Criou diretorio.
        retorno = 0;

    else//Erro ao criar diretorio.
        exit(1);

    return retorno;
}


/*Remove uma árvore de diretórios, onde nomeDiretorios
 é a raiz da árvore*/
int removeDiretorio(char * nomeDiretorio){

    int retorno = 0;
    char comando[7] = {'r','m',' ','-','R','f',' '};

    char * concatenado[100];//Concatena comando e nome do diretório.
    sprintf(concatenado, "%s %s ",comando, nomeDiretorio);

    //Executa o comando.
    int resultado = system(concatenado);

    return retorno;
}


