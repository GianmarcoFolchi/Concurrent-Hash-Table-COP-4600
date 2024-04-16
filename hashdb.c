#include "hashdb.h"

// Your Concurrent Hash Table implementation, including your Jenkins function
// and all linked list operations

// hashRecord *insert(hashRecord head, char *key, uint32_t salary) {
//     uint32_t hashValue = hash((const uint8_t *)key, strlen(key));
//     // TODO: Get writer lock here
// }

hashRecord *search(hashRecord *head, const char *key) {
    uint32_t hashValue = hash((const uint8_t *)key, strlen(key));
    // TODO: acquire a reader lock
    hashRecord *dummyHead = calloc(1, sizeof(hashRecord));
    dummyHead->next = head;
    hashRecord *runner = dummyHead;

    while (runner != NULL) {
        if (runner->hash == hashValue) {
            break;
        }
        runner = runner->next;
    }
    // TODO: release reader lock
    free(dummyHead);
    return runner;
}

hashRecord *delete(hashRecord *head, const char *key) {
    uint32_t hashValue = hash((const uint8_t *)key, strlen(key));
    // TODO: acquire a writer lock
    hashRecord *dummyHead = calloc(1, sizeof(hashRecord));
    dummyHead->next = head;
    hashRecord *runner = dummyHead;

    while (runner->next != NULL) {
        if (runner->next->hash == hashValue) {
            // TODO: Delete next node
            // TODO: release writer lock
            free(dummyHead);
        }
    }
    // TODO: release writer lock
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