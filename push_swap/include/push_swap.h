/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:36 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 16:36:09 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <get_next_line.h>

# define SMALL	2
# define BIG	3
# define TOP		4
# define BOTTOM		5

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	size_t			size;
	struct s_node	*bottom;
	struct s_node	*top;
}				t_stack;

typedef struct s_command
{
	char				*command;
	struct s_command	*prev;
	struct s_command	*next;
}				t_command;

typedef struct s_commands
{
	size_t				count;
	struct s_command	*top;
	struct s_command	*bottom;
}				t_commands;

typedef struct s_push_swap_tool
{
	struct s_list		*a;
	struct s_list		*b;
	struct s_commands	*commands;
	int					*sorted_num;
}				t_tool;

t_stack		*create_list(void);
void		delete_list(t_stack *stack);
t_node		*make_node(int value);
void		check_overlap(t_stack *stack, int value);
void		pop_front(t_stack *stack);
void		pop_back(t_stack *stack);
void		push_front(t_stack *stack, t_node *node);
void		push_back(t_stack *stack, t_node *node);
void		push_command(t_commands *stack, char *command);
t_command	*make_command(char *command);
void		sa(t_tool *tool);
void		sb(t_tool *tool);
void		ss(t_tool *tool);
void		pa(t_tool *tool);
void		pb(t_tool *tool);
void		ra(t_tool *tool);
void		rb(t_tool *tool);
void		rr(t_tool *tool);
void		rra(t_tool *tool);
void		rrb(t_tool *tool);
void		rrr(t_tool *tool);
void		two_element_sort(t_tool *tool, char target);
void		only_three_element_a_stack(t_tool *tool, int start, int end);
void		only_three_element_b_stack(t_tool *tool, int start, int end);
void		three_element_a_stack(t_tool *tool, int start, int end);
void		three_element_b_stack(t_tool *tool, int start, int end);
void		five_element_sort(t_tool *tool);
void		command_optimization(t_tool *tool);
void		replace_rr(t_tool *tool);
void		replace_rrr(t_tool *tool);
void		replace_ss(t_tool *tool);
void		command_optimization(t_tool *tool);
void		free_replace_node(t_command *first, t_command *second);
void		replace_command(t_commands *commands, \
			size_t position, size_t *size, char *command);
void		quick_sort(t_tool *tool);
int			find_pivot(int start, int end, int type);
void		sort_top_a(t_tool *tool, int start, int end);
void		sort_bottom_a(t_tool *tool, int start, int end);
void		recur_top_a(t_tool *tool, int start, int end);
void		recur_bottom_a(t_tool *tool, int start, int end);
void		hub_small_a_stack_size(t_tool *tool, int start, \
			int end, int position);
void		sort_top_b(t_tool *tool, int start, int end);
void		sort_bottom_b(t_tool *tool, int start, int end);
void		recur_top_b(t_tool *tool, int start, int end);
void		recur_bottom_b(t_tool *tool, int start, int end);
void		small_b_bottom(t_tool *tool, int start, int end);
void		hub_small_b_stack_size(t_tool *tool, int start, \
			int end, int position);
void		push_sort_number(t_tool *tool);
void		insertion_sort(t_tool *tool);
void		bubble_sort(t_tool *tool);
void		is_valid_argument(char *argument, t_stack *a_stack);
int			is_ascending(t_stack *stack, size_t start, size_t end);
int			is_descending(t_stack *stack, size_t start, size_t end);
t_commands	*create_commands(void);
void		init(t_tool *tool);
void		all_free(t_tool *tool);
void		delete_commands(t_commands *stack);
void		message_not_integer(void);
void		message_overlap(void);
void		message_memory(void);
char		**split_free(char ***result, size_t cnt);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**word_malloc(char **result, char const *s, char c, size_t wordcnt);
size_t		split_cnt(char const *s, char c);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_atoi(const char *str);
int			ft_range_check(char const *str, size_t i, int sign);
int			ft_isdigit(int c);
void		ft_checker(t_tool *tool);
void		hub_command(t_tool *tool, char *command, size_t size);
void		show_commands(t_commands *commands);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

#endif
