/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:40:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/06 16:20:43 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPE_H
# define SCOPE_H

# include <OpenGL/gl3.h>
# include "libft.h"
# include <stdio.h>
# include <time.h>
# include "mlx.h"
# include "mlx_opengl.h"

typedef struct		s_env
{
	void			*init;
	void			*win;
	int				win_width;
	int				win_height;
	unsigned int	vao;
	int				shader_program;
}					t_env;

#endif