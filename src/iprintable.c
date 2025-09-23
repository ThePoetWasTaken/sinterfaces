#include "iprintable.h"

void print(IPrintable fp) {
    IPrintableVtable vtable = fp.vtable;
    vtable.print(fp.object);
}

IPrintableVtable iprintable_init(void (*print)(void *)) {
    IPrintableVtable p = {
        .print = print,
    };
    return p;
}
