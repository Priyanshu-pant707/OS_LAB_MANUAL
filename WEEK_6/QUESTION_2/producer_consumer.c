#include<stdio.h>
#include <pthread.h>
#include<semaphore.h>
#include<unistd.h>


# define BUFFER_SIZE 5


int buffer[BUFFER_SIZE];

int in=0; // index for producer
int out=0; //index for the consumer

// semaphores
sem_t empty; // for prducer to reduce empty value  and consumer will increase its value
sem_t full;   // for producer to increase full value and consumer will decrease its value



// mutex for the critical section

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


//thread functions
void * producer(void *args){
    int item=0;
    for(int i=0;i<10;i++){
        item=i+1; //produced item value

        sem_wait(&empty);    // wait for empty slot   -> only work if its vaslue>0  otherwise wait
        pthread_mutex_lock(&mutex); // enter critical section and lock the mutex

        // crititcal section commands
        buffer[in]=item;
        printf("producer produced %d at index %d \n",item,in);
        in=(in+1)%5; // circular increment


        pthread_mutex_unlock(&mutex); // exit the critical section and unlock the mutex
        sem_post(&full); //signal that there is a new full slot

        sleep(1);
    }
    return NULL;
}


void * consumer(void *args){
    int item;
    for(int i=0;i<10;i++){
        sem_wait(&full);    // wait for full slot   -> only work if its vaslue>0  otherwise wait
        pthread_mutex_lock(&mutex);    // enter critical section and lock the mutex

        item =buffer[out];
        printf("consumer consumed %d from index %d \n",item,out);
        out=(out+1)%5; // circular increment
        pthread_mutex_unlock(&mutex); // exit the critical section and unlock the mutex
        sem_post(&empty); //signal that there is a new empty slot

        sleep(2);

    }

    return NULL;
}




int main(){
    pthread_t prod,cons;   // declare thread variables


    // intialize the semaphores

    sem_init(&empty,0,BUFFER_SIZE); // all slots are empty at the start
    sem_init(&full,0,0);            // no full slots at the start


    // create threads

    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    // wait for threads to finish
    pthread_join(prod,NULL);
    pthread_join(cons,NULL);

    // destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;



}