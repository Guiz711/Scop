/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:13:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 16:00:43 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keytable.h"

unsigned int	hashkey(t_keytable *kt, unsigned int key)
{
	return (key % kt->size);
}

bool			kt_pressed(t_keytable *kt, unsigned int key)
{
	unsigned int	hash;
	t_entry			*entry;

	hash = hashkey(kt, key);
	entry = kt->table[hash];
	// ft_putendl("start search");
	while (entry)
	{
		// ft_putendl("searching...");
		if (entry->key == key)
		{
			// ft_putendl("found");
			return (entry->ispressed);
		}
		entry = entry->next;
	}
	return (false);
}
