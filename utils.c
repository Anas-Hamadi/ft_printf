/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:34:35 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 17:31:10 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char* s)
{
	if (!s)
		return 0;
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (*s)
		res = res * 10 + (*s++ - '0');
	return (res);
}

int	nbr_length(long n, int sign)
{
	int counter;

	counter = 0;
	while (n >= 10)
	{
		n /= 10;
		counter++;
	}
	return (counter + 1 + sign);
}

int	ft_putnbr(int n)
{
	long nbr;
	long temp;
	char c;
	int	counter;

	nbr = n;
	counter = 0;
	
	if (n < 0)
		nbr *= -1;
	temp = nbr;
	while (temp >= 10 && counter++ >= 0)
		temp /= 10;
	
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
	return (counter + 1);
}
void	ft_putchar(char c)
{
	if (!c)
		return;
	write(1, &c, 1);
}

int	ft_strlen(char* s)
{
	size_t	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i])
		i++;
	return (i);
}