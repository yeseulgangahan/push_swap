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

typedef t_clinkedlist	t_list;

void	list_init(t_list *plist);
void	list_insert_back(t_list *plist, t_data data);
void	list_insert_front(t_list *plist, t_data data);
bool	list_first(t_list *plist, t_data *data);
bool	list_next(t_list *plist, t_data *pdata);
t_data	list_remove(t_list *plist);
int		list_count(t_list *plist);

#endif