/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:16:33 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 13:51:36 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork	t_fork;
typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef struct s_fork
{
	int					id;
	int					status;
	pthread_mutex_t		fork_mutex;
}						t_fork;

typedef struct s_philo
{
	pthread_t			thread;
	pthread_mutex_t		cnt_eat_mtx;
	pthread_mutex_t		lst_eat_mtx;
	int					count_eat;
	int					last_eaten;
	int					id;
	t_fork				*l_fork;
	t_fork				*r_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					philo_num;
	int					fork_num;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					max_eat;
	int					exit_flag;
	long				program_start;
	pthread_mutex_t		exit_mutex;
	pthread_mutex_t		print_mutex;
	t_philo				*ar_phil;
	t_fork				*arr_forks;
}						t_data;

void					ft_print_errors(char x);
void					ft_check_arguments(int argc, char *argv[]);
int						ft_atoi(const char *str);
void					ft_init_data(t_data *data, int argc, char *argv[]);
long					ft_start_time(void);
long					present_time(long start_time);
void					ft_create_philosophers(t_data *data);
void					ft_init_philosophers(t_data *data, int cnt);
void					ft_get_last_eat(t_philo *philo);
void					ft_think(t_philo *philo);
void					ft_sleep(t_philo *philo);
void					ft_eat(t_philo *philo);
void					ft_routine(void *params);
void					ft_take_odd(t_philo *philo);
void					ft_take_even(t_philo *philo);
void					ft_put_down_forks(t_philo *philo);
void					ft_print_execution(t_philo *philo, char c);
int						ft_check_if_eat_max(t_data *data);
void					ft_update_last_eaten(t_philo *philo);
void					ft_update_count_eat(t_philo *philo);
long					ft_register_last_eaten(t_philo *philo);
void					ft_free_arrays(t_data *data);
void					ft_free_all(t_data *data);
void					ft_bye_mutex(t_data *data, int count);
void					ft_join_threads(t_data *data);
int						ft_check_alive(t_data *data);
void					ft_create_forks(t_data *data);
int						ft_check_exit(t_data *data);
void					*ft_monitoring(void *args);
void					ft_one_case(char *argv[]);

#endif
