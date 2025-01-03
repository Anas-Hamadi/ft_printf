/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:47:38 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:25:28 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int	process_id(va_list ap, t_format* options)
{
	int sign;
	bool plus_flag;
	bool blank_flag;

	blank_flag = 0;
	plus_flag = 0;
	sign = 0;
	options->ndi = va_arg(ap, int);
	if (options->ndi < 0)
		sign = 1;
	if ((options->plus || options->blank) && (!sign))
		plus_flag = 1;
	else if (options->blank && !options->plus && !sign)
		blank_flag = 1;
	set_width_precision(options, sign, nbr_length(options->ndi, sign), 0);
	if (!options->precision && !options->leftAdjust)
		if (options->pad)
			dynamic_zero_padding(1,options,plus_flag,blank_flag);
		else
			dynamic_zero_padding(0,options,plus_flag,blank_flag);
	else
		print_p_w(options, sign, plus_flag, blank_flag);
}

void	apply_width_padding(t_format * l)
{
		while (l->width_spaces-- > 0 && (l->printed++))
			write(1, " ", 1);
}

void	print_p_w(t_format * l, bool sign, bool plus_flag, bool blank_flag)
{
	if (!l->leftAdjust)
		apply_width_padding(l);
	if (sign && (l->printed++))
		write(1, "-", 1);
	else if (plus_flag && (l->printed++))
		write(1, "+", 1);
	else if (blank_flag && (l->printed++))
		write(1, " ", 1);
	while (l->precsion_zeros-- > 0 && (l->printed++))
		write(1, "0", 1);
	l->printed += ft_putnbr(l->ndi);
	if (l->leftAdjust)
		apply_width_padding(l);
}

void	dynamic_zero_padding(bool valid_zero_padding, t_format* l, bool plus_flag, bool blank_flag)
{
	int	sign;

	sign = 0;

	if (l->ndi < 0)
		sign = 1;
	if (valid_zero_padding)
	{
		if(sign && (l->printed++))
			write(1, "-", 1);
		else if (plus_flag && (l->printed++))
			write(1, "+", 1);
		else if (blank_flag && (l->printed++))
			write(1, " ", 1);
		while (l->width_zeros-- > 0 && (l->printed++))
			write(1, "0", 1);
		l->printed += ft_putnbr(l->ndi);
	}
	else
		print_p_w(l, sign, plus_flag, blank_flag);
}
