/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:10:45 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/08 18:22:16 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flag
{
	int				width;
	int				sign;
	char			c;
	int				dot;
	int				len;
	int				star;
}					t_flag;

void				ft_print_flags(t_flag flags, int len);
int					ft_print_char(char c, t_flag flags);
int					ft_print_str(char *s, t_flag flags);
int					ft_print_unsign(unsigned int i, t_flag flags);
int					ft_print_hex(unsigned int i, t_flag flags, char c);
int					ft_print_point(size_t i, t_flag flags);
int					ft_print_nbr(int i, t_flag flags);
void				ft_hex_format(size_t i, char c);
int					ft_hex_len(unsigned int i);
t_flag				ft_flags_std(const char *str);
t_flag				ft_stars(int i, t_flag flags);
int					ft_printf(const char *str, ...);
char				*ft_utoa(unsigned int n);
int					ft_point_len(size_t i);

int					ft_atoi(const char *str);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t nb);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void*));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void*),
						void (*del)(void*));
t_flag				flags_init(t_flag flags, const char *s);
const char			*s_init_one(const char *s);
const char			*s_init_two(const char *s);

char				*ft_strdup_gnl(char *s1, int *err);
char				*ft_strjoin_gnl(char *s1, char *s2, int *err);
char				*ft_strcpy(char *dest, char *src);
int					get_next_line(int fd, char **line);

void				save_free(char **str);

void				*ft_calloc_int(size_t nmemb);
void				ft_bzero_int(void *s, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#endif
