/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:08:46 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:08:48 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_listt
{
	void			*content;
	struct s_list	*next;
}					t_listt;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_lstsize(t_listt *lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_listt **lst, t_listt *new);
void	ft_lstclear(t_listt **lst, void (*del)(void*));
void	ft_lstdelone(t_listt *lst, void (*del)(void*));
void	ft_lstiter(t_listt *lst, void (*f)(void *));
t_listt	*ft_lstnew(void *content);
t_listt	*ft_lstlast(t_listt *lst);
t_listt	*ft_lstmap(t_listt *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
int		found_newline(t_list *stockbuf);
t_list	*ft_lst_get_last(t_list *stockbuf);
int		read_and_stockbuf(int fd, t_list **stockbuf);
void	add_to_stockbuf(t_list **stockbuf, char *buf, int readed);
void	extract_line(t_list *stockbuf, char **line);
void	generate_line(char **line, t_list *stockbuf);
void	clean_stockbuf(t_list **stockbuf);
void	free_stockbuf(t_list *stockbuf);

#endif