NAME	= myftp

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
		./src/fct.c \
		./src/connexion.c \
		./src/switch_cmd.c \
		./src/cmd/HELP.c \
		./src/cmd/USER.c \
		./src/cmd/PASS.c \
		./src/cmd/NOOP.c \
		./src/cmd/CDUP.c \
		./src/cmd/PWD.c \
		./src/cmd/DELE.c \
		./src/cmd/CWD.c \
		./src/cmd/LIST.c \
		./src/loop.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 $(RM) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
