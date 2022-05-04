#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include"timer.h"

/*
    Laboratório 3 | Julia Lopes | 119137336

    Objetivo || Implementar uma solução sequencial e uma solução concorrente para o problema 
    de encontrar o menor e o maior valor de um vetor de numeros reais.

    Estratégia de divisão de threads || optei por fazer uma divisão das threads em blocos, portanto,
    se tendo 4 threads, dividimos o vetor em 4 grandes blocos, cada thread processando seu bloco respectivo.

    Implementação || optei por fazer a implementação tanto concorrente quanto sequencial fora da função main,
    dessa forma o código está mais organizado

    Algoritmo de execução || 

    Comandos para rodar a aplicação || 
        $ gcc extremos-vetor.c -o extremos-vetor -Wall -lpthread 
        $ ./extemos-vetor <dimensão do vetor> <número de threads>
*/

// Escopo Global

long long int dim; // dimensão do vetor de entrada
int nthreads; // número de threads
float *vetor; // vetor de entrada  

// Funções utilitárias 
float geraFloat() {
  return ((float) rand()) / ((float)RAND_MAX) * 1000.1;
}

void deltaTempo(double inicio, char mensagem[]) {
  double fim, delta;
  GET_TIME(fim);
  delta = fim - inicio;
  printf("Tempo %s: %lf\n", mensagem, delta);
}


// Fluxo das threads
typedef struct {
    float maior; 
    float menor;
} tArgs;


void * tarefa(void * arg) {
    // Escopo Local
    long int id = (long int) arg; // identificador da thread
    long int tamanhoBloco = dim/nthreads; // tamanho do bloco que cada thread irá executar
    long int inicial = id * tamanhoBloco; // elemento inicia do vetor
    long int final = id * tamanhoBloco; // elemento inicia do vetor
    float *maior, *menor;

    // Trata o resto da divisão de blocos, se houver
    if(id == nthreads) {
        final = dim;
    }

    // Execução
    maior = menor = 0;
    for(long int i = inicial; i < final; i++){
        if(vetor[i] > *maior){
            *maior = vetor[i];
        } else if(vetor[i] < *menor){
            *menor = vetor[i];
        }
        pthread_exit((void *)maior);
        pthread_exit((void *)menor);
    }
}

// Fluxo Principal
int main(int argc, char *argv[]) {
    float maiorSeq, menorSeq;
    double inicio; // tomada de tempo
    pthread_t *tid; // identificador de threads no sistema
    float *maior, *menor; /* valores de retorno das threads | a função join já recebe um endereço, portanto, não é necessário alocar espaço na memória */
    float maiorConc, menorConc;
    /* Recebe e Valida os parêmetros de entrada, são eles:
    (nome do programa, dimensão do vetor, número de threads ) */
    if(argc < 3) {
        fprintf(stderr, "Digite: %s <dimensão do vetor> <numero de threads>", argv[0]);
        return 1;
    }

    dim = atoll(argv[1]);
    nthreads = atoi(argv[2]);

    /* Aloca espaço de memória para o vetor de entrada */
    vetor = (float *) malloc((sizeof(float) * dim));
    if(vetor == NULL){
        fprintf(stderr, "ERRO--malloc\n");
        return 2;
    }

    /* Preenche o vetor de entrada com valores aleatórios */
    for(long int i=0; i<dim; i++){
        vetor[i] = geraFloat();
    }
    printf("\n");
    /* Execução | Sequencial */
    GET_TIME(inicio);

    maiorSeq = menorSeq = vetor[0];
    for(long int i=1; i<dim; i++){
        if(vetor[i] > maiorSeq){
            maiorSeq = vetor[i];
        } else if (vetor[i] < menorSeq){
            menorSeq = vetor[i];
        }
    }

    deltaTempo(inicio, "Sequencial");

    /* Execução | Concorrente */
    GET_TIME(inicio);

        // Criação das threads & alocação de memória
        tid = (pthread_t *) malloc(sizeof(pthread_t)*nthreads);
        if(tid == NULL) {
            fprintf(stderr, "ERRO--malloc\n");
            return 2;
        }

        for(long int i=0; i<nthreads; i++){
            if(pthread_create(tid+i, NULL, tarefa, (void *) i)){
                fprintf(stderr,"ERRO--pthred_create\n");
                return 3;
            }
        }
        // Aguarda término de execução
        for(long int i=0; i<nthreads; i++){
            if(pthread_join(*(tid+i), (void**)&maior)){
                fprintf(stderr,"ERRO--pthred_join\n");
                return 4;
            }
        }
        maiorConc = *maior;
        menorConc = *menor;
        // Computa os valores finais
    deltaTempo(inicio, "Concorrente");
    
    /* Exibição de resultados */

        // Maior elemento
    if(maiorSeq == maiorConc){
        printf("Maior elemento do vetor: %f\n", maiorSeq);
    } else {
        fprintf(stderr, "ERRO--soma-incorreta");
    }
        // Menor elemento
    if(menorSeq == menorConc){
        printf("Menor elemento do vetor: %f\n", menorSeq);
    } else {
        fprintf(stderr, "ERRO--soma-incorreta");
    }
    

    /* Libera os espaços de memória alocados */
    free(vetor);
    free(tid);

    return 0; 
}