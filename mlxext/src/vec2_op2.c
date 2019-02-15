/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:44:59 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/15 13:45:36 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

t_vec2	v2_v2_mult(t_vec2 u, t_vec2 v)
{
	u.x *= v.x;
	u.y *= v.y;
	return (u);
}

t_vec2	v2_f_mult(t_vec2 v, float f)
{
	v.x *= f;
	v.y *= f;
	return (v);
}

double	v2_dot(t_vec2 u, t_vec2 v)
{
	return (u.x * v.x + u.y * v.y);
}
