/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:07:38 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:41:22 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	process_x(t_format* l, va_list ap)
{
	unsigned int	n;
	char*	hex;
	int	len;
	
	n = va_arg(ap, unsigned int);
	hex = convert_hex(n, l->specifier);
	len = ft_strlen(hex);
	set_width_precision(l, 0, len, 2);
	if (!l->precision && !l->leftAdjust)
		if (l->pad)
			zero_padding_x(l, hex);
		else
			print_p_w_x(l, hex);
	else
		print_p_w_x(l, hex);
	free(hex);
}

void	zero_padding_x(t_format* l, char* hex)
{
	while (l->width_zeros-- > 0 && (l->printed++))
		write(1, "0", 1);
	if(l->hash && (l->printed += 2))
		write(1, "0x", 2);
	write(1, hex, ft_strlen(hex));
	l->printed += ft_strlen(hex);
}

void	print_p_w_x(t_format * l, char* hex)
{
	if (!l->leftAdjust)
		apply_width_padding(l);
	while (l->precsion_zeros-- > 0 && (l->printed++))
		write(1, "0", 1);
	if(l->hash && (l->printed += 2))
		write(1, "0x", 2);
	write(1, hex, ft_strlen(hex));
	l->printed += ft_strlen(hex);
	if (l->leftAdjust)
		apply_width_padding(l);
}

char*	convert_hex(unsigned int n, char x)
{
    char *hex_chars;
	char *add;
	size_t	i;
	unsigned int	nbr;
	
	add = (char*)malloc(sizeof(char)*16);
	nbr = n;
	i = 0;
    if (x == 'X')
        hex_chars = "0123456789ABCDEF";
    else
        hex_chars = "0123456789abcdef";
	while (nbr > 0 )
		nbr /= 16, i++;
	add[i--] = '\0';
	while (n > 0)
	{
		add[i--] = hex_chars[n % 16];
		n /= 16;
	}
	return (add);
}
