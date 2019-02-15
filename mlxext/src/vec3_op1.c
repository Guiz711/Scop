/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:40:09 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/15 13:41:20 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

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
	float	length;

	length = v3_magnitude(v);
	if (length)
	{
		v.x /= length;
		v.y /= length;
		v.z /= length;
	}
	return (v);
}
