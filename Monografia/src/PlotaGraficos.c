/*Plota funcoes no gnuplot.*/
void plotaFuncao(char * nomeArquivo){
    
    gnuplot_ctrl * h = gnuplot_init();/*Inicializa handler.*/
    
    gnuplot_cmd(h, "set terminal png");/*Comandos no terminal do gnuplot.*/
    gnuplot_cmd(h, "set output \"arq.png\"");
    gnuplot_cmd(h,"plot '%s' with lines lw 1 lt rgb 'green'", nomeArquivo);    
    gnuplot_close(h);/*Libera memoria do handler.*/
}

/*Plota histogramas no gnuplot.*/
void plotaHistograma(char * nomeArquivo){
   
    gnuplot_ctrl * h = gnuplot_init(); /*Inicializa handler.*/
    
    gnuplot_cmd(h, "set terminal png");/*Comandos no terminal do gnuplot.*/
    gnuplot_cmd(h, "set output \"arq.png\"");
    gnuplot_cmd(h, "plot '%s' with boxes ", nomeArquivo);
    gnuplot_close(h);/*Libera memoria do handler.*/
}
