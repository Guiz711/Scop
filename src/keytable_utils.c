/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:13:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/08 15:50:26 by gmichaud         ###   ########.fr       */
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
	while (entry)
	{
		if (entry->key == key)
		{
			return (entry->ispressed);
		}
		entry = entry->next;
	}
	return (false);
}
