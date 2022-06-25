# Laboratório 04 | Relatório
Análise de desempenho e cálculo da aceleração do programa de solução sequencial e uma solução concorrente para o problema de: dado um vetor de entrada de numeros inteiros, gerar um  vetor de saıda de números reais, calculando a raiz quadrada de todos os elementos do vetor de entrada que forem primos.


## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)
* [Análise | Atividade 1 | HelloThread.java](#análise--atividade-1--hellothreadjava)
* [Análise | Atividade 2 | OláThread.java](#análise--atividade-2--oláthreadjava)
* [Análise | Atividade 3 | TIncrementoBase.java](#análise--atividade-3--tincrementobasejava)
* [Análise | Atividade 4 | TIncrementoBase.java](#análise--atividade-4--tincrementobasejava)
* [Implementação | Atividade 5 | TIncrementoBase.java](#implementação--atividade-5--tincrementobasejava)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ javac 
```
```
$ java <classe principal(main)>
```

## Análise | Atividade 1 | HelloThread.java

**Objetivo** 
- Mostrar como criar um programa concorrente em Java. Em Java, a classe java.lang.Thread oferece metodos para criar threads,
iniciá-las, suspende-las e esperar pelo seu término.

**1 | Há mudanças na ordem de execução das threads? Por que isso ocorre?**
Sim, pois não existe nenhum mecanismo de controle em relação a execução das threads, dessa forma o término do programa não depende da finalização de execução entre as threads.

**2 | Após executar o programa várias vezes(linhas 43-46 descomentadas), qual a alteração na execução da aplicação pode ser observada e por que isso ocorre?**
A alteração se dá devido ao método join(), método responsável por aguardar a finalização de execução de todas as threads para liberar o próximo passo de execução, nesse caso, o término do programa.

## Análise | Atividade 2 | OláThread.java

**Objetivo** 
- Mostrar outra forma de criar threads em Java, usando herança.

## Análise | Atividade 3 | TIncrementoBase.java

**Objetivo** 
- Mostrar um exemplo de aplicac ̧ao com threads e memória compartilhada em Java.

**1 | Qual e a seção crítica do codigo? Qual saída é esperada para o programa (valor final de s)?**
- A seção crítica do código está localizada na classe S, pois é lá que possuímos a função principal de execução do programa, na qual o recurso compartilhado, no caso, a variável 'r' é incrementada. Também pode ser identificada uma segunda seção crítica, que deve ser protegida, que é onde acessamos novamente a variável 'r' através do método get().

- A saída esperada do programa, uma vez que possuímos duas threads, é de 200000.

**2 | Os valores impressos foram sempre o valor esperado? Por que?**
- Não. Na verdade, os valores impressos foram sempre menores que o valor esperado, indicando que houve perda na quantidade de incrementos da variável. Isso se deu devido à condição de corrida da aplicação, no qual a seção crítica que acessa o recurso compartilhado, estava desprotegida.

## Análise | Atividade 4 | TIncrementoBase.java

**Objetivo** 
- Mostrar como implementar exclusao mútua em Java.

**Roteiro**
1. Comente as linhas 17-23; e descomente as linhas 27-33 

**1 | Os valores impressos foram sempre o valor esperado? Por que?**
- Sim. Pois foram utilizados os mecanismos de sincronização, a assinatura syncronized, nos métodos caracterizados como seções críticas do programa.

## Implementação | Atividade 5 | TIncrementoBase.java

**Objetivo** 
- Implementar um programa concorrente em Java para encontrar a quantidade de números pares em um vetor de inteiros. Divida a tarefa entre as threads de forma balanceada e garanta ausência de condição de corrida.

**Roteiro**
1. Na thread main, crie um vetor de inteiros e o preencha com valores iniciais, em
seguida crie e dispare as threads, aguarde todas as threads terminarem e verifique
se o compito final está correto.
2. Teste seu programa variando o tamanho do vetor e o numero de threads.
