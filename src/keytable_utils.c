/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:13:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 19:05:32 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keytable.h"

unsigned int	hashkey(t_keytable *kt, unsigned int key)
{
	return (key % kt->size);
}

bool			kt_ispressed(t_keytable *kt, unsigned int key)
{
	unsigned int	hash;
	t_entry			*entry;

	hash = hashkey(kt, key);
	entry = kt->table[hash];
	while (entry->next)
	{
		if (entry->key == key)
		{
			return (entry->ispressed);
		}
		entry = entry->next;
	}
	return (false);
}
