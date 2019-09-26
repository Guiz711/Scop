/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:58:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/09/25 15:10:42 by gmichaud         ###   ########.fr       */
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
	mlx_hook(env.window.ptr, DESTROY_NOTIFY, 0L, quit, (void*)&env);
	mlx_hook(env.window.ptr, MOTION_NOTIFY, POINTER_MOTION_MASK, mouse_move, (void*)&env);
	mlx_hook(env.window.ptr, KEY_PRESS, KEY_PRESS_MASK, key_press, (void*)&env);
	mlx_hook(env.window.ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release, (void*)&env);
	mlx_hook(env.window.ptr, BUTTON_PRESS, BUTTON_PRESS_MASK, mouse_press, (void*)&env);
	mlx_hook(env.window.ptr, BUTTON_RELEASE, BUTTON_RELEASE_MASK, mouse_release, (void*)&env);
	mlx_loop_hook(env.window.init, &update, (void*)&env);
	mlx_loop(env.window.init);
	return (0);
}
