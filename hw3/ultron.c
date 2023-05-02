#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ultron.h"





void ultron_init(Ultron* ultron) {
    memset(ultron->memory, 0, ULTRON_MEMORY_SIZE*sizeof(int));
    ultron->pc = 0;
    ultron->ar = 0;
}

void ultron_dump(Ultron* ultron) {
    printf("PC: %d\n", ultron->pc);
    printf("AR: %d\n", ultron->ar);
    
    // we need to print the values right-aligned
    for(int i = 0; i < ULTRON_MEMORY_SIZE; i++){
        printf("%2d %4d\n",i, ultron->memory[i]);
    }
}

int ultron_memory(Ultron* ultron, int location) {
    return ultron->memory[location];
}

int ultron_accumulator(Ultron* ultron) {
    return ultron->ar; 
}

int ultron_pc(Ultron* ultron) {
    return ultron->pc;
}

void ultron_load(Ultron* ultron, int size, int* instructions) {
    for(int i = 0; i < size; i++){
        ultron->memory[i] = instructions[i];
    }
}

//======================================================
int ultron_run(Ultron* ultron) {

        int instruction = ultron->memory[ultron->pc];
        int operation = instruction / 100;
        int operand = instruction % 100;

        // printf("operation: %d   operand: %d \n", operation, operand);
    
    
    while(operation != HALT){

        int instruction = ultron->memory[ultron->pc];
        int operation = instruction / 100;
        int operand = instruction % 100;


        if(operation != READ && operation != WRITE &&
        operation != LOAD && operation != STORE &&
        operation != ADD && operation != SUBTRACT &&
        operation != BRANCHNEG && operation != HALT) {
            printf("ERROR : Invalid Operation\n");
            return -1; 
        }

        if(operand < 0 || operand > 32) {
            printf("ERROR : Invalid Operand Size\n");
            return -2;
        }

        if(ultron->pc < 0 || ultron->pc > 32) {
            printf("ERROR : Invalid PC size\n");
            return -3;
        }
        
        

        switch(operation) {
            case 10:
                // READ
                printf("? ");
                
                scanf("%d", &ultron->memory[operand]);
                
                ultron->pc++; 
                break;
            
            case 11: 
                // WRITE
                printf("= %d\n", ultron->memory[operand]);
                ultron->pc++; 
                break; 
            case 20:
                // LOAD
                //printf("%d\n", ultron->ar);
                ultron->ar = ultron->memory[operand];
                ultron->pc++; 
                break; 
            case 21:
                // store
                ultron->memory[operand] = ultron->ar;
                ultron->pc++; 
                break;
            case 30:
                // add
                // printf("%d\n", ultron->ar);
                // printf("%d\n", operand);

                ultron->ar += ultron->memory[operand];
                ultron->pc++; 
                break;
            case 31:
                // subtract
                ultron->ar -= ultron->memory[operand];
                ultron->pc++; 
                break;
            case 40:
                // branchneg
                if (ultron->ar < 0) {
                    ultron->pc = operand;
                } else {
                    ultron->pc++; 
                }
                
                break;
            case 43:
                // halt
                return 0;
                break;

            default:
                printf("Invalid operation\n");
                break;
        }
    }   
    return 0;
}

