#include <functional>

#ifndef POINT_H
#define POINT_H
struct Point {
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}
    Point(const Point& point): x(point.x), y(point.y) {}

    Point operator+(const Point& point) const;
    Point operator-(const Point& point) const;
    bool operator==(const Point& point) const;
    Point operator=(const Point& point);
};

namespace std {
    template <>
    struct hash<Point> {
        size_t operator()(const Point& point) const {
            // Combine the hash values of x and y using a hash function
            return hash<int>()(point.x) ^ hash<int>()(point.y);
        }
    };
}

const Point UP = Point(0, -1);
const Point RIGHT = Point(1, 0);
const Point DOWN = Point(0, 1);
const Point LEFT = Point(-1, 0);

Point middlePoint(int width, int height);

#endif