#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_all
{
	char	**map;
	void	*enemy;
	void	*zombie;
	void	*wall;
	void	*brain;
	void	*floor;
	void	*exit;
	void	*mlx;
	void	*win;
	int		c;
	int		e;
	int		p;
	int		lines;
}	t_all;

// checker
void		ft_error_map(void);
void		check_argv(int argc, char **argv);
void		check_elements(t_all *data);
void		check_updownwall(t_all *data);
void		check_leftrightwall(t_all *data);
// draw_map
void		*ft_choose_image(t_all *data, char ch);
void		ft_create_img(t_all *data);
void		ft_draw_map(t_all *data);

// key_hook
int			ft_check_c(t_all *data);
void		ft_move_key(int *x, int *y, int key);
void		ft_find_player(t_all *data, int *x, int *y);
int			ft_move(t_all *data, int key);
int			ft_key_hook(int key, t_all *data);
// step_count
void		ft_writenbr(int fd, int n, int r);
long int	ft_count_r(int n);
void		ft_count_step(int n, int fd);
// solong_utils
int		count_lines(t_all *data);
int		count_len(t_all *data);
int		ft_exit(void);
// so_long
void	check_qlines(t_all *data);
char	**ft_save_map(char *argv, t_all *data);
int		main(int argc, char **argv);
// errors
void ft_error_qlines(void);
void ft_error_arg(void);
void ft_error_elements(void);
void ft_error_wall(void);

// gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, unsigned int len);
void	*ft_memset(void *b, int c, size_t len);

#endif
