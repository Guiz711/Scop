/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:48:41 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/08 12:43:51 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int mouse_move(int x, int y, void *args)
{
	t_env	*env;

	env = (t_env*)args; 
	env->inputs.mouse_pos.x = (float)x;
	env->inputs.mouse_pos.y = (float)y;
	return (1);
}

int key_press(int keycode, void *args)
{
	t_env	*env;

	env = (t_env*)args;
	kt_updatekey(env->inputs.keys, keycode, true);
	return (1);
}

int key_release(int keycode, void *args)
{
	t_env	*env;

	env = (t_env*)args;
	kt_updatekey(env->inputs.keys, keycode, false);
	return (1);
}

bool	mouse_pressed(t_mouse mouse, unsigned int button)
{
	return (mouse.pressed_mask & (1 << button));
}

bool	mouse_released(t_mouse mouse, unsigned int button)
{
	return (mouse.released_mask & (1 << button));
}

int mouse_press(int button, int x, int y, void *args)
{
	t_env	*env;

	env = (t_env*)args;
	env->inputs.mouse.pressed_mask |= (1 << button);
	// kt_updatekey(env->inputs.mouse, button, true);
	env->inputs.click_pos.x = (float)x;
	env->inputs.click_pos.y = (float)y;
	return (1);
}

int mouse_release(int button, int x, int y, void *args)
{
	t_env	*env;

	env = (t_env*)args;
	env->inputs.mouse.pressed_mask &= ~(1 << button);
	env->inputs.mouse.released_mask |= (1 << button);
	// kt_updatekey(env->inputs.mouse, button, false);
	return (1);
}
