/* Codigo: Acessando variável compartilhada em um programa multithreading Java */
/* -------------------------------------------------------------------*/

import java.util.ArrayList;
import java.util.Random;


//classe da estrutura de dados (recurso) compartilhado entre as threads
class Contador {
   //recurso compartilhado (contador)
   private int cont;

   //construtor
   public Contador() { 
      this.cont = 0;
   }
   public synchronized void inc(){
      this.cont++; 
   }

   public synchronized int get() { 
      return this.cont; 
   }
   
}
  
  //classe que estende Thread e implementa a tarefa de cada thread do programa 
  class T extends Thread {
     //identificador da thread
     private int id;
     // array
     private ArrayList<Integer> vet;
     // numero de threads
     private int Nthreads; 
     //objeto compartilhado com outras threads
     Contador cont;
    
     //construtor
     public T(int tid, Contador cont, ArrayList<Integer> vet, int NThreads) { 
        this.id = tid; 
        this.cont = cont;
        this.vet = vet;
        this.Nthreads = NThreads;
     }
  
   //metodo main da thread
   public void run() {
      System.out.println("Thread " + this.id + " iniciou!");
      for (int i=id; i<vet.size(); i+=Nthreads) {
         int atual = (int)vet.get(i);
         if(atual%2 ==0){
            this.cont.inc();
         }
      }
      System.out.println("Thread " + this.id + " terminou!");  
   }
   
}

  
//classe da aplicacao
class Par {
   static final int N = 2;
   static final int L = 10;

   public static void main (String[] args) {

      //reserva espaço para um vetor de threads
      Thread[] threads = new Thread[N];
      
      //cria vetor de inteiros
      ArrayList<Integer> vetor = new ArrayList<Integer>(); 


      //inicializa vetor de inteiros com números aleatórios de 0 a 100
      Random random = new Random();

      for(int i=0; i<L; i++){
         vetor.add(random.nextInt(100));
         int n = (int)vetor.get(i);
         System.out.println("["+i+"] = "+ n);
      }

      

      //cria uma instancia do recurso compartilhado entre as threads
      Contador cont = new Contador();

      //cria as threads da aplicacao
      for (int i=0; i<threads.length; i++) {
         threads[i] = new T(i, cont, vetor, N);
      }

      //inicia as threads
      for (int i=0; i<threads.length; i++) {
         threads[i].start();
      }

      //espera pelo termino de todas as threads
      for (int i=0; i<threads.length; i++) {
         try { threads[i].join(); } catch (InterruptedException e) { return; }
      }

      System.out.println("Quantidade de números pares do vetor = " + cont.get()); 
   }
}