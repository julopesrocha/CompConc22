# Laboratório 09 | Relatório
O objetivo deste Laboratorio é praticar o uso de semáforos para implementar exclusão mútua e sincronização condicional. Vamos repetir o exerício do Lab 5, agora usando semáforos, ao inves de locks e variaveis de condição.
## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)
* [Análise | Atividade 1 | semaf_1.c](#análise--atividade-1--sem_1.c)
* [Análise | Atividade 2 | semaf_2.c](#análise--atividade-2--semaf-2c)
* [Implementação | LAB9 ](#implementação--lab-9)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ gcc -o ordem.c ordem -lpthread -Wall
```
```
$ ./ordem
```
## Exercícios de Introdução | Semáforos em C

## Análise | Atividade 1 | semaf_1.c

**Objetivo** 
- Introduzir o uso de semaforos na linguagem C e sistema operacional Linux.

**Execute o programa varias vezes. Os valores impressos foram sempre o valor esperado?**
Sim, pois uma vez que o semáforo binário foi inicializado com um sinal, a primeira thread conseguiu acessar a zona crítica, e executou a tarefa. Respeitando a exclusão mútua, a segunda thread ficou bloqueada até receber o sinal da primeira thread assim que saiu da zona crítica.


## Análise | Atividade 2 | semaf-2.c

**Objetivo** 
- Mostrar um exemplo de uso de semaforos para coordenar a ordem de execução das threads.

**Roteiro**
1. Leia o programa para entender como ele funciona. Quais sao os possíveis valores finais da variável y?
O único possível valor final da variável y será 2. Pois da forma com a qual o programa está funcionando para que as therads 2 e 3 sejam executadas, necessariamente a thread 1 terá que executar primeiro uma vez que as threads 2 e 3 estão bloqueadas devido às variáveis de condição atribuídas a elas no wait do semaoro. Também é possível notar que os semáforos são inicializados com valor "0", dessa forma, não há sinal disponível para ser consumido pelas threads iniciais.

2. Execute o programa varias vezes e observe os resultados impressos na tela.

3. O valor final da variável y variou? Por que?
Não variou. Pois não há condição de corrida entre as threads devido ao valor de inicialização dos semáforos.

4. Altere o valor de inicialização dos semáforos de 0 para 1: faça sem init(&condt2,0,1) e sem init(&condt3,0,1)

- Execute o programa varias vezes e observe os resultados impressos na tela. O que aconteceu e por que? 
Sim, pois dessa forma o condicionamento de execução das threads não irá mais ser efetivo uma vez que as duas tem liberdade de iniciar, e acessar ao mesmo tempo a zona crítica, causando condição de corrida no sistema.

## Implementação | LAB 9 

**Objetivo**
Projetar e implementar um programa concorrente onde a ordem de execução das threads e controlada no programa.

**Roteiro**
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