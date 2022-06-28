# include <stdio.h>
# include "push_swap.h"

void	test_print_arr(t_data *arr)
{
	int i;
	i = 0;
	while (arr[i])
	{
		printf("%d ", arr[i]);
		i++;
	}
}

void	test_print_stack_a(t_stack *pstack)
{
	size_t	stack_len = stack_count(pstack);

	size_t	i = 0;
	t_node *cur;

	cur = pstack->tail->next;
	while (i < stack_len)
	{
		printf("%d ", cur->data);
		cur = cur->next;
		i++;
	}
}