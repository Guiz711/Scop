/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 10:48:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/20 12:16:56 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

# include <OpenGL/gl3.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "error.h"

/*
** int init_shader(char *file, int shader_program)
**
** Reads a shader source file, compiles shader and attach it
** to the shader program.
** If no shader program exists, creates a shader program.
**
** PARAMS:
** - A char array containing the path to the shader source file.
** - The ID of the shader program on which you want to attach the shader, or 0
** if you want to create a new program.
**
** RETURN: The ID of the shader program or 0 if an error occurred.
*/

int		init_shader(char *file, int shader_program);

/*
** int link_shader_program(int program_id)
**
** Links a shader program.
**
** PARAMS: The ID of the shader program to link
**
** RETURN: 1 if success, 0 if failure
*/

int		link_shader_program(int program_id);

/*
** Error handling
*/

# define VERT_SHADER_EXT ".vert"
# define FRAG_SHADER_EXT ".frag"

# define SHD_ERR RED "SHADER ERROR: " RESET
# define SHD_ERR_NO_EXT SHD_ERR "No file extension\n"
# define SHD_ERR_UNK_EXT SHD_ERR "Unknown file extension " YEL "%s\n" RESET
# define SHD_ERR_VERT_EXT YEL "%s" RESET " for vertex shaders"
# define SHD_ERR_FRAG_EXT YEL "%s" RESET " for fragment shaders"
# define SH_ERR_EXT "Please use " SHD_ERR_VERT_EXT " or " SHD_ERR_FRAG_EXT "\n"
# define SHD_ERR_CREATE SHD_ERR "glCreateShader failed\n"
# define PRG_ERR_CREATE SHD_ERR "glCreateProgram failed\n"

int		shader_error(int shader_id);
int		shader_extension_error(char *extension);
int		shader_program_error(int program_id);
void	set_uniform_int(int program_id, const char *name, int value);
void	set_uniform_float(int program_id, const char *name, float value);
void	set_uniform_mat4(int program_id, const char *name, float *transform);

#endif
