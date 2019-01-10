#!/bin/bash

clear #Limpa a janela do terminal facilitando a visualizacao do resultado.

echo "The script starts now."

echo "Hi, $USER" # O sinal '$' eh utilizado para pegar o conteudo de uma variavel.
echo

echo "I will now fetch you a list of conected users:"
echo
w #Mostra quem estah logado e o que ele estah fazendo
echo

echo "I'm setting two variables now."
#Declara e instancia duas variaveis locais
COLOUR="black"
VALUE="9"
#Exibe duas variaveis locais criadas acima.
echo "This is a String: $COLOUR"
echo "and this is a number: $VALUE"

echo "Im giving you back your prompt now."
echo
