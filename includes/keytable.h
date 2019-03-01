/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keytable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:04:53 by gmichaud          #+#    #+#             */
/*   Updated: 2019/03/01 15:42:44 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYTABLE_H
# define KEYTABLE_H

# include "libft.h"
# include "stdbool.h"

# define KT_SIZE 100

typedef struct		s_entry
{
	int				key;
	bool			ispressed;
	int				released_frame;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_keytable
{
	unsigned int 	size;
	t_entry			**table;
}					t_keytable;

t_keytable			*kt_create(unsigned int size);
void				kt_delete(t_keytable **kt);

bool				kt_updatekey(t_keytable *kt, unsigned int key, bool ispressed);
bool				kt_pressed(t_keytable *kt, unsigned int key);
bool				kt_released(t_keytable *kt, unsigned int key);

unsigned int		hashkey(t_keytable *kt, unsigned int key);


#endif
