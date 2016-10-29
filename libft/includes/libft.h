/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:17:45 by abureau           #+#    #+#             */
/*   Updated: 2016/01/13 16:11:01 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <stdlib.h>
# define TRUE		1
# define FALSE		0

typedef int					t_bool;
typedef struct s_functable	t_functable;
typedef struct s_counter	t_counter;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

struct				s_functable
{
	t_counter		(*functab[7])(struct s_counter, int, char);
	char			*carac;
};

struct				s_counter
{
	int				value;
	unsigned char	ope;
	int				nbo;
	int				num;
	t_functable		func;
};

int					ft_atoi(const char *s);
void				ft_bzero(void *s, size_t n);
t_counter			ft_counteradd(t_counter cnt, int val, char c);
t_counter			ft_counterdiv(t_counter cnt, int val, char c);
t_counter			ft_countereq(t_counter cnt1, t_counter cnt2, char c);
void				ft_counterfree(t_counter *cnt);
t_counter			ft_counterinit(int nb, int i);
t_functable			ft_counterinitfunc(void);
t_counter			*ft_countermod(t_counter *cnt, const char *s);
t_counter			ft_countermodul(t_counter cnt, int val, char c);
t_counter			ft_countermul(t_counter cnt, int val, char c);
t_counter			ft_counterpow(t_counter cnt, int val, char c);
void				ft_counterrecap(t_counter *cnt);
t_counter			ft_counterset(t_counter cnt, int val, char c);
t_counter			*ft_countertab(const char *str);
void				ft_incdecvar(int *a, int *b);
void				ft_incfourvar(int *a, int *b, int *c, int *d);
void				ft_incthreevar(int *a, int *b, int *c);
void				ft_inctwovar(int *a, int *b);
void				ft_initfourvar(int *a, int *b, int *c, int *d);
void				ft_initthreevar(int *a, int *b, int *c);
void				ft_inittwovar(int *a, int *b);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int i);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void	**as);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t len);
int					ft_pow(int var, int pow);
void				ft_putchar(char	c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbrnl(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstrnb(const char *s, int nb);
char				*ft_strchr(const char *s, int c);
int					ft_square(int nbr);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(const char *s1, unsigned int start, size_t len);
char				*ft_strstr(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strtrimchar(char const *s, char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
#endif
