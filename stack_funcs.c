/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:58:58 by abiari            #+#    #+#             */
/*   Updated: 2021/06/12 12:00:22 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(const t_stack *stack)
{
	if (stack)
		return (stack->num);
	return (INT32_MIN);
}

void	push(t_stack **stack, int num)
{
	t_stack	*temp;

	temp = new_node(num);
	if (!(*stack))
		*stack = temp;
	else
	{
		temp->next = *stack;
		*stack = temp;
	}
}

void	print_stack(const t_stack *stack, void display_num(int num))
{
	if (stack)
	{
		display_num(stack->num);
		write(1, " ", 1);
		print_stack(stack->next, display_num);
	}
}

int	pop(t_stack **stack)
{
	int		num;
	t_stack	*next;

	if (!(*stack))
		return (INT32_MIN);
	num = (*stack)->num;
	next = (*stack)->next;
	free(*stack);
	*stack = next;
	return (num);
}

void	stack_addback(t_stack **stack, int num)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new_node(num);
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node(num);
}