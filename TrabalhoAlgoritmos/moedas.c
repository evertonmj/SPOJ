#include <stdio.h>
#include <string.h>

//determina o menor de dois numeros
int menor(int x, int y) {
    if (x < y) {
		return x;
	}
    else {
    	return y;
    }
}

//utiliza o metodo knapsack (metodo da mochila) para determinar o numero minimo de moedas
void knapsack(int precos[], int quantidadeMoedas, int moedas[], int precoMercadoria) {
	int i, j;

	for (i = 1; i <= precoMercadoria; i++){
        if (precos[i]) {
            for (j = 0; j < quantidadeMoedas; j++){
                if (i + moedas[j] > precoMercadoria) {
                    break;
                }
                if (precos[i + moedas[j]] == 0) {
                    precos[i + moedas[j]] = precos[i] + 1;
                } else {
                    precos[i + moedas[j]] = menor(precos[i + moedas[j]],precos[i] + 1);
                }
            }
        }
    }
}

//funcao principal do programa
int main() {
    int precoMercadoria, numeroMoedas;
    int i;
    int moedas[100];
    int precos[50000];
    
    scanf("%d", &precoMercadoria);
    //enquanto houverem mercadorias processa
    while(precoMercadoria > 0) {
        scanf("%d", &numeroMoedas);
        //zera todo o vetor de precos
        memset(precos,0,sizeof(precos));
        //obtem todas as moedas e as insere no vetor de precos nos locais apropriados
        for (i = 0; i < numeroMoedas; i++){
			scanf("%i", &moedas[i]);
			precos[moedas[i]] = 1;
		}
        //chama metodo da mochila (knapsack) para determinar a quantidade de moedas
        knapsack(precos, numeroMoedas, moedas, precoMercadoria);
        
        //exibe quantidade de moedas
        //caso nao seja possivel alcancar o valor exato, escreve Impossivel
        if(precos[precoMercadoria]) {
            printf("%d", precos[precoMercadoria]);
        } else {
            printf("Impossivel");   
        }
        
        printf("\n");  
        //obtem proximo caso de teste
        scanf("%d", &precoMercadoria);
    }
    
    return 0;
}