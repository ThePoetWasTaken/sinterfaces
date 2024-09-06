#include "iprintable.h"
#include "ishape.h"

void print(FatPointer fp) {
    IPrintable *vtable = (IPrintable *)fp.vtable;
    vtable->print(fp.ptr);
}

IPrintable iprintable_init(void (*print)(void *)) {
    IPrintable p = {
        .print = print,
    };
    return p;
}
