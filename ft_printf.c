/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:06:02 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 19:56:02 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	check_flag(char c, t_format* l)
{
	if((!is_invalid_at_f(c)) && (l->invalid = 1))
		return 0;
	if (c == '-')
		l->leftAdjust = 1;
	else if (c == '0')
		l->pad = 1;
	else if (c == '#')
		l->hash = 1;
	else if (c== '+')
		l->plus = 1;
	else if (c== ' ')
		l->blank = 1;
	return (1);
}
void	parse_flags(char* f, t_format* l)
{
	while(*f)
		if (check_flag(*f++, l))
			if (l->invalid)
				return ;
}

void	parse_format(char* f, t_format* l)
{
	char*	tracker;
	
	while (*f++ != '%' && (l->printed++))
		write(1, f, 1);
	if (*f == '%')
	{
		tracker = f;
		if (*f == '%' && *(f+1) && *(f+1) != '%')
		{
			if (*++f == '#' || *f == '-' ||
				*f == '+' || *f == '0' || *f == ' ')
				parse_flags(f,l);
			else if ((*f >= '1' && *f <= '9'))	
				parse_width(f, l);
			else if (*f == '.')
				parse_precision(f,l);
			else if (*f == 'd' || *f == 'i' || *f == 'u' ||
				*f == 'x' || *f == 'X' || *f == 'c' || *f == 's')
				l->specifier = *f;
			else if(!is_invalid_at_f(*f))
				l->invalid = 1;
		}
	}
	if (l->invalid)
		print_at_invalid(tracker, l);
}

void	print_at_invalid(char* tracker, t_format* l)
{
	while (*tracker && *(tracker+1) != '%')
	{
		write(1, tracker, 1);
		l->printed++;
		tracker++;
	}
}

int ft_printf(const char * format, ...)
{
	if (!format)
		return 0;
	va_list ap;
	t_format l;

	va_start(ap, format);
	ft_memset(&l, 0, sizeof(l));
	while (*format)
	{
		parse_format(format++, &l);
		if (!l.invalid)
			dispatch(&l, ap);
		format++;
		ft_memset(&l, 0, sizeof(l));
	}
	return (l.printed);
}
