#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ishape.h"
#include "iprintable.h"
#include "fatpointer.h"

typedef struct _Rectangle {
    IShape ishape;
    IPrintable iprintable;
    double height;
    double width; 
} Rectangle;

Rectangle rectangle_init(double height, double width);
FatPointer rectangle_make_shape(Rectangle *c);
FatPointer rectangle_make_printable(Rectangle *c);

#endif