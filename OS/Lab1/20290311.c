#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    
    if (pipe(fd) == -1) {
        perror("error pipe.");
    }

    int child_pid = fork();

    if (child_pid < 0) {
        perror("error child.");
    }

    if (child_pid == 0) { 
        close(fd[1]); 
        

        int rows, columns;
        read(fd[0], &rows, sizeof(int));
        read(fd[0], &columns, sizeof(int));
        
        int transpozed[columns][rows];
        
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                read(fd[0], &transpozed[column][row], sizeof(int));
            }
        }

        printf("Child Process:\n");
        for (int column = 0; column < columns; column++) {
            for (int row = 0; row < rows; row++) {
                printf("%d ", transpozed[column][row]);
            }
            printf("\n");
        }
        printf("\n");

        close(fd[0]); 
    } else { 
        close(fd[0]); 

        
        int rows, columns;
        scanf("%d %d", &rows, &columns);
        int matrix[rows][columns];

        write(fd[1], &rows, sizeof(int));
        write(fd[1], &columns, sizeof(int));

        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                int num;
                scanf("%d", &num);
                matrix[row][column] = num;
                write(fd[1], &num, sizeof(int));
            }
        }

        close(fd[1]);
        wait(NULL); 
        printf("Parent Process:\n");
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                printf("%d ", matrix[row][column]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
