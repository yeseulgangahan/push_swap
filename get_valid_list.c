# include "push_swap.h"

static int	ft_atoi_strict(const char *str)
{
	int		neg;
	size_t	num;
	size_t	temp_num;
	long	cnt;

	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	cnt = INT_MAX;
	while ('0' <= *str && *str <= '9')
	{
		temp_num =  num * 10 + (*str - '0');
		if (neg == -1 && (cnt == 0 || temp_num > -(size_t)INT_MIN))
			ft_pstr_exit("Error\n: some arguments are smaller than an integer..");
		if (neg == 1 && (cnt == 0 || temp_num > (size_t)INT_MAX))
			ft_pstr_exit("Error\n: some arguments are bigger than an integer..");
		num = temp_num;
		cnt = cnt / 10;
		str++;
	}
	if (*str != 0)
		ft_pstr_exit("Error\n: some arguments aren’t integers..");
	return (neg * num);
}

static bool	is_unique_number(t_clist *plist, int num)
{
	int		i;
	int		list_len;
	t_data	data;

	if (clist_first(plist, &data))
	{
		if (data == num)
			return (false);
		i = 1;
		list_len = clist_count(plist);
		while (i < list_len)
		{
			clist_next(plist, &data);
			if (data == num)
				return (false);
			i++;
		}
	}
	return (true);
}

static int	get_valid_number(t_clist *list, char *str)
{
	int num;

	num = ft_atoi_strict(str);
	if (is_unique_number(list, num) == false)
		ft_pstr_exit("Error\n: there are duplicates..");
	return (num);
}

t_clist	*get_valid_list(char **args)
{
	int		i;
	int		j;
	char	**temp;
	t_clist *plist;

	plist = malloc(sizeof(t_clist));
	clist_init(plist);
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], ' ') == NULL)
			clist_insert_back(plist, get_valid_number(plist, args[i]));
		else
		{
			temp = ft_split(args[i], ' ');
			j = 0;
			while (temp[j])
			{
				clist_insert_back(plist, get_valid_number(plist, temp[j]));
				j++;
			}
			ft_free_twoarr(temp);
		}
		i++;
	}
	return (plist);
}
