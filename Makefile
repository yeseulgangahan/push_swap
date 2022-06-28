NAME		:= push_swap

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
RM			:= rm -f

LIBFLAGS	:= -L./libft -lft

FTDIR		:= ./libft

SRCS	:= \
				push_swap_stack.c \
				push_swap_operations.c \
				main.c \
				get_valid_list.c \
				get_ordered_arr.c \
				partition_recursive.c \
				partition_recursive2.c \
				sort_last_n.c \
				test_func.c

# SRCS_BONUS	:= \
				main_bonus.c \

OBJS		= $(SRCS:.c=.o)
# OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJS	= $(OBJS_BONUS)
endif

.PHONY:		all clean fclean rclean re bonus

all:		$(NAME)

clean:
			make clean --directory=$(FTDIR)
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			make fclean --directory=$(FTDIR)
			$(RM) $(NAME)

rclean:		fclean
			$(RM) infile outfile

re:			fclean all

bonus:
			make BONUS=true

$(NAME):	$(OBJS)
			make --directory=$(FTDIR)
			$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@
