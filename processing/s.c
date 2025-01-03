/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:26 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:36:15 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_s(t_format* l, va_list ap)
{
	char *s;
	int	length;
	char* str;
	size_t	i;

	length = strlength(s);
	s = va_arg(ap, char*);
	i = 0;

	set_width_precision(l, 0, length,0);
	if (l->precision_width > length)
		print_s(l,s);
	else
	{
		str = (char*)malloc(sizeof(char) * l->precision_width);
		while (l->precision_width-- > 0)
			str[i] = s[i++];
		str[i] = '\0';
		print_s(l,str);
	}
	
}

void	print_s(t_format* l, char* s)
{
	if (l->leftAdjust)
	{
		l->printed += ft_putstr(s);
		apply_width_padding(l);
	}
	else
	{
		apply_width_padding(l);
		l->printed += ft_putstr(s);
	}
}

int	strlength(char* s)
{
	if (!s)
		return (0);
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
		
	return (counter);
}

int	ft_putstr(char* s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i++])
		write(1, &s[i], 1);
	return (i);
}
