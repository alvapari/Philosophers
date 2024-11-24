/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:07:53 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 11:13:46 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_execution(t_philo *philo, char c)
{
	char	*string;

	if (c == 'd')
		string = "died";
	else if (c == 'e')
		string = "is eating";
	else if (c == 't')
		string = "is thinking";
	else if (c == 's')
		string = "is sleeping";
	else if (c == 'l')
		string = "has taken the left fork";
	else if (c == 'r')
		string = "has taken the right fork";
	if (ft_check_exit(philo->data) == 1)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf(" %ld     philosopher Nº %i %s \n",
		present_time(philo->data->program_start), philo->id, string);
	pthread_mutex_unlock(&philo->data->print_mutex);
	if (ft_check_exit(philo->data) == 1)
		return ;
}
