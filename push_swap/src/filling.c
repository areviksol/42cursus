/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:46:11 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/11 17:27:46 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stack	*fill(int ac, char **av)
{
	t_stack		*stack_a;
	int			number;
	int			i;

	stack_a = NULL;
	number = 0;
	i = 1;
	while (i < ac)
	{
		number = ft_atoi(av[i]);
		if ((number > 2147483647) || (number < -2147483647 -1))
			err(&stack_a, NULL);
		if (i == 1)
			stack_a = createnode(number);
		else
			insertbottom(&stack_a, createnode((number)));
		i++;
	}
	return (stack_a);
}

int	*create_array(t_stack *node)
{
	int	array_length;
	int	i;
	int	*array;

	array_length = ft_list_size(node);
	array = (int *)malloc(array_length * sizeof(int));
	i = 0;
	while (node != NULL)
	{
		array[i] = node->value;
		node = (node)->next;
		i++;
	}
	return (array);
}

void	swap_values(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				s;

	s = 1;
	while (s == 1)
	{
		i = 1;
		s = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap_values(&tab[i - 1], &tab[i]);
				s = 1;
			}
			++i;
		}
	}
}

void	indexation(t_stack *stack_a, int stack_size)
{
	int	*num;
	int	y;

	num = create_array(stack_a);
	sort_int_tab(num, stack_size);
	while (stack_a != NULL)
	{
		y = 0;
		while (y < stack_size)
		{
			if (stack_a->value == num[y])
			{
				stack_a->index = y;
			}
			y++;
		}
		stack_a = stack_a->next;
	}
	free(num);
}
