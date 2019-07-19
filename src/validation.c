/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:26:59 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/19 13:45:43 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (s[i] != c && i == 0))
			count++;
		i++;
	}
	return (count);
}

/*
** Checking for valid symbols
*/

void	valid_smbls(char *line)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == ',' ||
			(str[i] >= 'A' && str[i] <= 'F') ||
			(str[i] >= 'a' && str[i] <= 'f'))
			i++;
		else
			ft_error("Map error\n");
	}
}

/*
** Checking for valid data in file
*/

void	validation(t_list *lines)
{
	int i;
	int j;

	while (lines->next)
	{
		i = ft_count_words(lines->data, ' ');
		j = ft_count_words(lines->data, ' ');
		if (i != j)
			ft_error("Map error\n");
		valide_smbls(list->data);
		list = list->next;
	}
}
