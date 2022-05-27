# Laboratório 06 | Relatório
O objetivo deste Laboratorio é praticar o uso de locks e variáveis de condição implementando
uma variaçao do problema dos leitores/escritores.


## Índice
* [Objetivo](#objetivo)
* [Roteiro](#roteiro)
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)

## Objetivo
:target: quando um escritor desejar escrever, nenhum leitor pode iniciar uma leitura enquanto o
escritor nao for atendido. Nesta solução, um leitor pode ter de esperar por muito tempo
(inanição), caso novos escritores cheguem com frequência.

## Roteiro
1. Pense o que precisa ser feito para dar prioridade para as operações de escrita,
como descrito acima.
2. Implemente a solução projetada, alterando o código que implementa o padrão básico leitores/escritores (fornecido junto com esse roteiro).
3. Execute a aplicação varias vezes e avalie os resultados obtidos (observe se ocorre
situações onde a prioridade de escrita foi contemplada).
4. Altere o numero de threads leitoras e escritoras e reavalie a aplicação.

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ gcc lab6.c -o lab6 -Wall -lpthread 
```
```
$ ./lab6
```