/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:01:20 by kbaridon          #+#    #+#             */
/*   Updated: 2025/03/27 14:41:27 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//libft
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
void	ft_perror(char *str);
char	*ft_strdup(char *src);
int		ft_atoi(const char *str);
size_t	ft_strlen_dbl(char **str);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(const char *str, char c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);

//libft bonus
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//get_next_line
char	*get_next_line(int fd);

//printf
int		ft_printf(const char *str, ...);
int		ft_putcharc(char c, int count);
int		ft_putstrc(const char *str, int count);
int		ft_putdecimal(int nb, int count);
int		ft_putundecimal(unsigned int nb, int count);
int		ft_puthexa(unsigned long long nb, int upper, int count);
int		ft_putpointer(void *p, int count);

#endif
