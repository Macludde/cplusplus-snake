
#include "point.h"
#include <iostream>

Point middlePoint(int width, int height) {
    return Point(width/2, height/2);
}

std::ostream& operator<<(std::ostream& out, const Point p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

Point Point::operator+(const Point& other) {
    return Point(x+other.x, y+other.y);
};
Point Point::operator-(const Point& other) {
    return Point(x-other.x, y-other.y);
};

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    return *this;
};


bool Point::operator==(const Point& other) const {
    std::cout << "checking point equality: " << (*this) << " == " << other << std::endl;
    return (x == other.x && y == other.y);
};

bool Point::operator<(const Point& other) const {
    return (x < other.x || (x == other.x && y < other.y));
};