/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do modulo de interface homen maquina********************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteudo: Mensagens informativas para o usuario,****************************/
/***************menu de opcoes, e metodos de linha de comando*******************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "../../arquivosH/UI/InterfaceUsuario.h"

void m_bemVindoAoSw(char * acrescimo)
{//Mensagem de inicializacao.

    printf("Seja bem vindo ao TCC %s", acrescimo);
}

void m_obrigadoVolteSempre(char * acrescimo)
{//Mensagem de termino.

    printf("Obrigado por utilizar nosso Sw volte sempre %s",acrescimo);
}

void m_menuOpcoesDistribuicoes(char * opcao1, char * opcao2, char * opcao3)
{//Menu de distribuicoes.

    printf("Digite %s para criar uma distribuição normal.",opcao1);
    printf("Digite %s para criar uma distribuição exponencial.",opcao2);
    printf("Digite %s para criar uma distribuição uniforme.",opcao3);
}

void m_menuOpcoesEstocastico(char * opcao1, char * opcao2)
{//Menu de operacoes estocasticas.

    printf("Digite %s para simular o movimento Browniano.",opcao1);
    printf("Digite %s para solucionar a integral atraves de EM.",opcao2);
}

void m_menuGraficos(char * opcao1, char * opcao2)
{//Menu de gravar graficos.

    printf("Digite %s para criar um grafico com configuracoes default.",opcao1);
    printf("Digite %s para customizar o grafico(avancado).",opcao2);
}


//Criar metodos que invoquem o scanner.
//...

void m_menuGeral()
{
    int exit = 1;
    while(exit == 1)
    {//Menu geral

        /*Criar uma variavel de farol para verificar
        se o usuario decidiu sair da aplicacao.*/

        //Mensagem de boas vindas para o usuario.
        m_bemVindoAoSw("");
        //Menus de opcao.

        //Invoca scanner.

        if(exit == 0){}
            //Mensagem de adeus.

    }
}



/*Deve ir para a camada de FileSystem*/
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************************Arquivo texto*****************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


int metodoXXX()
{

    //printf(" %s ", operacoes);
    return 1;
}
