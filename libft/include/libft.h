/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:23:20 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/12 20:19:40 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdio.h>

# define BASE_MAJ(x) "0123456789ABCDEF"[x]
# define BASE_MIN(x) "0123456789abcdef"[x]

typedef unsigned long long int	t_ull;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
void ft_cleaner(char **tab, int count);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
t_ull			ft_iterative_power(int nb, int power);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy (void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
size_t			ft_strlcat(char *dest, char const *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_strnstr(char *str, char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *str, char *to_find);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(long long n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strrev(char *str);
int				ft_intlen(long long n);
int				ft_abs(int i);
char			*ft_strresize(char *str, size_t size);
char			*ft_strrem(char *str, int from, int len);
int				ft_sqrt(int nb);
void			ft_putnbrendl(int i);
int				ft_chrindex(char *str, char c);
int				ft_chrindexi(char *str, char c, int len);
char			*ft_strjoini(char const *s1, char const *s2, size_t len);
char			*ft_strchri(const char *s, int c, unsigned int len);
char		*ft_itoabase_uns(unsigned long long n, int b, long long *f, char c);
char		*ft_ftoa(double floa, long long *f);
void			simple_sort(int *array, int len);
char			*ft_strndup(const char *s1, size_t n);
int			ft_countwords(char const *s, char c);
void			ft_puttab(char **tab);
int				ft_isspace(char c);
void			ft_lstpush(t_list **alst, t_list *new);
int				ft_freeret(void *p, int r);
int		ft_charwlen(wchar_t c);
int		ft_strwlen(wchar_t *s);
void	ft_putwchar(wchar_t c);
void	ft_putwstr(wchar_t *s);
char	**ft_tabcpy(char **tab);
int	ft_counttab(char **tab);

#endif
