/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:07:58 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/02 16:13:04 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dispatch(t_format* l, va_list ap)
{
	if (l->specifier == 'd' || l->specifier == 'i')
		process_id(ap, l);
	if (l->specifier == 'u')
		process_u(ap, l);
	if (l->specifier == 'c')
		process_c(ap,l);
	if (l->specifier == 's')
		process_s(ap,l);
	if (l->specifier == 'p')
		process_p(ap, l);
	if (l->specifier == 'x')
		process_x(l, ap);
	if (l->specifier == 'X')
		process_x(l, ap);
}