/*Grava um arquivo texto que representa o grafico a ser plotado.*/
int gravapontosgrafico(double * X, double * Y, int tamanho, char * nomeArquivo){

    int retorno = -1;
    FILE * arquivo = abreArquivoEscrita(nomeArquivo);
    if(arquivo != NULL)
    {
        fprintf(arquivo, "# %s\t\t%s\n", "X", "Y");//Header.

        int i;
        for(i = 0; i < tamanho; i++)
            fprintf(arquivo, "%f %f \n", X[i], Y[i]);

        fclose(arquivo);
        retorno = 0;
    }

    return retorno;
}

/*Abre um arquivo em modo de escrita.*/
FILE * abreArquivoEscrita(char * nomeArquivo){

    FILE * arquivo = fopen(nomeArquivo, "w+");//Abre arquivo
    if(arquivo != NULL)
        printf("\nArquivo foi aberto com sucesso.\n");

    else {
        printf("Nao foi possivel abrir o arquivo.");
        arquivo = NULL;
    }

    return arquivo;
}
