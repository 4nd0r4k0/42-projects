CC := cc

CFLAGS := -Wall -Wextra -Werror

PS_SRCS := 	ft_min_max.c ft_operations2.c ft_operations.c ft_solve_utils.c \
			ft_sort_utils.c ft_stack_utils.c ft_utils1.c ft_utils2.c ft_utils3.c push_swap.c 

PS_OBJS := $(PS_SRCS:.c=.o)

BONUS_SRCS := 	checker.c ft_checker_cmd_check.c ft_checker_operations.c ft_checker_split_utils.c \
				ft_checker_utils3.c ft_checker_utils.c get_next_line.c get_next_line_utils.c

BONUS_SRCS_PREFIX := $(addprefix bonus/, $(BONUS_SRCS))
BONUS_OBJS_PREFIX := $(BONUS_SRCS_PREFIX:.c=.o)

NAME := push_swap

CHECKER := checker

all: $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BONUS_OBJS_PREFIX) 
	$(CC) $(CFLAGS) $(BONUS_OBJS_PREFIX) -o $(CHECKER)

$(NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(NAME)

$(BONUS_OBJS_PREFIX): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PS_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $(PS_SRCS) 

fclean: clean
	rm -f $(NAME) $(CHECKER)

clean:
	rm -f $(PS_OBJS) $(BONUS_OBJS_PREFIX)

re: fclean all

.PHONY: all clean fclean re bonus
