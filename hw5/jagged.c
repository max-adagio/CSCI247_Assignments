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


    return 0;
}

// Return the element stored at the given bin and slot number.
// Success is set to 0 if the element was found, or -1 otherwise.
// If success is -1, 0 is returned.
int jagged_element(jagged_t* jagged, int bin, int slot, int* success) {
    return -1;
}

// Add an element to the bin. Return 0 is the element was
// added, or -1 if the representation is packed
int jagged_add(jagged_t* jagged, int bin, int element) {
    return -1;
}

// Remove the element from the given bin and slot. Return 0 on success,
// or -1 if the representation was packed or element not found.
int jagged_remove(jagged_t* jagged, int bin, int slot) {
    return -1;
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
