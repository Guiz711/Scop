/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:58:31 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/05 15:40:43 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader.h"

int		shader_error(int shader_id)
{
	char	*err;
	int		len;

	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &len);
	if (!(err = (char*)malloc(sizeof(*err) * len)))
		return (malloc_error_int(NULL));
	glGetShaderInfoLog(shader_id, len, NULL, err);
	fprintf(stderr, RED "SHADER ERROR: " RESET "Compilation failed.\n%s", err);
	return (0);
}

int		shader_program_error(int program_id)
{
	char	*err;
	int		len;

	glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &len);
	if (!(err = (char*)malloc(sizeof(*err) * len)))
		return (malloc_error_int(NULL));
	glGetProgramInfoLog(program_id, len, NULL, err);
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}

int		shader_extension_error(char *extension)
{
	if (!extension || ft_strchr(extension, '/'))
		fprintf(stderr, SHD_ERR_NO_EXT);
	else
		fprintf(stderr, SHD_ERR_UNK_EXT, extension);
	fprintf(stderr, SH_ERR_EXT, VERT_SHADER_EXT, FRAG_SHADER_EXT);
	return (0);
}
