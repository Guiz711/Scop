/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:35:12 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/04 19:53:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	*malloc_error(void *ptr)
{
	if (ptr)
		free(ptr);
	ft_putstr_fd(RED "ERROR: " RESET "malloc failed\n", STDERR_FILENO);
	return (NULL);
}

int		malloc_error_int(void *ptr)
{
	if (ptr)
		free(ptr);
	ft_putstr_fd(RED "ERROR: " RESET "malloc failed\n", STDERR_FILENO);
	return (0);
}

void	*throw_error(void *ptr, char *str)
{
	if (ptr)
		free(ptr);
	perror(str);
	return NULL;
}

int		custom_error_int(void *ptr, const char *err)
{
	if (ptr)
		free(ptr);
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}
