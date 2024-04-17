#include "hashdb.h"

// Your Concurrent Hash Table implementation, including your Jenkins function
// and all linked list operations

hashRecord *insert(hashRecord *head, const char *key, uint32_t salary) {
    uint32_t hashValue = hash((const uint8_t *)key, strlen(key));
    printf("INSERT,%u,%s,%d\n", hashValue, key, salary);

    hashRecord *newNode = calloc(1, sizeof(hashRecord));
    strncpy(newNode->name, key, sizeof(newNode->name) - 1);
    newNode->hash = hashValue;
    newNode->salary = salary;

    acquireWriteLock();

    // If the list is empty or the new node should be placed at the front
    if (head == NULL || newNode->hash < head->hash) {
        newNode->next = head;
        releaseWriteLock();
        return newNode;
    }

    // Find the insert position
    hashRecord *current = head;
    while (current->next != NULL && current->next->hash < newNode->hash) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;

    releaseWriteLock();
    return head;
}

hashRecord *search(hashRecord *head, const char *key) {
    uint32_t hashValue = hash((const uint8_t *)key, strlen(key));
    printf("SEARCH,%s\n", key);
    acquireReadLock();
    hashRecord *runner = head;
    while (runner != NULL) {
        if (runner->hash == hashValue) {
            break;
        }
        runner = runner->next;
    }
    releaseReadLock();
    return runner;
}

hashRecord *delete(hashRecord *head, const char *key) {
    uint32_t hashValue = hash((const uint8_t *)key, strlen(key));
    printf("DELETE,%s\n", key);
    acquireWriteLock();
    hashRecord *dummyHead = calloc(1, sizeof(hashRecord));
    dummyHead->next = head;
    hashRecord *runner = dummyHead;

    while (runner->next != NULL) {
        if (runner->next->hash == hashValue) {
            hashRecord *tmp = runner->next;
            runner->next = runner->next->next;
            free(tmp);
            break;
        }
        runner = runner->next;
    }
    releaseWriteLock();
    free(dummyHead);
    return head;
}

uint32_t hash(const uint8_t *name, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    while (i != length) {
        hash += name[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

// TODO: Fill these out
void acquireWriteLock() { printf("WRITE LOCK ACQUIRED\n"); }
void releaseWriteLock() { printf("WRITE LOCK RELEASED\n"); }
void acquireReadLock() { printf("READ LOCK ACQUIRED\n"); }
void releaseReadLock() { printf("READ LOCK RELEASED\n"); }

void printList(hashRecord *head) {
    if (head == NULL) return;
    hashRecord *runner = head;
    while (runner != NULL) {
        printf("%u,%s,%d", runner->hash, runner->name, runner->salary);
        runner = runner->next;
        if (runner != NULL) {
            printf("\n");
        }
    }
    printf("\n");
}