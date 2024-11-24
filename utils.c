/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:38:39 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 11:14:49 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int				c;
	unsigned int	result;
	int				sign;

	sign = 1;
	result = 0;
	c = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == 32)
		c++;
	while ((str[c] == '-' || str[c] == '+')
		&& (str[c +1] >= '0' && str[c +1] <= '9'))
	{
		if (str[c] == '-')
			sign = (-1) * sign;
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9') && str[c] != '\0')
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	return ((result) * (sign));
}

long	ft_start_time(void)
{
	struct timeval	time;
	long			timemls;

	gettimeofday(&time, NULL);
	timemls = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (timemls);
}

long	present_time(long start_time)
{
	struct timeval	time;
	long			temp;

	gettimeofday(&time, NULL);
	temp = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (temp - start_time);
}

void	ft_get_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lst_eat_mtx);
	philo->last_eaten = present_time(philo->data->program_start);
	pthread_mutex_unlock(&philo->lst_eat_mtx);
}

long	ft_register_last_eaten(t_philo *philo)
{
	long	nbr;

	pthread_mutex_lock(&philo->lst_eat_mtx);
	nbr = philo->last_eaten;
	pthread_mutex_unlock(&philo->lst_eat_mtx);
	return (nbr);
}
