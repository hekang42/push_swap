/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:21:28 by hekang            #+#    #+#             */
/*   Updated: 2020/10/07 19:37:03 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int cnt;

	if (s == 0)
		return ;
	cnt = 0;
	while (s[cnt])
	{
		write(fd, &s[cnt], 1);
		cnt++;
	}
	write(fd, "\n", 1);
}
