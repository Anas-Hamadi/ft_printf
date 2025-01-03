/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamadi <ahamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:59:09 by ahamadi           #+#    #+#             */
/*   Updated: 2025/01/02 16:29:00 by ahamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char*	ft_strdup(const char* s)
{
	if (!s)
		return (NULL);
	char*	dup;
	int	len;
	size_t i;

	i = 0;
	len = ft_strlen(s);
	dup = (char*)malloc(sizeof(char)* (len+1));
	if (!dup)
		return (NULL);
	while (s[i])
		dup[i] = s[i++];
	dup[i] = '\0';
	return (dup);
}

void	*ft_memset(void* s, int c, size_t n)
{
	if (!s)
		return (NULL);
	unsigned char*	p;
	p = (unsigned char*)s;

	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}