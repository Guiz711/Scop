/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42,fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:38:07 by hbouchet          #+#    #+#             */
/*   Updated: 2019/02/15 17:11:58 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

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
	mtx.elem[0][3] = value.x;
	mtx.elem[1][3] = value.y;
	mtx.elem[2][3] = value.z;
	return (mtx);
}

t_mtx4		mtx_rotation(t_axis axis, double pitch)
{
	t_mtx4	mtx;

	mtx.a[0] = (axis == X) ? 1 : cosf(pitch);
	mtx.a[1] = (axis == Z) ? -sinf(pitch) : 0;
	mtx.a[2] = (axis == Y) ? sinf(pitch) : 0;
	mtx.a[3] = 0;
	mtx.b[0] = (axis == Z) ? sinf(pitch) : 0;
	mtx.b[1] = (axis == Y) ? 1 : cosf(pitch);
	mtx.b[2] = (axis == X) ? -sinf(pitch) : 0;
	mtx.b[3] = 0;
	mtx.c[0] = (axis == Y) ? -sinf(pitch) : 0;
	mtx.c[1] = (axis == X) ? sinf(pitch) : 0;
	mtx.c[2] = (axis == Z) ? 1 : cosf(pitch);
	mtx.c[3] = 0;
	mtx.d[0] = 0;
	mtx.d[1] = 0;
	mtx.d[2] = 0;
	mtx.d[3] = 1;
	return (mtx);
}

t_mtx4		scale(t_vec3 factor)
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

	m.a[0] = 1 - 2 * (q.y * q.y + q.z * q.z);
	m.a[1] = 2 * (q.x * q.y + q.z * q.w);
	m.a[2] = 2 * (q.x * q.z - q.y * q.w);
	m.a[3] = 0;
	m.b[0] = 2 * (q.x * q.y - q.z * q.w);
	m.b[1] = 1 - 2 * (q.x * q.x + q.z * q.z);
	m.b[2] = 2 * (q.y * q.z + q.x * q.w);
	m.b[3] = 0;
	m.c[0] = 2 * (q.x * q.z + q.y * q.w);
	m.c[1] = 2 * (q.y * q.z - q.x * q.w);
	m.c[2] = 1 - 2 * (q.x * q.x + q.y * q.y);
	m.c[3] = 0;
	m.d[0] = 0;
	m.d[1] = 0;
	m.d[2] = 0;
	m.d[3] = 1;
	return (m);
}
