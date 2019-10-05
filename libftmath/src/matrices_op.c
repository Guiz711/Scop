/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:20:46 by gmichaud          #+#    #+#             */
/*   Updated: 2019/10/05 14:59:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

/*
** ft_mtx_mult(t_mtx4 mtx1, t_mtx4 mtx2) : Multiplies two matrices together.
** mtx1 * mtx2 is the order of the operation.
** returns a t_mtx4 matrix containing the matricial product mtx1 * mtx2.
*/

t_mtx4			mtx4_mult(t_mtx4 lhs, t_mtx4 rhs)
{
	t_mtx4	result;
	int		col;
	int		row;
	int		cur;
	float	sum;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			cur  = 0;
			sum = 0;
			while (cur < 4)
			{
				sum += lhs.elem[cur][row] * rhs.elem[col][cur];
				++cur;
			}
			result.elem[col][row] = sum;
			++row;
		}
		++col;
	}
	return (result);
}

t_mtx4	mtx_transpose(t_mtx4 matrix)
{
	t_mtx4	result;
	int		col;
	int		row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			result.elem[row][col] = matrix.elem[col][row];
			++row;
		}
		++col;
	}
	return (result);
}

t_mtx4	mtx_add(t_mtx4 lhs, t_mtx4 rhs)
{
	t_mtx4	result;
	int		col;
	int		row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			result.elem[col][row] = lhs.elem[col][row] + rhs.elem[col][row];
			++row;
		}
		++col;
	}
	return (result);
}

t_mtx4	mtx_sub(t_mtx4 lhs, t_mtx4 rhs)
{
	t_mtx4	result;
	int		col;
	int		row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			result.elem[col][row] = lhs.elem[col][row] - rhs.elem[col][row];
			++row;
		}
		++col;
	}
	return (result);
}
