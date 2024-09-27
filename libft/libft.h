/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:18:34 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/15 03:36:55 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

//Struct for a linked list
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

//Checkers
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

//String Related Manipulation
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, char *src, unsigned int size);
char	*ft_strnstr(char *str1, char *str2, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_toupper(int c);
int		ft_tolower(int c);

//Memory Manipulation
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_calloc(size_t num, size_t size);

//Tranformations
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

//File Descriptors
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;*/

//List Manipulation
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//Printf
int		ft_printf(const char *str, ...);
void	ft_c_conver(char c, int *count);
void	ft_d_conver(int n, int *count);
void	ft_s_conver(const char *str, int *count);
void	ft_p_conver(size_t ptr, int *count);
void	ft_u_conver(unsigned int n, int *count);
void	ft_x_conver(unsigned int x, char type, int *count);

//Get Next Line
char	*get_next_line(int fd);
void	read_savelst(int fd, t_list **lst, int *read_check);
void	lstnew_add(t_list **lst, char *buffer, int read_checked);
void	extract_line(t_list *lst, char **line);
void	clean_lst(t_list **lst);
int		newline_check(t_list *lst);
t_list	*next_element(t_list *lst);
void	create_line(char **line, t_list *lst);
void	free_list(t_list *lst);

#endif
