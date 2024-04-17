#include <stdio.h>

#include "hashdb.h"

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) 
{   
    // Creates an input file pointer
    FILE *file = fopen("commands.txt", "r");
    
    // Checks if input file pointer is null
    if (file == NULL) 
    {
        return 1;
    }

    // Continues to process commands
    processCommands(file);

    // hashRecord *head = NULL;
    // head = insert(head, (const char *)"0", (uint32_t)0);
    // head = insert(head, (const char *)"1", (uint32_t)1);
    // head = insert(head, (const char *)"2", (uint32_t)2);
    // head = insert(head, (const char *)"1", (uint32_t)3);
    // head = insert(head, (const char *)"4", (uint32_t)4);
    // printList(head);

    return 0;
}

void processCommands(FILE *file) 
{
    char line[MAX_BUFFER_SIZE];

    hashRecord *head = NULL;

    while (fgets(line, MAX_BUFFER_SIZE, file) != NULL)
    {
        // Splits line at delim of ","
        char *token = strtok(line, ",");
        
        if (token != NULL) 
        {
            // Handle commands based on the first token
            if (strcmp(token, "threads") == 0) 
            {
                // Grabs next string before delim
                char *numThreadsParam = strtok(NULL, ",");

                // Converts string to int
                int numThreads = atoi(numThreadsParam);

                // Do thread action
            } 
            else if (strcmp(token, "insert") == 0) 
            {
                char *nameParam = strtok(NULL, ",");
                char *salaryParam = strtok(NULL, ",");

                uint32_t salary = atoi(salaryParam);

                // Insert/Upserts data for the record with name and salary
                head = insert(head, nameParam, salary);
            } 
            else if (strcmp(token, "delete") == 0) 
            {
                char *nameParam = strtok(NULL, ",");

                // Delete record with name from list
                head = delete(head, nameParam);
            } 
            else if (strcmp(token, "search") == 0) 
            {
                char *nameParam = strtok(NULL, ",");

                // Search for record with name and print to output
                hashRecord *result = search(head, nameParam);

                if (result != NULL) 
                {
                    printf("Found: %s, Salary: %d\n", result->name, result->salary);
                } 
                else {
                    printf("Not found\n");
                }

            } 
            else if (strcmp(token, "print") == 0) 
            {
                // Print entire contents of list to output
                printList(head);
            } 
            else 
            {
                printf("Unknown command: %s\n", token);
            }
        }
    }
}
