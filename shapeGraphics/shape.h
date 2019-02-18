#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <string>

class Point{
    int x, y;
public:
    Point(int x = 0, int y = 0): x(x), y(y){}
    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend class Parallelogram;
};

class Shape{
protected:
    std::string color;
    static unsigned id;
    static std::string defaultColor;
public:
    virtual void rotate(double) = 0;
    virtual void multiplicateCoordinate(unsigned) = 0;
    virtual void changeCoordinate(Point, Point, Point) = 0;
};

class Parallelogram: public Shape{
    Point centre, point1, point2;
    unsigned id;
public:
    Parallelogram(Point, Point, Point, std::string);
    void rotate(double);
    void multiplicateCoordinate(unsigned);
    void changeCoordinate(Point, Point, Point);
    friend std::ostream& operator<<(std::ostream&, const Parallelogram&);
};

#endif // SHAPE_H
