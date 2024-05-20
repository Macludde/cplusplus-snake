#include "config.h"
#include <functional>
#include <iostream>

#ifndef POINT_H
#define POINT_H

struct Point {
    int x;
    int y;

    Point(const int x, const int y) : x(x), y(y) {};
    Point(const Point& other){
        x = other.x;
        y = other.y;
    };

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(const int scale) const;
    Point operator/(const int scale) const;
    Point& operator=(const Point& other);
    bool operator==(const Point& other) const;
    bool operator<(const Point& other) const;
};
std::ostream& operator<<(std::ostream& out, const Point p);

namespace std {
    template<> struct hash<Point>
    {
        std::size_t operator()(const Point& p) const noexcept
        {
            size_t hash = p.x*config.height*23 + p.y*17;
            return hash;
        }
    };
}

const Point UP = Point(0, -1);
const Point RIGHT = Point(1, 0);
const Point DOWN = Point(0, 1);
const Point LEFT = Point(-1, 0);

Point middlePoint(int width, int height);

#endif