/*c program for producer consumer problem.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;
void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex); 
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Produced item: %d\n", item);
        pthread_mutex_unlock(&mutex); 
        sem_post(&full); 
    }
}
void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full); 
        pthread_mutex_lock(&mutex); 
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumed item: %d\n", item);
        pthread_mutex_unlock(&mutex); 
        sem_post(&empty); 
    }
}
int main() {
    pthread_t prod, cons;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}