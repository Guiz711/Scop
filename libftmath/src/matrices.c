/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:38:07 by hbouchet          #+#    #+#             */
/*   Updated: 2019/03/29 12:06:01 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

/*
** The matrices functions are initializing t_mtx4 structs
** containing 4x4 matrices.
** Returns an initialized matrix type struct.
*/

t_mtx4		mtx_identity(void)
{
	t_mtx4	mtx;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mtx.elem[i][j] = i == j ? 1 : 0;
			++j;
		}
		++i;
	}
	return (mtx);
}

t_mtx4		mtx_translation(t_vec3 value)
{
	t_mtx4	mtx;

	mtx = mtx_identity();
	mtx.elem[3][0] = value.x;
	mtx.elem[3][1] = value.y;
	mtx.elem[3][2] = value.z;
	return (mtx);
}

t_mtx4		mtx_rotation(t_axis axis, float degrees)
{
	t_mtx4	mtx;
	float	rcos;
	float	rsin;

	rcos = cosf(degrees * DEG2RAD);
	rsin = sinf(degrees * DEG2RAD);
	mtx = mtx_identity();
	mtx.elem[0][0] = (axis == X) ? 1 : rcos;
	mtx.elem[1][0] = (axis == Z) ? -rsin : 0;
	mtx.elem[2][0] = (axis == Y) ? rsin : 0;
	mtx.elem[0][1] = (axis == Z) ? rsin : 0;
	mtx.elem[1][1] = (axis == Y) ? 1 : rcos;
	mtx.elem[2][1] = (axis == X) ? -rsin : 0;
	mtx.elem[0][2] = (axis == Y) ? -rsin : 0;
	mtx.elem[1][2] = (axis == X) ? rsin : 0;
	mtx.elem[2][2] = (axis == Z) ? 1 : rcos;
	return (mtx);
}

t_mtx4		mtx_scale(t_vec3 factor)
{
	t_mtx4	mtx;

	mtx = mtx_identity();
	mtx.elem[0][0] = factor.x;
	mtx.elem[1][1] = factor.y;
	mtx.elem[2][2] = factor.z;
	return (mtx);
}

t_mtx4		quat_to_mtx(t_vec4 q)
{
	t_mtx4	m;

	m.elem[0][0] = 1 - 2 * (q.y * q.y + q.z * q.z);
	m.elem[1][0] = 2 * (q.x * q.y + q.z * q.w);
	m.elem[2][0] = 2 * (q.x * q.z - q.y * q.w);
	m.elem[3][0] = 0;
	m.elem[0][1] = 2 * (q.x * q.y - q.z * q.w);
	m.elem[1][1] = 1 - 2 * (q.x * q.x + q.z * q.z);
	m.elem[2][1] = 2 * (q.y * q.z + q.x * q.w);
	m.elem[3][1] = 0;
	m.elem[0][2] = 2 * (q.x * q.z + q.y * q.w);
	m.elem[1][2] = 2 * (q.y * q.z - q.x * q.w);
	m.elem[2][2] = 1 - 2 * (q.x * q.x + q.y * q.y);
	m.elem[3][2] = 0;
	m.elem[0][3] = 0;
	m.elem[1][3] = 0;
	m.elem[2][3] = 0;
	m.elem[3][3] = 1;
	return (m);
}
