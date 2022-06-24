# include "push_swap.h"

static int	ft_atoi_strict(const char *str)
{
	int		neg;
	size_t	num;
	long	cnt;

	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	cnt = INT_MAX;
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN);
	while ('0' <= *str && *str <= '9')
	{
		if (neg == -1 && (cnt == 0 || num > -(size_t)INT_MIN))
			ft_pstr_exit("Error\n: some arguments are bigger than an integer..");
		if (neg == 1 && (cnt == 0 || num > (size_t)INT_MAX))
			ft_pstr_exit("Error\n: some arguments are smaller than an integer..");
		num = num * 10 + (*str - '0');
		cnt = cnt / 10;
		str++;
	}
	if (*str != 0)
		ft_pstr_exit("Error\n: some arguments aren’t integers..");
	return (neg * num);
}

static bool	is_unique_number(t_list *plist, int num)
{
	int		i;
	int		list_len;
	t_data	data;

	if (list_first(plist, &data))
	{
		if (data == num)
			return (false);
		i = 1;
		list_len = list_count(plist);
		while (i < list_len)
		{
			list_next(plist, &data);
			if (data == num)
				return (false);
			i++;
		}
	}
	return (true);
}

static int	get_valid_number(t_list *list, char *str)
{
	int num;

	num = ft_atoi_strict(str);
	if (is_unique_number(list, num) == false)
		ft_pstr_exit("Error\n: there are duplicates..");
	return (num);
}

t_list	*get_valid_list(char **args)
{
	int		i;
	int		j;
	char	**temp;
	t_list *plist;

	plist = malloc(sizeof(t_list));
	list_init(plist);
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], ' ') == NULL)
			list_insert_back(plist, get_valid_number(plist, args[i]));
		else
		{
			temp = ft_split(args[i], ' ');
			j = 0;
			while (temp[j])
			{
				list_insert_back(plist, get_valid_number(plist, temp[j]));
				j++;
			}
			free_twoarr(temp);
		}
		i++;
	}
	return (plist);
}