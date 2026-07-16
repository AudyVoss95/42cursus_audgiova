CC = cc
CFLAGS = -Wall -Wextra -Werror

# Indica ao compilador onde procurar os arquivos .h (cabeçalhos)
INCLUDES = -I include -I libft

NAME = libftprintf.a
AR = ar rcs

# 1. Adicionamos o prefixo "src/" em todas as fontes
SRCS = src/ft_printf.c \
       src/ft_putchar.c \
       src/ft_putstr.c \
       src/ft_puthexa.c \
       src/ft_putnbr.c \
       src/ft_putptr.c

# O make vai gerar os .o dentro da própria pasta "src/"
OBJS = $(SRCS:.c=.o)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): libft $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

libft:
	@make -C $(LIBFTDIR)

# 2. Regra de compilação genérica atualizada com as flags de INCLUDE
src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft