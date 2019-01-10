




//#include "statistics.h"

//Open iterative menu to user chosen an option.
//main()
//{
//    if(TESTE == 0) //Se nao for um teste.
//    {
//
//        int userInput = -1;
//        while(userInput == -1 && userInput != 999)
//        {
//
//            //Menu amigavel.
//            printf("Escolha a opcao 1 para gerar um grafico de distribuicao uniforme \n");
//            printf("Escolha a opcao 2 para gerar um histograma da distribuição uniforme \n");
//            printf("Escolha a opcao 3 para gerar um histograma da gaussiana \n");
//            printf("Escolha a opcao 4 para gerar um histograma da exponencial \n");
//            printf("Escolha a opcao 5 para gerar um gráfico do movimento browniano\n");
//            printf("Escolha a opcao 999 para sair \n");
//
//            scanf("%i",&userInput);//Entrada do usuario.
//            printf("\n\n");
//            int userInput = 4;
//
//            switch (userInput)  //Verifica qual operacao o usuario quer realizar.
//            {
//
//            case 1:
//            {
//
//                int NDePontos = 600000;//Define quantos numeros serao trabalhados.
//                int NDeBarras = 15;//Define tamanho dos intervalos.
//                int inicio = 0;//Tamanho eixo X
//                int fim = 1;
//                double tamanhoDaBarra = NDeBarras/NDePontos;
//                //Aloca memoria para os numeros, em outras palavras define um array.
//                double* y = (double*)malloc(NDePontos*sizeof(double));
//                double* x = (double*)malloc(NDePontos*sizeof(double));
//                double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));//Armazena o valor limite dos intervalos
//                char * nomeArquivoDat = "arquivo.dat";
//                distribuicaoUniforme(NDePontos ,x,y);//Create pseudo random numbers of uniform distribution
//                insertionSort(x,NDePontos);
//
//                double* arrayfrequencia = CreateHistogram(NDeBarras, x, NDePontos, intervalosEntreBarras, inicio, fim);
//
//                gravaArquivoHistograma(intervalosEntreBarras,arrayfrequencia,tamanhoDaBarra,NDeBarras,nomeArquivoDat);
//                gravaArquivoDistUniforme(x,y,NDePontos,nomeArquivoDat);//Create file with the pesudo numbers creates by function distribuicaoUniforme
//                plotHistogram(nomeArquivoDat);
//                plotFunction();//Save a png with points ploted by gnuplot
//
//                //Free the memory allocated by malloc
//                free(y);
//                free(x);
//                break;
//            }
//
//            case 2:  //Distribuicao Uniforme.
//            {
//
//                int NDePontos = 600000;//Define quantos numeros serao trabalhados.
//                int NDeBarras = 15;//Define tamanho dos intervalos.
//                int inicio = 0;//Tamanho eixo X
//                int fim = 1;
//
//                //Aloca memoria para os numeros, em outras palavras define um array.
//                double diff = (double)2.0/(double)NDeBarras;
//                double* numerosHistograma; //Armazena os numeros aletatorios usados para gerar um histograma
//                double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));//Armazena o valor limite dos intervalos
//                double* intervaloPlotar = (double*)malloc((NDeBarras+1)*sizeof(double));
//
//                numerosHistograma = randomNumberWithSeedLinear(NDePontos);
//                insertionSort(numerosHistograma,NDePontos);
//
//                char * nomeArquivoDat = "arquivo.dat";
//                //gravaArquivoDistUniforme(double*X, double*Y,int tamanho,char * nomeArquivo);
//
//
//                    //printArray(numerosHistograma,NDePontos);
//                    double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
//                                              NDePontos,intervalosEntreBarras,inicio,fim);
//
//                    //Create file with the pesudo numbers creates by function distribuicaoUniforme
//                    gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,
//                                           0.11111,NDeBarras,nomeArquivoDat);
//
//                    plotFunction();//Save a png with points ploted by gnuplot
//                    plotHistogram(nomeArquivoDat);
//
//
//                    //free(y);
//                    free(numerosHistograma);
//                    free(intervalosEntreBarras);
//                    break;
//
//            }
//
//                case 3:  //Distribuicao Gaussiana.
//                {
//
//                    //Aqui vem a gaussiana.
//                    int NDePontos = 100000;//Define quantos numeros serao trabalhados.
//                    int NDeBarras = 150;//Define tamanho dos intervalos.
//
//                    //Define o tamanho do intervalo onde serão gerados os numeros.
//                    int tamanhoTotalIntervalo = 8;
//                    int inicio = -4;
//                    int fim = 4;
//
////                    Aloca memoria para os numeros, em outras palavras define um array.
//                    double diff = (double)tamanhoTotalIntervalo/(double)NDeBarras;
//
////                    Armazena os numeros aletatorios usados para gerar um histograma
//                    double* numerosHistograma = (double*)malloc((NDePontos)*sizeof(double));
//
////                    Armazena o valor limite dos intervalos
//                    double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));
//
//                    numerosHistograma = distribuicaoGaussiana(NDePontos);
//
//                    char * nomeArquivoTeste = "arquivoTeste.dat";
//
//                    insertionSort(numerosHistograma,NDePontos);
//
//                    char * nomeArquivoDat = "arquivo.dat";
//                    double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
//                                              NDePontos,intervalosEntreBarras,inicio,fim);
//
//                    gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
//                                           NDeBarras,nomeArquivoDat);//Create file with the pesudo numbers
//                    //creates by function distribuicaoUniforme
//
//                    plotHistogram(nomeArquivoDat);
//
//                    free(numerosHistograma);
//                    free(intervalosEntreBarras);
//
//                    break;
//                }
//
//                case 4:  //Distribuicao Exponencial
//                {
//
//                    printf("Exponencial :)");
//                    //Aqui vem o codigo que calcula a exponencial.
//                    int npontos = 100000;
//                    int NDeBarras = 15;//Define tamanho dos intervalos.
//
//
//                    double lambda = 2.0;
//                    //Define o tamanho do intervalo onde serão gerados os numeros.
//                        int tamanhoTotalIntervalo = 5;
//                    int inicio = 0;
//                    int fim = 5;
//
//                    double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));//Armazena o valor limite dos intervalos
//                    double * Exp = distribuicaoExponencial(npontos,lambda);
//
//                    insertionSort(Exp,npontos);
//
//                    char * nomeArquivoDat = "exponencial.dat";
//                    double* arrayFrequencia = CreateHistogram(NDeBarras,Exp,
//                                              npontos,intervalosEntreBarras,inicio,fim);
//
//                    gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
//                                           NDeBarras,nomeArquivoDat);
//
//                    plotHistogram(nomeArquivoDat);
//
//
//                    free(arrayFrequencia);
//                    free(intervalosEntreBarras);
//                    free(Exp);
//
//                    break;
//                }
//
//                case 5:  //Movimento Browniano
//                {
//
//                    int tamanho = 1;
//                    int numeroPontos = 10000000;
//
//                    //Calula pontos do movimento Browniano.
//                    double * incrementoWiener = (double*)malloc(numeroPontos*sizeof(double));
//                    double * Brown = (double*)malloc(numeroPontos*sizeof(double));
//                    Brown = movimentoBrowniano(tamanho,numeroPontos,incrementoWiener);
//
//                    //Plota movimento Browniano
//                    gravaArquivoDistUniforme(incrementoWiener, Brown,numeroPontos,"arquivo.dat");
//                    plotFunction("arquivo.dat");
//
//                    //Libera memoria
//                    free(incrementoWiener);
//                    free(Brown);
//                    break;
//                }
//
//                case 6:
//                {
//
//                    //Solucao para a integral de Ito.
//                    double ito = integralITO();
//                    printf("Valor da integral de ITO %f ",ito);
//                    break;
//                }
//
//                case 7:
//                {
//
//                    //Algoritmo de Euler-Maruyama.
//                    eulerMaruyama();
//                    break;
//
//                }
//
//                case 999:
//                {
//
//                    userInput = 999;
//                    break;
//                }
//
//            }
//            }
//        }
//
//
//        if(TESTE == 1) //Se for apenas para testar.
//        {
//
////            int NDePontos = 100;//Define quantos numeros serao trabalhados.
////            int NDeBarras = 5;//Define tamanho dos intervalos.
////            int inicio = 0;//Tamanho eixo X
////            int fim = 1;
////
////            Aloca memoria para os numeros, em outras palavras define um array.
////            double diff = (double)2.0/(double)NDeBarras;
////            double* numerosHistograma;
////            double* intervalosEntreBarras =
////                (double*)malloc((NDeBarras+1)*sizeof(double));
////
////            numerosHistograma = randomNumberWithSeedLinear(NDePontos);
////            insertionSort(numerosHistograma,NDePontos);
////
////            char filename [ 20 ];
////            sprintf(filename,"%d_%d");
////            printf("%s",filena);
////            char * nomeArquivoDat = "arquivo.dat";
////            int gravaArquivoDistUniforme(double*X, double*Y,int tamanho,char * nomeArquivo)
////            {
////
////                printArray(numerosHistograma,NDePontos);
////                double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
////                                          NDePontos,intervalosEntreBarras,inicio,fim);
////
////                Create file with the pesudo numbers creates by function distribuicaoUniforme
////                gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,
////                                       0.11111,NDeBarras,filename);
////
////                plotFunction();//Save a png with points ploted by gnuplot
////                plotHistogram(filename);
////
////
////                free(y);
////                free(numerosHistograma);
////                free(intervalosEntreBarras);
////                break;
////
////
////
////
////
////
////                printf("delano  \n");
////                eulerMaruyama();
////
////                printf("Exponencial :)");
////                //Aqui vem o codigo que calcula a exponencial.
////                int npontos = 800000;
////                int NDeBarras = 1000;//Define tamanho dos intervalos.
////                double lambda = 2.0;
////
////                //Define o tamanho do intervalo onde serão gerados os numeros.
////                int tamanhoTotalIntervalo = 5;
////                int inicio = 0;
////                int fim = 5;
////
////                //Armazena o valor limite dos intervalos
////                double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));
////                double * Exp = distribuicaoExponencial(npontos,lambda);
////
////                insertionSort(Exp,npontos);
////
////                char * nomeArquivoDat = "exponencial.dat";
////                double* arrayFrequencia = CreateHistogram(NDeBarras,Exp,
////                                          npontos,intervalosEntreBarras,inicio,fim);
////
////                gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
////                                       NDeBarras,nomeArquivoDat);
////
////                plotHistogram(nomeArquivoDat);
////
////
////                free(arrayFrequencia);
////                free(intervalosEntreBarras);
////                free(Exp);
////
////                Aqui vem a gaussiana.
////                int NDePontos = 800000;//Define quantos numeros serao trabalhados.
////                int NDeBarras = 250;//Define tamanho dos intervalos.
////
////                //Define o tamanho do intervalo onde serão gerados os numeros.
////                int tamanhoTotalIntervalo = 8;
////                int inicio = -4;
////                int fim = 4;
////
////                //Aloca memoria para os numeros, em outras palavras define um array.
////                double diff = (double)tamanhoTotalIntervalo/(double)NDeBarras;
////
////                //Armazena os numeros aletatorios usados para gerar um histograma
////                double* numerosHistograma = (double*)malloc((NDePontos)*sizeof(double));
////
////                //Armazena o valor limite dos intervalos
////                double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));
////
////                numerosHistograma = distribuicaoGaussiana(NDePontos);
////
////                char * nomeArquivoTeste = "arquivoTeste.dat";
////
////                //insertionSort(numerosHistograma,NDePontos);
////
////                char * nomeArquivoDat = "arquivo.dat";
////                double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
////                                          NDePontos,intervalosEntreBarras,inicio,fim);
////
////                gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
////                                       NDeBarras,nomeArquivoDat);//Create file with the pesudo numbers
////                //creates by function distribuicaoUniforme
////
////                plotHistogram(nomeArquivoDat);
////
////                free(numerosHistograma);
////                free(intervalosEntreBarras);
////
//
//            }
//
//            return 0;
//        }
//
