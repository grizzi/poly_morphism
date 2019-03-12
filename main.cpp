#include <iostream>
#include "include/polygon.h"

int main() {
    geometry::Rectangle rect_1(2, 3);
    rect_1.printArea();

    geometry::Rectangle rect_2 = geometry::duplicate(rect_1);
    rect_2.printArea();

    geometry::Triangle triangle(3.0, 1.0);
    triangle.printArea();

    // pointers of Rectangle/Triangle are compatible with pointers of type Polygon
    geometry::Polygon * pol1 = &rect_1;
    geometry::Polygon * pol2 = &rect_2;
    geometry::Polygon * pol3 = &triangle;

    pol1->printArea();
    pol2->printArea();
    pol3->printArea();

}