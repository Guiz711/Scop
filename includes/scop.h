/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:40:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 19:06:26 by gmichaud         ###   ########.fr       */
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
# include "libftmath.h"

typedef enum		e_events
{
	ESC = 1 << 0,
	ROTATION_TRIGGER = 1 << 1,
	TRANSLATION_TRIGGER = 1 << 2,
	ZOOM_TRIGGER = 1 << 3,
}					t_events;

typedef struct		s_opengl
{
	uint32_t		vao;
	uint32_t		vbo;
	uint32_t		shader_program;
}					t_opengl;

typedef struct		s_input
{
	t_vec2			mouse_pos;
	t_vec2			click_pos;
	
}

typedef struct		s_env
{
	void			*init;
	void			*win;
	int				win_width;
	int				win_height;
	t_vec2			mouse_pos;
	bool			quit;
	int				middle;
}					t_env;

#endif
