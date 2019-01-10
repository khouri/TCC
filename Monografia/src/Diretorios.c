/*Cria um diretorio no local passado como parametro.*/
int criaDiretorio(char * nomeDiretorio){

    char comando[9] = {'m','k','d','i','r',' ','-','p',' '};/*Cria diretorio em Linux*/

    char * concatenado[100];//Concatena comando e nome do diretorio.
    sprintf(concatenado, "%s %s ",comando, nomeDiretorio);

    int resultado = system(concatenado);/*Executa o comando pelo SO.*/
    return resultado;
}

/*Remove uma arvore de diretorios, onde nomeDiretorios e a raiz da arvore*/
int removeDiretorio(char * nomeDiretorio){
    
    char comando[7] = {'r','m',' ','-','R','f',' '};

    char * concatenado[100];//Concatena comando e nome do diretorio.
    sprintf(concatenado, "%s %s ",comando, nomeDiretorio);
    
    int resultado = system(concatenado);/*Executa o comando.*/

    return resultado;
}
