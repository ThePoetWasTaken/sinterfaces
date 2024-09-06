#ifndef FAT_POINTER_H
#define FAT_POINTER_H

typedef struct _FatPointer {
    void *vtable;
    void *ptr;
} FatPointer;

#endif