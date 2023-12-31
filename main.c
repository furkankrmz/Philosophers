/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akirmizi <akirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:15:01 by akirmizi          #+#    #+#             */
/*   Updated: 2022/11/18 15:13:22 by akirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (argc != 5 && argc != 6)
		return (1);
	if (ft_check_args(argc, argv) == 0)
		return (2);
	philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo)
		return (3);
	ft_init_philos(philo, argc, argv);
	ft_init_mutex(philo, argv, forks, death);
	ft_join_threads(philo, argv);
	ft_free(philo, forks, death);
	return (0);
}
