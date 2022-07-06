/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:34:01 by yehan             #+#    #+#             */
/*   Updated: 2022/07/06 12:18:38 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushswap_init(t_pushswap *pushswap, char **args)
{
	pushswap->stack_a = ft_calloc(1, sizeof(t_stack));
	get_valid_stack_a(pushswap->stack_a, args);
	pushswap->stack_b = ft_calloc(1, sizeof(t_stack));
	pushswap->ordered_arr = get_ordered_arr(pushswap->stack_a);
	pushswap->is_initial = true;
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;
	size_t		len;

	if (argc > 1)
	{
		pushswap_init(&pushswap, argv);
		len = stack_count(pushswap.stack_a);
		if (stack_is_ascending_order(pushswap.stack_a, len) == false)
		{
			if (len <= 5)
				sort_small_problem(&pushswap, len);
			else
				partition_recur_stack_a(&pushswap, 0, len - 1);
		}
	}
	exit(0);
}
