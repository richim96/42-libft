/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:45:52 by rmei              #+#    #+#             */
/*   Updated: 2024/07/01 15:05:50 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* Macros */ 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_PFD
#  define MAX_PFD 1024
# endif

/* Structures */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_buffer
{
	char		*buffer;
	ssize_t		pos;
	ssize_t		end;
}	t_buffer;

typedef struct s_line
{
	char	*line;
	size_t	size;
	int		i;
}	t_line;

/* Libc functions */
int		ft_atoi(const char *nptr);
int		ft_haschar(char *s, char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_printf(const char *fmt, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_putnbr_base_fd(long n, int fd, char *base);
int		ft_putstr_fd(char *s, int fd);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_get_next_line(int fd);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

/* Linked list functions */
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);

#endif
