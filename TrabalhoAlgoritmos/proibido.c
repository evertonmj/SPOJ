/**
Este programa faz a busca de um numero em uma lista de numeros proibidos
@author Everton Mendonca
*/
#include <stdio.h>
#include <string.h>

long quantidadeNumProibido;
long numerosProibidos[160000];
long listaAux[160000];

/**
Esta funcao converte um array de string em um array de ints, quebrando a string com espacos
*/
void converterStringArray(char string[]) {
	char *numero;
	const char *espaco = " ";
	int i = 0;
	long var;

	numero = strtok(string, espaco);
  
	while(numero != NULL){
		sscanf (numero, "%ld", &var);
		numerosProibidos[i] = var;
	    numero = strtok(NULL, espaco);
		i++;
	}
}

/**
Ordena o array via quicksort
*/
void quicksort(long vetor[160000], long inicio, long fim){
    
   long pivo, aux, i, j, meio;
    
   i = inicio;
   j = fim;
    
   meio = (long) ((i + j) / 2);
   pivo = vetor[meio];
     
   do {
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
       
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   } while(j > i);
    
   if(inicio < j) {
	   quicksort(vetor, inicio, j);
   } 
   if(i < fim) {
	   quicksort(vetor, i, fim);   
   } 
}

/**
faz uma busca binaria no array de numeros proibidos
*/
int buscarNumeroProibido( int numero) {
   int e, m, d;
   e = 0; 
   d = quantidadeNumProibido - 1;
   while (e <= d) { 
      m = (e + d)/2; 
      if (numerosProibidos[m] == numero) {
		  return 1;
      }
      if (numerosProibidos[m] < numero) {
      	e = m + 1;
      } 
      else {
      	d = m - 1;
      } 
   }
   return -1;
}

/**
Funcao principal do sistema
*/
int main() {
	char stringAux[1600000];
	long numeroTeste;
	
	//obtem quantidade de numeros proibidos
	scanf("%ld", &quantidadeNumProibido);
	//obtem lista com numeros proibidos e tranforma em array de inteiros
	scanf(" %[^\n]s", stringAux);
	converterStringArray(stringAux);
	
	//ordena lista de numeros via quicksort
	quicksort(numerosProibidos, 0, quantidadeNumProibido - 1);
	
	//recebe valores a serem testados ate EOF
	while(scanf("%ld", &numeroTeste) != EOF) {
		if(buscarNumeroProibido(numeroTeste) == 1) {
			printf("sim\n");
		} else {
			printf("nao\n");
		}
	}
	
	return 0;
}