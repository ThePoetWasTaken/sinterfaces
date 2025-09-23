#include "circle.h"

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#   define M_PI 3.14159265358979323846 
#endif


double calculate_area_of_circle(void *ptr) {
    Circle *circle = (Circle *)ptr;
    return M_PI * circle->radius * circle->radius;
}

void print_circle(void *ptr) {
    printf("The circle area is %lf\n", calculate_area_of_shape(circle_make_shape(ptr)));
}

Circle circle_init(double radius) {
    IShapeVtable ishape = ishape_init(calculate_area_of_circle);
    IPrintableVtable iprintable = iprintable_init(print_circle);
    Circle c = {
        .iprintable = iprintable,
        .ishape = ishape,
        .radius = radius,
    };
    return c;
}

IShape circle_make_shape(Circle *c) {
    IShape fp = {
        .object = c,
        .vtable = c->ishape,
    };
    return fp;
}

IPrintable circle_make_printable(Circle *c) {
    IPrintable fp = {
        .object = c,
        .vtable = c->iprintable,
    };
    return fp;
}