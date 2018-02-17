#ifndef POINT_H
#define POINT_H

#include <iostream>

namespace figure {

using namespace std;

class Point {

public:

    explicit Point(int a = 0, int b = 0);

    int getX() const;

    int getY() const;

    Point operator+(const Point &p) const;

    Point &operator+=(const Point &p);

    Point &operator=(const Point &p);

    friend ostream &operator<<(ostream &os, const Point &p);

private:

    int x;
    int y;

};

}

#endif
