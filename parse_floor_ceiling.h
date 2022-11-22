/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_floor_ceiling.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:58:09 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/22 17:44:08 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FLOOR_CEILING_H
# define PARSE_FLOOR_CEILING_H


/* public libraries */
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>

/* private libraries */
# include "libft/libft.h"
# include "tokenize.h"
# include "structs.h"
# include "ft_strtol.h"

int strip_spaces(char *s);
void alpha(char *str);

#endif