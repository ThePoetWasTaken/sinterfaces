#ifndef MACROS_H
#define MACROS_H

#define DEFINE_INTERFACE(interface_name, struct_name)              \
    typedef struct _##interface_name {                             \
        struct_name vtable;                                        \
        void *object;                                              \
    } interface_name;                                              \


#endif