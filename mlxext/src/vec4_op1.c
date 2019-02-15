/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:51:42 by jgourdin          #+#    #+#             */
/*   Updated: 2019/02/15 14:17:57 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

float	v4_magnitude(t_vec4 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

float	v4_sqrmagnitude(t_vec4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

t_vec4	v4_normalize(t_vec4 v)
{
	float	length;

	length = v4_magnitude(v);
	if (length)
	{
		v.x /= length;
		v.y /= length;
		v.z /= length;
		v.w /= length;
	}
	return (v);
}

t_vec4	v4_add(t_vec4 u, t_vec4 v)
{
	t_vec4	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	res.w = u.w + v.w;
	return (res);
}

t_vec4	v4_substract(t_vec4 u, t_vec4 v)
{
	t_vec4	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	res.w = u.w - v.w;
	return (res);
}
