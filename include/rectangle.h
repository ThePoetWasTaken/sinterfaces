#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ishape.h"
#include "iprintable.h"

typedef struct _Rectangle {
    IShapeVtable ishape;
    IPrintableVtable iprintable;
    double height;
    double width; 
} Rectangle;

Rectangle rectangle_init(double height, double width);
IShape rectangle_make_shape(Rectangle *c);
IPrintable rectangle_make_printable(Rectangle *c);

#endif