/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:35:22 by gmichaud          #+#    #+#             */
/*   Updated: 2019/05/24 17:42:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define VERTEX_PREFIX "v "
# define FACE_PREFIX "f "

typedef enum	e_tkn_types
{
	none,
	vertex,
	normal,
	texture,
	face
}				t_tkn_types;

char		*read_file(char *file_name);

#endif
