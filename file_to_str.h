/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_to_str.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:57:22 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/08 16:07:10 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_TO_STR_H
# define FILE_TO_STR_H

/* Public libraries */
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* file_to_str.c */
int	get_map_fd(const char *map_name);
int	file_to_str(int fd, char **file_str);

#endif /* file_to_str.h */