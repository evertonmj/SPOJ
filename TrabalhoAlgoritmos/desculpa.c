//problema desculpa
#include <stdio.h>
#include <string.h>

//determina o maior de dois numeros
int maior(int x, int y) {
    if (x > y) {
		return x;
	}
    else {
    	return y;
    }
}
//utiliza o metodo knapsack (metodo da mochila) para determinar o numero maximo de desculpas
int knapsack(int quantidadeFrases, int compFrases[], int qtdDesculpe[], int comprimentoCartao) {
	int i, j, totalDesculpas;
	int matriz[quantidadeFrases+1][comprimentoCartao+1];

	for(i=0 ; i<quantidadeFrases ; i++) { 
		for(j=0 ; j<comprimentoCartao+1 ; j++) {
			matriz[i][j] = 0;
		}
	}

	for (i=1 ; i<= quantidadeFrases; i++) {
	    for (j=1 ; j<=comprimentoCartao ; j++) {
	    	if(compFrases[i] <= j) {
				matriz[i][j] = maior(matriz[i-1][j], qtdDesculpe[i] + matriz[i-1][j-compFrases[i]]);    
			}
	    	else {
	    		matriz[i][j] = matriz[i-1][j];
	    	} 
	    	totalDesculpas = matriz[i][j];
	    }
	}
	return totalDesculpas;
}
void imprimirResultado(int teste, int resultado) {
	printf("Teste %d\n", teste);
	printf("%d\n", resultado);
	printf("\n");
}

int main() {
	int comprimentoCartao;
	int quantidadeFrases;
	int comprimentoFrase;
	int quantidadeDesculpe;
	int teste = 1;
	int compFrases[1000];
	int qtdDesculpe[1000];
	
	//le a entrada inicial
	scanf("%d%d", &comprimentoCartao, &quantidadeFrases);
	while(comprimentoCartao > 0 && quantidadeFrases > 0) {
		int i = 1;
		int resultado;
		
		//le as proximas frases
		while(i <= quantidadeFrases) {
			scanf("%d%d", &comprimentoFrase, &quantidadeDesculpe);
			compFrases[i] = comprimentoFrase;
			qtdDesculpe[i] = quantidadeDesculpe;
			i++;
		}
		resultado = knapsack(quantidadeFrases, compFrases, qtdDesculpe, comprimentoCartao);

		imprimirResultado(teste, resultado);
		teste++;
		scanf("%d%d", &comprimentoCartao, &quantidadeFrases);
	}
	
	return 0;
}