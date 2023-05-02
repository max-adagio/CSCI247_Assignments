#include <stdio.h>

int main() {
    int r9 = 5;     // argv[1]

    int i = 0;
    int j = r9;   

    // outer loop must loop r9 times

    while (i < r9) {
        if(r9 - j <= r9) { 
            int loop = j;
            while (loop < r9+1) {
                printf("*");
                loop++;
            }
        } 
        j--;
        printf("\n");
        i++;
    }
}