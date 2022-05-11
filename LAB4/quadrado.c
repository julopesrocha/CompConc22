/*
    gcc quadrado.c -o quadrado -lpthread -lm 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include"timer.h"

// Escopo global

long int dim; // dimensão do vetor de entrada
int nthreads; // número de threads
int *vetor; //vetor de entrada com dimensão dim
int i_global = 0;
int *vetorEntrada;
double *vetorSaidaSequencial;
double *vetorSaidaConcorrente;
pthread_mutex_t mutex; // variável de lock para exclusão mútua

int primo(long long int n){
    if(n==1) return 0;
    if(n==1) return 1;
    if(n%2 == 0) return 0;
    for(int i = 3; i<sqrt(n)+1; i+2){
        if(n%i==0) return 0;
    }
    return 1;
}

void * tarefaPrimos(){
    int i_local;
    // início da seção crítica
    pthread_mutex_lock(&mutex);
    i_local = i_global;
    i_global++;
    //fim da seção crítica
    pthread_mutex_unlock(&mutex);

    while(i_local<dim){
        if(primo(vetorEntrada[i_local])){
            vetorSaidaConcorrente[i_local]= sqrt(vetorEntrada[i_local]);
        }
        else {
            vetorSaidaConcorrente[i_local] = vetorEntrada[i_local];
        }

        pthread_mutex_lock(&mutex);
        i_local = i_global;
        i_global++;
        //fim da seção crítica
        pthread_mutex_unlock(&mutex);

    }
    pthread_exit(NULL);
}


// Função utiliária para tomada de tempo
double deltaTempo(double inicio, char mensagem[]) {
  double fim, delta;
  GET_TIME(fim);
  delta = fim - inicio;
  printf("Tempo %s: %lf\n", mensagem, delta);
  return delta;
}

// Processa Primos
void processaPrimos(int *vetorEntrada, double *vetorSaida, int dim){
    for(int i = 0; i<dim; i++){
            if(primo(vetorEntrada[i])){
                vetorSaida[i] = sqrt(vetorEntrada[i]);
            }
            vetorSaida[i] = vetorEntrada[i];
    }
}


// Fluxo Principal
int main(int argc, char *argv[]){
    // Escopo Local
    double inicio, Tseq, Tconc; // tomada de tempo
    pthread_t *tid; // identificador de threads no sistema

    /* Valida dados de entrada */
    if(argc < 3) {
        fprintf(stderr,"Digite: %s <dimensão do vetor><número de threads>", argv[0]);
        return 1;
    }

    /* Atribui os parâmentros de entrada */
    dim = atoi(argv[1]);
    nthreads = atoi(argv[2]);

    /* Aloca espaço de memória para o vetor de entrada */
    vetorEntrada = (int *) malloc(sizeof(int)*dim);
    vetorSaidaSequencial = (double *) malloc(sizeof(double)*dim);
    vetorSaidaConcorrente = (double *) malloc(sizeof(double)*dim);

    if(vetorEntrada == NULL) {
        fprintf(stderr, "ERRO--malloc-vetores\n");
        return 2;
    }
    if(vetorSaidaConcorrente == NULL) {
        fprintf(stderr, "ERRO--malloc-vetores\n");
        return 2;
    }
    if(vetorSaidaSequencial == NULL) {
        fprintf(stderr, "ERRO--malloc-vetores\n");
        return 2;
    }

    /* Preenche o vetor de entrada com valores aleatórios */
    for(int i = 0; i<dim; i++){
        vetorEntrada[i] = rand()%(+1);
    }

    /* Execução | Sequencial */
        //tomada de tempo
    GET_TIME(inicio);

    processaPrimos(vetorEntrada, vetorSaidaSequencial, dim);

    Tseq = deltaTempo(inicio, "Sequencial");

    /* Execução | Concorrente */
        //tomada de tempo
    GET_TIME(inicio);

        // Alocação de memória
    tid = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
    if(tid == NULL) {
        fprintf(stderr, "ERRO--malloc\n");
        return 3;
    }

    pthread_mutex_init(&mutex, NULL);

        // Cria threads
    for(long int i=0; i<nthreads; i++){
        if(pthread_create(tid+i, NULL, tarefaPrimos, (void*) i)){
            fprintf(stderr, "ERRO--pthread-create\n");
            return 4;
        }
    }
        // Aguarda término de execução
    for(int i =0; i<nthreads; i++){
        if(pthread_join(*(tid+i), NULL)){
            fprintf(stderr, "ERRO--pthread-join\n");
            return 5;
        }
    }

    Tconc = deltaTempo(inicio, "Concorrente");

    /* Exibição de resultados */
        // Verifica valores e exibe
    int verifica = 1;
    for(long int i=0; i<dim; i++){
        if(abs(vetorSaidaConcorrente-vetorSaidaSequencial)>0.000000001){
            verifica=0;
            break;
        }
    }

    if(verifica == 0){
        printf("Os resultados são compatíveis\n");
    } else {
        fprintf(stderr, "ERRO--valores-diferentes\n");
    }
    
        //Exibe ganhos de execução
    printf("Percentual de Ganho: %lf\n", Tseq/Tconc);

    /* Libera os espaços de memória alocados */
    pthread_mutex_destroy(&mutex);
    free(vetorEntrada);
    free(vetorSaidaSequencial);
    free(vetorSaidaConcorrente);

    return 0;
}

