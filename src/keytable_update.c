/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:02:57 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 19:03:26 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keytable.h"

static t_entry	*create_entry(int key, bool ispressed)
{
	t_entry	*new;

	if (!(new = (t_entry*)malloc(sizeof(t_entry))))
		return (NULL);
	new->key = key;
	new->ispressed = ispressed;
	new->next = NULL;
	return (new);
}

static void		*add_entry(t_entry **list, t_entry *new)
{
	new->next = *list;
	*list = new;
}

bool			kt_updatekey(t_keytable *kt, unsigned int key, bool ispressed)
{
	unsigned int	hash;
	t_entry			*entry;

	hash = hashkey(kt, key);
	entry = kt->table[hash];
	while (entry->next)
	{
		if (entry->key == key)
		{
			entry->ispressed = ispressed;
			return (true);
		}
		entry = entry->next;
	}
	if (!(entry = create_entry(key, ispressed)))
		return (false);
	entry->next = kt->table[hash];
	kt->table[hash] = entry;
	return (true);
}
