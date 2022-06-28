# include "push_swap.h"

/* partition_recursive_stack_a */

static void	base_case_solve(t_pushswap *pushswap, size_t len)
{
	if (stack_is_ascending_order(pushswap->stack_a, len) == true)
		return ;
	else if (len == 2)
		sort_last_two(pushswap->stack_a, A);
	// else if (len == 3)
	// 	sort_last_three(pushswap->stack_a, pushswap->stack_b);
	// else if (len == 4)
	// 	sort_last_four(pushswap->stack_a, pushswap->stack_b);
	// else if (len == 5)
	// 	sort_last_five(pushswap->stack_a, pushswap->stack_b);
}

static void	chuck_move_to_top(t_stack *pstack, size_t left, size_t right)
{
	size_t	chuck_len_stack_b;

	chuck_len_stack_b = right - left + 1;
	while (chuck_len_stack_b != 0)
	{
		rrb(pstack);
		chuck_len_stack_b--;
	}
}

void	partition_recursive_stack_a(t_pushswap *pushswap, size_t left, size_t right)
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
			ra(pushswap->stack_a);
		else if (pushswap->ordered_arr[pivot1] <= stack_peek(pushswap->stack_a))
			pb(pushswap->stack_a, pushswap->stack_b);
		else
		{
			pb(pushswap->stack_a, pushswap->stack_b);
			rb(pushswap->stack_b);
		}
	}
	chuck_move_to_top(pushswap->stack_b, pivot1, pivot2 - 1);
	partition_recursive_stack_a(pushswap, pivot2, right);
	partition_recursive_stack_b(pushswap, pivot1, pivot2 - 1);
	partition_recursive_stack_b(pushswap, left, pivot1 - 1);
}
