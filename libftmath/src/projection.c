/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:26:04 by gmichaud          #+#    #+#             */
/*   Updated: 2019/09/26 18:50:37 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

static t_mtx4	ft_frustum_mtx(float top, float right, float near, float far)
{
	t_mtx4	m;

	m.elem[0][0] = 2 * near / (2 * right);
	m.elem[1][0] = 0;
	m.elem[2][0] = 0;
	m.elem[3][0] = 0;
	m.elem[0][1] = 0;
	m.elem[1][1] = 2 * near / (2 * top);
	m.elem[2][1] = 0;
	m.elem[3][1] = 0;
	m.elem[0][2] = 0;
	m.elem[1][2] = 0;
	m.elem[2][2] = -(far + near) / (far - near);
	m.elem[3][2] = -(2 * far * near) / (far - near);
	m.elem[0][3] = 0;
	m.elem[1][3] = 0;
	m.elem[2][3] = -1;
	m.elem[3][3] = 0;
	return (m);
}

t_mtx4			perspective(float fovy, float aspect, float near, float far)
{
	t_mtx4	m;
	float	top;
	float	right;

	top = near * tanf(fovy * (M_PI / 360));
	right = top * aspect;
	m = ft_frustum_mtx(top, right, near, far);
	return (m);
}

t_mtx4			orthographic(float top, float right, float near, float far)
{
	t_mtx4	m;

	m.elem[0][0] = 1 / right;
	m.elem[1][0] = 0;
	m.elem[2][0] = 0;
	m.elem[3][0] = 0;
	m.elem[0][1] = 0;
	m.elem[1][1] = 1 / top;
	m.elem[2][1] = 0;
	m.elem[3][1] = 0;
	m.elem[0][2] = 0;
	m.elem[1][2] = 0;
	m.elem[2][2] = -2 / (far - near);
	m.elem[3][2] = -((far + near) / (far - near));
	m.elem[0][3] = 0;
	m.elem[1][3] = 0;
	m.elem[2][3] = 0;
	m.elem[3][3] = 1;
	return (m);
}