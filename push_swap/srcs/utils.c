/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 03:12:51 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/12 01:08:59 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int long	ft_atol(const char *str, int *i)
{
	long long int	sign;
	long long int	result;

	sign = 1;
	result = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		*i += 1;
	}
	if (ft_isdigit(str[*i]) != 1)
		exit (write(2, "Error\n", 6));
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + str[*i] - '0';
		*i += 1;
	}
	return (sign * result);
}

int	ft_parsargv(char **argv, t_list **pilea, int argc, int i)
{
	int					*tmpi;
	int long			j;
	t_list				*tmp;
	int					ref;

	while (i < argc)
	{
		ref = 0;
		while (ref < ft_strlen(argv[i]))
		{
			j = ft_atol(argv[i], &ref);
			if (j > 2147483647 || j < -2147483648)
			{
				ft_lstclear(pilea, &free);
				return (1);
			}
			tmpi = malloc(sizeof(int));
			*tmpi = j;
			tmp = ft_lstnew(tmpi);
			ft_lstadd_back(pilea, tmp);
		}	
		i++;
	}
	return (0);
}

int	*ft_parsinput(t_list *pile, int *tab)
{
	int	i;

	i = 0;
	while (pile)
	{
		tab[i] = *pile->content;
		pile = pile->next;
		i++;
	}
	return (tab);
}

void	ft_sortoutput(t_val *val, int coef)
{
	int	i;
	int	prefix;

	i = val->len - 1;
	while (i >= 0)
	{
		prefix = ft_prefix(val->input[i], coef);
		val->trieur[prefix] -= 1;
		val->output[val->trieur[prefix]] = val->input[i];
		i--;
	}
}
