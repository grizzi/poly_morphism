#include <iostream>
#include <vector>

namespace geometry{

// Polygon class
class Polygon{
public:
    Polygon(double, double);
    ~Polygon() = default;
    double getLength() const;
    double getWidth() const;
    void setValues(double, double);
    void printArea();

    // virtual methods
    virtual double getArea() = 0;   // this defines a completely abstract method to be implemented by a base class --> pure virtual function

protected:
    double length_;
    double width_;
};

Polygon::Polygon(double length, double width):
        length_(length),
        width_(width)
{}

void Polygon::setValues(double length, double width){
    length_ = length;
    width_ = width;
}

void Polygon::printArea() {
    std::cout << getArea() << std::endl;
}

// Getters
double Polygon::getLength() const {return length_;};
double Polygon::getWidth() const {return width_;};


// Rectangle class
class Rectangle:
        public Polygon{
public:
    Rectangle(double, double);
    ~Rectangle() = default;
    double getArea();
};

Rectangle::Rectangle(double length, double width):
        Polygon::Polygon(length, width)
{}

double Rectangle::getArea() {
    return length_*width_;
}

Rectangle duplicate(Rectangle rect){
    Rectangle duplicate_rect = Rectangle(0.0, 0.0);   // can access because friend function
    duplicate_rect.setValues(rect.getLength()*2.0, rect.getWidth()*2.0);
    return duplicate_rect;
}

// Triangle class
class Triangle:
        public Polygon{
public:
    Triangle(double, double);
    ~Triangle() = default;
    double getArea();
};

Triangle::Triangle(double length, double width):
        Polygon::Polygon(length, width){};

double Triangle::getArea() {
    return length_*width_/2.0;
}

}
