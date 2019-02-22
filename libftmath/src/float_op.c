/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:15:07 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 13:38:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

bool	fequals(float a, float b)
{
	return (fabs(a - b) < FLT_EPSILON);
}

float	lerp(float a, float b, float t)
{
	return ((1.0f - t) * a + t * b);
}

float	fisqrt(float n)
{
	t_fisqrt_conv	conv;
	float			x2;

	x2 = n * 0.5f;
	conv.f = n;
	conv.i = 0x5f3759df - (conv.i >> 1);
	conv.f = conv.f * (1.5f - (x2 * conv.f * conv.f));
	return (conv.f);
}
