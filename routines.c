/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:47:10 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 12:41:11 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_routine(void *params)
{
	t_philo	*philo;

	philo = (t_philo *)params;
	while (ft_check_exit(philo->data) == 0)
	{
		ft_eat(philo);
		if (ft_check_exit(philo->data) == 1)
			break ;
		if (philo->count_eat == philo->data->max_eat)
			break ;
		ft_sleep(philo);
		if (ft_check_exit(philo->data) == 1)
			break ;
		ft_think(philo);
		if (ft_check_exit(philo->data) == 1)
			break ;
		usleep(100);
	}
}

void	ft_eat(t_philo *philo)
{
	long	end_eating_time;

	if (ft_check_exit(philo->data) == 1)
		return ;
	if (philo->id % 2 == 0)
		ft_take_even(philo);
	else
		ft_take_odd(philo);
	if (ft_check_exit(philo->data) == 1)
		return ;
	ft_print_execution(philo, 'e');
	ft_update_last_eaten(philo);
	ft_update_count_eat(philo);
	end_eating_time = present_time(philo->data->program_start)
		+ philo->data->eat_time;
	while (present_time(philo->data->program_start) < end_eating_time)
	{
		if (ft_check_exit(philo->data) == 1)
			break ;
		usleep(1);
	}
	ft_put_down_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	long	end_sleeping_time;

	if (ft_check_exit(philo->data) == 1)
		return ;
	ft_print_execution(philo, 's');
	end_sleeping_time = present_time(philo->data->program_start)
		+ philo->data->sleep_time;
	while (present_time(philo->data->program_start) < end_sleeping_time)
	{
		if (ft_check_exit(philo->data) == 1)
			break ;
		usleep(1);
	}
}

void	ft_think(t_philo *philo)
{
	if (ft_check_exit(philo->data) == 1)
		return ;
	ft_print_execution(philo, 't');
}
