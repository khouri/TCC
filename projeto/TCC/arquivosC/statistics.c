/*
This file generate pseudo random numbers, create a file do write
the points and call gnuplot program to make graphics.

Author: Adilson Lopes Khouri N°USP 6411994
*/

#include "../arquivosH/statistics.h"

////Generate 'tamanhoDaSerie' pseudo random numbers in a Range[0,tamanhoDaSerie) in linear format.
//double* randomNumberWithSeedLinear(int tamanhoDaSerie)
//{
////RAND_MAX	2147483647
//
//    int i;
//    double* pointer = (double*)malloc(tamanhoDaSerie*sizeof(double));
//    double rdMAX = RAND_MAX;
//    rdMAX = rdMAX+1;
//
//    /* inicializar o gerador de números aleatórios */
//    srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
//    for (i = 0; i < tamanhoDaSerie; i++)
//    {
//        //printf("valor de i %d   ",i);
//        *(pointer+i) = rand()/rdMAX;
//        //printf("value %f \n", *(pointer+i));
//    }
//    //printf("i value = %d",i);
//    //printf("valor de iterações %d ",i);
//    //printf("tamnhao %d",(tamanhoDaSerie*2));
//    return pointer;
//}

//
////Call gnuplot to read a file and plot a graphic
//void plotFunction(char* nomeArquivo)
//{
//
//    //handler do evento.
//    gnuplot_ctrl * h ;
//
//    //inicializa o gnuplot.
//    h = gnuplot_init();
//
//    gnuplot_cmd(h, "set terminal png"); //Informa que a saida sera um png
//    gnuplot_cmd(h, "set output \"arq.png\"");//Cria arquivo de png
//
//    //gnuplot_cmd(h, "set title 'oxy'"); //Titulo do grafico.
//
//    gnuplot_cmd(h,"plot '%s' with lines lt rgb 'green'",nomeArquivo);
//    //gnuplot_cmd(h,"plot '%s'lt rgb 'green'",nomeArquivo);
//    gnuplot_close(h);//Da free na memoria e fecha o handler de tratamento.
//}
//
//
////Funcao responsavel por plotar o grafico do histograma.
//void plotHistogram(char* nomeArquivo)
//{
//
//    gnuplot_ctrl * h ;//Invoca o handler do evento de inicializacao do evento.
//    h = gnuplot_init();//Chama o evento de inicializacao do gnuplot.
//
////Grava um png com o grafico plotado.
//    gnuplot_cmd(h, "set terminal png");
//    gnuplot_cmd(h, "set output \"arq.png\"");
//
////Altera a escala do grafico.
////gnuplot_cmd(h,"set yrange [0:1000]");//seta a altura do eixo y
////gnuplot_cmd(h,"set xrange [-0.1:1.1]");//seta a altura do eixo x
//
////gnuplot_cmd(h,"set xtics(0, 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1)");//coloca uma string numa posição do eixo x,
//
//
//    gnuplot_cmd(h,"plot '%s' with boxes lt rgb 'green' ",nomeArquivo);
//    gnuplot_close(h);//Dá um free no handler.
//
//}

