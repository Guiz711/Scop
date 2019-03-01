/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:09:25 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 20:06:54 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		init_window(t_window *window, int width, int height)
{
	window->width = width;
	window->height = height;
	if (!(window->init = mlx_init()))
		return (0);
	if (!(window->ptr = mlx_new_opengl_window(window->init,
		width, height, "SCOP")))
		return (0);
	mlx_opengl_window_set_context(window->ptr);
	return (1);
}

int		init_inputs(t_input *inputs)
{
	inputs->click_pos = init_vec2(0.0f, 0.0f);
	inputs->mouse_pos = init_vec2(0.0f, 0.0f);
	if (!(inputs->keys = kt_create(KT_SIZE)))
		return (0);
	if (!(inputs->mouse = kt_create(KT_SIZE)))
		return (0);
	return (1);
}

int		init_shaders(uint32_t *shader_program)
{
	if (!(*shader_program = init_shader("./src/shaders/vertex_shader.vert", 0)))
		return (0);
	if (!init_shader("./src/shaders/fragment_shader.frag", *shader_program))
		return (0);
	if (!link_shader_program(*shader_program))
		return (0);
	return (1);
}

int		init_opengl(t_opengl *opengl, t_object *object)
{
	// unsigned int ebo;

	init_shaders(&opengl->shader_program);
	glGenVertexArrays(1, &(opengl->vao));
	glGenBuffers(1, &opengl->vbo);
	// glGenBuffers(1, &ebo);
	glBindVertexArray(opengl->vao);
	glBindBuffer(GL_ARRAY_BUFFER, opengl->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertice) * object->size, object->vertices, GL_STATIC_DRAW);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glUseProgram(opengl->shader_program);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
	// glBindVertexArray(0);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	return (1);
}

int		init_env(t_env *env)
{
	if (!init_window(&env->window, 1080, 920))
		return (0);
	if (!init_inputs(&env->inputs))
		return (0);
	if (!(env->object = init_object()))
		return (0);
	if (!init_opengl(&env->opengl, env->object))
		return (0);
	return (1);
}
