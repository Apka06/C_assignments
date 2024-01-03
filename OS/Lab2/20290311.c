#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int matrix[MAX_ROWS][MAX_COLS];
int column_totals[MAX_COLS];
int num_rows, num_cols;

sem_t mutex;

void *calculate_column(void *arg) {
    int idx = *(int *)arg;
    int total = 0;

    for (int i = 0; i < num_rows; ++i) {
        total += matrix[i][idx];
    }

    sem_wait(&mutex);
    column_totals[idx] = total;
    sem_post(&mutex);

    pthread_exit(NULL);
}

void *print_totals(void *arg) {

    sem_wait(&mutex);
    for (int i = 0; i < num_cols - 1; ++i) {
        for (int j = 0; j < num_cols - i - 1; ++j) {
            if (column_totals[j] > column_totals[j + 1]) {

                int temp = column_totals[j];
                column_totals[j] = column_totals[j + 1];
                column_totals[j + 1] = temp;
            }
        }
    }
    sem_post(&mutex);

    for (int i = 0; i < num_cols; ++i) {
        printf("%d", column_totals[i]);
	if (i < num_cols - 1){printf(" ");}
    }
	printf("\n");
    pthread_exit(NULL);
}

int main() {

    scanf("%d %d", &num_rows, &num_cols);

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    sem_init(&mutex, 0, 1);

    pthread_t threads[num_cols];
    int column_indices[num_cols];

    for (int i = 0; i < num_cols; ++i) {
        column_indices[i] = i;
        pthread_create(&threads[i], NULL, calculate_column, (void *)&column_indices[i]);
    }

    for (int i = 0; i < num_cols; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_t print_thread;
    pthread_create(&print_thread, NULL, print_totals, NULL);

    pthread_join(print_thread, NULL);

    sem_destroy(&mutex);

    return 0;
}

