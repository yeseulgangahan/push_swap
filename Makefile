# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:36:36 by yehan             #+#    #+#              #
#    Updated: 2022/06/30 13:36:38 by yehan            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
RM			:= rm -f

LIBFLAGS	:= -L./libft -lft

FTDIR		:= ./libft

SRCS	:= \
				push_swap_stack.c \
				push_swap_stack2.c \
				push_swap_operations.c \
				push_swap_operations2.c \
				main.c \
				get_valid_list.c \
				get_ordered_arr.c \
				sort_small_problem.c \
				partition_recur_stack_a.c \
				partition_recur_stack_b.c \
				sort_last_3_data.c \
				sort_last_3_data2.c

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
