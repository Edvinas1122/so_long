/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:39:33 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/25 16:24:05 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*strcp(char *buf, char *buf2, int begin, int end)
{
	int	i;
	int	num;

	if (!buf)
	{
		return (buf2);
	}
	num = end - begin;
	i = 0;
	while (buf[i] && num)
	{
		if (buf[i] != '\n')
		{
			buf2[i + begin] = buf[i];
		}
		else
		{
			buf2[i + begin] = buf[i];
			buf2[i + begin + 1] = '\0';
			break ;
		}
		i++;
		num--;
	}
	return (buf2);
}

char	*strcp_pos(char *buf, char *buf2, int begin, int end)
{
	int	i;
	int	num;

	num = end - begin;
	if (num <= 0)
	{
		return (NULL);
	}
	i = 0;
	while (buf[i + begin] && num)
	{
		buf2[i] = buf[i + begin];
		i++;
		num--;
	}
	buf2[i] = '\0';
	return (buf2);
}

char	*allocate(char *buf2, t_buff buf_object)
{
	int	total;
	int	x;

	x = 0;
	total = buf_object.begin + buf_object.index + 2;
	if (!buf_object.buf && buf_object.begin == 0)
		return (NULL);
	buf2 = (char *)malloc(sizeof(char) * total);
	while (total)
	{
		buf2[x] = '\0';
		x++;
		total--;
	}
	return (buf2);
}

int	check_for_newline_n_null(char *buf)
{
	int	y;
	int	buf_len;

	buf_len = ft_strlen2(buf);
	y = 0;
	if (buf_len == 0)
	{
		return (0);
	}
	while (buf_len)
	{
		if (!buf[y] || buf[y] == '\n')
		{
			return (y);
		}
		y++;
		buf_len--;
	}
	return (-1);
}
