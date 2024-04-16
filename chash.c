#include <stdio.h>

#include "hashdb.h"

// 	Your main program that reads the commands.txt and produces output to the
// console

int main(int argc, char *argv[]) {
    printf("HERE\n");
    printf("%u", hash((const uint8_t *)"a", 1));
}