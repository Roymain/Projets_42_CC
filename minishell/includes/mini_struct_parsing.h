/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct_parsing.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:57:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/22 16:00:51 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCT_PARSING_H
# define MINI_STRUCT_PARSING_H

typedef struct s_quote
{
	int		index;
	int		start;
	char	q;
	char	*tmp;
	char	*str;
}				t_quote;

#endif
