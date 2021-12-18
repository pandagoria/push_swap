NAME =	push_swap

SRCS =	push_swap.c r_rr_swap.c \
		radix_sort.c min_sort.c check_input.c	\
		push_ab.c utils.c \

OBJS =	$(SRCS:.c=.o)

SRC_D =	$(SRCS:.c=.d)

HEADERS = -I push_swap.h \
		-I lift/libft.h \

CC = gcc

FLAGS =	-MMD -Wall -Werror -Wextra -fsanitize=address

.c.o:
	$(CC) $(FLAGS) $(HEADERS) -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	make bonus -C ./libft/
	$(CC) $(FLAGS) -L libft $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(SRC_D)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re:	fclean all

.PHONY: all clean fclean re 

-include $(SRC_D)
