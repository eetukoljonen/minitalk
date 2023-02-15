/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:07:00 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/15 12:33:19 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Server has recieved the message!\n", 1);
		exit(0);
	}
}

static void	error_check(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc != 3 || !*argv[2])
	{
		ft_putstr_fd("\033[0;31m.........WRONG FORMAT.........\n"
			"TRY: ./client <PID> <MESSAGE>\n", 2);
		exit (0);
	}
	while (argv[1][index])
	{
		if (!ft_isdigit(argv[1][index]))
		{
			ft_putstr_fd("\033[0;31mINVALID PID\n", 2);
			exit(0);
		}
		index++;
	}
	if (ft_atoi(argv[1]) == 0 || kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_putstr_fd("\033[0;31mINVALID PID\n", 2);
		exit (0);
	}
}

static void	send_size(pid_t pid, char *string)
{
	int	size;

	size = ft_strlen(string);
	while (size > 0)
	{
		size--;
		kill(pid, SIGUSR1);
		usleep(50);
	}
	kill(pid, SIGUSR2);
	usleep(50);
}

static void	send_string(pid_t pid, char *string)
{
	int	index;
	int	bit;

	bit = 0;
	index = 0;
	send_size(pid, string);
	while (string[index])
	{
		while (bit < 8)
		{
			if (string[index] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			bit++;
		}
		bit = 0;
		index++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	pid_t				pid;

	error_check(argc, argv);
	pid = ft_atoi(argv[1]);
	sig.sa_flags = 0;
	sig.sa_handler = handle_signal;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	send_string(pid, argv[2]);
	sleep(5);
	return (0);
}
