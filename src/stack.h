#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#define T Stack_T
typedef struct T *T;

extern T     Stack_new  (void);
extern int   Stack_empty(T stack);
extern void  Stack_push (T stack, void *x);
extern void *Stack_pop  (T stack);
extern void  Stack_free (T *stack);

#undef T
#endif
