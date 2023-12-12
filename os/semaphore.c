#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int total = 0;
int done = 0;
sem_t worker_lock, boss_lock;
void init(){
    sem_init(&worker_lock, 0, 0);
    sem_init(&boss_lock, 0, 1);
}

void sum(int N){
    for (int i=1; i<=N; i++){
        sem_wait(&boss_lock);
        total += i;
        printf("[Worker] processed i = %d\n", i);
        sem_post(&worker_lock);
    }
    done = 1;
    printf("[Worker] done\n");
}

void * worker(void * n){
    int N = (int)n;
    printf("Worker received N = %d\n", N);
    sum(N);
    return NULL;

}
void thr_wait(){
    while(!done){
        sem_wait(&worker_lock);
        printf("[Boss] running total = %d\n", total);
        sem_post(&boss_lock);
    }
}
int main(int argc, char *argv[]){
    printf("Main begin\n");
    init();
    int n = atoi(argv[1]);

    pthread_t wrk;
    pthread_create(&wrk, NULL, worker, (void*)n);
    thr_wait();
    return 0;
}