//
//int gravaArquivoHistograma(double*X, double*Y,double Z,int tamanho,char * nomeArquivo)
//{
//    //X = eixo X ; Y = frequencia dos pontos; Z = largura das barras.
//
//    FILE *arquivo = fopen(nomeArquivo, "w+");//Abre/Cria o arquivo para escrita.
//
//
//    if(arquivo != NULL)  // testa se o arquivo foi aberto com sucesso
//    {
//        printf("\nArquivo foi aberto com sucesso.\n");
//
//        fprintf(arquivo,"# %s\t\t%s\n","Eixo X","Frequência");//cria um header(ignorado pelo gnuplot) no arquivo.
//        int contador;//loop counter
//        for(contador = 0; contador <= tamanho ; contador++) //grava no arquivo todos os pontos X " " Y
//        {
//            //double diff = (*(X+contador) - *(X+contador+1))/2;
//            //Cria uma estrutura de arquivo para que possa ser lido no gnuplot -> e.g. x " "y "\n"
//            fprintf(arquivo,"%f %f \n",*(X+contador)+Z/2,*(Y+contador)/tamanho);
//        }
//
//        fclose(arquivo);//Fecha o arquivo aberto.
//        return 0;//Indica arquivo criado com sucesso.
//
//    }
//    else
//    {
//
//        printf("Nao foi possivel abrir o arquivo.");
//        return -1;//Indica erro
//    }
//
//}
//
//
////Create a file and save a variable number of pseudo random points
//int gravaArquivoTeste(double*X, int tamanho, char * nomeArquivo)
//{
//
//    FILE *arquivo = fopen(nomeArquivo, "w+");//Abre/Cria o arquivo para escrita.
//
//    if(arquivo != NULL)  // testa se o arquivo foi aberto com sucesso
//    {
//        printf("\nArquivo foi aberto com sucesso.\n");
//
//        printf("nome do arquivo %s \n",nomeArquivo);
//        printf("valor de tamanho %d \n ",tamanho);
//        printf("valor de X[0] %f  \n",*(X+0));
//
//        //double diferenca = (*(X+1) - *(X+0))/2;
//        //fprintf(arquivo,"# %s\t\t%s\n","X");//cria um header(ignorado pelo gnuplot) no arquivo.
//        int contador;//loop counter
//        for(contador = 0; contador < tamanho ; contador++) //grava no arquivo todos os pontos X " " Y
//        {
//
//            //Cria uma estrutura de arquivo para que possa ser lido no gnuplot -> e.g. x " "y "\n"
//            fprintf(arquivo,"%f \n",*(X+contador) );
//            //printf("contador %d ",contador);
//        }
//
//        fclose(arquivo);//Fecha o arquivo aberto.
//        return 0;//Indica arquivo criado com sucesso.
//
//    }
//    else
//    {
//
//        printf("Nao foi possivel abrir o arquivo.");
//        return -1;//Indica erro
//    }
//}//Fim da classe.
//
//
////Create a file and save a variable number of pseudo random points
//int gravaArquivoDistUniforme(double*X, double*Y,int tamanho,char * nomeArquivo)
//{
//
//    FILE *arquivo = fopen(nomeArquivo, "w+");//Abre/Cria o arquivo para escrita.
//
//    if(arquivo != NULL)  // testa se o arquivo foi aberto com sucesso
//    {
//        printf("\nArquivo foi aberto com sucesso.\n");
//
//        //double diferenca = (*(X+1) - *(X+0))/2;
//        fprintf(arquivo,"# %s\t\t%s\n","X","Y");//cria um header(ignorado pelo gnuplot) no arquivo.
//        int contador;//loop counter
//        for(contador = 0; contador < tamanho ; contador++) //grava no arquivo todos os pontos X " " Y
//        {
//
//            //Cria uma estrutura de arquivo para que possa ser lido no gnuplot -> e.g. x " "y "\n"
//            fprintf(arquivo,"%f %f \n",*(X+contador),*(Y+contador));
//        }
//        fclose(arquivo);//Fecha o arquivo aberto.
//        return 0;//Indica arquivo criado com sucesso.
//
//    }
//    else
//    {
//
//        printf("Nao foi possivel abrir o arquivo.");
//        return -1;//Indica erro
//    }
//}//Fim da classe.

//
//double * movimentoBrowniano(int intervalo, int numeroPontos,
//                            double * incrementoWiener)
//{
//    //Incremento no eixo x do gráfico(tempo)
//    double dt = (double)intervalo/(double)numeroPontos;
//    double* gaussiana = (double*)malloc((numeroPontos)*sizeof(double));//Gaussiana
//    double* W = (double*)malloc(numeroPontos*sizeof(double));//Pontos discretos de Brown.
//    gaussiana = distribuicaoGaussiana(numeroPontos);
//
//    //atribui os primeiros valores
//    *(incrementoWiener) = *(gaussiana+0) * sqrt(dt);
//    *(W)  = *(incrementoWiener+0);
//
//    int counter;
//    for(counter = 1; counter < numeroPontos; counter++)
//    {
//        *(incrementoWiener+counter) =  *(gaussiana+counter) * sqrt(dt);
//        *(W+counter)  =  *(W+(counter-1)) + *(incrementoWiener+counter);
//    }
//
//    free(gaussiana);
//    return W;
//}


