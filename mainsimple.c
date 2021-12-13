/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsimple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:56:02 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/13 13:25:53 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

int main(int ac, char **av)
{
    int    fd;
    char    *str;
	int i = 1;

	fd = 1;
	if (ac == 2)
	    fd =  open(av[1], O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        printf("read line %i :%s",i , str);
		i++;
        free(str);
    }
    printf("\n\nread line %i 2:%s",i ,str);
    free(str);
    close (fd);
    return (0);
}
