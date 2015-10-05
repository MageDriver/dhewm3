#ifndef __SYS_OPENMP_EXT__
#define __SYS_OPENMP_EXT__

#include <omp.h>

typedef omp_lock_t sys_sem_t;
#define Sys_Sem_Init(mutex_addr,pshared,value) omp_init_lock(mutex_addr);
#define Sys_Sem_Wait(mutex_addr) while (!omp_test_lock(mutex_addr))
#define Sys_Sem_Post(mutex_addr) omp_unset_lock(mutex_addr)

// Atomic Incrementor
#ifdef __GNUC__
#define Sys_Atomic_Inc(ptr) __sync_fetch_and_add ((ptr), 1)
#elif defined (_WIN32)
#define Sys_Atomic_Inc(ptr) InterlockedIncrement ((ptr))
#else
// I don't know the directive for atomic incrementors... fix me.
#error "Need some more porting work here"
#endif

#endif
