#ifndef CIRCLE_H
#define CIRCLE_h

#include "ishape.h"
#include "iprintable.h"
#include "fatpointer.h"

typedef struct _Circle {
    IShape ishape;
    IPrintable iprintable;
    double radius;
} Circle;

Circle circle_init(double radius);
FatPointer circle_make_shape(Circle *c);
FatPointer circle_make_printable(Circle *c);

#endif 