# Laboratório 09 | Relatório
O objetivo deste Laboratorio é introduzir o uso de semáforos.

## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)
* [Análise | Atividade 1 | semaf_1.c](#análise--atividade-1--sem_1.c)
* [Análise | Atividade 2 | semaf_2.c](#análise--atividade-2--semaf-2c)
* [Implementação | ](#)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ 
```
```
$ 
```

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