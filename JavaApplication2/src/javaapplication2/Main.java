/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication2;
import java.io.Console;

/**
 *
 * @author adilson
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

//        double value =  Math.cos(0.9999999);
//        System.out.print("\n\n"+value+"\n");
//        value = Math.sin(1);
//        System.out.print(""+value+"\n\n");

//        calcula logaritmo natural de um numero.
//          double valum = Math.log(0.75);
//          System.out.print(""+valum+"\n\n");


        Imprime novo = new Imprime();
        novo.printMaster(3,1);

    }

}

class Imprime {


    void printLnNumbers(double x){

        System.out.println("Ln de "+ x +" = "+Math.log(x)+"");
    }

    void printCosNumbers(double x){

        System.out.println("Cosseno de "+ x +" = "+Math.cos(x)+"");
    }

    void printSinNumbers(double x){

        System.out.println("Seno de "+ x +" = "+Math.sin(x)+"");
    }

      void printLnNumbers(double x,int i){

        System.out.println("Ln de "+ x +" = "+Math.sqrt((Math.log(x))* -2)+"");
    }

    void printCosNumbers(double x,int i){

        System.out.println("Cosseno de "+ x +" = "+Math.cos(x*2*Math.PI)+"");
    }

    void printSinNumbers(double x,int i){

        System.out.println("Seno de "+ x +" = "+Math.sin(x*2*Math.PI)+"");
    }

    void normalTeste() {

        double dt = 1/500;
        Math.random();

        System.out.print("");
    }


    void printMaster(int escolha, int l) {

        if(escolha == 1){

            System.out.println("Função seno escolhida");
            for(double i = 0; i < 1; i = i + 0.01){

                printSinNumbers(i,1);
            }

        }
        if(escolha == 2){

            System.out.println("Função cosseno escolhida");
            for(double i = 0; i < 1; i = i + 0.01){

                printCosNumbers(i,1);
            }

        }
        if(escolha == 3){

            System.out.println("Função ln escolhida");
            for(double i = 0; i < 1; i = i + 0.01){

                printLnNumbers(i,1);
            }
        }
    }
}