/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:40:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/09/26 18:11:48 by gmichaud         ###   ########.fr       */
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
# include "obj_parser.h"

#define WIN_W 1440
#define WIN_H 750

typedef struct		s_opengl
{
	uint32_t		vao;
	uint32_t		vbo;
	uint32_t		ebo;
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

typedef struct		s_vertex
{
	t_vec3			pos;
	t_vec3			color;
	t_vec3			tex;
}					t_vertex;

typedef struct		s_vertex_array
{
	t_vertex		*data;
	size_t			size;
}					t_vertex_array;

typedef struct		s_faces_array
{
	t_vec3i			*data;
	size_t			size;
}					t_faces_array;

typedef struct		s_object
{
	t_vertex_array	vertices;
	// t_faces_array	indices;
	t_mtx4			model;
	t_quat			rotation;
}					t_object;

typedef struct		s_env
{
	t_window		window;
	t_opengl		opengl;
	t_input			inputs;
	t_object		*object;
	t_mtx4			view;
	t_mtx4			projection;
}					t_env;

t_object			*init_object(void);
int					update(void *args);
int					init_env(t_env *env, char *file);

t_vec3_lst			*vec3f_lst_new(t_vec3 content);
t_vec3_lst			*vec3i_lst_new(t_vec3i content);
void				vec3_lst_add(t_vec3_lst **lst, t_vec3_lst *new);
void				vec3_lst_del(t_vec3_lst **lst);

t_object			*parse_obj_file(char *file_name);

int					mouse_move(int x, int y, void *args);
int					key_press(int keycode, void *args);
int					key_release(int keycode, void *args);
int					mouse_press(int button, int x, int y, void *args);
int					mouse_release(int button, int x, int y, void *args);

bool				mouse_pressed(t_mouse mouse, unsigned int button);
bool				mouse_released(t_mouse mouse, unsigned int button);
bool				mouse_just_pressed(t_mouse mouse, unsigned int button);

void				quit(void *env);

#endif
