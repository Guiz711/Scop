/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:58:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/05/30 18:53:11 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double	get_time(void)
{
	struct timespec curTime;

	clock_gettime(CLOCK_MONOTONIC, &curTime);
	return curTime.tv_sec + curTime.tv_nsec * 1e-9;
}

int main(int argc, char **argv)
{
	t_env					env;

	// if (argc != 2)
	// {
	// 	ft_putstr("Usage: ./scop docname\n");
	// 	return (0);
	// }

	init_env(&env, argv[1]);
	mlx_hook(env.window.ptr, MOTION_NOTIFY, 0, mouse_move, (void*)&env);
	mlx_hook(env.window.ptr, KEY_PRESS, 0, key_press, (void*)&env);
	mlx_hook(env.window.ptr, KEY_RELEASE, 0, key_release, (void*)&env);
	mlx_hook(env.window.ptr, BUTTON_PRESS, 0, mouse_press, (void*)&env);
	mlx_hook(env.window.ptr, BUTTON_RELEASE, 0, mouse_release, (void*)&env);
	mlx_loop_hook(env.window.init, &update, (void*)&env);
	mlx_loop(env.window.init);
	return (0);
}
