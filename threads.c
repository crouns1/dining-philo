/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:29:21 by jait-chd          #+#    #+#             */
/*   Updated: 2025/07/25 01:31:47 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *routine(void *arg)
{
    t_args *args = (t_args *)arg;
    int i= 0;
    // while(1) {
    // while(i < args->n_of_philos) {
        // pthread_mutex_init(&args->t_philo.resources[i] , NULL);
        // i++;
    // }
    printf("%d\n" , args->thread_id);
    // printf("thread %d\n", args->thread_id);
    return NULL;
}

void init_philos_and_threads(t_args *args, pthread_t **threads, t_args **philos)
{
    *threads = malloc(sizeof(pthread_t) * args->n_of_philos);
    *philos = malloc(sizeof(t_args) * args->n_of_philos);
    int i = 0;
    while (i < args->n_of_philos)
    {
        (*philos)[i] = *args;
        (*philos)[i].thread_id = i + 1;
        if (pthread_create(&(*threads)[i], NULL, routine, &(*philos)[i]) != 0)
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
}