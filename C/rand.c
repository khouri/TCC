#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char *RolaMoeda (void) {
    int r;
    r = rand () % 2;
    if (r == 1) return "cara";
    else return "coroa";
}

//Cada rodada os numeros utilizam a semente default == 0; sempre são identicos aos da rodada anterior.
void randomSemSemente() {//Adota zero por default

int i;
    /* inicializar o gerador de números aleatórios */
    for (i=0; i<50; i++)
    {
          printf("%d ", rand()%101);//Gera números entre 0 e 100
    }
    /* printf("DIGITE ENTER: ");
       getchar();
     
     */
}

//Cada rodada aqui os numeros gerados sao identicos aos da rodada anterior.
void randomComSementeDefinida() {

int i;

    printf("\n");
    printf("\n");
    /* inicializar o gerador de números aleatórios */
    srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i<50; i++)
    {
          printf("%d ", rand()%101);//Gera números entre 0 e 100
    }
    /* printf("DIGITE ENTER: ");
       getchar();
     
     */
    printf("\n");
    printf("\n");
    
}

//Cada rodada aqui os valores são diferentes pois a hora do pc muda.
void randomComSementeDefinidaPelaHoraDoPc() {
    
int i;
    /* inicializar o gerador de números aleatórios */
    srand(time(NULL));//Com essa semente ele gera números aleatórios(subentenda-se pseudo) baseado no horário do Pc 
    //srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i<50; i++)
    {
          printf("%d ", (rand()%101));//Gera números entre 0 e 100
    }
    /* printf("DIGITE ENTER: ");
       getchar();
     
     */

}

/*
Teria um viés aqui??????
Algum bug????
Alguma incosistencia?????


*/

void geraRangeDeNumerosAleatoriosComDiferenca(int ini, int fim) {

int i;

    /* inicializar o gerador de números aleatórios */
    srand(time(NULL));//Com essa semente ele gera números aleatórios(subentenda-se pseudo) baseado no horário do Pc 
    //srand(100);//semente aleatória que garante números aleatórios(subentenda-se pseudo) sempre iguais
    for (i=0; i<1000; i++)
    {
	int aux = (rand()%101)+10;
	if(aux > 100) {
	
	   aux = aux - 10;
	}

        printf("%d ", aux);//Gera números entre 0 e 100
    }
}

//Funcao qeu retorna um ponteiro de numeros aleatorios.



main()
{
 
    //randomComSementeDefinidaPelaHoraDoPc();   
    geraRangeDeNumerosAleatoriosComDiferenca(1,1);
    return 0;
}
