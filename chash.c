#include <stdio.h>

#include "hashdb.h"

// 	Your main program that reads the commands.txt and produces output to the
// console

int main(int argc, char *argv[]) {
    hashRecord *head = NULL;
    head = insert(head, (const char *)"0", (uint32_t)0);
    head = insert(head, (const char *)"1", (uint32_t)1);
    head = insert(head, (const char *)"2", (uint32_t)2);
    head = insert(head, (const char *)"1", (uint32_t)3);
    head = insert(head, (const char *)"4", (uint32_t)4);
    printList(head);
}