////Solve the uniform distribution problem.
//int distribuicaoUniforme(int numerodePontos,double* pontosNoEixoX, double* eixoY)
//{
//
//    double* serieRandom = randomNumberWithSeed(numerodePontos);//deve retornar o numeroDePontos*2
//    double rdMAX = RAND_MAX;
//    rdMAX = rdMAX+1;
//
//    //printf("rdMAX %f",rdMAX);
//
//    int i;//itera sobre serieRandom pegando os numeros de dois a dois <x,y>
//    int j=0;//Itera sobre os vetores de numeros aleatorios retornados que represntam todos os pontos de formato <x,y,0>
//    for(i=0; j < numerodePontos; i=i+2)
//    {
//
//        *(pontosNoEixoX+j) = *(serieRandom+i)/rdMAX;
//        *(eixoY+j) = *(serieRandom+i+1)/rdMAX;
//
//        j++;
//        //printf("O valor de serie Random: %.2f \n", *(serieRandom+i));
//        //printf("pontosNoEixoX:  %f ",*(pontosNoEixoX+i));
//        //printf("eixoY:  %f ",*(eixoY+i));
//    }
//    //printf("laco %d",numerodePontos);
//    free(serieRandom);
//
//    return 1;
//}
//
//
////Recebe N° total de barras no histograma e o tamanho total do intervalo.
//double* calculaNumeroDeIntervalos(int NumBarras, double tamTotalIntervalo)
//{
//
//    double * tamintervalos =
//        (double *) malloc((NumBarras+1)*sizeof(double));//Array que vai conter os limites de intervalos das barras.
//
//    double tamBarra = tamTotalIntervalo/NumBarras;//Armazena o tamanho de cada barra.
//
//    int count;//loop count
//    for(count = 0; count <= NumBarras; count++)  //O tamanhos eh a uma PA da diferenca razao = diferenca.
//    {
//
//        *(tamintervalos+count) = (tamBarra)*count;//Calcula todos os tamanhos de barras do histograma.
//        //printf("valor = %f",*(tamintervalos+count));
//    }
//
//    return tamintervalos;//Retorna um array com os limites dos intervalos das barras.
//}
//
//
////Retorna todos os intervalos entre valores.
//double* calculaNumeroDeIntervalos2(int NumBarras, double inicioIntervalo, double fimintervalo)
//{
//
//    //Array que vai conter os limites de intervalos das barras.
//    double * tamintervalos =
//        (double *) malloc((NumBarras+1)*sizeof(double));
//
//    //Guarda o valor sem inverter o sinal.
//    double inicio = inicioIntervalo;
//
//    //Retorna a diferenca entre valores considerando o sinal
//    double difff = calculaEspaco(inicioIntervalo,fimintervalo);
//
//    //define a largura de cada barra a ser plotada.
//    double tamBarra = difff/NumBarras;
//
//    int count;//loop count
//    for(count = 0; count <= NumBarras; count++)  //Os tamanhos sao uma PA com razao = diferenca.
//    {
//
//        *(tamintervalos+count) = (tamBarra*count) + inicio;//Calcula todos os tamanhos de barras do histograma.
//        //printf("valor = %f",*(tamintervalos+count));
//    }
//    //printf("\n\ncount %d",count);
//
//    return tamintervalos;//Retorna um array com os limites dos intervalos das barras.
//}


void InverteSinal(double * converter)
{
    //Inverte o sinal de um numero.

    //if((*converter) < 0) {

    (*converter)  = (*converter)  * -1;

}

//
//double calculaEspaco(double inicio, double fim)
//{
//    //Calcula a variacao de espaco entre dois pontos na reta.
//
//    if(inicio >= 0 && fim >= 0)
//    {
//        //aqui o inicio deve ser menor que o fim. 2 10, 2 eh menor que menos 10
//
//        return fim - inicio;
//    }
//
//    else if(inicio <= 0 && fim <= 0)
//    {
//        //Aqui o inicio eh menor que o fim e.g. -10 -2, -10 eh menor que -2
//
//        return inicio - fim;
//    }
//    else
//    {
//        //Aqui como o sinais sao diferentes apenas devemos somar normalmente
//
//        return fim - inicio;
//    }
//}

