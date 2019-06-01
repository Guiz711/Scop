/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:59:58 by gmichaud          #+#    #+#             */
/*   Updated: 2019/06/01 13:45:49 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec3_lst	*vec3f_lst_new(t_vec3 content)
{
	t_vec3_lst	*new;

	if (!(new = malloc(sizeof(t_vec3_lst))))
		return NULL;
	new->dataf = content;
	new->next = NULL;
	return (new);
}

t_vec3_lst	*vec3i_lst_new(t_vec3i content)
{
	t_vec3_lst	*new;

	if (!(new = malloc(sizeof(t_vec3_lst))))
		return NULL;
	new->datai = content;
	new->next = NULL;
	return (new);
}

void		vec3_lst_add(t_vec3_lst **lst, t_vec3_lst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void		vec3_lst_del(t_vec3_lst **lst)
{
	t_vec3_lst	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
	}
}
