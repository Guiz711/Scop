/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:43:46 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 16:11:32 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

float	v2_magnitude(t_vec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

float	v2_sqrmagnitude(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

t_vec2	v2_normalize(t_vec2 v)
{
	float	sqrlen;
	float	invlen;

	sqrlen = (v.x * v.x + v.y * v.y);
	if (sqrlen)
	{
		invlen = fisqrt(sqrlen);
		v.x *= invlen;
		v.y *= invlen;
	}
	return (v);
}

t_vec2	v2_add(t_vec2 u, t_vec2 v)
{
	t_vec2	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	return (res);
}

t_vec2	v2_substract(t_vec2 lhs, t_vec2 rhs)
{
	t_vec2	res;

	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return (res);
}
