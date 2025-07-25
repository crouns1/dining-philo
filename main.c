/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:50:32 by jait-chd          #+#    #+#             */
/*   Updated: 2025/07/25 00:33:05 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

   #include "philo.h"

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

