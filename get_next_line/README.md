*This project has been created as part of the 42 curriculum by audgiova.*

## Descrição

O **get_next_line** é um projeto do currículo da 42 cujo objetivo é desenvolver uma função em C capaz de ler e retornar uma linha por vez de um descritor de ficheiro (*file descriptor*). Através deste projeto, aprofundamos o conceito de variáveis estáticas, gestão dinâmica de memória com alocações precisas e manipulação de fluxos de entrada e ficheiros no ambiente Unix.

Após a validação, esta função pode ser integrada à nossa **libft**, tornando-se uma ferramenta fundamental para projetos futuros.

### Objetivo do Projeto

* 🎯 Desenvolver a função `get_next_line` que lê texto linha por linha até o final do ficheiro (EOF).
* 🧠 Compreender e dominar a persistência de dados através de variáveis estáticas.
* 🛡️ Garantir uma gestão rigorosa de memória via `malloc` e `free`, assegurando zero fugas de memória (*memory leaks*).
* ⚙️ Lidar com tamanhos de buffer arbitrários definidos via flag de compilação `-D BUFFER_SIZE=n`.

---

## Estrutura e Comportamento

A função principal possui o seguinte protótipo:

```c
char *get_next_line(int fd);

```

### Características de Retorno

* 📄 **Linha lida com sucesso:** Retorna a string referente à linha lida, incluindo o caractere delimitador `\n` ao final (caso o ficheiro contenha quebra de linha).


* 🔚 **Fim do ficheiro:** Retorna a última linha sem `\n` (caso o ficheiro termine sem quebra de linha) ou `NULL` quando a leitura for concluída.


* ⚠️ **Erro ou argumentos inválidos:** Retorna `NULL` se o descritor for inválido (`fd < 0`), se ocorrer erro de leitura com `read()`, ou se `BUFFER_SIZE <= 0`.


---

## Justificação do Algoritmo e Estrutura de Dados

### 1. Estrutura de Dados: Variável Estática

Como a leitura é feita em blocos de tamanho fixo (`BUFFER_SIZE`), o buffer de leitura pode conter mais dados do que o necessário para uma única linha. Para reter esses dados excedentes entre chamadas sucessivas de `get_next_line()`, utilizamos:

* 💾 **`static char *storage`:** Mantém os bytes lidos que ultrapassaram o caractere `\n` da chamada anterior, garantindo que nenhum caractere seja perdido.


### 2. Algoritmo de Fluxo Principal

O fluxo de execução divide-se em quatro fases essenciais:

1. 🛡️ **Validação Prévia:** Verifica se `fd` é válido, se `BUFFER_SIZE > 0` e se a alocação do buffer temporário ocorre com sucesso.


2. 📥 **Leitura e Acumulação:** Realiza chamadas consecutivas à função `read()`, concatenando o conteúdo lido na variável estática `storage` até encontrar o delimitador `\n` ou atingir o fim do ficheiro.


3. ✂️ **Extração da Linha:** Percorre o `storage` acumulado, calcula o tamanho exato até o `\n` (inclusive) ou final da string, aloca a memória necessária e copia a linha a ser retornada.


4. 🧹 **Atualização e Limpeza:** Atualiza a variável `storage`, preservando apenas os caracteres restantes após a quebra de linha, e liberta a memória antiga da linha anterior para prevenir vazamentos.


---

## Instruções de Compilação e Uso

### Pré-requisitos

* Compilador `cc` ou `gcc`

* Ferramenta `valgrind` (para testes de memória)
* Ambiente baseado em Linux/Unix

### Compilação

Para compilar o projeto junto ao seu código de teste (`main.c`):

**Com definição padrão de buffer (definida no header):**

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl

```

**Com definição de buffer customizado:**

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

```

### Exemplo de Uso

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("exemplo.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

```

---

## Recursos

### Referências Utilizadas

* [Man7.org - Manual da chamada de sistema read(2)](https://man7.org/linux/man-pages/man2/read.2.html) - Para compreender o retorno, controle de bytes lidos e gestão de buffer.


* [Man7.org - Manual de malloc(3) & free(3)](https://man7.org/linux/man-pages/man3/malloc.3.html) - Documentação sobre gestão e libertação de memória na heap.


* [GeeksforGeeks - Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Conceitos e tempo de vida de variáveis estáticas em C.


* [Valgrind User Manual](https://valgrind.org/docs/manual/index.html) - Diagnóstico e prevenção de fugas de memória e acessos ilegais.

### Uso de IA

A IA foi utilizada neste projeto para:

* 🔍 **Depuração e Análise de Memória:** Interpretação dos relatórios do Valgrind para identificar e corrigir pontos de *memory leaks* e acessos inválidos.

* 📝 **Montagem do README:** Estruturação da documentação técnica e detalhamento do algoritmo em conformidade com as diretrizes do subject.
