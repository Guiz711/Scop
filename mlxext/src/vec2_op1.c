/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42,fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:43:46 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/15 16:55:12 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

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
	float	length;

	length = v2_magnitude(v);
	if (length)
	{
		v.x /= length;
		v.y /= length;
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

t_vec2	v2_substract(t_vec2 u, t_vec2 v)
{
	t_vec2	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	return (res);
}
