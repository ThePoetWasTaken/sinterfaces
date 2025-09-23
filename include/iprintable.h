#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include "macros.h"

typedef struct _IPrintableVtable {
    void (*print)(void *);
} IPrintableVtable;

DEFINE_INTERFACE(IPrintable, IPrintableVtable);

IPrintableVtable iprintable_init(void (*print)(void *));
void print(IPrintable fp);

#endif