#include "jagged.h"

int main(int argc, char** argv) {
    jagged_t jagged;
    jagged_init(&jagged, 8);

    jagged_add(&jagged, 1, 5);
    jagged_add(&jagged, 1, 7);

    jagged_add(&jagged, 4, 3);
    jagged_add(&jagged, 1, 13);

    jagged_remove(&jagged, 1, 0);

    jagged_print(&jagged);

    jagged_pack(&jagged);
    jagged_print(&jagged);

    jagged_unpack(&jagged);
    jagged_print(&jagged);
}
