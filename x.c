#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <sys/time.h>
// mutex is a MUTual EXclusion device, and is useful for protecting shared data structures 
//from concurrent modifications, and implementing critical sections and monitors.
typedef struct  s_args
{
    int n_philos;
    int t_t_die;
    int t_t_eat;
    int t_t_sleep;
    // only init it maybe ill need it
    int n_of_t_each_ph_must_eat;
} t_args;

typedef struct s_table{
    pthread_mutex_t resource;
    int tajin_plates;
} t_table;

typedef struct s_philo{
    int id;
    pthread_t *philos;
} t_philo;

void *philo_routine(void *x) {
    (void)x;
    t_philo *philo = malloc(sizeof(t_philo));

    printf("%d philo\n" , philo->id) ;
}

int main(int c , char **v ) {
    // pthread_t *thread;
    t_args *args = malloc(sizeof(t_args));
    if(!args)
        return -1;
    t_table *table = malloc(sizeof(t_table));
    if(!table)
        return -1;    
    t_philo *philo;
    // if(!philo)
        // return -1;
        int i = 0;
    if(c  == 2)
    {
        args->n_philos = atoi(v[1]);
        while(i < args->n_philos) {
                pthread_mutex_init(&table->resource , NULL);
                printf("mutex\n");
                i++;
        } 
        i = 0;
        while(i < args->n_philos) {
            table->tajin_plates++;
            printf("plate has been created\n");
            i++;    
        }
        i = 0;
         while(i < args->n_philos) {
             philo->id = 0;
             pthread_create(&philo->philos[i] , NULL , philo_routine , NULL);
             philo->id++;
             i++;

        }
        i = 0;
        while(i < args->n_philos) {
            pthread_join(philo->philos[i] , NULL);
            i++;
        }

    }  else
        printf("############\n");
    return 0;
}