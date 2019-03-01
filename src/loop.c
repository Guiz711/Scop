/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:50:31 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 20:22:04 by gmichaud         ###   ########.fr       */
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
	static t_vec2	last_pos = {-1, -1};
	t_input	*inputs;
	t_quat	q;
	t_vec2	delta;

	inputs = &env->inputs;
	if (kt_pressed(inputs->keys, KEY_ESCAPE))
	{
		quit(env);
	}
	if (kt_pressed(inputs->mouse, MOUSE_MIDDLE))
	{
		delta = v2_substract(inputs->mouse_pos, last_pos);
		delta = v2_f_mult(delta, 0.5);
		q = euler_to_quat(init_vec3(delta.y, delta.x, 0));
		// ft_putendl("Coucou");
		// if (!quat_equal(q, last_rotation))
		// {
			// ft_putendl("Coucou2");
			// last_rotation = q;
			env->object->rotation = q;
		// }
	}
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
	matrix = quat_to_mtx(env->object->rotation);
	set_uniform_mat4(env->opengl.shader_program, "transform", (float*)&matrix);
	glBindVertexArray(env->opengl.vao);
	// glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	mlx_opengl_swap_buffers(env->window.ptr);
	return 1;
}
