# Laboratório 10 | Relatório
O objetivo deste Laboratorio é praticar o uso de semáforos para implementar exclusão
mútua e sincronização condicional.

## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)
* [Análise | Atividade 1](#análise--atividade-1)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ gcc -o esc_leit.c esc_leit -lpthread -Wall
```
```
$ ./esc_leit
```
## Exercícios Semáforos | Semáforos em C

## Análise | Atividade 1 

**Roteiro** 
- O algoritmo visto implementa uma solução para o problema dos leitores e escritores
(mais de um leitor pode ler ao mesmo tempo; apenas um escritor pode escrever de cada
vez e nenhum leitor pode estar lendo) com prioridade para escrita (sempre que há um
escritor esperando, o acesso para novos leitores é bloqueado até que o escritor seja atendido).

1. Quais devem ser os valores iniciais dos semaforos (em_e, em_l, escr, leit) para que o
algoritmo funcione corretamente?
Por serem semaforos que serão utilizados para exclusão mútua, 

2. É possível simplificar esse codigo (reduzir o uso dos mecanismos de sincronização)?

3. Implemente um programa em C para experimentar esse algoritmo. Inclua mensagens de log para acompanhar a execução e verificar a sua corretude. Teste seu programa variando o numero de threads “leitoras” e “escritoras". Certifique-se que ele funciona em todos os casos.