#include <stdio.h>
#include "jagged.c"

int main(int argc, char** argv) {
    jagged_t jagged;
    jagged_init(&jagged, 8);

    jagged_add(&jagged, 1, 145);
    jagged_add(&jagged, 1, 108);
    int success = 0;
    printf("%d\n", jagged_element(&jagged, 1, 0, &success));

//     jagged_add(&jagged, 4, 3);
//     jagged_add(&jagged, 1, 13);

//     jagged_remove(&jagged, 1, 0);

//     jagged_print(&jagged);

//     jagged_pack(&jagged);
//     jagged_print(&jagged);

//     jagged_unpack(&jagged);
//     jagged_print(&jagged);
}
