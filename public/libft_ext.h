/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_ext.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 11:47:47 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 12:56:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXT_H
# define LIBFT_EXT_H

# include <stddef.h>

unsigned long long	ft_absllnum(long long num);
char				*ft_decitohex(unsigned long long number);
void				*ft_memdup(const void *src, size_t len);
long long			ft_power(int n, int power);
char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
char				*ft_ulltoa(unsigned long long number);
size_t				ft_unumlen(unsigned long long number);
char				ft_iswhitespace(const char ch);
char				*ft_strnjoin(size_t n, ...);
char				**ft_split_set(char *str, char *set);
char				ft_charcmpset(char ch, char *set);
double				ft_atof(char *str);
char				*ft_dtoa(double n);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_split_free(char **splits);

#endif
