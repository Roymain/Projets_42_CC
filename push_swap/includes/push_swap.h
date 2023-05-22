/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:50:16 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/12 00:51:42 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_val
{
	t_list	*pilea;
	t_list	*pileb;
	int		max;
	int		min;
	int		*output;
	int		*input;
	int		*trieur;
	int		len;
	int		binlen;
	int		nbrneg;
}			t_val;

int		*tabneg(t_val val, int *neg, int i, int j);
int		*tabpos(t_val val, int *pos, int i, int k);
int		*tabinput(t_val val, int *pos, int *neg);

t_list	*caslow(int argc, t_val val);
void	ft_casplus(t_val *val, int i, int count, int saveindex);

t_list	*ft_callswap(t_list **pilea, t_list *tmp);
t_list	*ft_castrois(t_list *tmp, t_val val);
t_list	*ft_cascinq(t_list *tmp, t_val *val);
t_list	*ft_lstplus(t_list *lst);
int		ft_lstpluscheck(t_list *lst, int val);
void	ft_pusha(t_list **pilea, t_list **pileb);
void	ft_pushb(t_list **pilea, t_list **pileb);
void	ft_swaptopa(t_list **alst, t_list *new);
void	ft_swaptopb(t_list **alst, t_list *new);
void	ft_rotatepilea(t_list **pile);
void	ft_rotatepileb(t_list **pile);
void	ft_rotaterevpilea(t_list **pile);
void	ft_rotaterevpileb(t_list **pile);

int		ft_parsargv(char **argv, t_list **pilea, int argc, int i);
int		*ft_parsinput(t_list *pile, int *tab);
int		ft_prefix(int tab, int coeff);
int		ft_sizevalue(int min, int max);
void	ft_cumulprefix(t_val *val, int coef);
void	ft_sortoutput(t_val *val, int coef);
void	ft_transfert(t_val val);
void	ft_casneg(t_val val);
void	ft_addindex(t_val *val);

t_val	ft_minmax(t_list *pile, t_list *tmp, t_val val);
int		ft_checkmin(t_list **pile);
int		ft_checkmax(t_list **pile);
int		ft_checkorder(t_list **pile);
int		ft_checkdoublonstab(t_val *val);

int		*ft_dec_to_bin(int nbr, int size);
int		ft_count_len_binary(int nbr);
int		ft_countneg(t_val val);
int		ft_countunit(t_list **temp, int unit);
int		ft_saveindex(t_list *pile, int unit);
void	ft_free(t_val val);

void	ft_lstprint(t_list *lst);
void	ft_print_list(t_list **pa, t_val *env);

#endif