//
////Create two arrays, the first contains ferquence of points in each interval, and second contains the sizes of ranges
//double* CreateHistogram(double NDeBarras, double * pontosNoEixoX, int NDePontosEixoX, double * tamintervalos,
//                        int inicio, int fim)  //, double * pontosNoEixoX,int NDePontosEixoX
//{
//
//    double * aux = calculaNumeroDeIntervalos2(NDeBarras,inicio,fim);
//
//    double * NumerodePontosPorIntervalo =
//        (double*)malloc((NDeBarras+1)*sizeof(double));//Guarda o numero de barras a serem plotadas no gnuplot.
//
//    double sizeIntervalo = calculaEspaco(inicio,fim);
//
//    double diferenca = sizeIntervalo/NDeBarras;//Calcula o tamanho de uma barra do histograma.
//    printf("diferenca %f ",diferenca);
//
//    //Define o tamanho de cada intervalo em funcao do n° de particoes definidos.
//    int count;//Contador
//    for(count = 0; count <= NDeBarras; count++)
//    {
//
//        *(tamintervalos+count) = *(aux+count);
//        //*(tamintervalos+count) = (diferenca*count) + inicio;//Calcula todos os tamanhos de barras do histograma.
//        *(NumerodePontosPorIntervalo+count) = 0.0;//Inicializa o array de frequencia.
//        printf("tamintervalos %f\n",*(tamintervalos+count) );
//    }
//
//    int laco = 0;
//    for(count = 0; count < NDePontosEixoX; count++) //Calcula a frequencia dos pontos entre os intervalos definidos.
//    {
//
//        int count2;
//        for(count2 = 0; count2 <= NDeBarras; count2++)
//        {
//
//            if(*(pontosNoEixoX+count) >= *(tamintervalos+count2) &&
//                    *(pontosNoEixoX+count) < *(tamintervalos+count2+1))
//            {
//                //countMagic++;
//                *(NumerodePontosPorIntervalo+count2) = (*(NumerodePontosPorIntervalo+count2)) + 1;
//            }
//        }
//    }
//    return NumerodePontosPorIntervalo;
//}
//

//Sort Ascending a array 'v' with size 'n'.
void insertionSort(double* arrayToOrder, int n)
{
    int i, j;
    double chave;
    for(j=1; j<n; j++)
    {
        chave = arrayToOrder[j];
        i = j-1;
        while(i >= 0 && arrayToOrder[i] > chave)
        {
            arrayToOrder[i+1] = arrayToOrder[i];
            i--;
        }
        arrayToOrder[i+1] = chave;
    }
}

//
////Prints a array.
//void printArray(double * arrayToPrint, int sizeArray)
//{
//
//    printf("\n");
//    int contador;
//    for(contador = 0; contador < sizeArray ; contador++)
//    {
//
//        printf("%f ",*(arrayToPrint+contador));
//    }
//
//}



////Aqui vem o calculo da distribuicao exponencial.
//double * distribuicaoExponencial(int Npontos, double lambda)
//{
//
//    //Aloca memoria.
//    double * exp = (double*)malloc(Npontos*sizeof(double));//Armazena pontos da distribuicao exponencial.
//    double * eixoX = (double*)malloc(Npontos*sizeof(double));
//    double * eixoY = (double*)malloc(Npontos*sizeof(double));
//
//    //Obtem 2 arryas pseudo aleatorios de distribuicao Uniforme.
//    distribuicaoUniforme(Npontos,eixoX,eixoY);
//
//    //Calcula pontos da distribuicao exponencial.
//    int i = 0;
//    for(i = 0; i < Npontos; i++)
//        *(exp+i) = -1/lambda * log(1- *(eixoX+i));
//
//    //Libera Memoria alocada
//    free(eixoX);
//    free(eixoY);
//
//    return exp;
//}


////Resolve o problema da distribuicao gaussiana
//double* distribuicaoGaussiana(int Npontos)
//{
//    //Formula: sqrt(-2log(U1)*2*PI) * cos(U2)*2*PI
//
//    //Define dois arrays que recebem duas sequencias de numeros aleatorios.
//    double * numAleatorios1 = (double*)malloc(Npontos*sizeof(double));
//    double * numAleatorios2 = (double*)malloc(Npontos*sizeof(double));
//    double * gaussiana = (double*)malloc(Npontos*sizeof(double));
//    distribuicaoUniforme(Npontos,numAleatorios1,numAleatorios2);
//
//    int contador;
//    for(contador = 0; contador < Npontos; contador++)
//    {
//        //cos(U2)*2*PI.
//        double cosseno =
//            cos(*(numAleatorios2+contador)*2*PI);
//
//        //sqrt(-2log(U1)*2*PI).
//        double logaritmoNatural =
//            sqrt(-2*log((*(numAleatorios1+contador))));
//
//        //Valor da gaussiana.
//        *(gaussiana+contador) =  cosseno*logaritmoNatural;
//    }
//
//    free(numAleatorios1);
//    free(numAleatorios2);
//
//    return gaussiana;
//}

