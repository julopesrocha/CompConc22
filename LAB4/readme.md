# Laboratório 04 | Relatório
Análise de desempenho e cálculo da aceleração do programa de solução sequencial e uma solução concorrente para o problema de: dado um vetor de entrada de numeros inteiros, gerar um  vetor de saıda de números reais, calculando a raiz quadrada de todos os elementos do vetor de entrada que forem primos.


## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Como rodar o programa](#como-rodar-o-programa)
* [Tempos de execução](#tempos-de-execução)
* [Cálculo da aceleração](#cálculo-da-aceleração)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ gcc quadrado.c -o quadrado -Wall -lpthread lm
```
```
$ ./quadrado <dimensão do vetor> <número de threads>
```

## Tempos de execução
:warning: Tabela de testes gerada ao realizar testes para verificar o tempo de execução do programa com os inputs dados.

### Dimensão 10<sup>5</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** |  0.014490s |                                                                                                                                                                                 
| **1 Thread** | 0.013411s |
| **2 Threads** | 0.012902s |
| **4 Threads** | 0.011788s |

### Dimensão 10<sup>7</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | 6.841884s |                                                                                                                                                                                 
| **1 Thread** | 6.942035s |
| **2 Threads** | 3.698142s |
| **4 Threads** | 2.133143s |

### Dimensão 10<sup>8</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | s |                                                                                                                                                                                 
| **1 Thread** | s |
| **2 Threads** | s |
| **4 Threads** | s |

## Cálculo da aceleração
:abacus: Para realizar o cálculo da aceleração e poder estimar o ganho de desempenho, usaremos a Lei de Amdahl. O ganho de velocidade da execução é dado por: 
T<sub>sequencial</sub> / t<sub>s</sub> + t<sub>c</sub>, onde
- T<sub>sequencial</sub>: Tempo total de execução do programa sequencial
- t<sub>s</sub>: Tempo da parte sequencial do programa
- t<sub>c</sub>: Tempo da parte concorrente do programa usando P processadores

### Dimensão 10<sup>5</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **1 Thread** | 1.080469s |
 | **2 Threads** | 1.327405s |
 | **4 Threads** | 1.133558s |
 
### Dimensão 10<sup>7</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **1 Thread** | 0.985573s |
 | **2 Threads** | 1.850627s |
 | **4 Threads** | 3.203962s |
 
 ### Dimensão 10<sup>8</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **1 Thread** | s |
 | **2 Threads** | s |
 | **4 Threads** | s |
