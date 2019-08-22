/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:53:29 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/20 18:21:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "../libft/libft.h"
# define BUFF_SIZE 32

int get_next_line (const int fd, char **line);
int set_line(int fd, char **line, char **s);

#endif
