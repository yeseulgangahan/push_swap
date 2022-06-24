# include <stdio.h>
# include "circular_linked_list.h"

void	list_init(list *plist)
{
	plist->tail = NULL;
	plist->before = NULL;
	plist->cur = NULL;
	plist->num_of_data = 0;
}

void	list_insert_back(list *plist, t_data data)
{
	t_node	*newnode = malloc(sizeof(t_node));

	newnode->data = data;
	if (plist->tail == NULL)
	{
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	(plist->num_of_data)++;
}

void	list_insert_front(list *plist, t_data data)
{
	t_node	*newnode = malloc(sizeof(t_node));

	newnode->data = data;
	if (plist->tail == NULL)
	{
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
	}
	(plist->num_of_data)++;
}

bool	list_first(list *plist, t_data *pdata)
{
	if (plist->tail == NULL)
		return (false);
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;
	return (true);
}
bool	list_next(list *plist, t_data *pdata)
{
	if (plist->tail == NULL)
		return (false);
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return (true);
}

t_data	list_remove(list *plist)
{
	t_node	*rpos;
	t_data	rdata;

	rpos = plist->cur;
	rdata = rpos->data;
	if (rpos == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;		
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(rpos);
	(plist->num_of_data)--;
	return (rdata);
}

int		list_count(list *plist)
{
	return (plist->num_of_data);
}