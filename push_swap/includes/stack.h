/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:38:36 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/17 15:13:11 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				id;
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill(int ac, char **av);
t_stack		*getbottom(t_stack *stack);
t_stack		*getbeforebottom(t_stack *stack);
t_stack		*createnode(int value);
t_stack		*next_min(t_stack *a);

void		indexation(t_stack *stack_a, int ac);
void		sortthree(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		insertbottom(t_stack **stack, t_stack *new);
void		freemem(t_stack **stack);
void		ft_putstr(char *str);
void		err(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **src, t_stack **dest);
void		swap(t_stack *stack);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
void		sort_int_tab(int *tab, unsigned int size);
void		swap_values(int *a, int *b);
void		indexation(t_stack *stack_a, int stack_size);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_free(char **str);
void		ft_free2(int **num);
void		mainsort(t_stack **a, t_stack **b);
void		index_stack(t_stack **a);
void		atob(t_stack **stack_a, t_stack **stack_b, int number);
void		btoa(t_stack **stack_a, t_stack **stack_b);
void		butterfly(t_stack **a, t_stack **b);
void		identification(t_stack **stack);
void		sortfive(t_stack **a, t_stack **b);
void		sortfour(t_stack **a, t_stack **b);
void		smallsort(t_stack **a, t_stack **b);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_list_size(t_stack	*stack);
int			is_sorted(t_stack *stack);
int			abs(int nb);
int			validation(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
int			find_highest_index(t_stack *stack);
int			*create_array(t_stack *node);
int			count_strings(char const *s, char c);
int			recieveargc(char **av);
int			lenghtbinarybum(t_stack **a);
int			arg_is_number(char *av);
int			have_duplicates(char **av);
int			arg_is_zero(char *av);
int			maxmincheck(t_stack *a);
int			findmax(t_stack **stack);
int			generate_chunk(int size);
int			generate_chunk(int size);
int			index_of_min(t_stack *a);
int			a(char **av, int i);

char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);

char		**ft_split(char const *s, char c);
char		**recieveargv2(char	**av);

#endif