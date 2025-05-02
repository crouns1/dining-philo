/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:29:17 by jait-chd          #+#    #+#             */
/*   Updated: 2025/05/02 14:29:17 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
typedef struct s_args
{
    int time_to_eat;
    int time_to_die;
    int n_of_philos;
    int time_to_sleep;
    int number_of_times_each_philo_must_eat;
    int thread_id;
} t_args;

void conditions_that_must_be_true (t_args *args);
void check_how_args_must_be(int counter, char **vectors);
t_args *parse_args(int counter, char **vectors);
void *routine(void *arg);
void init_philos_and_threads(t_args *args, pthread_t **threads, t_args **philos);
void join_and_cleanup(pthread_t *threads, t_args *philos, int n_of_philos);


#endif