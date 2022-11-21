/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:31:36 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/08/11 14:10:32 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*cache;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

t_list	*make_node(int fd);
t_list	*find_node(t_list **lst, int fd);
void	del_node(t_list **lst, int fd, int flag);

char	*get_next_line(int fd);
char	*get_one_line(char *cache);
char	*read_file(int fd, char *cache);
char	*rest_cache(char *cache);

size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *cache, char *buffer);
#endif
