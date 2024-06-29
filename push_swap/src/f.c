/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:22:46 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/12 16:04:12 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	lenghtbinarybum(t_stack **a)
{
	int	max;
	int	i;
	int	tmp;

	i = 1;
	tmp = 2;
	max = ft_list_size(*a) - 1;
	while (tmp <= max)
	{
		tmp *= 2;
		i++;
	}
	return (i);
}

t_stack	*next_min(t_stack *a)
{
	int		head;
	t_stack	*node;
	t_stack	*min_node;

	min_node = NULL;
	head = 0;
	node = a;
	while (node)
	{
		if (node->index == -1 && (head == 0
				|| node->value < min_node->value))
		{
			head = 1;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

void	index_stack(t_stack **a)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = next_min(*a);
	while (head)
	{
		head->index = index++;
		head = next_min(*a);
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
