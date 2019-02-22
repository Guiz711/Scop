/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:44:59 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 11:15:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec2	v2_v2_mult(t_vec2 u, t_vec2 v)
{
	u.x *= v.x;
	u.y *= v.y;
	return (u);
}

t_vec2	v2_f_mult(t_vec2 v, float f)
{
	v.x *= f;
	v.y *= f;
	return (v);
}

double	v2_dot(t_vec2 u, t_vec2 v)
{
	return (u.x * v.x + u.y * v.y);
}

t_vec2	v2_divide(t_vec2 u, t_vec2 v)
{
	t_vec2	res;

	res.x = u.x / v.x;
	res.y = u.y / v.y;
	return (res);
}

bool	v2_equals(t_vec2 u, t_vec2 v)
{
	return (fequals(u.x, v.x) && fequals(u.y, v.y));
}
