#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "jagged.h"

// Initialize a jagged array object with the given number of bins.
// The array is initially unpacked.
void jagged_init(jagged_t* jagged, int bins) {
    jagged->size = 0;
    jagged->number_of_bins = bins;
    
    jagged->bins = calloc(bins,sizeof(entry_t*));
    
    // packed variables
    jagged->packed_values = NULL;
    jagged->offsets = NULL;
}

void jagged_free(jagged_t* jagged) {
    // jagged_t* i = jagged->bin[0];

    for (int i = 0; i < jagged->number_of_bins; i++) {
        if (jagged->bins[i] == NULL) {
            free(jagged->bins[i]);
            return;
        } else {
            entry_t* ptr = jagged->bins[i];
            while(jagged->bins[i] != NULL) {
                entry_t* temp = ptr->next;
                free(ptr);
                ptr = temp;
            }
            free(ptr);
            return;
        }
    }
    free(jagged->bins);
        // REMEMBER: to add code to free the actual entry linklists 
}

// Return the number of elements in the jagged array
int jagged_size(jagged_t* jagged) {
    return jagged->size;
}

// Return the number of bins
int jagged_bins(jagged_t* jagged) {
    return jagged->number_of_bins;
}

// Return the number of slots in the given bin
int jagged_slots(jagged_t* jagged, int bin) {
    entry_t* cur = jagged->bins[bin];
    int sizeOfBin = 0;
    while(cur->next != NULL) {
        cur = cur->next;
        sizeOfBin++;
    }
    return sizeOfBin;
}

// Return the element stored at the given bin and slot number.
// Success is set to 0 if the element was found, or -1 otherwise.
// If success is -1, 0 is returned.
int jagged_element(jagged_t* jagged, int bin, int slot, int* success) {
    entry_t* ptr = jagged->bins[bin];
    // traverse until you get to slot
    // if (jagged_slots(jagged, bin) >= slot) {
    //     *success = -1;
    //     return 0;
    // }
    // ptr might be pointing to NULL if jagged_add isn't working
    for (int i = 0; i <= slot; i++) {
        if (ptr == NULL) {  // if ptr is null
            *success = -1; 
            return 0;
        } if (i == slot && ptr != NULL) {
            // the slot has been found
            *success = 0;
            return ptr->value;
        }
        ptr = ptr->next;
    }

    *success = -1;
    return 0;
}

// Add an element to the bin. Return 0 is the element was
// added, or -1 if the representation is packed

// int jagged_add(jagged_t* jagged, int bin, int element) {
//     entry_t* binPtr = jagged->bins[bin];
    
//     if (jagged->bins[bin] == NULL) {
//         binPtr = (entry_t*) malloc(sizeof(entry_t*));
//         binPtr->value = element;
//         binPtr->next = jagged->bins[bin];
//         jagged->bins[bin] = binPtr;
//     } else {
//         // traverse to the last node in the list
//         entry_t* node = binPtr;
//         while (node->next != NULL) {
//             node = node->next;
//         }
//         // now we have found the last node in the bin
//         entry_t* newNode = (entry_t*) malloc(sizeof(entry_t));
//         newNode->value = element;
//         newNode->next = NULL;
//         node->next = newNode;
//     }
// }

int jagged_add(jagged_t* jagged, int bin, int element) {
    entry_t* cur = jagged->bins[bin];
    entry_t* new = (entry_t*) malloc(sizeof(entry_t*));
    new->value = element;
    new->next = NULL;

    if (jagged->bins[bin] == NULL) {
        jagged->bins[bin] = new;
        // return 0;
    } else {
        entry_t* i = cur;
        while(i->next != NULL) {
            i = i->next;
        }   // now the last node has been found
        i->next = new;         
        // return 0;
    }

    jagged->size++;
    // free(new);
    return -1;
}



// Remove the element from the given bin and slot. Return 0 on success,
// or -1 if the representation was packed or element not found.
int jagged_remove(jagged_t* jagged, int bin, int slot) {
    entry_t* ptr = jagged->bins[bin];

    if (ptr == NULL) {  // the linked list is not empty
        return -1;
    } else if (slot == 0) {     // slot is 0
        jagged->bins[bin] = ptr->next;
        jagged->size--;
        free(ptr);
        return 0;
    } else {        // linked list has values, and slot is not 0
        for (int i = 0; i <= slot; i++) {
            if (ptr->next == NULL) {
                return -1;
            } else if (i == slot - 1){  // possibly need to && with ptr->next == NULL
                entry_t* nextNode = ptr->next->next;
                free(ptr->next);
                ptr->next = nextNode;
                jagged->size--;
                return 0;
            }
            ptr = ptr->next;
        }
    }


    // // error catcher
    // if (ptr == NULL || bin < 0 || bin > jagged->number_of_bins || slot < 0 || slot > jagged_slots(jagged, bin)) {
    //     return -1;
    // }

    // int i = 0;
    // while (i <= slot) {
    //     ptr->next;
    //     i++;
    // }   // now ptr is pointing to the #"slot" node in the list
    
    // if (ptr->next->next != NULL) {
    //     ptr->next = ptr->next->next;
    //     free(ptr);
    // } else {

    // }

    // // check if [bin][slot] exists
    // for (int i = 0; i <= slot; i++) {
    //     if (ptr == NULL) {  // if the bin is empty
    //         return -1;      // there is no element to find

    //     } if (i == slot && ptr != NULL) {
    //         // the slot has been found
            
    //         return ptr->value;
    //     }
    //     ptr = ptr->next;
    // }

}

// Unpack the jagged array. Return 0 if successful or -1 if the array is
// already unpacked.
int jagged_unpack(jagged_t* jagged) {
    return -1;
}

// Pack the jagged array. Return 0 if successful or -1 if the array is already
// packed.
int jagged_pack(jagged_t* jagged) {
    return -1;
}

// Print a jagged array out. Useful for debugging
void jagged_print(jagged_t* jagged) {
}
