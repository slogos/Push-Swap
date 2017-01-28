/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/02 01:35:48 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUFF_SIZE 4

typedef	struct		s_gnl
{
	void			*content;
	size_t			content_size;
	struct s_gnl	*next;
}					t_gnl;

typedef	struct		s_list
{
	long			n;
	struct s_list	*next;
}					t_list;

typedef	struct		s_rot
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				n;
	int				m;
	int				max;
	int				min;
	int				len_a;
	int				len_b;
	int				len_a_diff;
	int				len_b_diff;
	int				moves;
	char			*char_del;
	struct s_rot	*next;
}					t_rot;

char				*g_str;
t_gnl				*ft_lstnew_gnl(void const *content, size_t content_size);
int					get_next_line(int const fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *s, size_t len);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isdigit(int c);
int					ft_isnumber(int c);
int					ft_isspace(int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_bzero(void *s, size_t n);
int					ft_strlen(const char *s);
int					ft_nbrlen(int n);
int					ft_nbrlen_base(long long n, int base);
int					ft_linelen(const char *str, int i);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long n, int base);
long				ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_base(long long nb, int base, int maj);
double				ft_power(double nb, double power);
int					ft_int_len(long n);
void				ft_lstnew(t_list **list);
void				ft_lstnew_move(t_rot **list);
char				*ft_strdup(char *str);
char				**ft_strsplit(char const *s, char c);

#endif
