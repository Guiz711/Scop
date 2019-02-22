/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:50:25 by jgourdin          #+#    #+#             */
/*   Updated: 2019/02/22 17:05:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_quat	axisangle_to_quat(t_vec4 axis, double angle)
{
	t_quat	qr;
	double	sin_a;

	sin_a = sin(angle / 2);
	qr.x = axis.x * sin_a;
	qr.y = axis.y * sin_a;
	qr.z = axis.z * sin_a;
	qr.w = cos(angle / 2);
	return (qr);
}

t_quat	euler_to_quat(t_vec3 rot)
{
	t_quat	x_quat;
	t_quat	y_quat;
	t_quat	z_quat;

	x_quat = axisangle_to_quat(init_vec4(1, 0, 0, 0), -rot.x * DEG2RAD);
	y_quat = axisangle_to_quat(init_vec4(0, 1, 0, 0), -rot.y * DEG2RAD);
	z_quat = axisangle_to_quat(init_vec4(0, 0, 1, 0), -rot.z * DEG2RAD);
	return (quat_mult(z_quat, quat_mult(x_quat, y_quat)));
}

t_quat	quat_lerp(t_quat start, t_quat end, float t)
{
	t_quat	result;
	float	invt;

	invt = 1.0f - t;
	result.x = invt * start.x + t * end.x;
	result.y = invt * start.y + t * end.y;
	result.z = invt * start.z + t * end.z;
	result.w = invt * start.w + t * end.w;
	return (quat_normalize(result));
}
