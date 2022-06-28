# include <unistd.h>
# include "./libft/include/libft.h"
# include "push_swap_operations.h"

void	sa(t_stack *pstack)
{
	stack_swap(pstack);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack *pstack)
{
	stack_swap(pstack);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	pa(t_stack *pstack1, t_stack *pstack2)
{
	stack_push(pstack1, pstack2);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack *pstack1, t_stack *pstack2)
{
	stack_push(pstack1, pstack2);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

void	ra(t_stack *pstack)
{
	stack_rotate(pstack, 1);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack *pstack)
{
	stack_rotate(pstack, 1);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack *pstack1, t_stack *pstack2)
{
	ra(pstack1);
	rb(pstack2);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	rra(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack *pstack1, t_stack *pstack2)
{
	rra(pstack1);
	rrb(pstack2);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
