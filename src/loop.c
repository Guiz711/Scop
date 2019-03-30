/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:50:31 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/08 17:28:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void quit(t_env *env)
{
	glDeleteVertexArrays(1, &env->opengl.vao);
	glDeleteBuffers(1, &env->opengl.vbo);
	mlx_destroy_window(env->window.init, env->window.ptr);
	exit(EXIT_SUCCESS);
}

void	update_input(t_env *env)
{
	t_input	*inputs;

	inputs = &env->inputs;
	if (kt_pressed(inputs->keys, KEY_ESCAPE))
	{
		quit(env);
	}
}

t_mtx4	update_mvt(t_env *env)
{
	t_input	*inputs;
	t_quat	q;
	t_vec2	delta;

	inputs = &env->inputs;
	if (mouse_pressed(inputs->mouse, MOUSE_MIDDLE))
	{
		delta = v2_substract(inputs->mouse_pos, inputs->click_pos);
		// if (kt_pressed(inputs->keys, KEY_SHIFT_LEFT))
			// q = euler_to_quat(init_vec3(0, 0, delta.x));
		// else
		q = euler_to_quat(init_vec3(delta.y, delta.x, 0));
		return (quat_to_mtx(quat_mult(env->object->rotation, q)));
	}
	if (mouse_released(inputs->mouse, MOUSE_MIDDLE))
	{
		ft_putendl("mouse released");
		delta = v2_substract(inputs->mouse_pos, inputs->click_pos);
		q = euler_to_quat(init_vec3(delta.y, delta.x, 0));
		env->object->rotation = quat_mult(env->object->rotation, q);
	}
	return (quat_to_mtx(env->object->rotation));
}

int		update(void *args)
{
	t_env	*env;
	int		success;
	char	info[512];
	t_quat	q;
	t_mtx4	matrix;

	env = (t_env*)args;

	update_input(env);

	glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// set_uniform_float(env->shader_program, "test", sin(get_time()) / 2.0f + 0.5f);
	// matrix = mtx_translation(init_vec3(0, 0, 0));
	matrix = update_mvt(env);
	set_uniform_mat4(env->opengl.shader_program, "transform", (float*)&matrix);
	glBindVertexArray(env->opengl.vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	// glDrawE(GL_TRIANGLES, 0, 3);
	mlx_opengl_swap_buffers(env->window.ptr);
	env->inputs.mouse.released_mask = 0;
	return 1;
}
