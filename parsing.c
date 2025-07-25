/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:23:56 by jait-chd          #+#    #+#             */
/*   Updated: 2025/07/25 00:30:41 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



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
        return NULL;

    args->n_of_philos = atoi(vectors[1]);
    args->time_to_die = atoi(vectors[2]);
    args->time_to_eat = atoi(vectors[3]);
    args->time_to_sleep = atoi(vectors[4]);

    return args;
}
