/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahine <rchahine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:09:12 by rchahine          #+#    #+#             */
/*   Updated: 2024/07/18 14:55:52 by rchahine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	char			buff[BUFFER_SIZE];
	int				i;
	int				n;
	char			*res;

	if (fd < 0)
		return (NULL);
	while (!exist(head))
	{
		i = 0;
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0)
			break ;
		if (n < 0)
			return (NULL);
		while (i < n)
			addlast(&head, buff[i++]);
	}
	res = ret(&head);
	if (res)
		return (res);
	return (NULL);
}
