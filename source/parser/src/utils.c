/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 04:54:38 by hastid            #+#    #+#             */
/*   Updated: 2020/03/01 04:56:38 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_int(int *p, char *v, int t)
{
	int i;
	int res;

	res = sscanf(v, "%d%n", p, &i);
	if (res != 1 || v[i] != '\0')
		return (ERROR);
	if (t == CAMERA && (*p < 0 || *p > 120))
		return (ERROR);
	return (SUCCESS);
}

int	get_double(double *p, char *v, int t)
{
	int i;
	int res;

	res = sscanf(v, "%lf%n", p, &i);
	if (res != 1 || v[i] != '\0' || *p < 0)
		return (ERROR);
	if (t == FOV && *p > 120)
		return (ERROR);
	return (SUCCESS);
}

int	get_vect(t_vect *v, char *s, int t)
{
	int i;
	int res;

	i = 0;
	res = sscanf(s, "%lf,%lf,%lf%n", &(v->x), &(v->y), &(v->z), &i);
	if (res != 3 || s[i] != '\0')
		return (ERROR);
	if (t == COLOR && !(V_COLOR(v->x) && V_COLOR(v->y) && V_COLOR(v->x)))
		return (ERROR);
	return (SUCCESS);
}
