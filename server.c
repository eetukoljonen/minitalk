/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:08:17 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/15 12:52:42 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static int	get_size(int signal)
{
	static int	size;
	int			tmp;

	if (signal == SIGUSR1)
		size++;
	else if (signal == SIGUSR2)
	{
		tmp = size;
		size = 0;
		return (tmp);
	}
	return (0);
}

static int	make_string(char c, int size)
{
	static char	*string;
	static int	check;
	static int	index;

	if (!check)
	{
		string = (char *)malloc(sizeof(char) * (size + 1));
		if (!string)
			exit(0);
		string[size + 1] = 0;
		check++;
	}
	string[index++] = c;
	if (index == size)
	{
		index = 0;
		check = 0;
		ft_putstr_fd(string, 1);
		ft_putchar_fd('\n', 1);
		free(string);
		return (1);
	}
	return (0);
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	check;
	static int	size;
	static int	bit;

	if (!size && context)
	{
		size = get_size(signal);
		return ;
	}
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		check = make_string(c, size);
		bit = 0;
		c = 0;
	}
	if (check)
	{
		kill(info->si_pid, SIGUSR1);
		check = 0;
		size = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr_fd("\033[0;34mSERVER PID == \033[0m", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handle_signal;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
