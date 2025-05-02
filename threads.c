/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:29:21 by jait-chd          #+#    #+#             */
/*   Updated: 2025/05/02 14:29:22 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *routine(void *arg)
{
    t_args *args = (t_args *)arg;
    while(1) {
    printf("Philosopher %d is eating\n", args->thread_id);
    usleep(args->time_to_eat * 1000); 
    printf("Philosopher %d is sleeping\n", args->thread_id);
    usleep(args->time_to_sleep * 10000);
    printf("Philosopher %d is thinking\n", args->thread_id);
    printf("Philosopher %d cycle has finished\n", args->thread_id);
    }
    return NULL;
}

void init_philos_and_threads(t_args *args, pthread_t **threads, t_args **philos)
{
    *threads = malloc(sizeof(pthread_t) * args->n_of_philos);
    *philos = malloc(sizeof(t_args) * args->n_of_philos);
    if (!*threads || !*philos)
    {
        perror("malloc failed");
        exit(1);
    }

    int i = 0;
    while (i < args->n_of_philos)
    {
        (*philos)[i] = *args;
        (*philos)[i].thread_id = i + 1;
        if (pthread_create(&(*threads)[i], NULL, &routine, &(*philos)[i]) != 0)
        {
            perror("pthread_create");
            exit(1);
        }
        i++;
    }
}

void join_and_cleanup(pthread_t *threads, t_args *philos, int n_of_philos)
{
    int i = 0;
    while (i < n_of_philos)
    {
        pthread_join(threads[i], NULL);
        i++;
    }

    free(threads);
    free(philos);
}