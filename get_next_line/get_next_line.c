/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:49:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/17 04:55:02 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
#if BUFFER_SIZE > 1
#undef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd)
{
	char *str = malloc(10000), *buf = str;
	while (fd >= 0 && BUFFER_SIZE > 0 && read(fd, buf, BUFFER_SIZE) && *buf++ != 10);
	return (buf > str) ? (*buf = 0, str) : (free(str), NULL);
}