/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:40:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 20:11:50 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float g_vertices[] = {
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

// void		print_vertices(t_vertice *vertices)
// {

// }

t_object	*init_object(void)
{
	t_object	*obj;
	int			i;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (NULL);
	if (!(obj->vertices = (t_vertice*)malloc(sizeof(t_vertice) * (sizeof(g_vertices) / 6))))
	{
		free(obj);
		return (NULL);
	}
	i = 0;
	while (i < 3)
	{
		obj->vertices[i].pos = init_vec3(g_vertices[i * 6], g_vertices[i * 6 + 1], g_vertices[i * 6 + 2]);
		obj->vertices[i].color = init_vec3(g_vertices[i * 6 + 3], g_vertices[i * 6 + 4], g_vertices[i * 6 + 5]);
		++i;
	}
	obj->size = 3;
	// obj->mtx = mtx_identity();
	obj->rotation = quat_identity();
	printf("%lu; %lu\n", sizeof(t_vertice) * obj->size, sizeof(g_vertices));
	return (obj);
}
