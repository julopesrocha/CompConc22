# Laboratório 03 | Relatório
Análise de desempenho e cálculo da aceleração do programa concorrente que encontra a quantidade de valores de um vetor de numeros reais que estao dentro de uma 
faixa de valores dada.

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
$ gcc extremos-vetor.c -o extremos-vetor -Wall -lpthread 
```
```
$ ./extemos-vetor <dimensão do vetor> <número de threads>
```

## Tempos de execução
:warning: Ao realizar testes para verificar o tempo de execução do programa com os inputs dados, percebi que o tempo sofre pequenas alterações de acordo com o intervalo dado.
Por conta disso, todos os testes foram realizados usando como base o intervalo 100 < x<sub>i</sub> < 500.

### Dimensão 10<sup>5</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | ?s |                                                                                                                                                                                 
| **2 Threads** | ?s |
| **4 Threads** | ?s |

### Dimensão 10<sup>7</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | ?s |                                                                                                                                                                                 
| **2 Threads** | ?s |
| **4 Threads** | ?s |

### Dimensão 10<sup>8</sup>
| Solução | Tempo de execução |
| --- | --- |
| **Sequencial** | ?s |                                                                                                                                                                                 
| **2 Threads** | ?s |
| **4 Threads** | ?s |

## Cálculo da aceleração
:abacus: Para realizar o cálculo da aceleração e poder estimar o ganho de desempenho, usaremos a Lei de Amdahl. O ganho de velocidade da execução é dado por: 
T<sub>sequencial</sub> / t<sub>s</sub> + t<sub>s</sub>, onde
- T<sub>sequencial</sub>: Tempo total de execução do programa sequencial
- t<sub>s</sub>: Tempo da parte sequencial do programa
- t<sub>s</sub>: Tempo da parte concorrente do programa usando P processadores

### Dimensão 10<sup>5</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **2 Threads** | ?s |
 | **4 Threads** | ?s |
 
### Dimensão 10<sup>7</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **2 Threads** | ?s |
 | **4 Threads** | ?s |
 
 ### Dimensão 10<sup>8</sup>
 | Threads | Aceleração |
 | --- | --- |
 | **2 Threads** | ?s |
 | **4 Threads** | ?s |