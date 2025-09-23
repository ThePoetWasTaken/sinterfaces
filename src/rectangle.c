#include "rectangle.h"

#include <stdio.h>

#include "iprintable.h"

double calculate_area_of_rectangle(void *ptr) {
    Rectangle *rect = (Rectangle *)ptr;
    return rect->height * rect->width;
}


void print_rect(void *ptr) {
    Rectangle *rect = (Rectangle *)ptr;
    printf("The rectangle area is %lf\n", calculate_area_of_shape(rectangle_make_shape(rect)));
}

Rectangle rectangle_init(double height, double width) {
    IShapeVtable ishape = ishape_init(calculate_area_of_rectangle);
    IPrintableVtable iprintable = iprintable_init(print_rect);
    Rectangle c = {
        .ishape = ishape,
        .iprintable = iprintable,
        .height = height,
        .width = width,
    };
    return c;
}

IShape rectangle_make_shape(Rectangle *c) {
    IShape fp = {
        .object = c,
        .vtable = c->ishape,
    };
    return fp;
}

IPrintable rectangle_make_printable(Rectangle *r) {
    IPrintable fp = {
        .object = r,
        .vtable = r->iprintable,
    };
    return fp;
}