/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahine <rchahine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:06:37 by rchahine          #+#    #+#             */
/*   Updated: 2024/07/11 14:06:37 by rchahine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct node{
	char		data;
	struct node	*next;
}	t_list;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	addlast(t_list **head, char c);
int		tsize(t_list *head);
char	*ret(t_list **head);
int		exist(t_list *head);
char	*get_next_line(int fd);
void	norm(t_list **head, char *res, int *i);

#endif