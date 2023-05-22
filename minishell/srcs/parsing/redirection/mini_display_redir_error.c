/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_display_redir_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:06:26 by mathismarti       #+#    #+#             */
/*   Updated: 2023/05/16 22:01:07 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_parsing.h"

void	mini_display_redir_error(void)
{
	write(2, "minishell: syntax error near unexpected token newline'\n", 56);
}
