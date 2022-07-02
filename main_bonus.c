/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:56:21 by yehan             #+#    #+#             */
/*   Updated: 2022/07/03 07:11:34 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/get_next_line.h"
#include "push_swap_bonus.h"

static void	apply_operation(t_pushswap *pushswap, char *input)
{
	if (!ft_strncmp(input, "sa\n", 4))
		sa_silent(pushswap->stack_a);
	else if (!ft_strncmp(input, "sb\n", 4))
		sb_silent(pushswap->stack_b);
	else if (!ft_strncmp(input, "ss\n", 4))
		ss_silent(pushswap->stack_a, pushswap->stack_b);
	else if (!ft_strncmp(input, "pa\n", 4))
		pa_silent(pushswap->stack_b, pushswap->stack_a);
	else if (!ft_strncmp(input, "pb\n", 4))
		pb_silent(pushswap->stack_a, pushswap->stack_b);
	else if (!ft_strncmp(input, "ra\n", 4))
		ra_silent(pushswap->stack_a);
	else if (!ft_strncmp(input, "rb\n", 4))
		rb_silent(pushswap->stack_b);
	else if (!ft_strncmp(input, "rr\n", 4))
		rr_silent(pushswap->stack_a, pushswap->stack_b);
	else if (!ft_strncmp(input, "rra\n", 5))
		rra_silent(pushswap->stack_a);
	else if (!ft_strncmp(input, "rrb\n", 5))
		rrb_silent(pushswap->stack_b);
	else if (!ft_strncmp(input, "rrr\n", 5))
		rrr_silent(pushswap->stack_a, pushswap->stack_b);
	else
		ft_pstr_exit("Error");
}

static void	get_next_operations(t_pushswap *pushswap)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			return ;
		apply_operation(pushswap, input);
		free(input);
	}
}

static void	pushswap_init(t_pushswap *pushswap, char **args)
{
	pushswap->stack_a = ft_calloc(1, sizeof(t_stack));
	get_valid_stack_a_bonus(pushswap->stack_a, args);
	pushswap->stack_b = ft_calloc(1, sizeof(t_stack));
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;
	size_t		len;

	if (argc > 1)
	{
		pushswap_init(&pushswap, argv);
		len = stack_count(pushswap.stack_a);
		get_next_operations(&pushswap);
		if (stack_count(pushswap.stack_a) == len
			&& stack_is_ascending_order(pushswap.stack_a, len) == TRUE)
			ft_putstr_fd("OK", 1);
		else
			ft_putstr_fd("KO", 1);
	}
	exit(0);
}
