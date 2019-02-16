/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxext.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42,fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:07:48 by jgourdin          #+#    #+#             */
/*   Updated: 2019/02/15 17:02:45 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>
# include <stdbool.h>
# include <float.h>

typedef enum	e_axis
{
	X,
	Y,
	Z,
}				t_axis;

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

typedef struct	s_mtx4
{
	float		elem[4][4];
}				t_mtx4;

/*
** Float functions
*/

bool			fequals(float a, float b);
float			lerp(float a, float b, float time);

/*
** Vector functions
*/

t_vec2			init_vec2(float x, float y);
t_vec3			init_vec3(float x, float y, float z);
t_vec4			init_vec4(float x, float y, float z, float w);
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

// t_mtx4			identity(void);
// t_mtx4			scale(double pitch_x, double pitch_y, double pitch_z);
// t_mtx4			translate(double t_x, double t_y, double t_z);
// t_mtx4			rotate(t_axis axis, double pitch);
// t_mtx4			mtx4_mult(t_mtx4 m1, t_mtx4 m2);
// t_vec4			new_coord(t_vec4 p, t_mtx4 mtx);

/*
** Quaternion functions
*/

// t_vec4			axisangle_to_quat(t_vec4 axis, double angle);
// t_vec4			euler_to_quat(t_vec3 rot);
// double			norm_quat(t_vec4 q);
// t_vec4			normalize_quat(t_vec4 q);
// t_vec4			mult_quat(t_vec4 q1, t_vec4 q2);
// t_mtx4			quat_to_mtx(t_vec4	q);

#endif
