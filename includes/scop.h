/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:40:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 20:38:40 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPE_H
# define SCOPE_H

# include <OpenGL/gl3.h>
# include "libft.h"
# include <stdio.h>
# include <time.h>
# include "mlx.h"
# include "error.h"
# include "mlx_opengl.h"
# include "libftmath.h"
# include "keytable.h"
# include "shader.h"
# include "mlx_events.h"

typedef struct		s_opengl
{
	uint32_t		vao;
	uint32_t		vbo;
	uint32_t		shader_program;
}					t_opengl;

typedef struct		s_mouse
{
	char			pressed_mask;
	char			released_mask;
}					t_mouse;

typedef struct		s_input
{
	t_vec2			mouse_pos;
	t_vec2			click_pos;
	t_keytable		*keys;
	t_mouse			mouse;
}					t_input;

typedef struct		s_window
{
	void			*init;
	void			*ptr;
	int				width;
	int				height;
}					t_window;

typedef struct		s_vertice
{
	t_vec3			pos;
	t_vec3			color;
}					t_vertice;

typedef struct		s_object
{
	t_vertice		*vertices;
	size_t			size;
	// t_mtx4			mtx;
	t_quat			rotation;
}					t_object;

typedef struct		s_env
{
	t_window		window;
	t_opengl		opengl;
	t_input			inputs;
	t_object		*object;
}					t_env;

t_object			*init_object(void);
int					update(void *args);
int					init_env(t_env *env);

int					mouse_move(int x, int y, void *args);
int					key_press(int keycode, void *args);
int					key_release(int keycode, void *args);
int					mouse_press(int button, int x, int y, void *args);
int					mouse_release(int button, int x, int y, void *args);

#endif
