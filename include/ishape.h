#ifndef ISHAPE_H
#define ISHAPE_H

#include "fatpointer.h"

typedef struct _IShape {
    double (*calculate_area)(void *);
} IShape;

IShape ishape_init(double (*calculate_area)(void *));
double calculate_area_of_shape(FatPointer fp);

#endif