
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define L 3
#define E 3

#define NTHREADS L+E

// Variaveis globais
sem_t leit, escr, em_l, em_e; //semaforos para sincronizar a ordem de execucao das threads
int e=0, l=0; //globais
int num_leitores=0; //numero de leitores lendo

float c, f=23.7; //variaveis auxiliares

//funcao executada pelos leitores
void *Leitor (void *threadid) {
    int tid =  * (int*) threadid, i;
    while(1) {
        sem_wait(&leit); 
        sem_wait(&em_l); l++; 
        if(l==1) sem_wait(&escr); 
        sem_post(&em_l);
        sem_post(&leit);
        sem_wait(&em_l); l--; 
        if(l==0) sem_post(&escr);
        sem_post(&em_l);
    }   
  pthread_exit(NULL);
}

//funcao executada pelos escritores
void *Escritor (void *threadid) {
  int tid = *(int*) threadid, i;
  while(1) {
    sem_wait(&em_e); e++;
    if(e==1) sem_wait(&leit);
    sem_post(&em_e);
    sem_wait(&escr);
    sem_wait(&em_e); e--;
    if(e==0) sem_post(&leit);
    sem_post(&em_e);
  }
  pthread_exit(NULL);
}

//funcao principal
int main(int argc, char *argv[]) {
  pthread_t tid[L+E];
  int t, id[L+E];
  
  //inicia os semaforos
  sem_init(&leit, 0, 1);
  sem_init(&escr, 0, 1);

  //cria as threads
  for (t=0; t<E; t++) {
     id[t]=t;
     if (pthread_create(&tid[t], NULL, Escritor, (void *)&id[t])) { printf("--ERRO: pthread_create()\n"); exit(-1); }
  }
  for (t=L; t<NTHREADS; t++) {
     id[t]=t-L;
     if (pthread_create(&tid[t], NULL, Leitor, (void *)&id[t])) { printf("--ERRO: pthread_create()\n"); exit(-1); }
  }  
  //--espera todas as threads terminarem
  for (t=0; t<NTHREADS; t++) {
    if (pthread_join(tid[t], NULL)) {
         printf("--ERRO: pthread_join() \n"); exit(-1); 
    } 
  } 
  pthread_exit(NULL);
}