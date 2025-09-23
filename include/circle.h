#ifndef CIRCLE_H
#define CIRCLE_h

#include "ishape.h"
#include "iprintable.h"

typedef struct _Circle {
    IShapeVtable ishape;
    IPrintableVtable iprintable;
    double radius;
} Circle;

Circle circle_init(double radius);
IShape circle_make_shape(Circle *c);
IPrintable circle_make_printable(Circle *c);

#endif 