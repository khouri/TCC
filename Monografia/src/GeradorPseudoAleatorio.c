/*Implementacao de um algoritmo que gera numeros
pseudo aleatorios entre 0 e c-1.*/
void geradorDeNumerosPseudoAleatorios(int qtdNumeros, int semente){

    int a = 13, b = 0, c = 997,
        X = 0,//Valor final.
        X0 = semente;//Semente

    int i;
    for(i = 1; i < qtdNumeros; i++){

        X = ( (X0 * a) + b ) % c;
        X0 = X;
        printf("%d ",X0);
    }
}
