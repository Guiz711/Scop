/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:40:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/05/24 19:38:33 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "obj_parser.h"

float g_vertices[] = {
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f
};

unsigned int indices[] = {
	0, 1, 3,
	1, 2, 3
};

void		free_dblarray(void ***ptr)
{
	int	i;

	i = 0;
	if (ptr && *ptr)
	{
		while ((*ptr)[i])
			free((*ptr)[i++]);
		free (*ptr);
		*ptr = NULL;
	}
}

int 		parse_vertex(char *definition, t_vertex_array *vert)
{
	char		*token;
	t_vertex	vertex;
	int			len;

	while ((token = strsep(&definition, " ")))
	{
		if (len >= 3)
			break;
		vertex.pos.elem[len] = atof(token);
		++len;
	}
	if (len < 3)
		return (-1);
	vert->data = realloc(vert->data, (vert->size + 1) * sizeof(t_vertex));
	vert->data[vert->size] = vertex;
	++vert->size;
	return (0);
}

int 		parse_face(char *definition, t_vertex_array *indices)
{
	char		*token;
	t_vec4		face;
	int			len;

	while ((token = strsep(&definition, " ")))
	{
		if (len >= 4)
			break;
		face.elem[len] = atof(token);
		++len;
	}
	if (len < 3)
		return (-1);
	if (len == 3)
	{
		indices->data = realloc(indices->data, (indices->size + 1) * sizeof(t_vertex));
		indices->data[indices->size].pos = init_vec3(face.x, face.y, face.z);
		++indices->size;
	}
	else
	{
		indices->data = realloc(indices->data, (indices->size + 2) * sizeof(t_vertex));
		indices->data[indices->size].pos = init_vec3(face.x, face.y, face.z);
		indices->data[indices->size + 1].pos = init_vec3(face.y, face.z, face.w);
		indices->size += 2;
	}
	return (0);
}

t_tkn_types	find_definition_type(char *token)
{
	if (!strcmp(token, "v"))
		return (vertex);
	if (!strcmp(token, "f"))
		return (face);
	return (none);
}

int		parse_definition(char *definition, t_object *obj)
{
	char		*token;
	t_tkn_types	type;

	token = strsep(&definition, " ");
	if (token)
	{
		type = find_definition_type(token);
		if (type == vertex)
			parse_vertex(definition, &obj->vertices);
		else if (type == face)
			parse_face(definition, &obj->indices);
	}
	return 0;
}

t_object	*init_object(void)
{
	t_object	*obj;
	int			i;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (NULL);
	// if (!(obj->vertices.data = (t_vertex*)malloc(sizeof(t_vertex) * (sizeof(g_vertices) / 3))))
	// {
	// 	free(obj);
	// 	return (NULL);
	// }
	// i = 0;
	// while (i < 4)
	// {
	// 	obj->vertices.data[i].pos = init_vec3(g_vertices[i * 3], g_vertices[i * 3 + 1], g_vertices[i * 3 + 2]);
	// 	++i;
	// }
	// if (!(obj->indices.data = (unsigned int*)malloc(sizeof(unsigned int) * 6)))
	// 	return (NULL);
	// i = 0;
	// while (i < 6)
	// {
	// 	obj->indices.data[i] = indices[i];
	// 	++i;
	// }
	obj->vertices.size = 0;
	obj->indices.size = 0;
	// obj->mtx = mtx_identity();
	obj->rotation = quat_identity();
	return (obj);
}

int		parse_obj_file(char *file_name)
{
	char		*original;
	char		*rawdata;
	char		*line;
	t_object	*obj;

	if (!(rawdata = read_file(file_name)))
		return (0);
	original = rawdata;
	obj = init_object();
	line  = NULL;
	while ((line = strsep(&rawdata, "\n")))
	{
		parse_definition(line, obj);
	}
	free(original);
	return (1);
}

char		*read_file(char *file_name)
{
	FILE	*file;
	size_t	len;
	size_t	ret;
	char	*content;

	if (!(file = fopen(file_name, "r")))
		return (NULL);
	fseek(file, 0, SEEK_END);
	len = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (!(content = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if ((ret = fread(content, 1, len, file)) != len)
	{
		free(content);
		return (NULL);
	}
	fclose(file);
	return (content);
}
