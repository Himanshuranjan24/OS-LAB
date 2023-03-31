/*c program for reader writer problem.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_READERS 5
sem_t mutex, wrt;
int readers_count = 0, data = 0;
void *writer(void *arg) {
    while (1) {
        sem_wait(&wrt); 
        data++; 
        printf("Data written by writer: %d\n", data);
        sem_post(&wrt); 
        sleep(rand() % 5); 
    }
}
void *reader(void *arg) {
    int id = *(int *)arg;
    while (1) {
        sem_wait(&mutex); 
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&wrt); 
        }
        sem_post(&mutex); 
        printf("Data read by reader %d: %d\n", id, data);
        sem_wait(&mutex); 
        readers_count--;
        if (readers_count == 0) {
            sem_post(&wrt); 
        }
        sem_post(&mutex); 
        sleep(rand() % 5); 
    }
}
int main() {
    pthread_t wr, rd[MAX_READERS];
    int i, id[MAX_READERS];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    pthread_create(&wr, NULL, writer, NULL);
    for (i = 0; i < MAX_READERS; i++) {
        id[i] = i + 1;
        pthread_create(&rd[i], NULL, reader, &id[i]);
    }
    pthread_join(wr, NULL);
    for (i = 0; i < MAX_READERS; i++) {
        pthread_join(rd[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}