#include "shape.h"

unsigned Shape::id = 0;
QString Shape::defaultColor = "white";

std::ostream& operator<<(std::ostream& out, const Point& point){
    out << "X: " << point.x << " Y: " << point.y;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Parallelogram& parallelogram){
    //out << "COLOR: " << parallelogram.color << std::endl;
    out << "ID: " << parallelogram.id << std::endl;
    for(unsigned i = 0; i < parallelogram.points.size(); ++i){
        std::cout << "Point " << i << " " << parallelogram.points[i] << std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse){
    //out << "COLOR " << ellipse.color << std::endl;
    out << "ID: " << ellipse.id << std::endl;
    for(unsigned i = 0; i < ellipse.points.size(); ++i)
        std::cout << "Point: " << i << ellipse.points[i] << std::endl;
    return out;
}

Point& Point::operator=(Point& point){
    this->x = point.x;
    this->y = point.y;
    return *this;
}

Parallelogram::Parallelogram(Point point1 = Point(0, 0), Point point2 = Point(0, 0), Point point3 = Point(0, 0), QString color = defaultColor)
            : id(Shape::id){
    this->color = color;
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
    points.push_back(Point(point3.x - point2.x + point1.x, point3.y - point2.y + point1.y));
}

void Parallelogram::changeCoordinate(std::vector<class Point>& newPoints){ // аргументы по умолчанию?
    for(unsigned i = 0; i < newPoints.size(); ++i)
        points[i] = newPoints[i];
    points[newPoints.size()].x = points[2].x - points[1].x + points[0].x;
    points[newPoints.size()].y = points[2].y - points[1].y + points[0].y;
}

void Parallelogram::multiplicateCoordinate(double k = 1){
    for(unsigned i = 0; i < points.size(); ++i){
        points[i].x *= k;
        points[i].y *= k;
    }
}

void Parallelogram::rotate(double angle){
    for(unsigned i = 1; i < points.size(); ++i){
        double length = sqrt(pow(points[0].x - points[i].x, 2) + pow(points[0].y - points[i].y, 2));
        if(points[i].x > points[0].x){
            points[i].x = length * cos(acos(fabs(points[0].x - points[i].x / length)) + angle * PI / 180);
            points[i].y = length * sin(asin(fabs(points[0].y - points[i].y / length)) + angle * PI / 180);
        }
        else{
            points[i].x = length * cos(acos(fabs(points[0].x - points[i].x / length)) * 2.25 + angle * PI / 180); // 2.25???
            points[i].y = length * sin(asin(fabs(points[0].y - points[i].y / length)) * 2.25 + angle * PI / 180); // завис от длины
        }
    }
}

Ellipse::Ellipse(Point point1, Point point2, Point point3, QString color): id(Shape::id){
    this->color = color;
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
    points.push_back(Point(point1.x - point2.x, point2.y));
}

void Ellipse::changeCoordinate(std::vector<Point>& newPoints){
    for(unsigned i = 0; i < newPoints.size(); ++i){
        points[i] = newPoints[i];
    }
    points[newPoints.size()].x = points[0].x - points[1].x;
    points[newPoints.size()].y = points[1].y;
}

void Ellipse::multiplicateCoordinate(double k){
    for(unsigned i = 0; i < points.size(); ++i){
        points[i].x *= k;
        points[i].y *= k;
    }
}

void Ellipse::rotate(double angle){
    for(unsigned i = 1; i < points.size(); ++i){
        double length = sqrt(pow(points[0].x - points[i].x, 2) + pow(points[0].y - points[i].y, 2));
        points[i].x = length * cos(acos(fabs(points[0].x - points[i].x / length)) + angle * PI / 180);
        points[i].y = length * sin(asin(fabs(points[0].y - points[i].y / length)) + angle * PI / 180);
    }
}

EllipseSector::EllipseSector(Point p1, Point p2, Point p3, QString color): id(Shape::id){
    this->color = color;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
}

void EllipseSector::multiplicateCoordinate(double k){
    for(unsigned i = 0; i < points.size(); ++i){
        points[i].x *= k;
        points[i].y *= k;
    }
}

void EllipseSector::changeCoordinate(std::vector<Point>& newPoints){
    for(unsigned i = 0; i < newPoints.size(); ++i){
        points[i] = newPoints[i];
    }
}

void EllipseSector::rotate(double angle){
    for(unsigned i = 1; i < points.size(); ++i){
        double length = sqrt(pow(points[0].x - points[i].x, 2) + pow(points[0].y - points[i].y, 2));
        points[i].x = length * cos(acos(fabs(points[0].x - points[i].x / length)) + angle * PI / 180);
        points[i].y = length * sin(asin(fabs(points[0].y - points[i].y / length)) + angle * PI / 180);
    }
}



