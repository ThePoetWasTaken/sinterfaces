#ifndef ISHAPE_H
#define ISHAPE_H

#include "macros.h"

typedef struct _IShapeVtable {
    double (*calculate_area)(void *);
} IShapeVtable;

DEFINE_INTERFACE(IShape, IShapeVtable);

IShapeVtable ishape_init(double (*calculate_area)(void *));
double calculate_area_of_shape(IShape fp);

#endif