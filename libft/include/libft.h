/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:15:39 by seushin           #+#    #+#             */
/*   Updated: 2022/06/10 15:48:17 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(
						const char *haystack, const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, int n);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					count_words(const char *s, char c);
char				**ft_split(const char *s, char c);
void				ft_free_strs(char **strs);
char				*ft_strreduce(const char **strs);

int					ft_is_set(const char *s, char c);
char				*ft_utoa(unsigned int n);
int					ft_atoi(const char *str);
int					ft_nbrlen(int n, int base);
char				*ft_itoa(int n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putchar(int c);
int					ft_putstr(char *str);
int					ft_putnstr(char *str, int n);

/*
** single linked list
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_lst);
void				ft_lstadd_back(t_list **lst, t_list *new_lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(
						t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
