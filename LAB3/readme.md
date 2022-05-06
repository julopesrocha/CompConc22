# Laboratório 03 | Relatório
Análise de desempenho e cálculo da aceleração do programa de solução sequencial e uma solução concorrente para o problema de encontrar o menor e o maior valor de um vetor de numeros reais.


## Índice
* [Informações sobre o hardware](#informações-sobre-o-hardware)
* [Estratégia de Divisão das threads](#estrategia-de-divisao-das-threads)
* [Como rodar o programa](#como-rodar-o-programa)
* [Tempos de execução](#tempos-de-execução)
* [Cálculo da aceleração](#cálculo-da-aceleração)

## Informações sobre o hardware
- Distro: Ubuntu 20.04.4 LTS
- Nome do Modelo: Intel(R) Core(TM) i3-8145U CPU @ 2.10GHz
- Arquitetura: x86_64

## Estratégia de Divisão das threads
:exclamation: Optei por fazer uma divisão das threads em blocos, portanto, tendo 4 threads, dividimos o vetor em 4 grandes blocos, nos quais cada thread estará processando seu bloco respectivo.

## Como rodar o programa
:thinking: Compila e executa o programa através dos comandos:
```
$ gcc extremos-vetor.c -o extremos-vetor -Wall -lpthread 
```
```
$ ./extemos-vetor <dimensão do vetor> <número de threads>
```

## Tempos de execução
:warning: Tabela de testes gerada ao realizar testes para verificar o tempo de execução do programa com os inputs dados.

### Dimensão 10<sup>5</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | 0.001834s |                                                                                                                                                                                 
| **1 Thread** | 0.002511s |
| **2 Threads** | 0.001483s |
| **4 Threads** | 0.001620s |

### Dimensão 10<sup>7</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | 0.033610s |                                                                                                                                                                                 
| **1 Thread** | 0.029204s |
| **2 Threads** | 0.012552s |
| **4 Threads** | 0.009918s |

### Dimensão 10<sup>8</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | 0.324655s |                                                                                                                                                                                 
| **1 Thread** | 0.281228s |
| **2 Threads** | 0.189437s |
| **4 Threads** | 0.062707s |

## Cálculo da aceleração
:abacus: Para realizar o cálculo da aceleração e poder estimar o ganho de desempenho, usaremos a Lei de Amdahl. O ganho de velocidade da execução é dado por: 
T<sub>sequencial</sub> / t<sub>s</sub> + t<sub>c</sub>, onde
- T<sub>sequencial</sub>: Tempo total de execução do programa sequencial
- t<sub>s</sub>: Tempo da parte sequencial do programa
- t<sub>c</sub>: Tempo da parte concorrente do programa usando P processadores

### Dimensão 10<sup>5</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **1 Thread** | 0.730450s |
 | **2 Threads** | 1.28438s |
 | **4 Threads** | 0.844427s |
 
### Dimensão 10<sup>7</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **1 Thread** | 1.020977s |
 | **2 Threads** | 2.677728s |
 | **4 Threads** | 4.417935s |
 
 ### Dimensão 10<sup>8</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **1 Thread** | 1.154419s |
 | **2 Threads** | 2.188666s |
 | **4 Threads** | 3.726620s |
