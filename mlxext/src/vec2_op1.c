/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:43:46 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/15 13:44:36 by gmichaud         ###   ########.fr       */
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
