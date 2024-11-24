/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:23:32 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 13:51:56 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_data(t_data *data, int argc, char *argv[])
{
	data->philo_num = ft_atoi(argv[1]);
	data->fork_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	data->exit_flag = 0;
	data->program_start = ft_start_time();
	data->arr_forks = NULL;
	data->ar_phil = NULL;
	if (pthread_mutex_init(&data->exit_mutex, NULL) != 0
		|| pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		printf("Mutexes have not been created. (Error)\n");
		exit(1);
	}
	ft_create_forks(data);
	ft_create_philosophers(data);
}

void	ft_create_forks(t_data *data)
{
	int	cnt;

	cnt = 0;
	data->arr_forks = malloc((sizeof(t_fork) * data->fork_num));
	if (!data->arr_forks)
	{
		printf("Array_forks has not been created. (Error)\n");
		exit(1);
	}
	while (cnt < data->fork_num)
	{
		data->arr_forks[cnt].id = cnt + 1;
		data->arr_forks[cnt].status = 0;
		if (pthread_mutex_init(&data->arr_forks[cnt].fork_mutex, NULL) != 0)
		{
			printf("Mutexes have not been created. (Error)\n");
			exit(1);
		}
		cnt++;
	}
}

void	ft_create_philosophers(t_data *data)
{
	int	cnt;

	cnt = 0;
	data->ar_phil = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->ar_phil)
	{
		printf("Array_philos has not been created. (Error)\n");
		exit(1);
	}
	ft_init_philosophers(data, cnt);
}

void	ft_init_philosophers(t_data *data, int cn)
{
	while (cn < data->philo_num)
	{
		data->ar_phil[cn].id = cn + 1;
		data->ar_phil[cn].count_eat = 0;
		data->ar_phil[cn].data = data;
		if (pthread_mutex_init(&data->ar_phil[cn].cnt_eat_mtx, NULL) != 0
			|| pthread_mutex_init(&data->ar_phil[cn].lst_eat_mtx, NULL) != 0)
			ft_print_errors('m');
		ft_get_last_eat(&data->ar_phil[cn]);
		data->ar_phil[cn].l_fork = &data->arr_forks[cn];
		if (cn == data->philo_num - 1)
			data->ar_phil[cn].r_fork = &data->arr_forks[0];
		else
			data->ar_phil[cn].r_fork = &data->arr_forks[cn + 1];
		pthread_create(&data->ar_phil[cn].thread, NULL, (void *)&ft_routine,
			(void *)&data->ar_phil[cn]);
		cn++;
	}
}

void	ft_join_threads(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data->philo_num)
	{
		if (pthread_join(data->ar_phil[cnt].thread, NULL) != 0)
		{
			printf("Impossible join a thread: Philosopher Id . %i(Error)\n",
				data->ar_phil[cnt].id);
			return ;
		}
		cnt++;
	}
}
