/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:50:48 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/22 22:50:39 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	printhex(unsigned int n, int ct)
{
	int		last_digit;

	if (n > 15)
	{
		ct = printhex(n / 16, ct);
	}
	last_digit = n % 16;
	ct += write(1, &"0123456789abcdef"[last_digit], 1);
	return (ct);
}
