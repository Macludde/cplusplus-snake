
#include "point.h"

Point Point::operator+(const Point& point) const {
    return Point(x+point.x, y+point.y);
}

Point Point::operator-(const Point& point) const {
    return Point(x-point.x, y-point.y);
}

bool Point::operator==(const Point& point) const {
    return x == point.x && y == point.y;
}

Point Point::operator=(const Point& point) {
    x = point.x;
    y = point.y;
    return *this;
}

Point middlePoint(int width, int height) {
    return Point(width/2, height/2);
}