//
//double integralITO()
//{
//
//    int tamanho = 1;
//    int pontos = 500;
//    double ito = 0;
//
//    //Obtem o incremento do movimento browniano e o valor da var aleatoria browniana.
//    double* dW = (double*)malloc(pontos*sizeof(double));
//    double* W = movimentoBrowniano(tamanho, pontos, dW);
//
//    //Calcula a soma das areas cuja base tende a 0(limite)
//    //Aqui eh calculada a integral do movimento browniano.
//    int counter;
//    for(counter = 1; counter < pontos; counter++)
//        ito = ito + ( *(W+counter-1) * (*(dW+counter)) );
//
//    //Libera a memoria
//    free(dW);
//    free(W);
//
//    return ito;
//}
//
//void eulerMaruyama()
//{
//
//    printf("cai");
//    // Obtem o incremento do movimento
//    //browniano e o valor da var aleatoria browniana.
//    int tamanho = 1;
//    int pontos = pow(2,8);
//    double * dW = (double*)malloc(pontos*sizeof(double));
//    double * W = movimentoBrowniano(tamanho, pontos, dW);
//    char * nome = "Exactly_exp.dat";
//    char * nome2 = "EM_exp.dat";
//
//    int lambda = 2;
//    int mi = 1;
//    int xZero = 1;
//    int T = 1;
//    double N = pow(2,8);
//    double dt = 1/N;
//    int numeroPontosEM = (int)T/dt;
//    double R = 1;
//
//    double L = (int)N/R;
//    double R_Dt = R*dt;
//    printf("%d",numeroPontosEM);
//
//    int aux = 1;
//
//    if(EULER == 1)
//    {
//        //Metodo aproximado
//
//        double * Xem = (double*)malloc((numeroPontosEM)*sizeof(double));//Solucao aproximada.
//        double Xtemp = xZero;
//
//        //printf("Valor de L %d \n",L);
//        int i;
//        for(i = 0; i < L ; i++)
//        {
//            double Winc = somaPosicoesArray( (R*i) , R*(i+1), dW);
//            Xtemp = Xtemp + (R_Dt*lambda*Xtemp) + Xtemp*Winc*mi;
//            *(Xem+i) = Xtemp;
//        }
//
//        printf("Valor do contador %d \n",i);
//
//        //getchar();
//        //Cria o array: ([dt:dt:T])
//        double * arrayEstocastico = incrementoDt(0,R_Dt,T);//Ok!
//
//        gravaArquivoDistUniforme(arrayEstocastico,Xem,(int)L-1,nome2);
//        plotFunction(nome2);
//
//        free(Xem);
//        free(arrayEstocastico);
//    }
//
//
//    if(EULER == 0)
//    {
//        //Retorna um n negativo, faz sentido meu mov
//        //browniano(500 pts) esta mais para baixo que p cima.
//        //Logo a soma eh negativa.
//        double somaW = somaPosicoesArray(0,pontos,W);
//
//        //Calcula Xtrue, que eh a solução exata.
//        double * Xtrue = (double*)malloc((numeroPontosEM)*sizeof(double));
//
//        //X(t)*dt*lambda que representa a parte deterministica da equacao.
//        double termoDeterministico = lambda-0.5*pow(mi,2);//como mi = 1, o valor desse termo sera -1;
//        //printf("termoDeterministico %f",termoDeterministico);//1.5
//
//        //Cria o array: ([dt:dt:T])
//        double * arrayEstocastico = incrementoDt(0,dt,T);//Ok!
//        //printArray(arrayEstocastico,numeroPontosEM);
//
//        //mi*W
//        double * miVezesArrayEstocastico =
//            multiplicaNumeroVetor(mi,W,numeroPontosEM);
//
//        //printArray(miVezesArrayEstocastico,numeroPontosEM);
//
//        //X+mi*dW
//        double * miVezesArrayEstocastico_arrayEstocastico =
//            somaDoisArrays(arrayEstocastico,
//                           miVezesArrayEstocastico, numeroPontosEM);
//
//        //printArray(miVezesArrayEstocastico_arrayEstocastico,numeroPontosEM);
//
//        double * expoente =
//            multiplicaNumeroVetor(termoDeterministico,
//                                  miVezesArrayEstocastico_arrayEstocastico,numeroPontosEM);
//
//        //printArray(expoente,numeroPontosEM);
//
//        //eleva tudo a funcao exp();
//        double * exponencial =
//            exponenciaNumeroVetor(1,expoente,numeroPontosEM);
//
//        //printArray(exponencial,numeroPontosEM);
//
//        gravaArquivoDistUniforme(arrayEstocastico,exponencial,numeroPontosEM-1,nome);
//        plotFunction(nome);
//
//
//        //Libera a memoria utilizada
//        free(arrayEstocastico);
//        free(exponencial);
//        free(miVezesArrayEstocastico_arrayEstocastico);
//        free(W);
//        free(dW);
//        free(Xtrue);
//        free(expoente);
//        free(miVezesArrayEstocastico);
//    }




    //gravaArquivoHistograma(arrayEstocastico,exponencial,1/2,(int)T/dt,"Leitura.dat  ");
    //free(termo1Vezez_miVezesArrayEstocastico_arrayEstocastico);

