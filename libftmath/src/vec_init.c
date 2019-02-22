/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:05:43 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 17:50:08 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

/*
** The ft_init_vecx functions are initializing t_vec structs
** containing 2D, 3D or 4D vector coordinates.
** Returns an initialized vector type struct.
*/

t_vec2	init_vec2(float x, float y)
{
	t_vec2	dest;

	dest.x = x;
	dest.y = y;
	return (dest);
}

t_vec3	init_vec3(float x, float y, float z)
{
	t_vec3	dest;

	dest.x = x;
	dest.y = y;
	dest.z = z;
	return (dest);
}

t_vec4	init_vec4(float x, float y, float z, float w)
{
	t_vec4	dest;
	
	dest.x = x;
	dest.y = y;
	dest.z = z;
	dest.w = w;
	return (dest);
}

t_vec4	vec3_to_vec4(t_vec3 src, double w)
{
	t_vec4	dest;

	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
	dest.w = w;
	return (dest);
}


