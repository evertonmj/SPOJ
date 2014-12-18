#include <stdio.h>
#include <string.h>

int particao[20];
int matrizAlunos[20][20];

int verificarSeTodosGostam(int aluno, int nivelArvore) {
	int i;
    for (i = 0; i < nivelArvore; i++) {
       if (!matrizAlunos[particao[i]][aluno]) {
            return 0;
	   }
    }
    return 1;
}

int backtracking(int verticeInicial, int nivelArvore, int melhorEscolha, int numeroAlunos) { 
    particao[nivelArvore++] = verticeInicial;
	int aluno;
    if (nivelArvore > melhorEscolha) {
        melhorEscolha = nivelArvore;
	}
    for (aluno = verticeInicial + 1; aluno < numeroAlunos; aluno++) {
        if (verificarSeTodosGostam(aluno, nivelArvore) == 1) {
            melhorEscolha = backtracking(aluno, nivelArvore, melhorEscolha, numeroAlunos);
		}
	}
	
	return melhorEscolha;
}

int definirNumeroFinalAlunos(int numeroAlunos, int melhorEscolha) {
	int i, n = 0;
    for (i = 0; i < numeroAlunos; i++) {
        melhorEscolha = 0;
        melhorEscolha = backtracking(i, 0, melhorEscolha, numeroAlunos);
        if (melhorEscolha > n) {
            n = melhorEscolha;
		}
        if (n == numeroAlunos) {
        	break;
        }
     }
     
	 return n;
}

//funcao principal do sistema
int main() {
	int i, j;
	int numeroAlunos, alunoRecusa;
	int teste = 1;
	
	scanf("%d", &numeroAlunos);
	
	while(numeroAlunos > 0) {
		int resultado = 0;
		int melhorEscolha = 0;
		//seta a matriz de alunos inicialmente com todos igual a 1
		for(i = 0; i < numeroAlunos; i++) {
			for(j = 0; j < numeroAlunos; j++) {
				matrizAlunos[i][j] = 1;
			}
		}
			
		//para cada um dos alunos, checa quais ele nao gosta e seta como 0 na matriz
		for(i = 0; i < numeroAlunos; i++) {
			scanf("%d", &alunoRecusa);	
			while(alunoRecusa > 0) {
				matrizAlunos[i][alunoRecusa - 1] = 0;
				matrizAlunos[alunoRecusa - 1][i] = 0;
				scanf("%d", &alunoRecusa);
			}
		}
		//obtem o resultado final da turma
		resultado = definirNumeroFinalAlunos(numeroAlunos, melhorEscolha);
		
		printf("Teste %d\n%d\n", teste, resultado);
		teste++;
		//pega o proximo set de alunos
		scanf("%d", &numeroAlunos);
	}
	
	return 0;
}