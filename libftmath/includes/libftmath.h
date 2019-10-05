/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmath.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:07:48 by jgourdin          #+#    #+#             */
/*   Updated: 2019/10/05 16:10:11 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

# include <math.h>
# include <stdbool.h>
# include <float.h>
# include <stdint.h>

# define DEG2RAD (M_PI / 180.0f)

typedef enum	e_axis
{
	X,
	Y,
	Z,
}				t_axis;

typedef union	e_fisqrt_conv
{
	float		f;
	uint32_t	i;
}				t_fisqrt_conv;

typedef union 	u_vec2
{
	float		elem[2];
	struct
	{
		float	x;
		float	y;
	};
	struct
	{
		float	u;
		float	v;
	};
	struct
	{
		float	width;
		float	height;
	};
}				t_vec2;

typedef union	u_vec3
{
	float		elem[3];
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	struct
	{
		float	u;
		float	v;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
	};
}				t_vec3;

typedef union	u_vec4
{
	float		elem[4];
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
		float	a;
	};
}				t_vec4;

typedef union	u_vec3i
{
	int			elem[3];
	struct
	{
		int		x;
		int		y;
		int		z;
	};
}				t_vec3i;

typedef union	u_vec4i
{
	int			elem[4];
	struct
	{
		int		x;
		int		y;
		int		z;
		int		w;
	};
}				t_vec4i;

typedef struct	s_mtx4
{
	float		elem[4][4];
	t_vec4		vec[4];
}				t_mtx4;

typedef t_vec4	t_quat;
/*
** Float functions
*/

bool			fequals(float a, float b);
float			lerp(float a, float b, float time);
float			fisqrt(float n);

/*
** Vector functions
*/

t_vec2			init_vec2(float x, float y);
t_vec3			init_vec3(float x, float y, float z);
t_vec4			init_vec4(float x, float y, float z, float w);
t_vec3i			init_vec3i(int x, int y, int z);
t_vec4i			init_vec4i(int x, int y, int z, int w);
t_vec4			vec3_to_vec4(t_vec3 src, double w);

float			v2_magnitude(t_vec2 v);
float			v2_sqrmagnitude(t_vec2 v);
t_vec2			v2_normalize(t_vec2 v);
t_vec2			v2_add(t_vec2 u, t_vec2 v);
t_vec2			v2_substract(t_vec2 u, t_vec2 v);
t_vec2			v2_v2_mult(t_vec2 u, t_vec2 v);
t_vec2			v2_f_mult(t_vec2 v, float f);
double			v2_dot(t_vec2 u, t_vec2 v);
t_vec2			v2_divide(t_vec2 u, t_vec2 v);
bool			v2_equals(t_vec2 u, t_vec2 v);

float			v3_magnitude(t_vec3 v);
float			v3_sqrmagnitude(t_vec3 v);
t_vec3			v3_normalize(t_vec3 v);
t_vec3			v3_add(t_vec3 u, t_vec3 v);
t_vec3			v3_substract(t_vec3 u, t_vec3 v);
t_vec3			v3_v3_mult(t_vec3 u, t_vec3 v);
t_vec3			v3_f_mult(t_vec3 v, float f);
double			v3_dot(t_vec3 u, t_vec3 v);
t_vec3			v3_divide(t_vec3 u, t_vec3 v);
bool			v3_equals(t_vec3 u, t_vec3 v);
t_vec3			v3_cross(t_vec3 u, t_vec3 v);

float			v4_magnitude(t_vec4 v);
float			v4_sqrmagnitude(t_vec4 v);
t_vec4			v4_normalize(t_vec4 v);
t_vec4			v4_add(t_vec4 u, t_vec4 v);
t_vec4			v4_substract(t_vec4 u, t_vec4 v);
t_vec4			v4_v4_mult(t_vec4 u, t_vec4 v);
t_vec4			v4_f_mult(t_vec4 v, float f);
double			v4_dot(t_vec4 u, t_vec4 v);
t_vec4			v4_divide(t_vec4 u, t_vec4 v);
bool			v4_equals(t_vec4 u, t_vec4 v);

/*
** Matrix functions
*/

t_mtx4			mtx_identity(void);
t_mtx4			mtx_translation(t_vec3 value);
t_mtx4			mtx_rotation(t_axis axis, float angle);
t_mtx4			mtx_scale(t_vec3 factor);
t_mtx4			mtx_transpose(t_mtx4 matrix);
t_mtx4			mtx4_mult(t_mtx4 lhs, t_mtx4 rhs);
t_mtx4			quat_to_mtx(t_vec4 q);
t_mtx4			orthographic(float top, float right, float near, float far);
t_mtx4			perspective(float fovy, float aspect, float near, float far);

/*
** Quaternion functions
*/

t_quat			quat_identity();
double			quat_norm(t_quat q);
t_quat			quat_normalize(t_quat q);
t_quat			quat_mult(t_quat q1, t_quat q2);
t_quat			axisangle_to_quat(t_vec4 axis, double angle);
t_quat			euler_to_quat(t_vec3 rot);
t_quat			quat_lerp(t_quat start, t_quat end, float t);
bool			quat_equal(t_quat u, t_quat v);

#endif
