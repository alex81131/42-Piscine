/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slario <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:25:00 by slario            #+#    #+#             */
/*   Updated: 2024/02/25 17:56:58 by slario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

int	ft_strlen(char *str);
int	ft_mini_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int	check(char c, char *charset);
int	count_str(char *str, char *charset);
int	ft_strlen_split(char *str, char *charset);
char	*word(char *str, char *charset);
char	**ft_split(char *str, char *charset);
char	*dict(const char *filename);
char	**keyword(char *str);
int	parse(char *str);
void	chop_chop(int nbr);


#endif
