/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hezzahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:59:15 by hezzahir          #+#    #+#             */
/*   Updated: 2020/02/13 20:30:35 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Sphere <origin> <raduis> <color> <val> <translation> <rotation> 
*/

void		set_sphere(char **words, t_rtv1 *r)
{
	t_shape		*shape;
	t_sphere	*sphere;
	t_shape		*elt;

	shape = (t_shape*)ft_memalloc(sizeof(t_shape));
	sphere = (t_sphere*)ft_memalloc(sizeof(t_sphere));
	sphere->origin = get_vect_from_str(words[1]);
	sphere->radius = ft_atof(words[2]);
	sphere->color = get_color_from_str(words[3]);
	sphere->val = ft_atoi(words[4]);
	sphere->tran = get_vect_from_str(words[5]);
	sphere->rot = get_vect_from_str(words[6]);
	shape->shape = sphere;
	shape->id = 1;
	shape->next = NULL;
	elt = r->shape;
	if (r->shape == NULL)
		r->shape = shape;
	else
	{
		while (elt->next != NULL)
			elt = elt->next;
		elt->next = shape;
	}
	sphere->origin = trans(sphere->origin, sphere->tran);
	r->is_okey[2] = '1';
}

void		sphere_checker(t_rtv1 *r, t_sphere sphere)
{
	t_light	*light;
	double	dist;

	light = r->light;
	while (light)
	{
		dist = distance(light->origin, sphere.origin);
		if (dist < sphere.radius * sphere.radius)
			light->intensity = 0;
		light = light->next;
	}
}
