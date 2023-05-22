/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_display_export_errors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:06:12 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 21:44:40 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini_builtin.h"

void	mini_display_export_error(int error)
{
	if (error == NOT_VALID)
		write(2, "minishell: export: '=': not a valid identifier\n", 48);
}
