/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:06:08 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/12 18:00:16 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	sortthree(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	atob(t_stack **stack_a, t_stack **stack_b, int number)
{
	int	counter;

	counter = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if ((*stack_a)->index <= counter + number)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}

void	btoa(t_stack **a, t_stack **b)
{
	int		id;
	t_stack	*tmp;

	tmp = (*b);
	while ((*b) != NULL)
	{
		id = findmax(b);
		if (id > (ft_list_size(*b) - 1) / 2)
		{
			while ((*b)->index != ft_list_size(*b) - 1)
				rrb(b);
		}
		else
		{
			while ((*b)->index != ft_list_size(*b) - 1)
				rb(b);
		}
		pa(a, b);
		tmp = *b;
	}
}

void	butterfly(t_stack **a, t_stack **b)
{
	int	len;
	int	chunk;

	len = ft_list_size(*a);
	chunk = generate_chunk(len);
	atob(a, b, chunk);
	btoa(a, b);
}

void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size <= 5)
		smallsort(a, b);
	else
		butterfly(a, b);
}
