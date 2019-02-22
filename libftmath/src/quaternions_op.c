/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:44:36 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 13:24:08 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

double	quat_norm(t_quat q)
{
	double norm;

	norm = sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	return (norm);
}

t_quat	quat_normalize(t_quat q)
{
	float	sqrlen;
	float	invlen;

	sqrlen = (q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	if (sqrlen)
	{
		invlen = fisqrt(sqrlen);
		q.x *= invlen;
		q.y *= invlen;
		q.z *= invlen;
		q.w *= invlen;
	}
	return (q);
}

t_quat	quat_mult(t_quat q1, t_quat q2)
{
	t_quat	qr;

	qr.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	qr.y = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
	qr.z = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
	qr.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	return (qr);
}
