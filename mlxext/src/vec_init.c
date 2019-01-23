/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:05:43 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/23 16:56:32 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxext.h"

/*
** The ft_init_vecx functions are initializing t_vec structs
** containing 3D or 4D vector coordinates.
** Returns an initialized vector type struct.
*/

void	init_vec3(double x, double y, double z, t_vec3 dest)
{
	dest[0] = x;
	dest[1] = y;
	dest[2] = z;
}

void	copy_vec3(t_vec3 src, t_vec3 dest)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

void	init_vec4(t_vec3 src, double w, t_vec4 dest)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = w;
}

void	copy_vec4(t_vec4 src, t_vec4 dest)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
}

void	vec4_to_vec3(t_vec4 src, t_vec3 dest)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}
