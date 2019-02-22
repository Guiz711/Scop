/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:39:19 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 11:15:24 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec4	v4_v4_mult(t_vec4 u, t_vec4 v)
{
	u.x *= v.x;
	u.y *= v.y;
	u.z *= v.z;
	u.w *= v.w;
	return (u);
}

t_vec4	v4_f_mult(t_vec4 v, float f)
{
	v.x *= f;
	v.y *= f;
	v.z *= f;
	v.w *= f;
	return (v);
}

double	v4_dot(t_vec4 u, t_vec4 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w);
}

t_vec4	v4_divide(t_vec4 u, t_vec4 v)
{
	t_vec4	res;

	res.x = u.x / v.x;
	res.y = u.y / v.y;
	res.z = u.z / v.z;
	res.w = u.w / v.w;
	return (res);
}

bool	v4_equals(t_vec4 u, t_vec4 v)
{
	return (fequals(u.x, v.x) && fequals(u.y, v.y) && fequals(u.z, v.z)
		&& fequals(u.w, v.w));
}
