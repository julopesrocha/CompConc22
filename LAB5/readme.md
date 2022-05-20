# Laboratório 05 | Relatório
O objetivo deste Laboratorio é introduzir o uso de soluções de sincronização por condição, usando variáveis de condição oferecidas pela biblioteca Pthreads.


## Índice
* [Objetivo](#objetivo)
* [Roteiro](#roteiro)
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)

## Objetivo
:target: Projetar e implementar um programa concorrente onde a ordem de execução
das threads e controlada no programa, usando variáveis de condição

## Roteiro
Implemente um programa com 5 threads:
- A thread 1 imprime a frase “Volte sempre!”.
- A thread 2 imprime a frase “Fique a vontade.”
- A thread 3 imprime a frase “Sente-se por favor.”
- A thread 4 imprime a frase “Aceita um copo d’agua?.”
- A thread 5 imprime a frase “Seja bem-vindo!”
As threads devem ser criadas todas de uma vez na func ̧ao main. A ordem de impressão
das mensagens (execução das threads) deverão ser:
- A thread 5 deve sempre ser a primeira a imprimir sua mensagem.
- A thread 1 deve sempre ser a ultima a imprimir sua mensagem.
- A ordem em que as threads 2, 3 e 4 imprimem suas mensagens nao importa, mas todas devem sempre imprimir suas mensagens depois da thread 5 e antes da thread 1.

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