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
1. Para que fosse atendidas as modificações requeridas foi adicionada uma variável global que será um contador representando a lista de espera das threads escritoras
2. Para que a leitura seja iniciada, é necessaŕio verificar se, além de não haver uma thread escritora executando, também não há nenhuma thread escritora aguardando na lista de espera, pois a escritora teria prioridade
3. Ao iniciar o fluxo da escritora, quando bloqueamos a variavel mutex, incrementamos a lista de espera e é realizada a verificação se existe alguma escritora/leitora executando nesse momento. Se não houver, a thread sairá da lista de espera e iniciará a escrita
4. Ao finalizar a escrita, se não houver thread na lista de espera, será lançado um broadcast para que as leitoras sejam liberadas, garantindo que a segurança e prioridade da lista de espera das escritoras

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