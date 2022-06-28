# include "push_swap.h"

/* partition_recursive_stack_b */

static void	base_case_solve(t_pushswap *pushswap, size_t len)
{
	size_t	i;

	if (stack_is_descending_order(pushswap->stack_b, len) == false)
	{
		if (len == 2)
			sort_last_two(pushswap->stack_b, B);
		// else if (len == 3)
		// 	sort_last_three(pushswap->stack_a, pushswap->stack_b);
		// else if (len == 4)
		// 	sort_last_four(pushswap->stack_a, pushswap->stack_b);
		// else if (len == 5)
		// 	sort_last_five(pushswap->stack_a, pushswap->stack_b);
	}
	i = 0;
	while (i < len)
	{
		pa(pushswap->stack_b, pushswap->stack_a);
		i++;
	}
}

static void	chuck_move_to_top(t_pushswap *pushswap, size_t left, size_t pivot1, size_t pivot2)
{
	size_t	chuck_len_stack_a;
	size_t	chuck_len_stack_b;

	chuck_len_stack_a = pivot2 - pivot1;
	chuck_len_stack_b = pivot1 - left;
	while (chuck_len_stack_b != 0)
	{
		rrr(pushswap->stack_a, pushswap->stack_b);
		chuck_len_stack_a--;
		chuck_len_stack_b--;
	}
	if (chuck_len_stack_a != 0)
		rra(pushswap->stack_a);
}

void	partition_recursive_stack_b(t_pushswap *pushswap, size_t left, size_t right)
{
	size_t	pivot1;
	size_t	pivot2;
	size_t	len;

	len = right - left + 1;
	if (len <= 2)
	{
		base_case_solve(pushswap, len);
		return ;
	}
	pivot1 = left + (len / 3);
	pivot2 = left + (len / 3 * 2);
	while (len--)
	{
		if (pushswap->ordered_arr[pivot2] <= stack_peek(pushswap->stack_a))
			pa(pushswap->stack_b, pushswap->stack_a);
		else if (pushswap->ordered_arr[pivot1] <= stack_peek(pushswap->stack_a))
		{
			pa(pushswap->stack_b, pushswap->stack_a);
			ra(pushswap->stack_a);
		}
		else
			rb(pushswap->stack_b);
	}
	partition_recursive_stack_a(pushswap, pivot2, right);
	chuck_move_to_top(pushswap, left, pivot1, pivot2);
	partition_recursive_stack_a(pushswap, pivot1, pivot2 - 1);
	partition_recursive_stack_b(pushswap, left, pivot1 - 1);
}
