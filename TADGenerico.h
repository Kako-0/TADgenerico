#ifndef _TAD_h_
#define _TAD_h_
typedef struct _cofo_ Cofo;

#ifdef _cofo_c_
    Cofo *cofCreate(int);
    int cofInsert(Cofo *, void *elm);
    void *cofQuerry(Cofo *, void *placa,void *marca, int(*cmp)(void*, void*, void*));
    void *cofRemove(Cofo *, void *placa, void *marca, int(*cmp)(void*, void *,void*));
    void *cofGetFirst(Cofo *c);
    void *cofGetNext(Cofo *c);
    int *cofDestroy(Cofo *c);
    int cmpPlacaMarca(void *placa,void *marca, void *elm);
#else
    extern Cofo *cofCreate(int);
    extern int cofInsert(Cofo *, void *elm);
    extern void *cofQuerry(Cofo *, void *placa, void *marca, int(*cmp)(void*, void*, void*));
    extern void *cofRemove(Cofo *, void *placa, void *marca, int(*cmp)(void*, void *,void*));
    extern void *cofGetFirst(Cofo *c);
    extern void *cofGetNext(Cofo *c);
    extern int *cofDestroy(Cofo *c);
    extern int cmpPlacaMarca(void *placa,void *marca, void *elm);

#endif // _cofo_c_
#endif // _cofo_h_
