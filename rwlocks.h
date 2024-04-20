#ifndef _RWLOCK_H_
#define _RWLOCK_H_

#include <semaphore.h>

// Define the rwlock_t structure
typedef struct _rwlock_t {
    sem_t writelock;
    sem_t lock;
    int readers;
} rwlock_t;

// Declare functions for initializing the lock
void rwlock_init(rwlock_t *lock);

// Declare functions for acquiring and releasing read locks
void rwlock_acquire_readlock(rwlock_t *lock);
void rwlock_release_readlock(rwlock_t *lock);

// Declare functions for acquiring and releasing write locks
void rwlock_acquire_writelock(rwlock_t *lock);
void rwlock_release_writelock(rwlock_t *lock);

#endif // _RWLOCK_H_
