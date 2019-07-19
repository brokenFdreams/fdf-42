/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:34:59 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/19 13:44:01 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

long int	ft_atoi_base(char *str)
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
		while (ar[j] && ft_toupper(str[i]) != ar[j])
			j++;
		if (!ar[j])
			return (res);
		res = res * 16 + j;
		i++;
	}
	return (res);
}
