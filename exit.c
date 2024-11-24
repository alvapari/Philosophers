/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:09:31 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 12:14:20 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_bye_mutex(t_data *data, int count)
{
	if (data)
	{
		pthread_mutex_destroy(&data->exit_mutex);
		pthread_mutex_destroy(&data->print_mutex);
	}
	if (data->arr_forks != NULL)
	{
		while (count < data->philo_num)
		{
			pthread_mutex_destroy(&data->arr_forks[count].fork_mutex);
			count++;
		}
	}
	count = 0;
	if (data->ar_phil != NULL)
	{
		while (count < data->philo_num)
		{
			pthread_mutex_destroy(&data->ar_phil[count].cnt_eat_mtx);
			pthread_mutex_destroy(&data->ar_phil[count].lst_eat_mtx);
			count++;
		}
	}
}

void	ft_free_arrays(t_data *data)
{
	if (data->ar_phil != NULL)
		free(data->ar_phil);
	if (data->arr_forks != NULL)
		free(data->arr_forks);
}

void	ft_free_all(t_data *data)
{
	int	count;

	count = 0;
	ft_bye_mutex(data, count);
	ft_free_arrays(data);
	exit(0);
}
