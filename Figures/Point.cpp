#include "Point.h"
#include <string>
#include <vector>

Point::Point()
{
    yPosition=0;
    xPosition=0;
    pointName="NN";
}
Point::Point(double x,double y,std::string name)
{
    xPosition=x;
    yPosition=y;
    pointName=name;
}
Point::Point(double x,double y)
{
    xPosition=x;
    yPosition=y;
}
void Point::move(std::vector<double> moveVector)
{
    xPosition+=moveVector[0];
    yPosition+=moveVector[1];
}
void Point::setXPosition(double x)
{
    xPosition=x;
}
void Point::setYPosition(double y)
{
    yPosition=y;
}
void Point::setName(std::string newName)
{
    pointName=newName;
}
std::vector<double> Point::getPosition() const
{
    std::vector<double> pointPos{xPosition,yPosition};
    return pointPos;
}
std::string Point::getName() const
{
    return pointName;
}

