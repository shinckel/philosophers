/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:36 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/17 19:17:00 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
// malloc, free, exit
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# include "../libft/header/libft.h"

// "e" stands for special ANSI codes
// # define SUCCESS "\n\e[1;42m SUCCESS you got a sorted list! \e[0m\n"
// # define REPEAT "\e[1;41m ERROR repeated numbers in stack \e[0m\n"
// # define OVERFLOW "\e[1;41m ERROR number overflow \e[0m\n"
// # define SYNTAX "\e[1;41m ERROR syntax error \e[0m\n"

// # define PA "\e[1;48;5;027m [pa] push to stack a \e[0m\n"
// # define PB "\e[1;48;5;027m [pb] push to stack b \e[0m\n"

// # define RA "\e[1;48;5;129m [ra] rotate stack a \e[0m\n"
// # define RB "\e[1;48;5;129m [rb] rotate stack b \e[0m\n"
// # define RR "\e[1;48;5;129m [rr] rotate both stacks \e[0m\n"

// # define RRA "\e[1;48;5;018m [rra] reverse rotate stack a \e[0m\n"
// # define RRB "\e[1;48;5;018m [rrb] reverse rotate stack b \e[0m\n"
// # define RRR "\e[1;48;5;018m [rrr] reverse rotate both stacks \e[0m\n"

// # define SA "\e[1;30;48;5;226m [sa] swap two top numbers stack a \e[0m\n"
// # define SB "\e[1;30;48;5;226m [sb] swap two top numbers stack b \e[0m\n"
// # define SS "\e[1;30;48;5;226m [ss] swap two top numbers both stacks \e[0m\n"

/* ************************************************************************** */
# define REPEAT "Error\n"
# define OVERFLOW "Error\n"
# define SYNTAX "Error\n"

# define PA "pa\n"
# define PB "pb\n"

# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"

# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
/* ************************************************************************** */

// lock the processes
typedef struct s_mutex
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	think_lock;

} t_mutex;


typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// help and check list, user messages
void		print_list(t_stack *list);
void		user_message(char *str);

// handle errors & free
void		free_matrix(char **argv);
void		error_free(t_stack **a, char **argv, bool flag_argc_2);
void		free_stack(t_stack **stack);
int			error_repetition(long long *numbers, int len);
int			error_syntax(char *str_nbr);

// actions
void		push(t_stack **destRef, t_stack **sourceRef, char *str);
void		rotate(t_stack **headRef, t_stack **tmpRef, char *str);
void		reverse_rotate(t_stack **headRef, t_stack **tmpRef, char *str);
void		swap(t_stack **headRef, int flag, char *str);

// linked list
void		append_node(t_stack **stack, int nbr);
t_stack		*find_last_node(t_stack *head);
bool		stack_sorted(t_stack *stack);
int			stack_len(t_stack *stack);

// create stack
void		stack_init(t_stack **a, char **argv, int argc, bool flag_argc_2);
long long	*normalize(long long *numbers, int len);

// algorithms
void		radix_sort(t_stack **a, t_stack **b, int len);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);

#endif