/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:50:31 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 17:53:34 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	update_input(t_env *env)
{
	if (env->quit)
	{
		quit(env);
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



	q = euler_to_quat(init_vec3(0, 0, 0));
	if (env->middle)
	{
		q = euler_to_quat(init_vec3(0, 0, (float)env->mouse_pos.x));
	}

	glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// set_uniform_float(env->shader_program, "test", sin(get_time()) / 2.0f + 0.5f);
	// matrix = mtx_translation(init_vec3(0, 0, 0));
	// matrix = mtx_scale(init_vec3(2, 1, 1));
	matrix = quat_to_mtx(q);
	set_uniform_mat4(env->shader_program, "transform", (float*)&matrix);
	glBindVertexArray(env->vao);
	// glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	mlx_opengl_swap_buffers(env->win);
	return 1;
}
