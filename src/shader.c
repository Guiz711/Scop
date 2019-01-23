/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:15:48 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/20 12:07:25 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader.h"

char		*init_read(int size, char *src)
{
	char	*str;

	if (!(str = ft_strnew(size)))
		return (malloc_error(NULL));
	return (ft_strcpy(str, src));
}

char		*extend_read(int size, char *src, char *dest)
{
	if (!(dest = realloc(dest, size + 1)))
		return (malloc_error(dest));
	return (ft_strcat(dest, src));
}

static char	*read_shader(const char* file)
{
	char	*shader;
	char	buffer[BUFF_SIZE + 1];
	int		tot_size;
	int		ret;
	int		fd;

	shader = NULL;
	tot_size = 0;
	if((fd = open(file, O_RDONLY)) == -1)
		return (throw_error(NULL, RED "OPEN SHADER ERROR" RESET));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tot_size += ret;
		if (!shader)
		{
			if (!(shader = init_read(tot_size, buffer)))
				return (NULL);
		}
		else if (!(shader = extend_read(tot_size, buffer, shader)))
			return (NULL);
	}
	close(fd);
	if (ret == -1)
		return (throw_error(shader, RED "READ SHADER ERROR" RESET));
	return (shader);
}

static int	compile_shader(char *shader_source, GLenum type)
{
	int				shader_id;
	int				success;

	if (!(shader_id = glCreateShader(type)))
		return (custom_error_int(shader_source, SHD_ERR_CREATE));
	glShaderSource(shader_id, 1, (const char**)&shader_source, NULL);
	ft_printf("test3 %s \n", shader_source);
	glCompileShader(shader_id);
	free(shader_source);
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success)
		return (shader_error(shader_id));
	return (shader_id);
}

static int	attach_shader(int shader_id, int shader_program)
{
	if (!shader_program)
	{
		if(!(shader_program = glCreateProgram()))
			return (custom_error_int(NULL, PRG_ERR_CREATE));
	}
	glAttachShader(shader_program, shader_id);
	return (shader_program);
}

/*
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

int		init_shader(char *file, int shader_program)
{
	char		*shader_source;
	char		*extension;
	int			shader_id;
	GLenum		shader_type;

	extension = ft_strrchr(file, '.');
	if (extension && !ft_strcmp(extension, VERT_SHADER_EXT))
		shader_type = GL_VERTEX_SHADER;
	else if (extension && !ft_strcmp(extension, FRAG_SHADER_EXT))
		shader_type = GL_FRAGMENT_SHADER;
	else
		return (shader_extension_error(extension));
	if (!(shader_source = read_shader(file)))
		return (0);
	ft_printf("test shader %s \n", shader_source);
	if (!(shader_id = compile_shader(shader_source, shader_type)))
		return (0);
	shader_program = attach_shader(shader_id, shader_program);
	glDeleteShader(shader_id);
	return (shader_program);
}

/*
** Links a shader program.
** 
** PARAMS: The ID of the shader program to link
**
** RETURN: 1 if success, 0 if failure
*/

int		link_shader_program(int program_id)
{
	int	success;

	glLinkProgram(program_id);
	glGetProgramiv(program_id, GL_LINK_STATUS, &success);
	if (!success)
		return (shader_program_error(program_id));
	return (1);
}

/*
** Set uniform values.
** 
** PARAMS: The ID of the shader program to link, the name of the uniform value,
** the value itself.
*/

void	set_uniform_int(int program_id, const char *name, int value)
{
	glUniform1i(glGetUniformLocation(program_id, name), value);
}

void	set_uniform_float(int program_id, const char *name, float value)
{
	glUniform1f(glGetUniformLocation(program_id, name), value);
}

void	set_uniform_mat4(int program_id, const char *name, float *transform)
{
	glUniformMatrix4fv(glGetUniformLocation(program_id, name), 1,
		GL_FALSE, transform);
}
