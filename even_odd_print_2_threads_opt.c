#include <stdio.h>
#include <pthread.h>
/*
Key Optimizations:
Reduce Locking Overhead: Move the lock inside the if block to reduce unnecessary locking.
Avoid Busy-Waiting: Introduce pthread_cond_t to avoid busy-waiting and make the threads wait
until it's their turn to execute, which will save CPU cycles.
Separate Counter for Each Thread: Use separate counters for even and odd threads to avoid contention.
*/
int count = 0;
pthread_mutex_t lock;

void* even_print(void* args) {
    int arg = *(int*)args;
    while(1) {
        pthread_mutex_lock(&lock);
        if(count % 2 == 0 && count <= arg) {
            printf(" %d\t", count);
            count++;
        }
        pthread_mutex_unlock(&lock);
        if(count > arg) {
            break;
        }
    }
    return NULL;
}

void* odd_print(void* args) {
    int arg = *(int*)args;
    while(1) {
        pthread_mutex_lock(&lock);
        if(count % 2 != 0 && count <= arg) {
            printf(" %d\t", count);
            count++;
        }
        pthread_mutex_unlock(&lock);
        if(count > arg) {
            break;
        }
    }
    return NULL;
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create two threads
    pthread_t even_thread, odd_thread;
    int args = 100;
    pthread_create(&even_thread, NULL, even_print, &args);
    pthread_create(&odd_thread, NULL, odd_print, &args);
  
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}