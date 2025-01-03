/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:20:44 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 16:51:57 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_width(char* f, t_format* l)
{
	size_t	i;
	size_t j;
	char*	width;
	
	i = 0;
	j = 0;
	width = NULL;
	while ((f[i] >= '0' && f[i++] <= '9'))
		if(!is_invalid_at_w(f[i]) && (l->invalid = 0))
			return 0;
	width = (char*)malloc(sizeof(char)*i);
	width[i] = '\0';
	while (*f && i--)
		width[j++] = *f++;
	l->width = ft_atoi(width);
	free(width);
}

void	parse_precision(char* f, t_format* l)
{
	size_t	i;
	size_t	j;
	char*	precision;

	j = 0;
	i = 1;

	if ((f[i] >= '0' && f[i] <= '9'))
	{
		while ((f[i] >= '0' && f[i++] <= '9'))
			if (is_invalid_at_p(f[i]))
				l->invalid = 1;
				
		precision = (char*)malloc(sizeof(char) * i);
		precision[i] = '\0';
		while (++f && i--)
			precision[j++] = *f;
		l->precision = 1;
		l->precision_width = ft_atoi(precision);
		free(precision);
	}
	else if (is_invalid_at_p(f[i]))
		l->invalid = 1;
	else
		l->precision = 1;
}

void	parse_specifier(char* f, t_format* l)
{
	if (*f == 'd' || *f == 'i' || *f == 'u' ||
				 *f == 'x' || *f == 'X' || *f == 'c' || *f == 's')
			l->specifier = *f;
}

void	set_width_precision(t_format* l, bool sign, int arg_length, int hash)
{
	bool plus_flag;
	bool blank_flag;

	blank_flag = 0;
	plus_flag = 0;
	if ((l->plus || l->blank) && (!sign))
		plus_flag = 1;
	else if (l->blank && !l->plus && !sign)
		blank_flag = 1;
	l->width_spaces = l->width - l->precision_width - sign - plus_flag- blank_flag - hash;
	l->precsion_zeros = l->precision_width - arg_length + sign;
	l->width_zeros = l->width - arg_length - plus_flag - blank_flag - hash;
}
