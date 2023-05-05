#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
    struct node* previous;
} node_t;
// size of 4 + 8 + 8 = 20B

node_t* make_node(int value, node_t* next, node_t* previous){
    
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = next;
    newNode->previous = previous;

    return newNode;

    // node_t node = make_node(value, next, previous);
}

node_t* add_back(node_t** list, int value) {
    if ((*list) == NULL) {
        node_t* node = make_node(value, NULL, NULL); 
        
        printf("- added successsfully\n");
        return node; 
        
    } else {
        // find the last element of the list
        printf("- started else\n");

        node_t* i = *list;
        while (i->next != NULL) {
            i = i->next;
            printf("- loop\n");
        }
        printf("- passed iterator\n");
        // now i, the node_t, contains the last node in the list, where i-> == NULL
        node_t* newNode = make_node(value, NULL, i);  
        i->next = newNode;

        printf("- ended else\n");
        return newNode;
    }
}

void print_list(node_t* list, int backwards) {
    for (node_t* node = list; node != NULL; node = node->next) {
        printf("%d \n", node->value);
    }
}

int main() {
    node_t* bruh = NULL;
    printf("- test01\n");

    bruh = add_back(&bruh, 5);
    print_list(bruh, 0);
    bruh = add_back(&bruh, 8);
    print_list(bruh, 0);
    bruh = add_back(&bruh, 12);
    print_list(bruh, 0);



}
