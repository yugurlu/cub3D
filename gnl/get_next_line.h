/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugurlu <yugurlu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:52:12 by yugurlu           #+#    #+#             */
/*   Updated: 2023/04/11 12:13:28 by yugurlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *lft_str, char *buff);
char	*ft_line(char *handle);
char	*ft_clean(char *handle);
int		ft_strnewline(char *s);

#endif
