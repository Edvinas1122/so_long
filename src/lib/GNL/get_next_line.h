/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:03:01 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/25 16:24:19 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct t_buff
{
	char	*buf;
	int		begin;
	int		end;
	int		index;
}	t_buff;

char	*get_next_line(int fd);
int		check_for_newline_n_null(char *buf);
t_buff	remainder_alloc(char *remainder);
t_buff	readt_buff(int fd, int end);
char	*ft_remainder(t_buff buf_object, char *remainder);
char	*buf_until_end(int fd, char *buf2, int end);
char	*allocate(char *buf2, t_buff buf_object);
int		ft_strlen2(char *str);
char	*strcp(char *buf, char *buf2, int begin, int end);
char	*strcp_pos(char *buf, char *buf2, int begin, int end);
#endif
