/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do módulo UI********************************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: funções que permitem ao usuário entrar com dados,*****************/
/***************através de linha de comando*************************************************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


#include "../../arquivosH/UI/UIConsole.h"


/*Leitura de teclado.*/
int linhaComando(){

    char arr[70];

    printf("Jovem, digite um valor: ");
    scanf("%[^\n]", arr);//Le uma linha inteira(espacos em branco) do scanf.

    printf("o valor lido do teclado foi: %s ", arr);

    //strcmp();
    if(strcmp(arr,"aa") == 0)
        printf("\n\n oxy \n\n");

//    if(strcmp(arr,"\n") == 0)
//        printf("\n\n oxy22 \n\n");

    return 1;
}


/*Mensagem informativa que indica ao usuário
que o comando é inválido.*/
void m_comandoInexistente(){

    printf("O comando digitado nao eh valido, digite -h para obter ajuda!");
}


/*Mensagens informativas de ajuda, explicam
todos os parâmetros.*/
void m_Help(){

    char * gau = "Digite -g para calcular uma gaussiana \n";
    char * exp = "Digite -e para calcular uma exponencial \n";
    char * uni = "Digite -u para calcular uma uniforme \n";
    char * mBrow = "Digite -mb para calcular um movimento browniano \n";
    char * help = "Digite -h para help \n";
    char * plotar = "Digite -p para plotar um grafico \n";
    char * em = "Digite -em para solucionar a equacao estocastica \n";

    printf(" %s %s %s %s %s %s %s ",gau, exp, uni, mBrow, help, plotar, em);
}


//Colocar como define no '.h'
char * gaussiana = "-g";
char * exponencial = "-e";
char * uniforme = "-u";
char * movBrowniano = "-mb";
char * help = "-h";
char * plotarGrafico = "-p";
char * eMaruyama = "-em";
char * carregarDados = "-c";


/*Decide quais funcoes chamar baseado na
entrada do usuario.*/
int menuLinhaComando(char args[][5])
{

    if(strcmp(args[1], gaussiana) == 0)
    {

    }

    else if(strcmp(args[1], exponencial) == 0)
    {

    }

    else if(strcmp(args[1], uniforme) == 0)
    {

    }

    else if(strcmp(args[1], movBrowniano) == 0)
    {

    }

    else if(strcmp(args[1], plotarGrafico) == 0)
    {

    }

    else if(strcmp(args[1], eMaruyama) == 0)
    {

    }

    else if(strcmp(args[1], carregarDados) == 0)
    {

    }

    else if(strcmp(args[1],help) == 0)
        m_Help();

    else//Digitou comando inexistente.
        m_comandoInexistente();

}



