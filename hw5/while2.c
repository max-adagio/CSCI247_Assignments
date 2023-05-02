#include <stdio.h>

int main() {
    int num = 5;     // argv[1]

    int i = 0;
    int j = num;   

    // outer loop must loop num times
    while (i < num) {
        j = i;
        while (j >= 0) {
            printf("*");
            j--;
        }
        printf("\n");
        i++;
    }
}