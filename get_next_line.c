/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:52:01 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/13 16:21:56 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_itoa(int n, char *str)
{
	int	nb;
	int	i;

	if (n == 0)
		str[0] = 0;
	i = 0;
	nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	str[i--] = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			i;
	char			*str;
	int			mem;
	int			ret;

	if (buffer[0] == -1)
		return (0);
	str = malloc(sizeof(char));
	str[0] = 0;
	while (1)
	{
		i = ft_atoi(buffer);
		if (buffer[0] != 0)
			i++;
		if (buffer[0] == 0)
		{
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret == BUFFER_SIZE)
				buffer[BUFFER_SIZE] = -1;
			if (ret < BUFFER_SIZE)
				buffer[ret] = 0;
		}
		mem = i;
		while (buffer[i] != '\n' && buffer[i] != 0 && buffer[i] != -1)
			i++;
		str = ft_strjoin(str, ft_substr(&buffer[mem], 0, i - mem + 1));
		if (buffer[i] == '\n')
		{
			ft_itoa(i, buffer);
			return (str);
		}
		if (buffer[i] == 0)
		{
			buffer[0] = -1;
			return (str);
		}
		if (buffer[i] == -1)
			buffer[0] = 0;
		
	}
	return (str);
}
