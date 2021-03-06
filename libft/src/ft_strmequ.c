/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hezzahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:48:08 by hezzahir          #+#    #+#             */
/*   Updated: 2020/02/27 23:39:33 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strmequ(char *str, char **cmps)
{
	int	i;

	i = 0;
	if (str && cmps)
		while (cmps[i])
		{
			if (ft_strequ(str, cmps[i]))
				return (i + 1);
			i++;
		}
	return (0);
}
