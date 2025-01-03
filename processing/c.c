/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:49:10 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:31:38 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	process_c(t_format* l, va_list ap)
{
	char	c;
	
	c = va_arg(ap, char);
	set_width_precision(l, 0, 1,0);
	if (!l)
		return ;
	if (!l->leftAdjust)
		apply_width_padding(l);
	ft_putchar(c);
	l->printed++;
	if (l->leftAdjust)
		apply_width_padding(l);
}