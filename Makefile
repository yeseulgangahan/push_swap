# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:36:36 by yehan             #+#    #+#              #
#    Updated: 2022/06/30 19:28:59 by yehan            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
NAME_BONUS	:= checker

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
RM			:= rm -f

LIBFLAGS	:= -L./libft -lft

FTDIR		:= ./libft

SRCS	:= \
				push_swap_operations.c \
				push_swap_operations2.c \
				push_swap_operations3.c \
				main.c \
				get_valid_stack_a.c \
				get_ordered_arr.c \
				sort_small_problem.c \
				partition_recur_stack_a.c \
				partition_recur_stack_b.c \
				sort_last_3_data.c \
				sort_last_3_data2.c

SRCS_BONUS	:= \
				push_swap_operations_bonus.c \
				push_swap_operations2_bonus.c \
				push_swap_operations3_bonus.c \
				main_bonus.c \
				get_valid_stack_a_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

.PHONY:			all clean fclean rclean re bonus

all:			$(NAME)

bonus:			$(NAME_BONUS)

clean:
				make clean --directory=$(FTDIR)
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				make fclean --directory=$(FTDIR)
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

$(NAME):		$(OBJS)
				make --directory=$(FTDIR)
				$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@

$(NAME_BONUS):	$(OBJS_BONUS)
				make --directory=$(FTDIR)
				$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@
