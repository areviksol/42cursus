/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:55:12 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/12 17:36:46 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	identification(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp->id = i;
		i++;
		tmp = tmp->next;
	}
}

int	findmax(t_stack **stack)
{
	t_stack	*temp;
	int		size;
	int		pos;

	identification(stack);
	temp = *stack;
	size = ft_list_size(*stack) - 1;
	pos = -1;
	while (++pos < size && temp)
	{
		if (temp->index == size)
			return (pos);
		temp = temp->next;
	}
	return (pos);
}

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}
