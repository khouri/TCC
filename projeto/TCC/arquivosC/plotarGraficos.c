/*******************************************************************************************/
/*******************************************************************************************/
/*************************Arquivo C do módulo de plotar gráficos****************************/
/*******************************************************************************************/
/*******************************************************************************************/
/***************Conteúdo: funções que plotam gráficos de acordo com arquivo*****************/
/*********texto gravado contendo todos os pontos da função no formato X x Y*****************/
/*******************************************************************************************/
/***************Autor: Adilson Lopes Khouri*************************************************/
/*******************************************************************************************/
/*******************************************************************************************/


/*Importa a facade do gnuplot.*/
#include "../arquivosH/plotarGraficos.h"
#include "../gnuplot/gnuplot_i.h"
#include "../gnuplot/gnuplot_i.c"


/*Plota funções no gnuplot.*/
void plotaFuncao(char * nomeArquivo){

    /*Inicializa handler.*/
    gnuplot_ctrl * h = gnuplot_init();

    /*Comandos no terminal do gnuplot.*/
    gnuplot_cmd(h, "set terminal png"); //Informa que a saida sera um png.
    gnuplot_cmd(h, "set output \"arq.png\"");//Cria arquivo de png.
    gnuplot_cmd(h,"plot '%s' with lines lw 1 lt rgb 'green'", nomeArquivo);

    gnuplot_close(h);/*Libera memória do handler.*/
}


/*Plota histogramas no gnuplot.*/
void plotaHistograma(char * nomeArquivo){

    /*Inicializa handler.*/
    gnuplot_ctrl * h = gnuplot_init();

    /*Comandos no terminal do gnuplot.*/
    gnuplot_cmd(h, "set terminal png");
    gnuplot_cmd(h, "set output \"arq.png\"");
    gnuplot_cmd(h, "plot '%s' with boxes ", nomeArquivo);

    //Libera memória do handler.
    gnuplot_close(h);

}
