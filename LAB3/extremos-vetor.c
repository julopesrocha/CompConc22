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

long int dim; // dimensão do vetor de entrada
int nthreads; // número de threads
float *vetor; // vetor de entrada  

// Funções utilitárias 
float geraFloat() {
  return ((float) rand()) / ((float)RAND_MAX) * 1000.1;
}

double deltaTempo(double inicio, char mensagem[]) {
  double fim, delta;
  GET_TIME(fim);
  delta = fim - inicio;
  printf("Tempo %s: %lf\n", mensagem, delta);
  return delta;
}


// Fluxo das threads
typedef struct {
    long int maior; 
    long int menor;
} tArgs;


void * tarefa(void * arg) {
    // Escopo Local
    long int id = (long int) arg; // identificador da thread
    long int tamanhoBloco = dim/nthreads; // tamanho do bloco que cada thread irá executar
    long int inicial = id * tamanhoBloco; // elemento inicia do vetor
    long int final = id * tamanhoBloco; // elemento inicia do vetor
    tArgs *estrutura = malloc(sizeof(tArgs));
    long int maior = vetor[inicial];
    long int menor = vetor[inicial];

    // Trata o resto da divisão de blocos, se houver
    if(id == nthreads-1) {
        final = dim;
    }

    // Execução

    for(long int i = inicial; i < final; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        } else if(vetor[i] < menor){
            menor = vetor[i];
        }
    }
    estrutura->maior=maior;
    estrutura->menor=menor;

    //retorna o maior e o menor
    pthread_exit((void *) estrutura);
}

// Fluxo Principal
int main(int argc, char *argv[]) {
    int maiorSeq, menorSeq, maiorConc, menorConc;
    double inicio; // tomada de tempo
    pthread_t *tid; // identificador de threads no sistema
    tArgs *retorno; // valor de retorno das threads | a função join já recebe um endereço, portanto, não é necessário alocar espaço na memória


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
        vetor[i] = rand() % (i+1);
    }
    printf("\n");
    /* Execução | Sequencial */
    GET_TIME(inicio);


    for(long int i=0; i<dim; i++){
        if(i==0) {
            maiorSeq = vetor[0];
            menorSeq = vetor[0];
        } else {
            if(vetor[i] > maiorSeq){
                maiorSeq = vetor[i];
            } else if (vetor[i] < menorSeq){
                menorSeq = vetor[i];
            }
        }
    }

    double Tseq = deltaTempo(inicio, "Sequencial");

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
        maiorConc = vetor[0];
        menorConc = vetor[0];
        for(long int i=0; i<nthreads; i++){
            if(pthread_join(*(tid+i), (void**) &retorno)){
                fprintf(stderr,"ERRO--pthred_join\n");
                return 4;
            }
            // valores globais
            if(retorno->maior>maiorConc){
                maiorConc = retorno->maior;
            }
            if(retorno->menor<menorConc){
                menorConc = retorno->menor;
            }
        }

        // Computa os valores finais
    double Tconc = deltaTempo(inicio, "Concorrente");
    
    /* Exibição de resultados */

        // Verifica valores e exibe
    if(maiorSeq == maiorConc && menorSeq == menorConc){
        printf("Maior elemento do vetor: %d\nMenor elemento do vetor: %d\n", maiorSeq, menorConc);
    } else {
        fprintf(stderr, "ERRO--soma-incorreta\n");
    }

    
    printf("Ganho: %f\n", (Tseq/Tconc));

    /* Libera os espaços de memória alocados */
    free(vetor);
    free(tid);

    return 0; 
}