#!/bin/bash

clear #Limpa a janela do terminal facilitando a visualizacao do resultado.

echo "The script starts now."

echo "Exemplo de uso da variavel 'HOME': $HOME" #Armazena o caminho do meu diretório home.
echo "Exemplo de uso da variavel 'TERM': $TERM" # Exibe o tipo de terminal em uso.

#echo "Esse eh o caminh ateh meu diretorio HOME"
ls /etc/rc3.d/S*

echo


#Obs: O comando printenv print na tea do terminal todas as variaveis de ambiente do SO Linux
#Obs2: Variaveis em bash nao devem conter espacos entre o operador = e.g. correto: varname="oxy", errado varname = "oxy"
#
#
#
#
#
#
#
