import java.util.Scanner;

/**
 * Solucao para o problema JFILA14
 * @author Everton Mendonca
 */
class JFila14 {
    
    public int n;
    public int[] listaFila;
    public int m;
    public int[] listaSaida;
    public int[] numerosAux;
    
    public static void main(String[] args) {
        JFila14 jFila = new JFila14();
        Scanner scanner = new Scanner(System.in);
        jFila.processarEntrada(scanner);        
        jFila.exibirResultado();
    }
    
    public void processarEntrada(Scanner scanner) {
        if(scanner.hasNext()) {
            this.n = Integer.parseInt(scanner.nextLine());
            this.listaFila = this.transformarLinhaEmArray(this.n, scanner.nextLine().split("\\s+"));
            this.m = Integer.parseInt(scanner.nextLine());
            this.listaSaida = this.transformarLinhaEmArray(this.m, scanner.nextLine().split("\\s+"));
            ordenarQuicksort(this.listaSaida, this.m);
        } 
    }
    
    public int[] transformarLinhaEmArray(int n, String[] numeros) {
        
        int[] retorno = new int[n];
        
        for(int i = 0; i < n; i++) {
            retorno[i] = Integer.parseInt(numeros[i]);
        }
        
        return retorno;
    }

    
    public void exibirResultado() {
        for(int i = 0; i < this.n; i++) {
            if(!this.estaNaListaSaida(this.listaFila[i])) {
              System.out.print(this.listaFila[i] + " ");  
            }
        }
    }
    
    public boolean estaNaListaSaida(int pessoa) {
        int i = 0;
        int j;
        int t = this.m - 1;
        while(i <= t) {
            j = (i + t) / 2;
            if(this.listaSaida[j] == pessoa) {
                return true;
            }
            if(this.listaSaida[j] < pessoa) {
                i = j + 1;
            } else {
                t = j - 1;
            }
        }
        
        return false;
    }
    
    public void ordenarQuicksort(int[] lista, int tamanho) {
        if (lista ==null || lista.length==0){
          return;
        }
        this.numerosAux = lista;
        quicksort(0, tamanho - 1);
      }

      private void quicksort(int inicio, int fim) {
        int i = inicio, j = fim;
        int pivo = this.numerosAux[inicio + (fim-inicio)/2];

        while (i <= j) {
          while (this.numerosAux[i] < pivo) {
            i++;
          }
          while (this.numerosAux[j] > pivo) {
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
        int temp = this.numerosAux[i];
        this.numerosAux[i] = this.numerosAux[j];
        this.numerosAux[j] = temp;
      }
}
