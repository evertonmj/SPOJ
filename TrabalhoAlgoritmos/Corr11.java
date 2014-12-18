
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author everton
 */
class Corr11 {
    
    class Carro {
        public int identificador;
        public long tempoTotal;
    }
    
    public int numCarros;
    public int numVoltas;
    public Carro[] listaCarros;
    public Carro[] listaAux;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Corr11 corrida = new Corr11();
        corrida.processarEntrada(scanner);
        corrida.ordenarQuicksort();
        corrida.exibirResultado();
    }
    
    public void processarEntrada(Scanner scanner) {
        if(scanner.hasNext()) {
            String[] entradaIni = scanner.nextLine().split("\\s+");
            this.numCarros = Integer.parseInt(entradaIni[0]);
            this.numVoltas = Integer.parseInt(entradaIni[1]);
            this.listaCarros = new Carro[this.numCarros];
            this.listaAux = new Carro[this.numCarros];
            Carro carro = null;
            
            for(int i = 0; i < this.numCarros; i++) {
                long totalCarro = 0;
                String[] voltas = scanner.nextLine().split("\\s+");
                
                for (int j = 0; j < this.numVoltas; j++) {
                    totalCarro += Long.parseLong(voltas[j]);
                }
                
                carro = new Carro();
                carro.identificador = i;
                carro.tempoTotal = totalCarro;
                
                this.listaCarros[i] = carro;
            }
        } 
    } 
    
    
    public void exibirResultado() {
        for(int i = 0; i < 3; i++) {
            System.out.println(this.listaCarros[i].identificador + 1);
        }
    }
    
    public void ordenarQuicksort() {
        this.listaAux = this.listaCarros;
        quicksort(0, this.numCarros - 1);
      }

      private void quicksort(int inicio, int fim) {
        int i = inicio, j = fim;
        long pivo = this.listaAux[inicio + (fim-inicio)/2].tempoTotal;

        while (i <= j) {
          while (this.listaAux[i].tempoTotal < pivo) {
            i++;
          }
          while (this.listaAux[j].tempoTotal > pivo) {
            j--;
          }

          if (i <= j) {
            trocar(i, j);
            i++;
            j--;
          }
        }
        if (inicio < j)
          quicksort(inicio, j);
        if (i < fim)
          quicksort(i, fim);
      }

      private void trocar(int i, int j) {
        Carro temp = this.listaAux[i];
        this.listaAux[i] = this.listaAux[j];
        this.listaAux[j] = temp;
      }
}
