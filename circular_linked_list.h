#ifndef CIRCULAR_LINKED_LIST_H
# define CIRCULAR_LINKED_LIST_H

# include <stdbool.h>

typedef int	t_data;

typedef struct	s_node
{
	t_data			data;
	struct s_node	*next;
}	t_node;

typedef struct	s_clinkedlist
{
	t_node	*tail;
	t_node	*before;
	t_node	*cur;
	int		num_of_data;
} 	t_clinkedlist;

typedef t_clinkedlist	list;

void	list_init(list *plist);
void	list_insert_back(list *plist, t_data data);
void	list_insert_front(list *plist, t_data data);
bool	list_first(list *plist, t_data *data);
bool	list_next(list *plist, t_data *pdata);
t_data	list_remove(list *plist);
int		list_count(list *plist);

#endif