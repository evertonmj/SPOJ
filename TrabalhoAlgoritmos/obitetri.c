/**
Problema OBITETRI
*/
#include <stdio.h>
#include <string.h>

long conjuntoTeste = 1;

struct Jogador {
	int classificacao;
	char nome[16];
	int pontuacao;
};

//calcula a pontuacao total de cada jogador
int calcularPontuacaoTotal(char string[]) {
	char *numero;
	const char *espaco = " ";
	int maximo, minimo, pontuacaoTotal = 0;
	int valores[13];
	
	int i = 0,j = 0;
	int var;

	numero = strtok(string, espaco);
  
	while(numero != NULL){
		sscanf (numero, "%d", &var);
		if(var >= 0 && var <= 1000) {
			valores[i] = var;
	    	numero = strtok(NULL, espaco);
			i++;
		}
	}
	
	minimo = valores[j];
	while(j < i) {
		//determina o minimo do conjunto
		if(valores[j] < minimo) {
			minimo = valores[j];
		}
		//determina o maximo do conjunto
		if(valores[j] > maximo) {
			maximo = valores[j];
		}
		
		pontuacaoTotal += valores[j];
		j++;
	}
	
	//subtrai maximo e minimo da pontuacao total
	pontuacaoTotal -= minimo;
	pontuacaoTotal -= maximo;
	
	return pontuacaoTotal;
}

/**
Ordena o array via quicksort pela pontuacao
*/
void quicksort(struct Jogador vetor[1200], int inicio, int fim){  
   int i, j, meio;
   struct Jogador pivo, aux;
    
   i = inicio;
   j = fim;
    
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   while (j > i) {
      while (vetor[i].pontuacao > pivo.pontuacao) {
		  i = i + 1;
	  }
      while (vetor[j].pontuacao < pivo.pontuacao) {
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

/**
Ordena o array via quicksort pelo nome dos jogadores
*/
void quicksortNome(struct Jogador vetor[1200], int inicio, int fim){  
   int i, j, meio;
   struct Jogador pivo, aux;
    
   i = inicio;
   j = fim;
    
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   while (j > i) {
      while (strcmp(vetor[i].nome, pivo.nome) < 0) {
		  i = i + 1;
	  }
      while (strcmp(vetor[j].nome, pivo.nome) > 0) {
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
	   quicksortNome(vetor, inicio, j);
   } 
   if(i < fim) {
	   quicksortNome(vetor, i, fim);   
   } 
}

/**
Ordena a lista de jogadores por total de pontuacao alcancada
Em caso de empate, os jogadores deverao ser ordenados por ordem alfabetica
*/
void ordenarJogadores(int quantidadeJogadores, struct Jogador jogadores[1200]) {
	int i = 0, classificacaoAnterior = 0, pontuacaoAnterior = 0, j, y, final;
	
	//ordena os jogadores via pontuacao
	quicksort(jogadores, 0, quantidadeJogadores - 1);
	//ordena os jogadores pelo nome
	for (j = 1; j < quantidadeJogadores; j++) {
		if (jogadores[j].pontuacao == jogadores[j-1].pontuacao) {
			final = j;
		    for (y = j + 1; y < quantidadeJogadores; y++) {
		    	if (jogadores[y].pontuacao == jogadores[j].pontuacao) {
		    		final = y;
		    	}
		    }
			quicksortNome(jogadores, j - 1, final);
			j = final;
		}
	}
	//determina classificacoes
	while(i < quantidadeJogadores) {
		if(pontuacaoAnterior == jogadores[i].pontuacao) {
			jogadores[i].classificacao = classificacaoAnterior;
		} else {
			jogadores[i].classificacao = (i+1);
		}
		pontuacaoAnterior = jogadores[i].pontuacao;
		classificacaoAnterior = jogadores[i].classificacao;
		i++;
	}
}

//exibe o resultado final ja ordenado
void exibirResultado(int quantidadeJogadores, struct Jogador jogadores[1200]) {
	int i = 0;
	
	printf("Teste %ld\n", conjuntoTeste);
	//exibe classificacoes
	while(i < quantidadeJogadores) {
		printf("%d %d %s\n", jogadores[i].classificacao, jogadores[i].pontuacao, jogadores[i].nome);
		i++;
	}
}

int main() {
	int quantidadeJogadores;
	char stringAux[250];
	
	scanf("%d", &quantidadeJogadores);
	
	//enquanto a entrada for diferente de zero, continua executando
	while(quantidadeJogadores > 0 && quantidadeJogadores <= 1000) {
		struct Jogador jogadores[1200];
		int i = 0;
		
		while(i < quantidadeJogadores) {
			struct Jogador jogador;
			scanf("%s", jogador.nome);
			scanf(" %[^\n]s", stringAux);
			jogador.pontuacao = calcularPontuacaoTotal(stringAux);
			jogadores[i] = jogador;
			i++;
		}	
		ordenarJogadores(quantidadeJogadores, jogadores);	
		//exibe resultado do conjunto de teste
		exibirResultado(quantidadeJogadores, jogadores);
		conjuntoTeste++;
		//pega a proxima quantidade de jogadores
		scanf("%d", &quantidadeJogadores);
		if(quantidadeJogadores > 0) {
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}