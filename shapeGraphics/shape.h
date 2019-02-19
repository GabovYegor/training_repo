#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "widget.h"

#define PI 3.14159

class Point{
public:
    int x, y;
public:
    Point(int x = 0, int y = 0): x(x), y(y){}
    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend class Parallelogram;
    Point& operator=(Point& point);
};

class Shape{
protected:
    std::string color;
    static unsigned id;
    static std::string defaultColor;
public:
    virtual void rotate(double) = 0;
    virtual void multiplicateCoordinate(unsigned) = 0;
    virtual void changeCoordinate(std::vector <class Point>&) = 0;
    virtual void print(class Widget&) = 0;
};

class Parallelogram: public Shape{
    std::vector <class Point> points;
    unsigned id;
public:
    Parallelogram(Point, Point, Point, std::string);
    Parallelogram(){}
    void rotate(double);
    void multiplicateCoordinate(unsigned);
    void changeCoordinate(std::vector <class Point>&);
    void print(class Widget&);
    friend std::ostream& operator<<(std::ostream&, const Parallelogram&);
};

class Ellipse: public Shape{
public:
    Ellipse(Point, Point ,Point, std::string);
    Ellipse(){}
    void rotate(double){}
    void multiplicateCoordinate(unsigned){}
    void changeCoordinate(std::vector <class Point>&){}
    void print(class Widget&){}
};

#endif // SHAPE_H
