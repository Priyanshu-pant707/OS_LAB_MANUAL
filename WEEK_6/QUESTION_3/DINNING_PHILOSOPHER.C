#include <stdio.h>      
#include <pthread.h>    
#include <semaphore.h>  
#include <unistd.h>     

# define N 5


// global semaphore array : one semaphore per chopstick

sem_t chopstick[N];

// thread function for the philosphers

void  * philosopher(void * num){
    int id= *(int *)num;

    while(1){
        // thinking

        printf("philosphoher %d is thinking \n",id);
        sleep(3);  // thinking for three seconds

        // left and right chopstick

        int left=id;
        int right=(id+1)%N;


        // now try to pick the chopsticks

        // try for the left one
        if(sem_trywait(&chopstick[left])==0){
      // if left is acquired , try to pick the right one
      if(sem_trywait(&chopstick[right])==0){

        // now the bock the chopsticks are acquired 

        printf("philosopher %d is eating \n",id);
        sleep(2); // eating for two seconds

        // now release the left and right chopsticks

        sem_post(&chopstick[left]);
        sem_post(&chopstick[right]);
        printf("philosopher %d has released chopsticks %d and %d \n",id,left,right);

      }
      else{
        
        // could not acquire right chopstick , release left one

        sem_post(&chopstick[left]);
        printf("philosopher %d released chopstick %d as right chopstick %d is not available \n",id,left,right);
      }
        }

        // small delay  to avoid busy waiting and reduce the cpu usage
        usleep(100);
    }
}



int main(){
     pthread_t tid[N];  // Array to store thread IDs
    int ids[N];        // Array to store philosopher IDs

    // Initialize semaphores: each chopstick is initially available (value 1)
    for (int i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);  // pshared=0 (threads in same process)

    // Create philosopher threads
    for (int i = 0; i < N; i++) {
        ids[i] = i;  // Assign philosopher ID
        pthread_create(&tid[i], NULL, philosopher, &ids[i]);
        // pthread_create(thread ID, attributes, function, argument)
    }

    // Wait for threads to finish (in this case, they run forever)
    for (int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}