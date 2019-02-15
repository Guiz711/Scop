/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:15:07 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/15 14:24:21 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

bool	fequals(float a, float b)
{
	return (fabs(a - b) < FLT_EPSILON);
}

float	lerp(float a, float b, float time)
{
	return ((1.0f - time) * a + time * b);
}
