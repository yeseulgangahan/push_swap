# include <stdio.h> /* 임시. ft_printf 넣어야 함 */
# include "push_swap_operations.h"
// # include "./libft/include/libft.h"

void	sa(t_stack *pstack)
{
	stack_swap(pstack);
	printf("sa\n");
}

void	sb(t_stack *pstack)
{
	stack_swap(pstack);
	printf("sb\n");
}

void	pa(t_stack *pstack1, t_stack *pstack2)
{
	stack_push(pstack1, pstack2);
	printf("pa\n");
}

void	pb(t_stack *pstack1, t_stack *pstack2)
{
	stack_push(pstack1, pstack2);
	printf("pb\n");
}

void	ra(t_stack *pstack)
{
	stack_rotate(pstack, 1);
	printf("ra\n");
}
void	rb(t_stack *pstack)
{
	stack_rotate(pstack, 1);
	printf("rb\n");
}

void	rr(t_stack *pstack1, t_stack *pstack2)
{
	ra(pstack1);
	rb(pstack2);
	printf("rr\n");
}

void	rra(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	printf("rra\n");
}

void	rrb(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	printf("rrb\n");
}
void	rrr(t_stack *pstack1, t_stack *pstack2)
{
	rra(pstack1);
	rrb(pstack2);
	printf("rrr\n");
}
