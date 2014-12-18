#include <stdio.h>
#include <string.h>

long quantidadeConsultas;

struct Consulta {
	long horaInicio;
	long horaFim;
};

struct Consulta consultas[100000];

/**
Esta funcao converte um array de string em um array de ints, quebrando a string com espacos
*/
struct Consulta converterStringArray(char string[]) {
	char *token;
	const char *separador = " ";
	long horaInicio;
	long horaFim;
	struct Consulta consulta;

	token = strtok(string, separador);
	sscanf (token, "%ld", &horaInicio);
	consulta.horaInicio = horaInicio;

	token = strtok(NULL, separador);	
	sscanf (token, "%ld", &horaFim);
	consulta.horaFim = horaFim;	
	
	return consulta;
}

/**
Ordena o array via quicksort
*/
void quicksort(struct Consulta vetor[100000], long inicio, long fim){
    
   long i, j, meio;
   struct Consulta pivo, aux;
    
   i = inicio;
   j = fim;
    
   meio = (long) ((i + j) / 2);
   pivo = vetor[meio];
     
   do {
      while (vetor[i].horaFim < pivo.horaFim) i = i + 1;
      while (vetor[j].horaFim > pivo.horaFim) j = j - 1;
       
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

int seletorAtividades(struct Consulta consultasS[100000], struct Consulta consultasF[100000]) {
	int i = 0;
	int j = 1;
	int quantidadeConsultasValidas = 1;
	
	while(j < quantidadeConsultas) {
		if(consultasS[j].horaInicio >= consultasF[i].horaFim){
			quantidadeConsultasValidas++;
			i = j;
		}
		j++;
	}
	
	return quantidadeConsultasValidas;
}

/**
Funcao principal do programa
*/
int main() {
	char entradaConsulta[100000];
	int resultado;
	
	scanf("%ld", &quantidadeConsultas);
	int i = 0;
	while (i < quantidadeConsultas) {
		scanf(" %[^\n]s", entradaConsulta);
		consultas[i] = converterStringArray(entradaConsulta);
		i++;
	}
	
	quicksort(consultas, 0, quantidadeConsultas);
	
	resultado = seletorAtividades(consultas, consultas);
	
	printf("%d\n", resultado);
	
	return 0;
}