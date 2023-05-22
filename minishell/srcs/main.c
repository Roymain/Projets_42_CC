/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2023/05/16 22:05:06 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	mini_condition(char *line, t_mini *mini)
{
	if (mini_parsing_line(line, mini) == 1)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		mini->cmd->listcmd->key[0] = 0;
	}
	if (line[0] && mini->cmd->listcmd->key[0])
		ft_exec(mini, NULL);
}

static void	mini_main_loop(t_mini *mini, char *line)
{
	mini_init_cmd(mini);
	//add_history(line);
	mini_condition(line, mini);
	ft_free_all(mini->track_cmd);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	char	*line;
	int		status;

	mini_init(&mini, argc, argv);
	ft_parsenv(&mini.env->list, envp, &mini.track_env);
	signal(SIGINT, mini_handler);
	signal(SIGQUIT, mini_quit);
	mini_position(&line);
	while (line && ft_strncmp(line, "exit", ft_strlen("exit ")))
	{
		signal(SIGINT, mini_handler);
		signal(SIGQUIT, mini_quit);
		mini_main_loop(&mini, line);
		mini_position(&line);
	}
	status = mini.env->return_value;
	ft_free_all(mini.track_env);
	free(line);
	//rl_clear_history();
	printf("exit\n");
	exit (status);
}
