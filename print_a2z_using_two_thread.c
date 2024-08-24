#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;
int turn = 0; // 0 for thread1, 1 for thread2

void* thread_func1(void* arg) {
    for (char c = 'a'; c <= 'z'; c += 2) {
        /* acquare lock */
        pthread_mutex_lock(&mutex);
        while (turn != 0) {
            pthread_cond_wait(&cond_var, &mutex);
        }
        /* First print then mark turn is 1 */
        printf("%c\t", c);
        turn = 1;
        /* signal to other thread */
        pthread_cond_signal(&cond_var);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* thread_func2(void* arg) {
    for (char c = 'b'; c <= 'z'; c += 2) {
        /* acquare lock */
        pthread_mutex_lock(&mutex);
        while(turn != 1) {
            pthread_cond_wait(&cond_var, &mutex);
        }
        /* first print then signal */
        printf("%c\t", c);
        turn = 0;
        /* signal to other thread */
        pthread_cond_signal(&cond_var);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    /* Create thread1 */
    if (pthread_create(&thread1, NULL, thread_func1, NULL) != 0) {
        printf("Unable to create thread1\n");
    }

    /* Create thread2 */
    if (pthread_create(&thread2, NULL, thread_func2, NULL) != 0) {
        printf("Unable to create thread2\n");
    }

    /* Wait for thread1 and thread2 to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    /* Destroy mutex and condition variable */
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);

    return 0;
}