/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:15:44 by abiari            #+#    #+#             */
/*   Updated: 2021/06/21 17:17:51 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_dups(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (j->num == i->num)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	check_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			if (arg[i] != '-' || (arg[i] == '-' && i != 0)
				|| ((arg[i] == '-' && i == 0
						&& arg[i + 1] == '\0')))
				return (0);
		i++;
	}
	return (1);
}

int	check_arg(char *arg)
{
	int	tmp;

	if (!check_digit(arg))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (strlen(arg) > 10)
	{
		printf("Error\n");
		return (0);
	}
	else if (ft_strlen(arg) == 10)
	{
		tmp = ft_atoi(arg + 1);
		if (tmp > 147483647)
		{
			printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	check_ops_return(int ret, t_stack **a)
{
	if (!ret)
		return (255);
	if (!is_sorted(a) || ret == 2)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	clear_stack(a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		ret;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (255);
	}
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]))
			return (255);
		stack_addback(&a, ft_atoi(argv[i]));
		i++;
	}
	if (check_dups(a))
	{
		printf("Error\n");
		return (255);
	}
	ret = ops_checker(&a);
	return (check_ops_return(ret, &a));
}
