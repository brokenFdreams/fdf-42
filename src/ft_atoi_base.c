/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:34:59 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/22 11:04:27 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long int	ft_atoi_base(char *str, int base)
{
	int			i;
	int			j;
	long int	res;
	char		*ar;

	if (!(ar = ft_strjoin("", "0123456789ABCDEF")))
		ft_error("Malloc error\n");
	i = 0;
	res = 0;
	while (str[i] && str[i] != ' ')
	{
		j = 0;
		while (ar[j] && ft_toupper(str[i]) != ar[j] && j < base)
			j++;
		if (!ar[j] && j >= base)
			return (res);
		res = res * base + j;
		i++;
	}
	return (res);
}
