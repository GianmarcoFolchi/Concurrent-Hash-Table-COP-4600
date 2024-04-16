#include <pthread.h>  // For pthread_rwlock_t
#include <stdint.h>

typedef struct hash_struct {
    uint32_t hash;
    char name[50];
    uint32_t salary;
    struct hash_struct *next;
} hashRecord;

hashRecord *insert(const char *key, uint32_t salary);
hashRecord *search(const char *key);
hashRecord *delete(const char *key);
uint32_t hash(const uint8_t *name, size_t length);