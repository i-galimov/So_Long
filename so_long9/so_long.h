/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:03:09 by eassamer          #+#    #+#             */
/*   Updated: 2021/12/15 16:44:35 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1024

typedef struct s_var{
	void	*mlx;
	void	*win;
	void	*img;
	char	**s;
	int		x;
	int		y;
	int		h;
	int		b;
	int		d;
	int		px;
	int		py;
	int		w;
	int		len;
}	t_var;

typedef struct s_res
{
	int	x;
	int	y;
}	t_res;

char	*get_next_line(int fd);
char	*ft_change_text(char *text);
char	*ft_just_a_line(char *text);
char	*ft_read(char *text, int fd);
char	**get_map(char *s);
int		my_kf(int keycode, t_var *he);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin1(char *s1, char *s2);
void	printmap(t_var *he, char **s);
void	left(t_var *he);
void	right(t_var *he);
void	up(t_var *he);
void	down(t_var *he);
void	printcount(t_var *he);
int		ft_checkc(t_var *he);
void	ft_print_m(t_var *he);
char	*ft_itoa(int n);
void	printimg(t_var *he, char *s);
void	printe(t_var *he, char c);
int		check_map(char **s, t_res *xe);
int		checklen(char **s);
void	freeblocks(t_var *he);
char	*ft_strdup(char *str);
#endif
