/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>     		+#+ 	+:+    	+#+       */
/*                                          	+#+#+#+#+#+      +#+          */
/*   Created: 2025/07/29 03:30:59 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/29 03:30:59 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_single_cmd(t_data *data, t_env *envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_error("Fork failed\n", 1);
	if (pid == 0)
	{
		ft_redirection(data->token);
		execute_cmd(envp, data->cmd[0]);
		exit(127);
	}
	waitpid(pid, &status, 0);
	data->exit_status = WEXITSTATUS(status);
	free_args(data);
}

int	is_path(char *cmd)
{
	if (!cmd)
		return (0);
	if (cmd[0] == '/' || cmd[0] == '.')
		return (1);
	return (0);
}

void	execute_direct_path(char **cmd, char **envp_array)
{
	if (access(cmd[0], F_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	if (access(cmd[0], X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
	execve(cmd[0], cmd, envp_array);
	perror("execve");
	exit(126);
}

int	handle_path_command(char **cmd, char **envp_array)
{
	if (is_path(cmd[0]))
	{
		execute_direct_path(cmd, envp_array);
		free_split(envp_array);
		return (1);
	}
	return (0);
}

void	execute_cmd(t_env *env, char **cmd)
{
	char	**envp_array;
	char	**paths;
	char	*full_envp;

	if (!cmd || !cmd[0])
		return ;
	envp_array = env_list_to_array(env);
	if (!envp_array)
		return ;
	if (handle_path_command(cmd, envp_array))
		return ;
	full_envp = get_env_value_list(env, "PATH");
	if (!full_envp)
		handle_no_path(cmd, envp_array);
	paths = ft_split(full_envp, ':');
	if (!paths)
	{
		free_split(envp_array);
		return ;
	}
	handle_path_search(paths, envp_array, cmd);
}
