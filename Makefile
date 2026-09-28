# Variables
NAME        = shell
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

# Fichier source
SRCS        = shell.c

# Fichiers objets générés
OBJS        = $(SRCS:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
