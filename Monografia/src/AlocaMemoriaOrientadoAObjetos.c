/*Aloca memória para doubles.*/
double * alocaMemoriaDouble(int tamanhoAlocar){

    return (double*)malloc(tamanhoAlocar*sizeof(double));
}

/*Desaloca memoria de double.*/
void liberaMemoriaDouble(double * liberar){

    free(liberar);
}
