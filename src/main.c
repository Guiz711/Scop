/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:58:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 17:54:16 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "shader.h"
#include "mlx_events.h"

const char* vertex_shader = "#version 410 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n\0";

const char* fragment_shader = "#version 410 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

float vertices[] = {
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

// float matrix[] = {
// 	1, 0, 0, 0,
// 	0, 1, 0, 0,
// 	0, 0, 1, 0,
// 	0.5, 0, 0, 1
// };

// t_mtx4 matrix = {
// 	{1, 0, 0, 0},
// 	{0, 1, 0, 0},
// 	{0, 0, 1, 0},
// 	{0.5, 0, 0, 1}
// };

// unsigned int indices[] = {
// 	0, 1, 2
// };

int		init_env(t_env *env)
{
	env->win_height = 920;
	env->win_width = 1080;
	env->quit = false;
	env->middle = 0;
	env->mouse_pos = init_vec2(0, 0);
	if (!(env->init = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_opengl_window(env->init, env->win_width,
		env->win_height, "scop")))
		return (0);
	mlx_opengl_window_set_context(env->win);
	return (1);
}

int compile_vertex_shader()
{
	int				vs;
	int				success;
	char			info[512];

	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vs, 512, NULL, info);
		printf("%s", info);
		return (-1);
	}
	return vs;
}

int compile_fragment_shader()
{
	int				fs;
	int				success;
	char			info[512];

	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fs, 512, NULL, info);
		printf("%s", info);
		return (-1);
	}
	return fs;
}

// float get_time()
// {
// 	static clock_t	begin = 0;
// 	clock_t			end;

// 	if (begin == 0)
// 		begin = clock();
// 	end = clock();
// 	return((float)(end - begin) / CLOCKS_PER_SEC);
// }

double	get_time(void)
{
	struct timespec curTime;

	clock_gettime(CLOCK_MONOTONIC, &curTime);
	return curTime.tv_sec + curTime.tv_nsec * 1e-9;
}

void init_opengl(t_env *env)
{
	// unsigned int ebo;

	glGenVertexArrays(1, &(env->vao));
	glGenBuffers(1, &env->vbo);
	// glGenBuffers(1, &ebo);
	glBindVertexArray(env->vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glUseProgram(env->shader_program);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
	// glBindVertexArray(0);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int init_shaders(t_env *env)
{
	int				vs;
	int				fs;
	int				success;
	char			info[512];

	if((vs = compile_vertex_shader()) == -1)
		return (-1);
	if((fs = compile_fragment_shader()) == -1)
		return (-1);
	env->shader_program = glCreateProgram();
	glAttachShader(env->shader_program, vs);
	glAttachShader(env->shader_program, fs);
	glLinkProgram(env->shader_program);
	glGetProgramiv(env->shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(env->shader_program, 512, NULL, info);
		printf("%s", info);
		return 0;
	}
	glDeleteShader(vs);
	glDeleteShader(fs);
	return 1;
}

void quit(t_env *env)
{
	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	mlx_destroy_window(env->init, env->win);
	exit(EXIT_SUCCESS);
}

int mouse_move(int x, int y, void *param)
{
	((t_env*)param)->mouse_pos.x = x;
	((t_env*)param)->mouse_pos.y = x;
	return (0);
}

int key_press(int keycode, void *param)
{
	if (keycode == KEY_ESCAPE)
	{
		((t_env*)param)->quit = true;
	}
	return (0);
}

int mouse_press(int button, int x, int y, void *param)
{
	if (button == MOUSE_MIDDLE)
	{
		((t_env*)param)->middle = 1;
	}
	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{
	if (button == MOUSE_MIDDLE)
	{
		((t_env*)param)->middle = 0;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_env					env;

	// if (argc != 2)
	// {
	// 	ft_putstr("Usage: ./scop docname\n");
	// 	return (0);
	// }

	init_env(&env);
	env.shader_program = init_shader("./src/shaders/vertex_shader.vert", 0);
	if (!env.shader_program)
		return (0);
	if (!init_shader("./src/shaders/fragment_shader.frag", env.shader_program))
		return (0);
	if (!link_shader_program(env.shader_program))
		return (0);
	init_opengl(&env);
	mlx_hook(env.win, MOTION_NOTIFY, 0, mouse_move, (void*)&env);
	mlx_hook(env.win, KEY_PRESS, 0, key_press, (void*)&env);
	mlx_hook(env.win, BUTTON_PRESS, 0, mouse_press, (void*)&env);
	mlx_hook(env.win, BUTTON_RELEASE, 0, mouse_release, (void*)&env);
	mlx_loop_hook(env.init, &loop, (void*)&env);
	mlx_loop(env.init);
	return (0);
}
