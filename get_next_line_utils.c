/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahine <rchahine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:41:01 by rchahine          #+#    #+#             */
/*   Updated: 2024/07/18 14:21:12 by rchahine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//sah
void	addlast(t_list **head, char c)
{
	t_list	*new;
	t_list	*curr;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->data = c;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

//sah
int	exist(t_list *head)
{
	while (head != NULL)
	{
		if (head -> data == '\n')
			return (1);
		head = head -> next;
	}
	return (0);
}

//sah
int	tsize(t_list *head)
{
	int	count;

	count = 0;
	if (!head)
		return (0);
	while (head != NULL && head->data != '\n')
	{
		head = head -> next;
		count ++;
	}
	return (count);
}

void	norm(t_list **head, char *res, int *i)
{
	t_list	*temp;

	if (*head)
	{
		temp = (*head);
		res[(*i)++] = (*head)->data;
		*head = (*head)->next;
		free(temp);
	}
}

char	*ret(t_list **head)
{
	char	*res;
	int		i;
	t_list	*temp;

	if (*head == NULL)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (tsize(*head) + 2));
	if (!res)
		return (NULL);
	while (*head != NULL && (*head)->data != '\n')
	{
		temp = *head;
		res[i++] = (*head)-> data;
		(*head) = (*head)-> next;
		free(temp);
	}
	norm(head, res, &i);
	res[i] = '\0';
	return (res);
}
