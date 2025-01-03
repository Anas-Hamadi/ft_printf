/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:19:44 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:38:38 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_p(t_format* l, va_list ap)
{
	void* p;
	unsigned long add;
	bool plus_flag;
	bool blank_flag;

	p = va_arg(ap, void*);
	add = (unsigned long)p;
	blank_flag = 0;
	plus_flag = 0;
	 if (!p)
        add = ft_strdup("0");
    else
        add = convert_address(p);
	if ((l->plus || l->blank))
		plus_flag = 1;
	else if (l->blank && !l->plus)
		blank_flag = 1;
	set_width_precision(l, 0, ft_strlen(add), 0);
	if (!l->precision && !l->leftAdjust)
		if (l->pad)
			zero_padding_p(l,plus_flag,blank_flag, add);
		else
			print_p_w_p(l, plus_flag, blank_flag, add);
	else
		print_p_w_p(l, plus_flag, blank_flag, add);
}

void	zero_padding_p(t_format* l, bool plus_flag, bool blank_flag, char* add)
{
	if (plus_flag && (l->printed++))
		write(1, "+", 1);
	else if (blank_flag && (l->printed++))
		write(1, " ", 1);
	while (l->width_zeros-- > 0 && (l->printed++))
		write(1, "0", 1);
	write(1, add, ft_strlen(add));
	l->printed += ft_strlen(add);
}

void	print_p_w_p(t_format * l, bool plus_flag, bool blank_flag, char* add)
{
	if (!l->leftAdjust)
		apply_width_padding(l);
	if (plus_flag && (l->printed++))
		write(1, "+", 1);
	else if (blank_flag && (l->printed++))
		write(1, " ", 1);
	while (l->precsion_zeros-- > 0 && (l->printed++))
		write(1, "0", 1);
	write(1, add, ft_strlen(add));
	l->printed += ft_strlen(add);
	if (l->leftAdjust)
		apply_width_padding(l);
}

