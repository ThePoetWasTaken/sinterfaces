#include <stdio.h>

#include "ishape.h"
#include "iprintable.h"
#include "circle.h"
#include "rectangle.h"

int main() {
    Circle c = circle_init(3);
    Rectangle r = rectangle_init(4, 3);
    
    FatPointer shape1 = circle_make_shape(&c);
    FatPointer shape2 = rectangle_make_shape(&r);

    FatPointer printable1 = circle_make_printable(&c);
    FatPointer printable2 = rectangle_make_printable(&r);

    printf("%lf, %lf\n", calculate_area_of_shape(shape1), calculate_area_of_shape(shape2));

    print(printable1);
    print(printable2);
    return 0;
}