/**********************************************************/
/**********************************************************/
/*******Arquivo C do módulo de gravarArquivo***************/
/**********************************************************/
/*******Conteúdo: funções que gravam arquivos**************/
/**********************************************************/
/*******Autor: Adilson Lopes Khouri************************/
/**********************************************************/
/**********************************************************/

#include "../arquivosH/gravarArquivos.h"


/*Grava um arquivo texto que representa o gráfico a ser plotado.*/
int gravaPontosGrafico(double * X, double * Y,
                       int tamanho, char * nomeArquivo) {

    int retorno = -1;//Valor de erro.
    FILE * arquivo = abreArquivoEscrita(nomeArquivo);
    if(arquivo != NULL)
    {//Se o arquivo abriu corretamente, grave.

        fprintf(arquivo,"# %s\t\t%s\n","X","Y");//Header.

        int i;//contador.
        for(i = 0; i < tamanho; i++)//grava no formato: X " " Y
            fprintf(arquivo, "%f %f \n", X[i], Y[i]);

        fclose(arquivo);//Fecha o arquivo.
        retorno = 0;//Sucesso.
    }

    return retorno;
}


/*Grava um arquivo texto que representa o gráfico a ser plotado.*/
int gravaPontosGrafico2(double * X, double * Y, double passoEuler,
                        int tamanho, char * nomeArquivo) {

    int retorno = -1;//Valor de erro.
    //double dt = passoEuler;
    //printf("%f",dt);
    FILE * arquivo = abreArquivoEscrita(nomeArquivo);
    if(arquivo != NULL)
    {//Se o arquivo abriu corretamente, grave.

        fprintf(arquivo,"# %s\t\t%s\n","X","Y");//Header.
        int i;//contador.
        double natural = 0;
        for(i = 0; i < tamanho; i++)//grava no formato: X " " Y
        {
             if(passoEuler == natural || natural == 0)
             {
                fprintf(arquivo, "%f %f \n", X[i], Y[i]);
                //printf("%f",natural);
                natural = 0;
             }

             natural = natural + 1;
        }
        //printf("%f",natural);
        //printf("%f",aux);


        fclose(arquivo);//Fecha o arquivo.
        retorno = 0;//Sucesso.
    }

    return retorno;
}


/*Abre um arquivo em modo de escrita.*/
FILE * abreArquivoEscrita(char * nomeArquivo){

    FILE * arquivo = fopen(nomeArquivo, "w+");//Abre arquivo

    if(arquivo != NULL)//Se não ocorreu erro na abertura.
        printf("\nArquivo foi aberto com sucesso.\n");

    else {

        printf("Nao foi possivel abrir o arquivo.");
        arquivo = NULL;
    }

    return arquivo;
}

