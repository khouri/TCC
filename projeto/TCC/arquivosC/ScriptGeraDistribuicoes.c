#include "../arquivosH/distribuicoes.h"
#include "../arquivosH/estatistica.h"
#include "../arquivosH/ScriptGeraDistribuicoes.h"

int criaDiretorio(char * nomeDiretorio)
{

    //printf("\n\n");
    char * arr[100];// = (char *) malloc((100)*sizeof(char));
    char comando[9] = {'m','k','d','i','r',' ','-','p',' '};


//    char * comando = "mkdir -p ";

    sprintf(arr, "%s %s ",comando, nomeDiretorio);

    int teste;
    //printf(" valor %s \n",arr);

    //Tenta criar um diretorio.
    teste = system(arr);//mkdir(nomeDiretorio);

    if (!teste){}
        //printf("DIRETORIO CRIADO\n %d",teste);

    else
    {
        //printf("DIRETORIO NAO CRIADO\n %d",teste);
        exit(1);
    }

    //free(arr);
    //0 em caso de sucesso -1 em caso de falha.
    return teste;
}

char * concatenaChar(char * a, char * b, char * separador)
{//Concatena dois chars.

    char * concatena[100];
//    strcat(concatena, a);
//    strcat(concatena,separador);
//    strcat(concatena, b);
    sprintf(concatena,"%s %s %s", a, separador, b);
    //printf("valum  %s",concatena);

    return concatena;
}

char * converteEConcatenaInt(int a, int b)
{//Converte e concatena dois inteiros em char.

    char * concatena[50];
    sprintf(concatena, "%d_%d", a, b);
    return concatena;
}


void geraDist()
{

    //printf("\n\n");
    char * nomeDir = "output/";
    char * exp = concatenaChar("output","Exponencial","/");
   // printf("\n\n %s", exp);
    char * gau = "Gaussiana";
    char * uni = "Uniforme";
    //char * aux = concatenaChar(nomeDir,exp,"");
    //printf("%s", aux);

    criaDiretorio("output");
    criaDiretorio("output/Uniforme");
    criaDiretorio("output/Gaussiana");
    criaDiretorio(exp);

    int dist[3] = {0,1,2};//Uniforme, Gaussiana, Exponencial.
    int numPontos[6] = {100000, 200000, 400000, 600000, 800000, 1000000};
    int numBarras[8] = {15,50,100,150,200,250,500,1000};

    int k;
    for(k = 0; k < 3; k++)
    {//Percorre as distribuicoes.

        int i;
        for(i = 0; i < 6; i++)
        {//Percorre os pontos

            int j;
            for(j = 0; j < 8; j++)
            {//Percorre as barras.

                //printf("valor %d %d %d",k,i,j);
                switch(dist[k])
                {
                    case 0:
                    {
                        char * uniforme = "output/Uniforme";

                        char * nomeDir2 = converteEConcatenaInt(numPontos[i], numBarras[j]);
                        printf("\n nomeDir2 antes %.30s",nomeDir2);

                        char * tree = concatenaChar(uniforme, nomeDir2, "/");
                        printf("\n tree antes %.30s",tree);

                        criaDiretorio(tree);

                        printf("\n tree depois %.30s",tree);

//                      int nBarras = 100;
//                      int nPontos = 100000;
                        int inicio = 0;
                        int fim = 1;
                        char * nomeArquivo = concatenaChar(tree,"Uniforme.dat","/");
                        printf("\n di %s",nomeArquivo);
                        //printf("%s",nomeArquivo);
                        getchar();

                        double * dUniforme  = d_Uniforme(numPontos[i],seed1);
                        struct histograma * h = calculaFrequencia(dUniforme,numPontos[i],
                                                                  numBarras[j],inicio,fim);

                        gravaArquivoHistograma2(h,nomeArquivo);

                        plotHistogram(nomeArquivo);

                        freeHistograma(h);
                        free(dUniforme);
                        break;
                    }
                    case 1:
                    {
                        char * uniforme = "output/Gaussiana";
                        char * nomeDir2 = converteEConcatenaInt(numPontos[i], numBarras[j]);
                        char * tree = concatenaChar(uniforme,nomeDir2,"/");
                        criaDiretorio(tree);

                        char * gaussiana = "Gaussiana";
//
//                        //Aqui vem a gaussiana.
////                        int NDePontos = 100000;
////                        int NDeBarras = 150;
////
////                        //Define o tamanho do intervalo onde serão gerados os numeros.
////                        int tamanhoTotalIntervalo = 8;
////                        int inicio = -4;
////                        int fim = 4;
////                        char * nome = "Gaussiana.dat";
////
////                        //Gera os numeros pseudo aleatorios satisfazendo a distribuicao gaussiana.
////                        double * Gau = distribuicaoGaussiana(NDePontos);
////                        histograma * h = calculaFrequencia(Gau, NDePontos, NDeBarras, inicio, fim);
////
////                        frequenciaRelativa(h);
////
////                        //Grava arquivo do histograma e plota o mesmo.
////                        gravaArquivoHistograma2(h,nome);
////                        plotHistogram(nome);
////
////                        //Libera memoria.
////                        free(Gau);
////                        freeHistograma(h);
                        break;
                    }
                    case 2:
                    {
                        char * uniforme = "output/Exponencial";
                        char * nomeDir2 = converteEConcatenaInt(numPontos[i], numBarras[j]);
                        char * tree = concatenaChar(uniforme,nomeDir2,"/");
                        criaDiretorio(tree);
//                        char * exponencial = "Exponencial";
//
//                        //1000000_15
//                        char * nomeDir = converteEConcatenaInt(numPontos[i], numBarras[j]);
//
//                        //output/Exponencial
//                        char * nomePasta = concatenaChar(nomeDir,exponencial,"/");
//
//                        //output/Exponencial/1000000_15
//                        char *nomeFinal = concatenaChar(nomePasta,nomeDir,"/");
//
//                        //output/Exponencial/1000000_15/exponencial.dat
//                        char * nomeArquivoDat = concatenaChar(nomeFinal,"exponencial.dat","/");
//
//                        //Aqui vem o codigo que calcula a exponencial.
////                        int npontos = 100000;
////                        int NDeBarras = 100;
////                        double lambda = 2.0;
////
////                        int inicio = 0;
////                        int fim = 5;
////
////                        double * exp = distribuicaoExponencial(npontos,lambda);
////                        struct histograma * h = calculaFrequencia(exp, npontos, NDeBarras, inicio, fim);
////
////                        frequenciaRelativa(h);
////
////                        gravaArquivoHistograma2(h,nomeArquivoDat);
////                        plotHistogram(nomeArquivoDat);
////
////                        freeHistograma(h);
////                        free(exp);
                        break;
                    }
                }
            }
        }
    }
}//Fim do Script





