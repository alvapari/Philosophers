/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:43:19 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 11:12:27 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_errors(char x)
{
	if (x == 'n')
	{
		printf("Arguments must be 4 or 5 positive integers. Example:\n");
		printf("./philo 5 800 200 200 || 5 800 200 200 7\n");
	}
	if (x == 'p')
		printf("The number of philosophers must be between 1 and 200\n");
	if (x == 'l')
	{
		printf("Time_to_die, time_to_eat and time_to_sleep ");
		printf("should not be less than 60\n");
	}
	if (x == 'z')
		printf("Philosophers must eat at least once (optional argument)\n");
	if (x == 'm')
		printf("Mutexes have not been created. (Error)\n");
	exit(1);
}

void	ft_check_arguments(int argc, char *argv[])
{
	int	count;
	int	count_2;

	count = 1;
	while (count < argc)
	{
		count_2 = 0;
		while (argv[count][count_2] != '\0')
		{
			if (argv[count][count_2] >= '0' && argv[count][count_2] <= '9')
				count_2++;
			else
				ft_print_errors('n');
		}
		count++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) == 0)
		ft_print_errors('p');
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		ft_print_errors('l');
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		ft_print_errors('z');
}
