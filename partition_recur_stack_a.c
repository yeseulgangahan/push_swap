/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_recur_stack_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:43:49 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 10:46:01 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_ra_data_only(t_pushswap *pushswap, size_t pivot2, size_t range)
{
	t_data	data;

	while (range)
	{
		stack_next(pushswap->stack_a, &data);
		if (pushswap->ordered_arr[pivot2] > data)
			break ;
		range--;
	}
	if (range == 0)
		return (true);
	else
		return (false);
}

static void	partition_first(t_pushswap *pushswap,
	size_t pivot1, size_t pivot2, size_t len)
{
	t_data	data;

	while (len)
	{
		stack_peek(pushswap->stack_a, &data);
		if (pushswap->ordered_arr[pivot2] <= data)
		{
			if (is_ra_data_only(pushswap, pivot2, len - 1) == true)
				break ;
			ra(pushswap->stack_a);
		}
		else if (pushswap->ordered_arr[pivot1] <= data)
			pb(pushswap->stack_a, pushswap->stack_b);
		else
		{
			pb(pushswap->stack_a, pushswap->stack_b);
			rb(pushswap->stack_b);
		}
		len--;
	}
	pushswap->is_initial = false;
}

static size_t	partition_next(t_pushswap *pushswap,
	size_t pivot1, size_t pivot2, size_t len)
{
	t_data	data;
	size_t	ra_cnt;

	ra_cnt = 0;
	while (len)
	{
		stack_peek(pushswap->stack_a, &data);
		if (pushswap->ordered_arr[pivot2] <= data)
		{
			if (is_ra_data_only(pushswap, pivot2, len - 1) == true)
				break ;
			ra(pushswap->stack_a);
			ra_cnt++;
		}
		else if (pushswap->ordered_arr[pivot1] <= data)
		{
			pb(pushswap->stack_a, pushswap->stack_b);
			rb(pushswap->stack_b);
		}
		else
			pb(pushswap->stack_a, pushswap->stack_b);
		len--;
	}
	return (ra_cnt);
}

static void	move_range_to_top(t_pushswap *pushswap,
	size_t range_stack_a, size_t range_stack_b)
{
	while (range_stack_a != 0 && range_stack_b != 0)
	{
		rrr(pushswap->stack_a, pushswap->stack_b);
		range_stack_a--;
		range_stack_b--;
	}
	while (range_stack_a != 0)
	{
		rra(pushswap->stack_a);
		range_stack_a--;
	}
	while (range_stack_b != 0)
	{
		rrb(pushswap->stack_b);
		range_stack_b--;
	}
}

void	partition_recur_stack_a(t_pushswap *pushswap, size_t left, size_t right)
{
	size_t	pivot1;
	size_t	pivot2;
	size_t	len;
	size_t	ra_cnt;

	len = right - left + 1;
	if (stack_is_ascending_order(pushswap->stack_a, len) == true)
		return ;
	else if (len == 2)
		sa(pushswap->stack_a);
	else
	{
		pivot1 = left + (len / 3);
		pivot2 = left + (len / 3 * 2);
		if (pushswap->is_initial == true)
			partition_first(pushswap, pivot1, pivot2, len);
		else
		{
			ra_cnt = partition_next(pushswap, pivot1, pivot2, len);
			move_range_to_top(pushswap, ra_cnt, pivot2 - pivot1);
		}
		partition_recur_stack_a(pushswap, pivot2, right);
		partition_recur_stack_b(pushswap, pivot1, pivot2 - 1);
		partition_recur_stack_b(pushswap, left, pivot1 - 1);
	}
}
