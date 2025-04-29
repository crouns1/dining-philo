    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   main.c                                             :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2025/04/24 20:50:32 by jait-chd          #+#    #+#             */
    /*   Updated: 2025/04/26 21:11:24 by jait-chd         ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

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

    void conditions_that_must_be_true (t_args *args) {
        if(args->n_of_philos < 1 || args->time_to_eat < 0 || args->time_to_sleep < 0 || args->time_to_die < 0) {
            printf("check args and try again\n");
        }    
    }

    void check_how_args_must_be(int counter, char **vectors)
    {
        if (counter != 5 && counter != 6)
        {
            write(2, "Number of args not on point\n", 28);
            exit(1);
        }
        int i = 1;
        while (i < counter)
        {
            int j = 0;
            while (vectors[i][j] != '\0')
            {
                if (vectors[i][j] < '0' || vectors[i][j] > '9')
                {
                    write(2, "The arg must be (int)\n", 22);
                    exit(1);
                }
                j++;
            }
            i++;
        }
    }

    t_args *parse_args(int counter, char **vectors)
    {
        check_how_args_must_be(counter, vectors);

        t_args *args = malloc(sizeof(t_args));
        if (!args)
        {
            perror("malloc");
            exit(1);
        }

        args->n_of_philos = atoi(vectors[1]);
        args->time_to_die = atoi(vectors[2]);
        args->time_to_eat = atoi(vectors[3]);
        args->time_to_sleep = atoi(vectors[4]);

        return args;
    }

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

    int main(int counter, char **vectors)
    {
        t_args *args = parse_args(counter, vectors);

        pthread_t *threads;
        t_args *philos;
        conditions_that_must_be_true(args);
        init_philos_and_threads(args, &threads, &philos);
        join_and_cleanup(threads, philos, args->n_of_philos);

        free(args);
        return 0;
    }