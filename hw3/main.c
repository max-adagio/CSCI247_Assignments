#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ultron.h"

void ultron_init(Ultron* ultron);
void ultron_dump(Ultron* ultron);
int ultron_memory(Ultron* ultron, int location);
int ultron_accumulator(Ultron* ultron);
int ultron_pc(Ultron* ultron);
void ultron_load(Ultron* ultron, int size, int* instructions);
int ultron_run(Ultron* ultron);

// for testing only

void printArr(int *arr, int size) {
    printf("The array contains: ");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    Ultron U;
    ultron_init(&U);

    // printf("=== === Welcome to Ultron === ===\n");
    
    int instructNum = ULTRON_MEMORY_SIZE;
    int memArray[ULTRON_MEMORY_SIZE];
    int inputReg;


    // if the user wants to input instructions in the terminal
    if(argc >= 3 && strcmp(argv[1], "-i") == 0) {
        instructNum = atoi(argv[2]);
        for(int i = 0; i < instructNum; i++) {
            scanf("%d", &inputReg);
            getchar();
            memArray[i] = inputReg;
        }

        ultron_load(&U, instructNum, memArray);
        ultron_run(&U);
        printf("Result: %d\n", ultron_run(&U));
        ultron_dump(&U);

        return 0;
    }


    if(argc >= 3 && strcmp(argv[1], "-f") == 0) {
        FILE *file = fopen(argv[2], "r");
        int i=0;
        int num;
        while(fscanf(file, "%d", &num) > 0) {
            memArray[i] = num;
            i++;
        }
        fclose(file);

        ultron_load(&U, instructNum, memArray);
        ultron_run(&U);
        // printf("Result: %d\n", ultron_run(&U));
        ultron_dump(&U);

        return 0;
    }

    return 0;
}
