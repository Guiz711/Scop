/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:42:09 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 11:15:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	v3_v3_mult(t_vec3 u, t_vec3 v)
{
	u.x *= v.x;
	u.y *= v.y;
	u.z *= v.z;
	return (u);
}

t_vec3	v3_f_mult(t_vec3 v, float f)
{
	v.x *= f;
	v.y *= f;
	v.z *= f;
	return (v);
}

double	v3_dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	v3_divide(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.x / v.x;
	res.y = u.y / v.y;
	res.z = u.z / v.z;
	return (res);
}

bool	v3_equals(t_vec3 u, t_vec3 v)
{
	return (fequals(u.x, v.x) && fequals(u.y, v.y) && fequals(u.z, v.z));
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3 w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}
