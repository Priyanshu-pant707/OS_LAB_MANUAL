# Producer - consumer problem 
- using semaphore and pthread


## Introduction
- this problem is a classic example of process synchronization 
  - producer : generates data and puts it into a shared buffer.
  - consumer : takes data from the shared buffer and processes it.
  - constraints :  ensure the producer does not overwrite unconsumed items and consumer does not  read the empty slots.

## Synchronization tools 
1. counting semapgores -> to track the empty and full slots in the buffer.
2. mutex (pthread_mutex_t) ->  protect the critical seaction (buffer) to prevent race conditions.
3. Circular buffer -> efficiently use fixed-size buffer.




## producer thread function

```c
void *producer(void *args){
    int item = 0;
    for(int i = 0; i < 10; i++){
        item = i + 1; // Produced item

        sem_wait(&empty);          // Wait for empty slot
        pthread_mutex_lock(&mutex); // Lock critical section

        buffer[in] = item; // Insert item into buffer
        printf("producer produced %d at index %d \n", item, in);
        in = (in + 1) % BUFFER_SIZE; // Circular increment

        pthread_mutex_unlock(&mutex); // Unlock critical section
        sem_post(&full);             // Signal full slot available

        sleep(1); // Simulate production delay
    }
    return NULL;
}
```

- Step - by - step :
  1. produce item -> item=i+1;
  2. wait on empty semaphore -> ensures buffer has empty slots
  3. Lock mutex -> enter the critical section (exclusive access to buffer)
  4. insert item into buffer -> buffer[in]=item.
  5. circular increament -> in=(in+1)%buffersize.
  6. unlock mutex -> exit the critical section
  7. post full semaphore -> notify consumer that an element is available.
  8. sleep(1) -> simulate the production time.




## Consumer thread function

```c

void *consumer(void *args){
    int item;
    for(int i = 0; i < 10; i++){
        sem_wait(&full);           // Wait for filled slot
        pthread_mutex_lock(&mutex); // Lock critical section

        item = buffer[out];        // Remove item
        printf("consumer consumed %d from index %d \n", item, out);
        out = (out + 1) % BUFFER_SIZE; // Circular increment

        pthread_mutex_unlock(&mutex); // Unlock critical section
        sem_post(&empty);            // Signal empty slot available

        sleep(2); // Simulate consumption time
    }
    return NULL;
}


```

- Step - by - step :
 1. wait on full semaphore -> ensures buffer has item to consume.
 2. lock mutex -> exclusive access to buffer.
 3. consume item -> item=buffer[out]
 4. circular increment -> out=(out+1)% buffersize
 5. unlock the mutex -> allow other thread to access the buffer
 6. Post the empty semaphore -> signal the producer that empty slot is available
 7. sleep(2) -> simulate the consumption time.

 
