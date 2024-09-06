#include "ishape.h"
#include "fatpointer.h"

double calculate_area_of_shape(FatPointer fp) {
    IShape *vtable = (IShape *)fp.vtable;
    return vtable->calculate_area(fp.ptr);
}

IShape ishape_init(double (*calculate_area)(void *)) {
    IShape ishape = {
        .calculate_area = calculate_area,
    };
    return ishape;
}