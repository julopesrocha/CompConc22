#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NTHREADS  5

/* Variáveis Globais */
pthread_mutex_t x_mutex;
pthread_cond_t x_cond;
int x=0;

/* Exibe mesngaens 2-4 */

void *MI(void *t){
    // int *id = (int*)t;
    printf("MI | thread  iniciada\n");

    pthread_mutex_lock(&x_mutex);
    if(x==0){
        printf("MI | thread vai se bloquear\n");
        pthread_cond_wait(&x_cond, &x_mutex);
    }
    if(x==1){
        printf("Fique a vontade.\n");
    } else if(x==2){
        printf("Sente-se por favor.\n");
    } else if(x==3){
        printf("Aceita um copo d'agua?\n");
    }
    x++;
    pthread_cond_signal(&x_cond);
    pthread_mutex_unlock(&x_mutex); 
    pthread_exit(NULL);
}

/* Exibe mensagens 1 e 5 */
void *M1(void *t) {
    /* identificar a thread 5 -> modificar a variavel global(condiçao); 
       se alguma thread chegar antes deve ser bloqueada;
       quando a prox chegar, deve verificar a condição e liberar a thread bloqueada,
       que ira verificar a variavel global e dar prosseguimento a sua condição 
    */
    printf("M1 | Comecei a thread\n");
     
    pthread_mutex_lock(&x_mutex);
    if(x==3){
        pthread_cond_wait(&x_cond, &x_mutex);
        printf("M1 | Bloqueada\n");  // Exibe thread 1 | última mensagem
    } else if(x==0){
        printf("Seja bem-vindo!\n"); // Exibe primeira msg, thread 5
        x++;
        pthread_cond_broadcast(&x_cond);
    } else if(x>3){
       printf("Volte sempre!\n");  // Exibe thread 1 | última mensagem
    } 
    pthread_mutex_unlock(&x_mutex);    

    pthread_exit(NULL);
}

int main(void){
    pthread_t threads[NTHREADS];

    /* Inicializa lock(variavel de exclusão mútua e a variável de condição */
    pthread_mutex_init(&x_mutex, NULL);
    pthread_cond_init(&x_cond, NULL);

    /* Cria as threads */
    pthread_create(&threads[4], NULL, M1, NULL);
    pthread_create(&threads[1], NULL, MI, NULL);
    pthread_create(&threads[2], NULL, MI, NULL);
    pthread_create(&threads[3], NULL, MI, NULL);
    pthread_create(&threads[0], NULL, M1, NULL);

    /* Aguarda término de todas as threads */
    for (int i=0; i<NTHREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("Fim\n");

    /* Desaloca variáveis e termina */
    pthread_mutex_destroy(&x_mutex);
    pthread_cond_destroy(&x_cond);
    return 0;
}