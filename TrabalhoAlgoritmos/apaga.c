//problema do apaga
#include <stdio.h>

//atraves de uma busca binaria busca pela posicao correta do numero
int determinarPosicaoCorreta(int i, int j, char digito, char resultado[])
{
	int y;
	
	while(i <= j){
		y = (i + j) / 2;
		if(resultado[y] < digito)
			j = y - 1;
		else
		   i = y + 1;	
	}
	
	return i;	
}

//funcao principal do sistema
int main() {
	int apagar, posicao, qtdDigitos;
	
	scanf("%d%d", &qtdDigitos, &apagar);
	
	while(qtdDigitos > 0 && apagar > 0) {
		char digitos[qtdDigitos + 1]; 
		int j, i, posicaoAnterior = 0, fim;
		
		fim = qtdDigitos - apagar;
		char resultado[fim + 1];
		scanf("%s", digitos);
		
		resultado[0] = digitos[0];
		j = 0;
		
		//percorre o vetor de digitos para encontrar os mais significativose preenche o vetor de resultados
		for(i = 1; i < qtdDigitos; i++) {
			if(i <= apagar) {
				posicao = determinarPosicaoCorreta(0, j, digitos[i], resultado);
			} else {
				posicao = determinarPosicaoCorreta(i - apagar, j, digitos[i], resultado);
			}
			
			if(posicao < fim) {
				resultado[posicao] = digitos[i];
				j = posicao;
			}
		}
		//determina o final do vetor de resultado
		resultado[fim] = '\0';
		
		printf("%s\n", resultado);
		scanf("%d%d", &qtdDigitos, &apagar);
	}
	
	return 0;
}
