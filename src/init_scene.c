/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:40:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/05/30 18:50:17 by gmichaud         ###   ########.fr       */
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
	if (!(new = vec3_lst_new(vec)))
		return (-1);
	vec3_lst_add(&(parser->vertices), new);
	++(parser->vertices_len);
	return (0);
}

int 		parse_face(char *definition, t_parser *parser)
{
	char		*token;
	t_vec4		face;
	int			len;
	t_vec3_lst	*new;

	len = 0 ;
	while ((token = strsep(&definition, " ")))
	{
		if (len >= 4)
			break;
		face.elem[len] = atof(token);
		++len;
	}
	if (len < 3)
		return (-1);
	if (!(new = vec3_lst_new(init_vec3(face.x, face.y, face.z))))
		return (-1);
	vec3_lst_add(&(parser->indices), new);
	++(parser->indices_len);
	if (len > 3)
	{
		if (!(new = vec3_lst_new(init_vec3(face.y, face.z, face.w))))
			return (-1);
		vec3_lst_add(&(parser->indices), new);
		++(parser->indices_len);
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
	obj->indices.data = NULL;
	obj->indices.size = 0;
	obj->rotation = quat_identity();
	return (obj);
}

int		fill_object(t_object *obj, t_parser *parser)
{
	int			i;
	t_vec3_lst	*tmp;

	if (!(obj->vertices.data = malloc(sizeof(t_vertex) * parser->vertices_len)))
		return (-1);
	obj->vertices.size = parser->vertices_len;
	tmp = parser->vertices;
	i = parser->vertices_len - 1;
	while (i >= 0)
	{
		obj->vertices.data[i].pos = tmp->data;
		tmp = tmp->next;
		--i;
	}
	if (!(obj->indices.data = malloc(sizeof(t_vertex) * parser->indices_len)))
		return (-1);
	obj->indices.size = parser->indices_len;
	tmp = parser->indices;
	i = parser->indices_len - 1;
	while (i >= 0)
	{
		obj->indices.data[i].pos = tmp->data;
		tmp = tmp->next;
		--i;
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
	parser.vertices_len = 0;
	parser.indices_len = 0;
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
