/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:48:18 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/03 14:47:21 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


bool	is_invalid_at_f(char f)
{
	if (f != '#' && f != '-' &&
		f != '+' && f != ' ' && f != '0' &&
		(f < '0' || f > '9')
		&& f != '.' && f != 'd' && f != 'i' &&
		f != 'u' &&
		f != 'p' && f != 'x' && f != 'X' &&
		f != 'c' && f != 's')
		return (0);
	else
		return (1);
}

bool	is_invalid_at_w(char* f)
{
	while (*f++)
	{
		if ((*f < '0' && *f > '9') && *f != '.' &&
		 *f != 'd' && *f != 'i' && *f != 'u' &&
		 *f != 'p' && *f != 'x' && *f != 'X' &&
		  *f != 'c' && *f != 's')
		 	return (0);
		else
			return (1);		
	}
}
bool	is_invalid_at_p(char* f)
{
	while (*f++)
	{
		if ((*f < '0' && *f > '9') && *f != 'd' &&
		 *f != 'i' && *f != 'u' &&
		 *f != 'p' && *f != 'x' && *f != 'X' &&
		  *f != 'c' && *f != 's')
		 	return (0);
		else
			return (1);		
	}
}

