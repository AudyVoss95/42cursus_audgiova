*Este projeto foi criado como parte do currículo 42 por audgiova.*

## Descrição

O **ft_printf** é um projeto do currículo da 42 cujo objetivo é recriar a famosa função `printf` da biblioteca padrão do C (`libc`). Através dele, aprofundamos o entendimento sobre funções variádicas — funções que aceitam um número variável de argumentos — e consolidamos a estruturação de códigos modulares e reutilizáveis.

Após a validação, esta biblioteca pode ser integrada à nossa **libft**, permitindo o seu uso em projetos futuros dentro da escola.

### Objetivo do Projeto

* Reimplementar o comportamento essencial da função `printf` original


* Dominar a manipulação de argumentos variáveis em C através da macro `stdarg.h`

* Garantir a contagem exata de bytes impressos, simulando fielmente o valor de retorno original


* Praticar a criação de bibliotecas estáticas utilizando a ferramenta `ar`


---

## Descrição Detalhada da Biblioteca

A biblioteca é compilada como `libftprintf.a` e gerencia as seguintes conversões obrigatórias:

### Funções e Conversões Suportadas

O núcleo do projeto consiste em ler a string de formato caractere por caractere. Quando um `%` é encontrado, o caractere seguinte define a conversão a ser tratada:

* `%c` - Escreve um único caractere


* `%s` - Escreve uma string (cadeia de caracteres comuns)


* `%p` - Escreve o endereço de um ponteiro `void` em formato hexadecimal


* `%d` - Escreve um número decimal em base 10 com sinal


* `%i` - Escreve um inteiro em base 10


* `%u` - Escreve um número decimal sem sinal (unsigned)


* `%x` - Escreve um número em formato hexadecimal (base 16) com letras minúsculas


* `%X` - Escreve um número em formato hexadecimal (base 16) com letras maiúsculas


* `%%` - Escreve o próprio caractere de percentagem



---

## Justificação do Algoritmo e Estrutura de Dados

### 1. Estrutura de Dados: Funções Variádicas

Como o `ft_printf` precisa receber um número imprevisível de parâmetros, a estrutura de controle utilizada baseia-se nas macros de `<stdarg.h>`:

* `va_list`: Uma lista que armazena os argumentos variáveis.


* `va_start`: Inicializa a lista ligando-a ao último parâmetro fixo (`format`).


* `va_arg`: Resgata o próximo argumento da lista, exigindo a especificação do tipo de dado correto.


* `va_end`: Limpa a memória associada à lista de argumentos.



### 2. Algoritmo de Fluxo Principal

O algoritmo adota uma abordagem linear e condicional:

1. Um loop percorre a string `format` até encontrar o caractere nulo `\0`.


2. **Se** o caractere atual for diferente de `%`, ele é impresso diretamente usando `ft_putchar` e o contador de bytes é incrementado.
3. **Se** o caractere for `%`, o índice avança para avaliar o especificador. A função `ft_check_conversion` intercepta o caractere correspondente e despacha o argumento da `va_list` para a função auxiliar adequada (ex: `ft_puthexa`, `ft_putnbr`).


4. Cada função auxiliar é responsável por realizar a escrita através da chamada de sistema `write` e retornar o número exato de bytes exibidos na tela, mantendo o acumulador global atualizado.



---

## Instruções de Compilação e Uso

### Pré-requisitos

* Compilador `cc` ou `gcc`

* Ferramenta `Make`

* Ambiente baseado em Linux/Unix



### Compilação

Para compilar a biblioteca e gerar o arquivo estático `libftprintf.a` na raiz do repositório:

```bash
make

```

### Regras do Makefile

* `make all` - Compila os arquivos fonte da `libft` e do `ft_printf`, gerando a biblioteca.


* `make clean` - Remove os arquivos objeto (`*.o`) criados durante a compilação.


* `make fclean` - Remove os arquivos objeto e o arquivo final `libftprintf.a`.


* `make re` - Executa o `fclean` e o `all` em sequência para uma recompilação limpa.



### Uso da Biblioteca

Para integrar o `ft_printf` no teu projeto pessoal:

1. Inclui o arquivo de cabeçalho no teu código fonte:

```c
#include "ft_printf.h"

```

2. Compila o teu programa ligando o arquivo estático da biblioteca e os caminhos de inclusão correspondentes:



```bash
cc main.c libftprintf.a -I./include -I./libft -o meu_programa

```

---

## Recursos

### Referências Utilizadas

* [Man7.org - Manual Oficial do Printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Para entender o comportamento padrão das conversões e retornos.


* [CPlusPlus - stdarg.h reference](https://cplusplus.com/reference/cstdarg/) - Documentação sobre o gerenciamento de argumentos variáveis.


* [Man7.org - Manual da chamada de sistema write](https://man7.org/linux/man-pages/man2/write.2.html) - Entendimento técnico do output de dados no file descriptor.


* [GeeksforGeeks - Variadic Functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/) - Conceitos e exemplos práticos de funções variádicas.

### Uso de IA

A IA foi utilizada neste projeto para:
* **Pesquisa**: Levantamento de informações sobre as funções da libc baseado em documentações e referências
* **Montagem do README**: Estruturação e organização da documentação do projeto, incluindo descrições detalhadas das funções, exemplos de uso e instruções de compilação.