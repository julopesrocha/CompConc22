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

// Fluxo das threads

// Fluxo Principal
int main(int argc, char *argv[]) {
    double maior, menor;
    // double inicio, fim; // variáveis para tomada de tempo

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
    printf("Vetor: ");
    for(long int i=0; i<dim; i++){
        vetor[i] = 1000.1/(i+1);
        printf("%f,", vetor[i]);
    }
    printf("\n");
    /* Execução | Sequencial */
    maior = menor = vetor[0];
    for(long int i=1; i<dim; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        } else if (vetor[i] < menor){
            menor = vetor[i];
        }
    }

    /* Execução | Concorrente */
        // Criação das threads & alocação de memória
        // Aguarda término de execução
        // Computa os valores finais

    /* Exibição de resultados */
    printf("Maior elemento do vetor: %f\n", maior);
    printf("Menor elemento do vetor: %f\n", menor);

    /* Libera os espaços de memória alocados */
    free(vetor);

    return 0; 
}