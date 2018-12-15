/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:58:57 by gmichaud          #+#    #+#             */
/*   Updated: 2018/12/15 18:27:56 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

int		init_env(t_env *env)
{
	env->win_height = 920;
	env->win_width = 1080;
	if (!(env->init = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_opengl_window(env->init, env->win_width,
		env->win_height, "scop")))
		return (0);
	return (1);
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
	printf("%s\n", (char*)glGetString(GL_VERSION));
	mlx_loop(env.init);
	return (0);
}