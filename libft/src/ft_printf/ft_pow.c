/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 13:41:01 by mguerrea          #+#    #+#             */
/*   Updated: 2018/12/31 13:41:15 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_pow(int x, int y)
{
	if (!y)
		return (1);
	return (x * ft_pow(x, --y));
}
