/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:40:09 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 13:08:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

float	v3_magnitude(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	v3_sqrmagnitude(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3	v3_normalize(t_vec3 v)
{
	float	sqrlen;
	float	invlen;

	sqrlen = (v.x * v.x + v.y * v.y + v.z * v.z);
	if (sqrlen)
	{
		invlen = fisqrt(sqrlen);
		v.x *= invlen;
		v.y *= invlen;
		v.z *= invlen;
	}
	return (v);
}

t_vec3	v3_add(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}

t_vec3	v3_substract(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	return (res);
}
