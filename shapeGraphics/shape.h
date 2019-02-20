#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "widget.h"
#include <QString>

#define PI 3.14159

class Point{
public:
    int x, y;
public:
    Point(int x = 0, int y = 0): x(x), y(y){}
    friend std::ostream& operator<<(std::ostream&, const Point&);
    Point& operator=(Point& point);
};

class Shape{
protected:
    std::vector <class Point> points;
    QString color;
    static unsigned id;
    static QString defaultColor;
public:
    Shape(){
        ++id;
    }
    virtual void rotate(double) = 0;
    virtual void multiplicateCoordinate(double) = 0;
    virtual void changeCoordinate(std::vector <class Point>&) = 0;
    void setColor(QString color){this->color = color;}
    friend class Widget;
};

class Parallelogram: public Shape{
    unsigned id;
    // mb add own variable & write in points from base class
public:
    Parallelogram(Point, Point, Point, QString);
    Parallelogram(){}
    void rotate(double);
    void multiplicateCoordinate(double);
    void changeCoordinate(std::vector <class Point>&);
    friend std::ostream& operator<<(std::ostream&, const Parallelogram&);
};

class Ellipse: public Shape{
    unsigned id;
    // mb add own variable & write in points from base class
public:
    Ellipse(Point, Point ,Point, QString);
    Ellipse(){}
    void rotate(double);
    void multiplicateCoordinate(double);
    void changeCoordinate(std::vector <class Point>&);
    friend std::ostream& operator<<(std::ostream&, const Ellipse&);
};

class EllipseSector: public Shape{
    unsigned id;
    // mb add own variable & write in points from base class
public:
    EllipseSector(Point, Point, Point, QString);
    EllipseSector(){}
    void rotate(double);
    void multiplicateCoordinate(double);
    void changeCoordinate(std::vector <class Point>&);
};

#endif // SHAPE_H
