#include <stdio.h>
#include <string.h>

int quantidadeCartas;
long numeros[10];

//esta funcao converte um array de string em um array de ints, quebrando a string com espacos
void converterStringArray(char string[]) {
	char *numero;
	const char *espaco = " ";
	int i = 0;
	long var;

	numero = strtok(string, espaco);
	sscanf (numero, "%ld", &var);
	quantidadeCartas = var;

	numero = strtok(NULL, espaco);
	
	while(numero != NULL){
		sscanf (numero, "%ld", &var);
		if(var < 1000000000) {
			numeros[i] = var;
	    	numero = strtok(NULL, espaco);
			i++;
		}
	}
}

//ordena o array via quicksort
void quicksort(long vetor[], int inicio, int fim){  
   int i, j, meio;
   long pivo, aux;
    
   i = inicio;
   j = fim;
    
   meio = (long) ((i + j) / 2);
   pivo = vetor[meio];
   
   while (j > i) {
      while (vetor[i] < pivo) {
		  i = i + 1;
	  }
      while (vetor[j] > pivo) {
		  j = j - 1;
      }
			  
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }
    
   if(inicio < j) {
	   quicksort(vetor, inicio, j);
   } 
   if(i < fim) {
	   quicksort(vetor, i, fim);   
   } 
}

//imprime as combinacoes
void imprimirResultado(const long v[], const int quantidade) {
  if (v != 0) {
	  int i;
    for (i = 0; i < quantidade; i++) {
      printf("%ld ", v[i]);
    }
    printf("\n");
  }
}

//rotacionar o vetor a esquerda
void rotacionarEsquerda(long v[], const int inicio, const int quantidade) {
  long aux = v[inicio];
  int i;
  for (i = inicio; i < quantidade - 1; i++) {
    v[i] = v[i + 1];
  }
  v[quantidade - 1] = aux;
}

//faz a troca entre os elementos i e j do vetor
void trocar(long vetor[], const int i, const int j) {
  long aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

//imprime as diferentes combinacoes do vetor informado
void imprimirCombinacoes(long v[], const int inicio, const int quantidade) {
  imprimirResultado(v, quantidade);
  if (inicio < quantidade) {
    int i, j;
    for (i = quantidade - 2; i >= inicio; i--) {
      for (j = i + 1; j < quantidade; j++) {
    	  trocar(v, i, j);
    	  imprimirCombinacoes(v, i + 1, quantidade);
      }
      rotacionarEsquerda(v, i, quantidade);
    }
  }
}

//funcao principal do programa
int main() {
	char stringAux[1000000];
	
	scanf(" %[^\n]s", stringAux);
	
	converterStringArray(stringAux);
	
	//enquanto a entrada for diferente de zero, continua executando
	while(quantidadeCartas > 0) {	
		if(quantidadeCartas >= 1 && quantidadeCartas <= 8) {
			quicksort(numeros, 0, quantidadeCartas-1);
			imprimirCombinacoes(numeros, 0, quantidadeCartas);
			//le a proxima entrada
			quantidadeCartas = 0;
			scanf(" %[^\n]s", stringAux);
			converterStringArray(stringAux);
			printf("\n");
		}
	}
	
	return 0;
}
