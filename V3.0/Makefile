NAME = get_next_line

SRC =	get_next_line_utils.c	\
		get_next_line.c			\


#SRC_BONUS =
			

OBJS = $(SRC:%.c=%.o)

#OBJS_BONUS = $(OBJS) $(SRC_BONUS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

comp: $(NAME) $(SRC)
	$(CC) $(CFLAGS) $(SRC) main.c
	make clean
	./a.out | cat -e

debug:  $(NAME) $(SRC)
	$(CC) -g $(SRC) main.c
	make clean
	lldb a.out
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# bonus: $(NAME) $(OBJS_BONUS)
# 	ar -rc $(NAME) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean debug comp re