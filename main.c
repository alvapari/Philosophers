/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:42:19 by alvapari          #+#    #+#             */
/*   Updated: 2024/11/04 12:17:13 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data		data;
	pthread_t	monitor;

	if (argc != 5 && argc != 6)
		ft_print_errors('n');
	ft_check_arguments(argc, argv);
	if (ft_atoi(argv[1]) == 1)
		ft_one_case(argv);
	ft_init_data(&data, argc, argv);
	pthread_create(&monitor, NULL, (void *)&ft_monitoring, (void *)&data);
	if (pthread_join(monitor, NULL) != 0)
	{
		printf("Impossible join a monitor thread. (Error)\n");
		ft_free_all(&data);
	}
	ft_join_threads(&data);
	ft_free_all(&data);
}