//    insertionSort(miVezesArrayEstocastico_arrayEstocastico,256);
//    printArray(miVezesArrayEstocastico_arrayEstocastico,(int)T/dt);

//    //printArray(arrayEstocastico,pontos);
//
//    //printf("arrayEstocastico posicao 500 %f \n", *(arrayEstocastico+499));
//    gravaArquivoTeste(arrayEstocastico,256,"ronaldoLouco.dat");
    //free(arrayEstocastico);
//
//    printf("Digite algo porra!1");
//    getchar();

    //double * solution = somaNumeroVetor(2,arrayEstocastico,(int)T/dt);

    //printArray(solution,(int)T/dt);

//    printf("ArrayEstocastico posicao 500 %f \n", *(arrayEstocastico+499));
//    printf("solution posicao 500 %f \n", *(solution+499));

//
//    printf("Digite algo porra!2");
//    getchar();

    //double * solution2 = multiplicaNumeroVetor(termoDeterministico,solution,pontos);

//
//    printf("Digite algo porra!3");
//    getchar();

    //double * solution3 = exponenciaNumeroVetor(2,solution2,pontos);


//    free(arrayEstocastico);
    //free(solution);
    //free(solution2);
    //free(solution3);
    //free(arrayEstocastico);

//
//    printf("Digite algo porra!4");
//    getchar();

//    Xtrue = ;

//
//    int R = 4;
//    int DT = R * dt;
//    int L = N/R;
//
//    //Calcula a solucao por euler maruyama.
//    double * Xem = (double*)malloc(pontos*sizeof(double));
//    double Winc = 0;
//    double Xtemp = xZero;
//
//
//    int contador2;
//    for(contador2 = 1; contador2 < pontos; contador2++)
//    {
//        Winc = somaPosicoesArray(R*(contador2 - 1)+1,R*contador2,dW);
//        Xtemp = Xtemp + DT*lambda*Xtemp + mi*Xtemp*Winc;
//        *(Xem + contador2) = Xtemp;
//    }
//
//    return Xtrue;
//}
//
//double * somaDoisArrays(double * a, double * b, int tamanho)
//{
//    //Soma dois arrays(a[0] + b[0] ate tamanho),
////suponho que ambos tenham o msm tamanho
//
//    //Recebe a soma dos vetores.
//    double * retorno = (double*)malloc(tamanho*sizeof(double));
//
//    int contador;
//    for(contador = 0; contador < tamanho ; contador++)
//        *(retorno+contador) = *(a+contador) + *(b+contador);
//
//    return retorno;
//}
//
//double somaPosicoesArray(int inicio, int fim, double * array)
//{
//    //Soma um intervalo(inicio - fim) de posicoes do array.
////Inclusive inicio e fim sao somados.
//
//    double soma = 0;
//    int contador = inicio;
//    while(contador <= fim)
//    {
//        soma = soma + *(array+contador);
//        contador++;
//    }
//
//    return soma;
//}
//
//double * exponenciaNumeroVetor(double numero,
//                               double * array, int tamanhoArray)
//{
//    //Eleva todos os números de um vetor a funcao exp(x);
//
//    double * retorno = (double*)malloc(tamanhoArray*sizeof(double));
//
//    int contador;
//    for(contador = 0; contador < tamanhoArray ; contador++)
//        *(retorno+contador) = exp(*(array+contador));
//
//    return retorno;
//}
//
//double * multiplicaNumeroVetor(double numero, double * array, int tamanhoArray)
//{
//    //Multiplica um numero em todas as posicoes de um array.
//
//    double * retorno = (double*)malloc(tamanhoArray*sizeof(double));
//
//    int contador;
//    for(contador = 0; contador < tamanhoArray ; contador++)
//        *(retorno+contador) = *(array+contador) * numero;
//
//    return retorno;
//}
//
//double * somaNumeroVetor(double numero, double * array, int tamanhoArray)
//{
//    //Soma um numero em todas as posicoes de um array.
//
//    double * retorno = (double*)malloc(tamanhoArray*sizeof(double));
//
//    int contador;
//    for(contador = 0; contador < tamanhoArray ; contador++)
//    {
//        //printf("%f \n",*(array+contador));
//        *(retorno+contador) = *(array+contador) + numero;
//        // printf("%f \n",*(array+contador));
//    }
//    //printf("numero %f", numero);
//
//    return retorno;
//}
//
//double* incrementoDt(double inicio, double intervalo, int fim)
//{
//    int tamanhoArray = fim/intervalo;
//    //printf("tamanho array6 %d \n ",tamanhoArray);
//
//    double * arrayDt = (double*)malloc(tamanhoArray*sizeof(double));
//    int aux = intervalo;
//
//    //Inicializa array com intervalos de dt.
//    //Nao comeca no zero, a primeira posicao eh intervalo(dt).
//    double contador;
//    int contador2 = 0;
//    for(contador = intervalo; contador < fim; contador = contador + intervalo)
//    {
//        //Itera sobre os incrementos dt.
//
//        *(arrayDt+contador2) = contador;
//        contador2++;
//    }
//
//    return arrayDt;//Retorna o array de incrementos.
//}

