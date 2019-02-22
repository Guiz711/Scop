/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:04:53 by gmichaud          #+#    #+#             */
/*   Updated: 2019/02/22 19:06:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYTABLE_H
# define KEYTABLE_H

# include "libft.h"
# include "stdbool.h"

# define DEFAULT_SIZE 100

typedef struct		s_entry
{
	int				key;
	bool			ispressed;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_keytable
{
	unsigned int 	size;
	t_entry			**table;
}					t_keytable;

unsigned int		hashkey(t_keytable *kt, unsigned int key);
bool				kt_ispressed(t_keytable *kt, unsigned int key);
t_keytable			*kt_create(unsigned int size);
bool				kt_updatekey(t_keytable *kt, unsigned int key,
	bool ispressed);
void				kt_delete(t_keytable **kt);
t_keytable			*kt_create(unsigned int size);


#endif
