/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:40:44 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/29 20:48:29 by gmichaud         ###   ########.fr       */
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

int 		parse_vertex(t_object *obj)
{
	
}

t_tkn_types	find_definition_type(char *token)
{
	if (strcmp())
}

int		parse_definition(char *definition)
{
	char	**tokens;
	int		type;

	if (!(definition = ft_strtrim(definition)))
		return (0);
	if (!(tokens = ft_strsplit(definition, ' ')))
		return (0);
	if (tokens[0])
	{

	}
}

int		parse_obj_file(char *file_name)
{
	char	*rawdata;
	char	*definition;
	int		i;

	if (!(rawdata = read_file(file_name)))
		return (0);
	i = 0;
	while (strsep(rawdata, ""))
	{
		parse_definition(definitions[i]);
		++i;
	}
	free(rawdata);
	free_dblarray(&definitions);
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

t_object	*init_object(void)
{
	t_object	*obj;
	int			i;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (NULL);
	if (!(obj->vertices.data = (t_vertex*)malloc(sizeof(t_vertex) * (sizeof(g_vertices) / 3))))
	{
		free(obj);
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		obj->vertices.data[i].pos = init_vec3(g_vertices[i * 3], g_vertices[i * 3 + 1], g_vertices[i * 3 + 2]);
		++i;
	}
	if (!(obj->indices.data = (unsigned int*)malloc(sizeof(unsigned int) * 6)))
		return (NULL);
	i = 0;
	while (i < 6)
	{
		obj->indices.data[i] = indices[i];
		++i;
	}
	obj->vertices.size = 4;
	obj->indices.size = 6;
	// obj->mtx = mtx_identity();
	obj->rotation = quat_identity();
	return (obj);
}
