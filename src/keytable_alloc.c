/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:01:35 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 19:05:29 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keytable.h"

static void		delete_entries(t_entry **list)
{
	t_entry	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = *list;
			*list = (*list)->next;
			free(tmp);
		}
		*list = NULL;
	}
}

void			kt_delete(t_keytable **kt)
{
	unsigned int	i;

	if (kt)
	{
		i = 0;
		while (i < (*kt)->size)
		{
			delete_entries(&(*kt)->table[i]);
			++i;
		}
		free((*kt)->table);
		free(*kt);
		*kt = NULL;
	}
}

t_keytable		*kt_create(unsigned int size)
{
	t_keytable *new;

	if (size == 0)
		size = DEFAULT_SIZE;
	if (!(new = (t_keytable*)malloc(sizeof(t_keytable))))
		return (NULL);
	if (!(new->table = (t_entry**)ft_memalloc(sizeof(t_entry*) * size)))
	{
		free(new);
		return (NULL);
	}
	new->size = size;
	return (new);
}
