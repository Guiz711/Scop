/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:51:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/02 12:13:08 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strcat(char *dest, const char *src)
// {
// 	size_t len;
// 	size_t i;

// 	len = ft_strlen(dest);
// 	i = 0;
// 	while (src[i])
// 	{
// 		dest[len + i] = src[i];
// 		i++;
// 	}
// 	dest[len + i] = '\0';
// 	return (dest);
// }

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while (*tmp)
		++tmp;
	while(*src)
		*(tmp++) = *(src++);
	*tmp = '\0';
	return (dest);
}