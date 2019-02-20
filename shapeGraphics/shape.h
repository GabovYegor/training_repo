#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

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
    std::vector <class Point> points;
    std::string color;
    static unsigned id;
    static std::string defaultColor;
public:
    Shape(){
        ++id;
    }
    virtual void rotate(double) = 0;
    virtual void multiplicateCoordinate(unsigned) = 0;
    virtual void changeCoordinate(std::vector <class Point>&) = 0;
};

class Parallelogram: public Shape{
    unsigned id;
public:
    Parallelogram(Point, Point, Point, std::string);
    Parallelogram(){}
    void rotate(double);
    void multiplicateCoordinate(unsigned);
    void changeCoordinate(std::vector <class Point>&);
    friend std::ostream& operator<<(std::ostream&, const Parallelogram&);
};

class Ellipse: public Shape{
    unsigned id;
public:
    Ellipse(Point, Point ,Point, std::string);
    Ellipse(){}
    void rotate(double){}
    void multiplicateCoordinate(unsigned);
    void changeCoordinate(std::vector <class Point>&);
    friend std::ostream& operator<<(std::ostream&, const Ellipse&);
};

#endif // SHAPE_H
