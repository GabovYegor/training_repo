#include "shape.h"

unsigned Shape::id = 0;
std::string Shape::defaultColor = "white";

std::ostream& operator<<(std::ostream& out, const Parallelogram& parallelogram){
    out << "COLOR: " << parallelogram.color << std::endl;
    out << "ID: " << parallelogram.id << std::endl;
    for(unsigned i = 0; i < parallelogram.points.size(); ++i){
        std::cout << "Point " << i << " " << parallelogram.points[i] << std::endl;
    }
    return out;
}

Point& Point::operator=(Point& point){
    this->x = point.x;
    this->y = point.y;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Point& point){
    out << "Point X: " << point.x << " Point Y: " << point.y << std::endl;
    return out;
}

Parallelogram::Parallelogram(Point point1 = Point(0, 0), Point point2 = Point(0, 0), Point point3 = Point(0, 0), std::string color = defaultColor)
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
    points.push_back(Point(points[2].x - points[1].x + points[0].x, points[2].y - points[1].y + points[0].y));
}

void Parallelogram::multiplicateCoordinate(unsigned k = 1){
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

Ellipse::Ellipse(Point centre, Point point1, Point point2, std::string color): id(Shape::id){
    this->color = color;
    points.push_back(centre);
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(Point(points[0].x - points[1].x, points[0].y));
    points.push_back(Point(points[0].x, points[0].y - points[2].y));
}

void Ellipse::changeCoordinate(std::vector<Point>& newPoints){
    for(unsigned i = 0; i < newPoints.size(); ++i){
        points[i] = newPoints[i];
    }
    points.push_back(Point(points[0].x - points[1].x, points[0].y));
    points.push_back(Point(points[0].x, points[0].y - points[2].y));
}

void Ellipse::multiplicateCoordinate(unsigned k){
    for(unsigned i = 0; i < points.size(); ++i){
        points[i].x *= k;
        points[i].y *= k;
    }
}


