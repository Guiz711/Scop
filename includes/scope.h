/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:40:01 by gmichaud          #+#    #+#             */
/*   Updated: 2018/12/15 18:16:07 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPE_H
# define SCOPE_H

# include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h> 
#include <OpenGL/glu.h> 
#include <OpenGL/glext.h>
# include <stdio.h>
# include "mlx.h"
# include "mlx_opengl.h"

typedef struct		s_env
{
	void			*init;
	void			*win;
	int				win_width;
	int				win_height;
}					t_env;

#endif