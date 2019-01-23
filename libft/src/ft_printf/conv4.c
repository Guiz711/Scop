/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:25:14 by gmichaud          #+#    #+#             */
/*   Updated: 2018/12/31 16:41:51 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_hex_maj(va_list ap, t_options options)
{
	char			*conv;
	int				ret;
	unsigned int	nb;

	ret = 0;
	nb = va_arg(ap, unsigned int);
	if (!(conv = ft_lltoa_base((unsigned long long)nb, 16, 'X', options)))
		return (-1);
	if (options.precision == 0)
		conv[0] = '\0';
	if (options.flags & ALT && nb != 0 && options.precision != 0)
	{
		if ((options.flags & ZERO) == 0 || options.flags & PADD_RIGHT)
			ft_endcpy(&conv[2], conv, ft_strlen(conv) - 1);
		conv[0] = '0';
		conv[1] = 'X';
	}
	ret += print(conv, options);
	free(conv);
	return (ret);
}

int		conv_lhex_maj(va_list ap, t_options options)
{
	char			*conv;
	unsigned long	nb;
	int				ret;

	ret = 0;
	nb = va_arg(ap, unsigned long);
	if (!(conv = ft_lltoa_base((unsigned long long)nb, 16, 'X', options)))
		return (-1);
	if (options.precision == 0)
		conv[0] = '\0';
	if (options.flags & ALT && nb != 0 && options.precision != 0)
	{
		if ((options.flags & ZERO) == 0 || options.flags & PADD_RIGHT)
			ft_endcpy(&conv[2], conv, ft_strlen(conv) - 1);
		conv[0] = '0';
		conv[1] = 'X';
	}
	ret += print(conv, options);
	free(conv);
	return (ret);
}

int		conv_llhex_maj(va_list ap, t_options options)
{
	char				*conv;
	unsigned long long	nb;
	int					ret;

	ret = 0;
	nb = va_arg(ap, unsigned long long);
	if (!(conv = ft_lltoa_base(nb, 16, 'X', options)))
		return (-1);
	if (options.precision == 0)
		conv[0] = '\0';
	if (options.flags & ALT && nb != 0 && options.precision != 0)
	{
		if ((options.flags & ZERO) == 0 || options.flags & PADD_RIGHT)
			ft_endcpy(&conv[2], conv, ft_strlen(conv) - 1);
		conv[0] = '0';
		conv[1] = 'X';
	}
	ret += print(conv, options);
	free(conv);
	return (ret);
}

int		conv_hhex_maj(va_list ap, t_options options)
{
	char			*conv;
	unsigned short	nb;
	int				ret;

	ret = 0;
	nb = (unsigned short)va_arg(ap, int);
	if (!(conv = ft_lltoa_base((unsigned long long)nb, 16, 'X', options)))
		return (-1);
	if (options.precision == 0)
		conv[0] = '\0';
	if (options.flags & ALT && nb != 0 && options.precision != 0)
	{
		if ((options.flags & ZERO) == 0 || options.flags & PADD_RIGHT)
			ft_endcpy(&conv[2], conv, ft_strlen(conv) - 1);
		conv[0] = '0';
		conv[1] = 'X';
	}
	ret += print(conv, options);
	free(conv);
	return (ret);
}

int		conv_hhhex_maj(va_list ap, t_options options)
{
	char			*conv;
	unsigned char	nb;
	int				ret;

	ret = 0;
	nb = (unsigned char)va_arg(ap, int);
	if (!(conv = ft_lltoa_base((unsigned long long)nb, 16, 'X', options)))
		return (-1);
	if (options.precision == 0)
		conv[0] = '\0';
	if (options.flags & ALT && nb != 0 && options.precision != 0)
	{
		if ((options.flags & ZERO) == 0 || options.flags & PADD_RIGHT)
			ft_endcpy(&conv[2], conv, ft_strlen(conv) - 1);
		conv[0] = '0';
		conv[1] = 'X';
	}
	ret += print(conv, options);
	free(conv);
	return (ret);
}
