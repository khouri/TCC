#include <stdio.h> 

//Imprime String
int metodo5(char entrada[]) {


return 1;
}

//Exemplo de switch/case
int metodo4(int numeroDeVezes) {

   switch(numeroDeVezes) {//Aqui vc pode entrar com strings ou numeros.

	case 1:
	  printf("1");
	  break;
	
	case 2:
	  printf("2");
	  break;
	  
	case 3:
	  printf("3");
	  break;
	
	case 4:
	  printf("4");
	  break;
	  
	default:
	  printf("default");
	  break;
   } 

}


int metodo3(int numeroDeVezes) {

if(numeroDeVezes < 5) {

	printf("porco");

} else if(numeroDeVezes >= 5) {

	printf("porco2");

} else {

	printf("porco3");

}
return 1;
}

//Laco 'for' que imprime oxy.
int metodo2(int numeroDeVezes) {

int contador;
for(contador = 0; contador < numeroDeVezes; contador++) {

	printf("oxy \n");

}

return 1;
}

//Laco 'while' que imprime oxy.
int metodo(int numeroDeVezes) {

int contador = 0;
while(contador < numeroDeVezes) {
	
	printf("oxy \n");
	contador = contador + 1;

}

return 1;
}

int main () {

	printf ("Hello, world!\n");//printa ola, mundo na tela.
	//Esses dois comandos juntos param a execucao do programa.
	printf("DIGITE ENTER: ");
	getchar();
	metodo4(10);

return 0;
}

/*

para compilar via terminal:

compila e gera o object
gcc hello.c -o hello

executa por linha de comando o object
./hello

*/
