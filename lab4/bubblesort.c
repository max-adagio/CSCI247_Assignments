#include <stdio.h>


typedef struct {

     char *data;

     int key;

} item;

 

item array[] = {

     {"Bill", 62},

     {"Hill", 60},

     {"Barcak", 42},

     {"Dicky", 105},

     {"W.", 1},

};


void sortOG(item *a, int size) { 
    int i = 0, j = 0;

    int s;

    for (; i < size && s != 0; i++) {

        s = 0;
        for (j = 0; j < size; j++) {
                if (a[j].key > a[j+1].key) {

                        item t = a[j];
                        a[j] = a[j+1];
                        a[j+1] = t;
                        s++;
                }
        }
        size--;
    }
}

//Sort the items
void sort(item *array, int size) { 
    // int i = 0, j = 0;
    // int s;

    for(int i = 0; i < size - 1; i++) {
        // s = 0;
        // printf("%d\n",i);

        for (int j = 0; j < size - i - 1; j++) {
            printf("%d\n",j);
            if (array[j].key > array[j+1].key) {
                item temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                //s++;
            }
        }
        //size--;
    }

}

// void sort2(item array[], int size) {

//     // loop to access each array element
//     for (int i = 0; i < size - 1; i++) {
        
//     // loop to compare array elements
//         for (int j = 0; j < size - i - 1; j++) {
            
//             // compare two adjacent elements
//             // change > to < to sort in descending order
//             if (array[j].key > array[j + 1].key) {
            
//             // swapping occurs if elements
//             // are not in the intended order
//             item temp = array[j];
//             array[j] = array[j + 1];
//             array[j + 1] = temp;
//             }
//         }
//     }
// }
   

int main() {

    for (int i = 0; i < 5; i++){
        printf("(%d ", array[i].key);
        printf("%s) ", array[i].data);
    }

    printf("\n");
    sort(array,5); 

    for (int i = 0; i < 5; i++){
        printf("(%d ", array[i].key);
        printf("%s) ", array[i].data);
    }
    printf("\n");

    return 0;

}



