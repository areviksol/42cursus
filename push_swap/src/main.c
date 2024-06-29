/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:58:37 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/16 17:00:46 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	guard_free_av(char ***as)
{
	int	x;

	if (!as || !*as)
		return ;
	x = -1;
	while ((*as)[++x])
		free((*as)[x]);
	free(*as);
	*as = 0;
}

void	helper(t_stack **a, t_stack **b, char **cav)
{
	int	size;

	size = ft_list_size(*a);
	indexation(*a, size);
	push_swap(a, b, size);
	freemem(a);
	freemem(b);
	guard_free_av(&cav);
}	

void	helper2(char **cav, t_stack **a)
{
	guard_free_av(&cav);
	freemem(a);
}

int	y(int count, char **cav)
{
	if (count < 2)
	{
		guard_free_av(&cav);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**cav;

	cav = recieveargv2(av);
	count = recieveargc(cav);
	if (y(count, cav) == 0)
		return (0);
	if (validation(cav) == 0)
	{
		guard_free_av(&cav);
		err(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill(count, cav);
	if (is_sorted(stack_a))
	{
		helper2(cav, &stack_a);
		return (0);
	}
	helper(&stack_a, &stack_b, cav);
	return (0);
}
