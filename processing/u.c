/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:50:09 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:27:44 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	unsigned int temp;
	char c;
	size_t	counter;

	counter = 0;
	temp = n;
	while (temp >= 10 && counter++ >= 0)
		temp /= 10;
	
	if (n >= 10)
		ft_putnbr_u(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
	return (counter + 1);
}

void	print_p_w_u(t_format * l)
{
	if (!l->leftAdjust)
		apply_width_padding(l);
	while (l->precsion_zeros-- > 0  && (l->printed++))
		write(1, "0", 1);
	l->printed += ft_putnbr_u(l->nu);
	if (l->leftAdjust)
		apply_width_padding(l);
}

void	zero_padding_u(t_format* l)
{
	while (l->width_zeros-- > 0 && (l->printed++))
		write(1, "0", 1);
	l->printed += ft_putnbr_u(l->nu);
}

int	process_u(va_list ap, t_format* l)
{	
	l->nu = va_arg(ap, unsigned);
	set_width_precision(l, 0, nbr_length(l->nu, 0), 0);
	if (!l->precision && !l->leftAdjust)
		if (l->pad)
			zero_padding_u(l);
		else
			print_p_w_u(l);
	else
		print_p_w_u(l);
}
