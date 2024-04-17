#include <stdio.h>

#include "hashdb.h"

#define MAX_BUFFER_SIZE 1024

void processCommands(FILE *file);

int main(int argc, char *argv[]) {
    // Creates an input file pointer
    FILE *file = fopen("commands.txt", "r");
    if (file == NULL) {
        return 1;
    }
    processCommands(file);

    return 0;
}

void processCommands(FILE *file) {
    char line[MAX_BUFFER_SIZE];

    hashRecord *head = NULL;

    while (fgets(line, MAX_BUFFER_SIZE, file) != NULL) {
        // Splits line at delim of ","
        char *token = strtok(line, ",");

        if (token != NULL) {
            // Handle commands based on the first token
            if (strcmp(token, "threads") == 0) {
                // Grabs next string before delim
                char *numThreadsParam = strtok(NULL, ",");
                int numThreads = atoi(numThreadsParam);

                // Do thread action
                printf("Running %d threads\n", numThreads);
            } else if (strcmp(token, "insert") == 0) {
                char *nameParam = strtok(NULL, ",");
                char *salaryParam = strtok(NULL, ",");
                uint32_t salary = atoi(salaryParam);
                head = insert(head, nameParam, salary);
            } else if (strcmp(token, "delete") == 0) {
                char *nameParam = strtok(NULL, ",");
                head = delete (head, nameParam);
            } else if (strcmp(token, "search") == 0) {
                char *nameParam = strtok(NULL, ",");
                search(head, nameParam);
            } else if (strcmp(token, "print") == 0) {
                printList(head);
            } else {
                printf("Unknown command: %s\n", token);
            }
        }
    }
}