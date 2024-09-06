#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include "fatpointer.h"

typedef struct _IPrintable {
    void (*print)(void *);
} IPrintable;

void print(FatPointer fp);
IPrintable iprintable_init(void (*print)(void *));

#endif