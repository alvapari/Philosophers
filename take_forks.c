/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:07:23 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 11:14:17 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_take_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->fork_mutex);
	philo->l_fork->status = 1;
	if (ft_check_exit(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->l_fork->fork_mutex);
		return ;
	}
	ft_print_execution(philo, 'l');
	pthread_mutex_lock(&philo->r_fork->fork_mutex);
	philo->r_fork->status = 1;
	if (ft_check_exit(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->l_fork->fork_mutex);
		pthread_mutex_unlock(&philo->r_fork->fork_mutex);
		return ;
	}
	ft_print_execution(philo, 'r');
}

void	ft_take_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->fork_mutex);
	philo->r_fork->status = 1;
	if (ft_check_exit(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->r_fork->fork_mutex);
		return ;
	}
	ft_print_execution(philo, 'r');
	pthread_mutex_lock(&philo->l_fork->fork_mutex);
	philo->l_fork->status = 1;
	if (ft_check_exit(philo->data) == 1)
	{
		pthread_mutex_unlock(&philo->l_fork->fork_mutex);
		pthread_mutex_unlock(&philo->r_fork->fork_mutex);
		return ;
	}
	ft_print_execution(philo, 'l');
}

void	ft_put_down_forks(t_philo *philo)
{
	philo->l_fork->status = 0;
	pthread_mutex_unlock(&philo->l_fork->fork_mutex);
	philo->r_fork->status = 0;
	pthread_mutex_unlock(&philo->r_fork->fork_mutex);
}
