/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:26:59 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/24 14:44:09 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		ft_count_words(char const *s, char c)
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

static void	valid_smbls(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == ',' ||
			(str[i] >= 'A' && str[i] <= 'F') || str[i] == 'X' ||
			(str[i] >= 'a' && str[i] <= 'f') || str[i] == 'x' ||
			str[i] == '-')
			i++;
		else
			ft_error("Map error\n");
	}
}

/*
** Checking for valid data in file
*/

void		validation(t_list *lines)
{
	int i;
	int j;

	while (lines->next)
	{
		i = ft_count_words(lines->content, ' ');
		j = ft_count_words(lines->content, ' ');
		if (i != j)
			ft_error("Map error\n");
		valid_smbls(lines->content);
		lines = lines->next;
	}
}
