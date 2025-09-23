#include <stdio.h>

#include "ishape.h"
#include "iprintable.h"
#include "circle.h"
#include "rectangle.h"

int main() {
    Circle c = circle_init(3);
    Rectangle r = rectangle_init(4, 3);
    
    IShape shape1 = circle_make_shape(&c);
    IShape shape2 = rectangle_make_shape(&r);

    IPrintable printable1 = circle_make_printable(&c);
    IPrintable printable2 = rectangle_make_printable(&r);

    print(printable1);
    print(printable2);
    return 0;
}