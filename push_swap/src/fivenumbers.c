/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:33:53 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/12 15:51:57 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	index_of_min(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a->value;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			index = i;
		}
		i++;
		a = a->next;
	}
	return (index);
}

void	sortfive(t_stack **a, t_stack **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)
		sa(a);
	else if (i == 2)
	{
		ra(a);
		ra(a);
	}
	else if (i == 3)
	{
		rra(a);
		rra(a);
	}
	else if (i == 4)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sortfour(a, b);
	pa(a, b);
}

void	sortfour(t_stack **a, t_stack **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)
		sa(a);
	else if (i == 2)
	{
		rra(a);
		rra(a);
	}
	else if (i == 3)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sortthree(a);
	pa(a, b);
}

void	smallsort(t_stack **a, t_stack **b)
{
	int	size;

	if (ft_list_size(*a) == 0
		|| ft_list_size(*a) == 1)
		return ;
	size = ft_list_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sortthree(a);
	else if (size == 4)
		sortfour(a, b);
	else if (size == 5)
		sortfive(a, b);
}
