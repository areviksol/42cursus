/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vvvv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:05:25 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/12 18:02:40 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	guard_free(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = 0;
}

char	**recieveargv2(char **av)
{
	char	**arr;
	int		i;
	char	*str;
	char	*s1;

	i = -1;
	while (av[++i])
	{
		if (i == 0)
			str = ft_strjoin(av[i], " ");
		else
		{
			s1 = str;
			str = ft_strjoin(str, av[i]);
			guard_free(&s1);
			s1 = str;
			str = ft_strjoin(str, " ");
			guard_free(&s1);
		}
	}
	arr = ft_split(str, ' ');
	guard_free(&str);
	return (arr);
}

int	recieveargc(char **av)
{
	int		i;
	char	*str;
	int		argc;
	char	*s1;

	i = 0;
	while (av[i])
	{
		if (i == 0)
			str = ft_strjoin(av[i], " ");
		else
		{
			s1 = str;
			str = ft_strjoin(str, av[i]);
			guard_free(&s1);
			s1 = str;
			str = ft_strjoin(str, " ");
			guard_free(&s1);
		}
		i++;
	}
	argc = count_strings(str, ' ');
	guard_free(&str);
	return (argc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	char	*r;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	sublen = ft_strlen(s + start);
	if (sublen < len)
		len = sublen;
	r = malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s + start, len + 1);
	return (r);
}

int	validation(char **av)
{
	int	t;
	int	i;
	int	countofzeros;

	t = 0;
	countofzeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_zero(av[i]) && av[i][0] == '0')
		{
			while (av[i][t] == '0')
				t++;
			av[i] = ft_substr(av[i], t, ft_strlen(av[i]) - t);
		}
		if (!arg_is_number(av[i]))
			return (0);
		countofzeros += arg_is_zero(av[i]);
		if (a(av, i) == 0)
			return (0);
		i++;
	}
	if (countofzeros > 1 || have_duplicates(av))
		return (0);
	return (1);
}
