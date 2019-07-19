/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:10:08 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/19 15:58:36 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Add new element to list
*/

void	ft_line_list(t_list **begin, void *line)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *begin;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		ft_error("Malloc error");
	new->content = line;
	new->content_size = ft_strlen((char*)line);
	if (!tmp)
		*begin = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
** Free list and free all data its contains
*/

void	ft_freelist(t_list **begin)
{
	t_list	*tmp;

	while (*begin)
	{
		free((*begin)->content);
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
}
