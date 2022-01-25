/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:33:16 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/13 19:53:55 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buff	remainder_alloc(char *remainder)
{
	t_buff	buf_object;
	int		i;

	buf_object.begin = 0;
	buf_object.end = ft_strlen2(remainder);
	buf_object.buf = (char *)malloc(sizeof(char) * (buf_object.end + 1));
	i = buf_object.end;
	while (i > 0)
	{
		buf_object.buf[i] = '\0';
		i--;
	}
	buf_object.index = 0;
	buf_object.index = check_for_newline_n_null(remainder);
	if (buf_object.index == -1)
	{
		strcp_pos(remainder, buf_object.buf, 0, buf_object.end);
		free(remainder);
	}
	else
		strcp_pos(remainder, buf_object.buf, 0, buf_object.index + 1);
	return (buf_object);
}

t_buff	readbuff(int fd, int end)
{
	t_buff	buf_object;
	int		i;

	buf_object.buf = (char *)malloc(sizeof(char) * (4 + 1));
	i = 4;
	while (i > 0)
	{
		buf_object.buf[i] = '\0';
		i--;
	}
	buf_object.end = read(fd, buf_object.buf, 4);
	buf_object.index = 0;
	if (buf_object.end <= 0)
	{
		free(buf_object.buf);
		buf_object.buf = NULL;
		buf_object.begin = end;
		return (buf_object);
	}
	buf_object.end = end + buf_object.end;
	buf_object.begin = end;
	buf_object.index = check_for_newline_n_null(buf_object.buf);
	return (buf_object);
}

char	*ft_remainder(t_buff buf_object, char *remainder)
{
	char	*return_r;
	int		len;

	len = buf_object.end - buf_object.begin - buf_object.index - 1;
	if (len <= 0 || buf_object.buf == NULL)
	{
		if (remainder)
			free(remainder);
		return (NULL);
	}	
	return_r = (char *)malloc(sizeof(char) * (len + 1));
	if (remainder)
	{
		strcp_pos(remainder, return_r, buf_object.index + 1, buf_object.end);
		free (remainder);
	}
	else
	{
		strcp_pos(buf_object.buf, return_r,
			buf_object.index + 1, buf_object.end);
		if (!return_r)
			return (NULL);
	}
	return (return_r);
}

char	*buf_until_end(int fd, char *buf2, int end)
{
	t_buff		buf_object;
	static char	*remainder;

	if (!remainder)
		buf_object = readbuff(fd, end);
	else
	{
		buf_object = remainder_alloc(remainder);
		if (buf_object.index == -1)
			remainder = NULL;
	}
	if (buf_object.index == -1)
	{
		buf2 = buf_until_end(fd, buf2, buf_object.end);
	}
	else
	{
		remainder = ft_remainder(buf_object, remainder);
		buf2 = allocate(buf2, buf_object);
		if (!buf2)
			return (NULL);
	}
	strcp(buf_object.buf, buf2, buf_object.begin, buf_object.end);
	free(buf_object.buf);
	return (buf2);
}

char	*get_next_line(int fd)
{
	char		*buf2;

	if (fd < 0)
		return (NULL);
	buf2 = NULL;
	return (buf_until_end(fd, buf2, 0));
}
