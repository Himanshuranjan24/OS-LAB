/*c program for dining philosophers problem.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5 
sem_t forks[N];
sem_t waiter;
void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;
    while (1) {
        sem_wait(&waiter); 
        sem_wait(&forks[left]); 
        sem_wait(&forks[right]); 
        printf("Philosopher %d is eating\n", id);
        sem_post(&forks[right]); 
        sem_post(&forks[left]); 
        sem_post(&waiter); 
        sleep(rand() % 5); 
    }
}
int main() {
    pthread_t ph[N];
    int i, id[N];
    sem_init(&waiter, 0, N-1); 
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1); 
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }
    for (i = 0; i < N; i++) {
        pthread_join(ph[i], NULL);
    }
    sem_destroy(&waiter);
    for (i = 0; i < N; i++) {
        sem_destroy(&forks[i]);
    }
    return 0;
}