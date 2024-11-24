/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:56:35 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 12:05:38 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_monitoring(void *args)
{
	t_data	*data;

	data = args;
	while (1)
	{
		if (ft_check_alive(data) == 1)
		{
			pthread_mutex_lock(&data->exit_mutex);
			data->exit_flag = 1;
			pthread_mutex_unlock(&data->exit_mutex);
			break ;
		}
		if (ft_check_if_eat_max(data) == 1)
		{
			pthread_mutex_lock(&data->exit_mutex);
			data->exit_flag = 1;
			pthread_mutex_unlock(&data->exit_mutex);
			break ;
		}
	}
	return (NULL);
}

int	ft_check_exit(t_data *data)
{
	pthread_mutex_lock(&(data->exit_mutex));
	if (data->exit_flag != 0)
	{
		pthread_mutex_unlock(&data->exit_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->exit_mutex);
	return (0);
}

int	ft_check_alive(t_data *data)
{
	int		cnt;
	long	last_eaten;

	cnt = 0;
	last_eaten = 0;
	while (cnt < data->philo_num)
	{
		last_eaten = ft_register_last_eaten(&data->ar_phil[cnt]);
		if (present_time(data->program_start) - last_eaten > data->die_time)
		{
			ft_print_execution(&(data->ar_phil[cnt]), 'd');
			return (1);
		}
		cnt++;
	}
	return (0);
}

int	ft_check_if_eat_max(t_data *data)
{
	int	cnt;
	int	meals_eaten;
	int	no_hungry_phil;

	cnt = 0;
	meals_eaten = 0;
	no_hungry_phil = 0;
	while (cnt < data->philo_num)
	{
		pthread_mutex_lock(&data->ar_phil[cnt].cnt_eat_mtx);
		meals_eaten = data->ar_phil[cnt].count_eat;
		pthread_mutex_unlock(&data->ar_phil[cnt].cnt_eat_mtx);
		if (meals_eaten == data->max_eat)
			no_hungry_phil++;
		cnt++;
	}
	if (no_hungry_phil == data->philo_num)
		return (1);
	return (0);
}

void	ft_one_case(char *argv[])
{
	int	time;

	time = ft_atoi(argv[2]);
	printf("0     philosopher Nº 1 has taken the left fork \n");
	printf("%i     philosopher Nº 1 die\n", time + 1);
	exit(0);
}
