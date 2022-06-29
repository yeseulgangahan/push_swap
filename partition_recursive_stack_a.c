# include "push_swap.h"

static void	base_case_solve(t_pushswap *pushswap, size_t len)
{
	if (len == 2 && stack_is_ascending_order(pushswap->stack_a, len) == false)
		sa(pushswap->stack_a);
}

static bool	is_ra_needed(t_pushswap *pushswap, size_t pivot2, size_t range)
{
	t_data	data;

	while (range)
	{
		stack_next(pushswap->stack_a, &data);
		if (pushswap->ordered_arr[pivot2] > data)
			break;
		range--;
	}
	if (range == 0)
		return (false);
	else
		return (true);
}

static size_t	partition(t_pushswap *pushswap, size_t pivot1, size_t pivot2, size_t len)
{
	t_data	data;
	size_t	ra_cnt;

	ra_cnt = 0;
	while (len)
	{
		stack_peek(pushswap->stack_a, &data);
		if (pushswap->ordered_arr[pivot2] <= data)
		{
			if (is_ra_needed(pushswap, pivot2, len - 1) == false)
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

static void	move_range_to_top(t_pushswap *pushswap, size_t range_stack_a, size_t range_stack_b)
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

void	partition_recursive_stack_a(t_pushswap *pushswap, size_t left, size_t right)
{
	size_t	pivot1;
	size_t	pivot2;
	size_t	len;
	size_t	ra_cnt;

	len = right - left + 1;
	if (len <= 2)
		base_case_solve(pushswap, len);
	else
	{
		pivot1 = left + (len / 3);
		pivot2 = left + (len / 3 * 2);
		ra_cnt = partition(pushswap, pivot1, pivot2, len);
		move_range_to_top(pushswap, ra_cnt, pivot2 - pivot1);
		partition_recursive_stack_a(pushswap, pivot2, right);
		partition_recursive_stack_b(pushswap, pivot1, pivot2 - 1);
		partition_recursive_stack_b(pushswap, left, pivot1 - 1);
	}
}
