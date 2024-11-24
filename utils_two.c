/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:50:42 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/03 20:51:27 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_update_last_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->lst_eat_mtx);
	philo->last_eaten = present_time(philo->data->program_start);
	pthread_mutex_unlock(&philo->lst_eat_mtx);
}

void	ft_update_count_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->cnt_eat_mtx);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->cnt_eat_mtx);
}
