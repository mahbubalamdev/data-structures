#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int total = 0;
int done = 0;
sem_t empty, full;
void init(){
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 1);
}

void sum(int N){
    for (int i=1; i<=N; i++){
        sem_wait(&empty);
        total += i;
        printf("[Worker] processed i = %d\n", i);
        sem_post(&full);
    }
    sem_wait(&empty);
    done = 1;
    printf("[Worker] done\n");
    sem_post(&full);
    
}

void * worker(void * n){
    int N = (int)n;
    printf("Worker received N = %d\n", N);
    sum(N);
    return NULL;

}
void thr_wait(){
    while(!done){
        sem_wait(&full);
        printf("[Main] running total = %d\n", total);
        sem_post(&empty);
    }
}
int main(int argc, char *argv[]){
    printf("Main begin\n");
    init();
    int n = atoi(argv[1]);

    pthread_t wrk;
    pthread_create(&wrk, NULL, worker, (void*)n);
    thr_wait();
    printf("Grand total = %d\n", total);
    printf("Main end\n");
    return 0;
}