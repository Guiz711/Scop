/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:40:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/10/05 14:53:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "obj_parser.h"

bool	CompareVertex(t_vertex v1, t_vertex v2)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (v1.pos.elem[i] != v2.pos.elem[i]
			|| v1.tex.elem[i] != v2.tex.elem[i])
			return (false);
	}
	return (true);
}

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

int 		parse_vertex(char *definition, t_parser *parser)
{
	char		*token;
	t_vec3		vec;
	int			len;
	t_vec3_lst	*new;

	len = 0 ;
	while ((token = strsep(&definition, " ")))
	{
		if (len >= 3)
			break;
		vec.elem[len] = atof(token);
		++len;
	}
	if (len < 3)
		return (-1);
	if (!(new = vec3f_lst_new(vec)))
		return (-1);
	vec3_lst_add(&(parser->vertices), new);
	++(parser->vertices_len);
	return (0);
}

int 		parse_texture(char *definition, t_parser *parser)
{
	char		*token;
	t_vec3		vec;
	int			len;
	t_vec3_lst	*new;

	len = 0 ;
	while ((token = strsep(&definition, " ")))
	{
		if (len >= 3)
			break;
		vec.elem[len] = atof(token);
		++len;
	}
	if (len < 3)
		return (-1);
	if (!(new = vec3f_lst_new(vec)))
		return (-1);
	vec3_lst_add(&(parser->texcoords), new);
	++(parser->texcoords_len);
	return (0);
}

int 		parse_face(char *definition, t_parser *parser)
{
	char		*token;
	t_vec4i		face;
	int			len;
	t_vec3_lst	*new;

	len = 0 ;
	while ((token = strsep(&definition, " ")))
	{
		if (len >= 4)
			break;
		face.elem[len] = atoi(token) - 1;
		++len;
	}
	if (len < 3)
		return (-1);
	if (!(new = vec3i_lst_new(init_vec3i(face.x, face.y, face.z))))
		return (-1);
	vec3_lst_add(&(parser->indices), new);
	++(parser->indices_len);
	if (len > 3)
	{
		if (!(new = vec3i_lst_new(init_vec3i(face.x, face.z, face.w))))
			return (-1);
		vec3_lst_add(&(parser->indices), new);
		++(parser->indices_len);
	}
	return (0);
}

t_tkn_types	find_definition_type(char *token)
{
	if (!strcmp(token, VERTEX_PREFIX))
		return (vertex);
	if (!strcmp(token, TEXCOORD_PREFIX))
		return (texture);
	if (!strcmp(token, FACE_PREFIX))
		return (face);
	return (none);
}

int		parse_definition(char *definition, t_parser *parser)
{
	char		*token;
	t_tkn_types	type;

	token = strsep(&definition, " ");
	if (token)
	{
		type = find_definition_type(token);
		if (type == vertex)
			parse_vertex(definition, parser);
		else if (type == texture)
			parse_texture(definition, parser);
		else if (type == face)
			parse_face(definition, parser);
	}
	return 0;
}

t_object	*init_object(void)
{
	t_object	*obj;
	int			i;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (NULL);
	obj->vertices.data = NULL;
	obj->vertices.size = 0;
	// obj->indices.data = NULL;
	// obj->indices.size = 0;
	obj->rotation = quat_identity();
	obj->model = mtx_identity();
	return (obj);
}

t_vec3	*get_vertices_array(t_vec3_lst *vert_lst, size_t len)
{
	t_vec3	*vertices;
	size_t	i;

	if (!(vertices = (t_vec3*)malloc(sizeof(t_vec3) * len)))
		return (NULL);
	i = len - 1;
	while (vert_lst)
	{
		vertices[i] = vert_lst->dataf;
		--i;
		vert_lst = vert_lst->next;
	}
	return (vertices);
}

int		fill_object(t_object *obj, t_parser *parser)
{
	t_vec3		*vertices;
	t_vec3_lst	*tmp;
	int			i;
	t_vec3		colors[5];

	colors[0] = init_vec3(0.1, 0.1, 0.1);
	colors[1] = init_vec3(0.3, 0.3, 0.3);
	colors[2] = init_vec3(0.5, 0.5, 0.5);
	colors[3] = init_vec3(0.7, 0.7, 0.7);
	colors[4] = init_vec3(0.9, 0.9, 0.9);
	if (!(vertices = get_vertices_array(parser->vertices, parser->vertices_len)))
		return (-1);
	if (!(obj->vertices.data = malloc(sizeof(t_vertex) * parser->indices_len * 3)))
		return (-1);
	obj->vertices.size = parser->indices_len * 3;
	tmp = parser->indices;
	i = obj->vertices.size - 1;
	while (tmp)
	{
		obj->vertices.data[i].pos = vertices[tmp->datai.z];
		obj->vertices.data[i].color = colors[i / 3 % 5];
		--i;
		obj->vertices.data[i].pos = vertices[tmp->datai.y];
		obj->vertices.data[i].color = colors[i / 3 % 5];
		--i;
		obj->vertices.data[i].pos = vertices[tmp->datai.x];
		obj->vertices.data[i].color = colors[i / 3 % 5];
		--i;
		tmp = tmp->next;
	}
	return (0);
}

t_object	*parse_obj_file(char *file_name)
{
	char		*original;
	char		*rawdata;
	char		*line;
	t_object	*obj;
	t_parser	parser;

	parser.vertices = NULL;
	parser.indices = NULL;
	parser.texcoords = NULL;
	parser.vertices_len = 0;
	parser.indices_len = 0;
	parser.texcoords_len = 0;
	if (!(rawdata = read_file(file_name)))
		return (NULL);
	original = rawdata;
	obj = init_object();
	line  = NULL;
	while ((line = strsep(&rawdata, "\n")))
	{
		parse_definition(line, &parser);
	}
	fill_object(obj, &parser);
	free(original);
	return (obj);
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
