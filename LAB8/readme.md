# Laboratório 08 | Relatório
Projetar e implementar uma aplicação concorrente em Java usando o padrão
basico leitores/escritores.

## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)
* [Descrição](#descrição)
* [Roteiro](#roteiro)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ javac Lep.java
```
```
$ java Lep
```

## Descrição
A aplicação terá como elemento central uma variável inteira inicializada com valor 0 (representando a nossa base de dados) que sera lida e alterada pelas threads.
Três tipos de threads deverão ser implementadas:
• T1: modifica a variavel incrementando seu valor de 1 (operação de escrita).
• T2: le a variável e a imprime na tela indicando se é um valor par ou ímpar(operação de leitura).
• T3: primeiro le a variável e a imprime na tela (operação de leitura); faz um processamento “bobo” qualquer (mais significativo); e depois modifica a variável escrevendo o valor do seu identificador de thread (operação de escrita).

## Roteiro
1. Considere um numero x de threads T1 (x >= 1), um numero y de threads T2
(y >= 1) e um numero z de threads T3 (z >= 1).
2. Acrescente no seu codigo a impressão de informações que permitam acompanhar a execução da aplicação para verificar se as condições lógicas do problema sao satisfeitas.
3. Execute a aplicação várias vezes e avalie os resultados obtidos.
4. Altere o numero de threads de cada tipo e reexecute a aplicação.