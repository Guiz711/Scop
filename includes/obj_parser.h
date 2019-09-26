/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:35:22 by gmichaud          #+#    #+#             */
/*   Updated: 2019/09/26 16:45:30 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define VERTEX_PREFIX "v"
# define TEXCOORD_PREFIX "vt"
# define FACE_PREFIX "f"

typedef enum	e_tkn_types
{
	none,
	vertex,
	normal,
	texture,
	face
}				t_tkn_types;

typedef struct		s_vec3_lst
{
	t_vec3				dataf;
	t_vec3i				datai;
	struct s_vec3_lst	*next;
}					t_vec3_lst;

typedef struct		s_parser
{
	t_vec3_lst		*vertices;
	size_t			vertices_len;
	t_vec3_lst		*texcoords;
	size_t			texcoords_len;
	t_vec3_lst		*indices;
	size_t			indices_len;
}					t_parser;

char		*read_file(char *file_name);

#endif
