# include "pushswap_operations.h"
# include "libft.h"

void	sa(stack *pstack)
{
	stack_swap(pstack);
	ft_printf("sa\n");
}

void	sb(stack *pstack)
{
	stack_swap(pstack);
	ft_printf("sb\n");
}

void	pa(stack *pstack1, stack *pstack2)
{
	stack_push(pstack1, pstack2);
	ft_printf("pa\n");
}

void	pb(stack *pstack1, stack *pstack2)
{
	stack_push(pstack1, pstack2);
	ft_printf("pb\n");
}

void	ra(stack *pstack)
{
	stack_rotate(pstack, 1);
	ft_printf("ra\n");
}
void	rb(stack *pstack)
{
	stack_rotate(pstack, 1);
	ft_printf("rb\n");
}

void	rr(stack *pstack1, stack *pstack2)
{
	ra(pstack1);
	rb(pstack2);
	ft_printf("rr\n");
}

void	rra(stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	ft_printf("rra\n");
}

void	rrb(stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	ft_printf("rrb\n");
}
void	rrr(stack *pstack1, stack *pstack2)
{
	rra(pstack1);
	rrb(pstack2);
	ft_printf("rrr\n");
}