/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:35:58 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/04 19:49:45 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <stdio.h>

void	*malloc_error(void *ptr);
int		malloc_error_int(void *ptr);
void	*throw_error(void *ptr, char *str);
int		custom_error_int(void *ptr, const char *err);

#endif