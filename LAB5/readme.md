# Laboratório 05 | Relatório
O objetivo deste Laboratorio é introduzir o uso de soluções de sincronização por condição, usando variáveis de condição oferecidas pela biblioteca Pthreads.


## Índice
* [Objetivo](#objetivo)
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)

## Objetivo
:target: Projetar e implementar um programa concorrente onde a ordem de execução
das threads e controlada no programa, usando variáveis de condição

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ gcc cond.c -o cond -Wall -lpthread 
```
```
$ ./quadrado
```