////Open iterative menu to user chosen an option.
//main()
//{
//
////printf("%f",exp(1));
//
//    int testes = 0;
////printf("ivandre \n");
//
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
////        int userInput = 4;
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
//                //gravaArquivoDistUniforme(x,y,NDePontos,nomeArquivoDat);//Create file with the pesudo numbers creates by function distribuicaoUniforme
//                plotHistogram(nomeArquivoDat);
//                //plotFunction();//Save a png with points ploted by gnuplot
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
//                // double* intervaloPlotar = (double*)malloc((NDeBarras+1)*sizeof(double));
//
//                numerosHistograma = randomNumberWithSeedLinear(NDePontos);
//                insertionSort(numerosHistograma,NDePontos);
//
//                char * nomeArquivoDat = "arquivo.dat";
//                //int gravaArquivoDistUniforme(double*X, double*Y,int tamanho,char * nomeArquivo){
//
//                //printArray(numerosHistograma,NDePontos);
//                double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
//                                          NDePontos,intervalosEntreBarras,inicio,fim);
//
//                gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.11111,NDeBarras,nomeArquivoDat);//Create file with the pesudo numbers creates by function distribuicaoUniforme
//                //plotFunction();//Save a png with points ploted by gnuplot
//                plotHistogram(nomeArquivoDat);
//
//
//                //free(y);
//                free(numerosHistograma);
//                free(intervalosEntreBarras);
//                break;
//
//            }
//
//            case 3:  //Distribuicao Gaussiana.
//            {
//
//                //Aqui vem a gaussiana.
//                int NDePontos = 100000;//Define quantos numeros serao trabalhados.
//                int NDeBarras = 150;//Define tamanho dos intervalos.
//
//                //Define o tamanho do intervalo onde serão gerados os numeros.
//                int tamanhoTotalIntervalo = 8;
//                int inicio = -4;
//                int fim = 4;
//
//                //Aloca memoria para os numeros, em outras palavras define um array.
//                double diff = (double)tamanhoTotalIntervalo/(double)NDeBarras;
//
//                //Armazena os numeros aletatorios usados para gerar um histograma
//                double* numerosHistograma = (double*)malloc((NDePontos)*sizeof(double));
//
//                //Armazena o valor limite dos intervalos
//                double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));
//
//                numerosHistograma = distribuicaoGaussiana(NDePontos);
//
//                char * nomeArquivoTeste = "arquivoTeste.dat";
//
//                //insertionSort(numerosHistograma,NDePontos);
//
//                char * nomeArquivoDat = "arquivo.dat";
//                double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
//                                          NDePontos,intervalosEntreBarras,inicio,fim);
//
//                gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
//                                       NDeBarras,nomeArquivoDat);//Create file with the pesudo numbers
//                //creates by function distribuicaoUniforme
//
//                plotHistogram(nomeArquivoDat);
//
//                free(numerosHistograma);
//                free(intervalosEntreBarras);
//
//                break;
//            }
//
//            case 4:  //Distribuicao Exponencial
//            {
//
//                printf("Exponencial :)");
//                //Aqui vem o codigo que calcula a exponencial.
//                int npontos = 100000;
//                int NDeBarras = 15;//Define tamanho dos intervalos.
//
//
//                double lambda = 2.0;
//                //Define o tamanho do intervalo onde serão gerados os numeros.
//                int tamanhoTotalIntervalo = 5;
//                int inicio = 0;
//                int fim = 5;
//
//                double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));//Armazena o valor limite dos intervalos
//                double * Exp = distribuicaoExponencial(npontos,lambda);
//
//                insertionSort(Exp,npontos);
//
//                char * nomeArquivoDat = "exponencial.dat";
//                double* arrayFrequencia = CreateHistogram(NDeBarras,Exp,
//                                          npontos,intervalosEntreBarras,inicio,fim);
//
//                gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
//                                       NDeBarras,nomeArquivoDat);
//
//                plotHistogram(nomeArquivoDat);
//
//
//                free(arrayFrequencia);
//                free(intervalosEntreBarras);
//                free(Exp);
//
//                break;
//            }
//
//            case 5:  //Movimento Browniano
//            {
//
//
//
//                int tamanho = 1;
//                int numeroPontos = 10000000;
//
//                //Calula pontos do movimento Browniano.
//                double * incrementoWiener = (double*)malloc(numeroPontos*sizeof(double));
//                double * Brown = (double*)malloc(numeroPontos*sizeof(double));
//                Brown = movimentoBrowniano(tamanho,numeroPontos,incrementoWiener);
//
//                //Plota movimento Browniano
//                gravaArquivoDistUniforme(incrementoWiener, Brown,numeroPontos,"arquivo.dat");
//                plotFunction("arquivo.dat");
//
//                //Libera memoria
//                free(incrementoWiener);
//                free(Brown);
//
//
//            }
//
//            case 6:
//            {
//
//                //Solucao para a integral de Ito.
//                double ito = integralITO();
//                printf("Valor da integral de ITO %f ",ito);
//            }
//
//            case 7:
//            {
//
//                //Algoritmo de Euler-Maruyama.
//                eulerMaruyama();
//
//            }
//
//            case 999:
//            {
//
//                userInput = 999;
//                break;
//            }
//
//            }
//        }
//    }
//
//
//    if(TESTE == 1) //Se for apenas para testar.
//    {
//
//        int NDePontos = 100;//Define quantos numeros serao trabalhados.
//        int NDeBarras = 5;//Define tamanho dos intervalos.
//        int inicio = 0;//Tamanho eixo X
//        int fim = 1;
//
//        //Aloca memoria para os numeros, em outras palavras define um array.
//        double diff = (double)2.0/(double)NDeBarras;
//        double* numerosHistograma;
//        double* intervalosEntreBarras =
//                            (double*)malloc((NDeBarras+1)*sizeof(double));
//
//        numerosHistograma = randomNumberWithSeedLinear(NDePontos);
//        insertionSort(numerosHistograma,NDePontos);
//
//        char filename [ 20 ];
//        sprintf(filename,"%d_%d");
//        //printf("%s",filena);
//       // char * nomeArquivoDat = "arquivo.dat";
//        //int gravaArquivoDistUniforme(double*X, double*Y,int tamanho,char * nomeArquivo){
//
//        //printArray(numerosHistograma,NDePontos);
//        double* arrayFrequencia = CreateHistogram(NDeBarras,numerosHistograma,
//                                  NDePontos,intervalosEntreBarras,inicio,fim);
//
//        //Create file with the pesudo numbers creates by function distribuicaoUniforme
//        gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,
//                               0.11111,NDeBarras,filename);
//
//        //plotFunction();//Save a png with points ploted by gnuplot
//        plotHistogram(filename);
//
//
//        //free(y);
//        free(numerosHistograma);
//        free(intervalosEntreBarras);
////        break;
//
//
//
//
//
//
////     printf("delano  \n");
////     eulerMaruyama();
//
////        printf("Exponencial :)");
////        //Aqui vem o codigo que calcula a exponencial.
////        int npontos = 800000;
////        int NDeBarras = 1000;//Define tamanho dos intervalos.
////        double lambda = 2.0;
////
////        //Define o tamanho do intervalo onde serão gerados os numeros.
////        int tamanhoTotalIntervalo = 5;
////        int inicio = 0;
////        int fim = 5;
////
////        //Armazena o valor limite dos intervalos
////        double* intervalosEntreBarras = (double*)malloc((NDeBarras+1)*sizeof(double));
////        double * Exp = distribuicaoExponencial(npontos,lambda);
////
////        insertionSort(Exp,npontos);
////
////        char * nomeArquivoDat = "exponencial.dat";
////        double* arrayFrequencia = CreateHistogram(NDeBarras,Exp,
////                                  npontos,intervalosEntreBarras,inicio,fim);
////
////        gravaArquivoHistograma(intervalosEntreBarras,arrayFrequencia,0.0666666,
////                               NDeBarras,nomeArquivoDat);
////
////        plotHistogram(nomeArquivoDat);
////
////
////        free(arrayFrequencia);
////        free(intervalosEntreBarras);
////        free(Exp);
//
//        //Aqui vem a gaussiana.
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
////
//
//
//    }
//
//    return 0;
//}
