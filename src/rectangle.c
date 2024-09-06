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
    IShape ishape = ishape_init(calculate_area_of_rectangle);
    IPrintable iprintable = iprintable_init(print_rect);
    Rectangle c = {
        .ishape = ishape,
        .iprintable = iprintable,
        .height = height,
        .width = width,
    };
    return c;
}

FatPointer rectangle_make_shape(Rectangle *c) {
    FatPointer fp = {
        .ptr = c,
        .vtable = &c->ishape,
    };
    return fp;
}

FatPointer rectangle_make_printable(Rectangle *r) {
    FatPointer fp = {
        .ptr = r,
        .vtable = &r->iprintable,
    };
    return fp;
}