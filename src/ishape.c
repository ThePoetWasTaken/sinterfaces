#include "ishape.h"

double calculate_area_of_shape(IShape fp) {
    return fp.vtable.calculate_area(fp.object);
}

IShapeVtable ishape_init(double (*calculate_area)(void *)) {
    IShapeVtable ishape = {
        .calculate_area = calculate_area,
    };
    return ishape;
}