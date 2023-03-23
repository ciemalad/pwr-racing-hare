#include "LineSegment.h"
#include <iostream>
#include <cmath>
#include <string>

LineSegment::LineSegment()
{
    firstPoint.setXPosition(0);
    firstPoint.setYPosition(0);
    firstPoint.setName("NN1");

    secondPoint.setXPosition(1);
    secondPoint.setYPosition(0);
    secondPoint.setName("NN2");
    setSegmentLength();
    setSegmentName();
}
LineSegment::LineSegment(Point a, Point b)
{
    firstPoint=a;
    secondPoint=b;
    setSegmentLength();
    setSegmentName();
}
void LineSegment::setSegmentLength()
{
    segmentLength= sqrt(pow(secondPoint.getPosition()[0]-firstPoint.getPosition()[0],2)+pow(secondPoint.getPosition()[1]-firstPoint.getPosition()[1],2));
}
void LineSegment::show()
{
    std::cout<<firstPoint.getName()<<std::endl;
    std::cout<<firstPoint.getPosition()[0]<<std::endl;
    std::cout<<firstPoint.getPosition()[1]<<std::endl;
    std::cout<<secondPoint.getName()<<std::endl;
    std::cout<<secondPoint.getPosition()[0]<<std::endl;
    std::cout<<secondPoint.getPosition()[1]<<std::endl;
    std::cout<<segmentLength<<std::endl;
    std::cout<<segmentName<<std::endl;

}
void LineSegment::setFirstPoint(Point P)
{
    firstPoint=P;
    setSegmentLength();
    setSegmentName();
}
void LineSegment::setSecondPoint(Point P)
{
    secondPoint=P;
    setSegmentLength();
    setSegmentName();
}
bool LineSegment::isPointOnLine(Point C)
{
return true;
}
void LineSegment::setSegmentName()
{
    segmentName=firstPoint.getName()+secondPoint.getName();
}
void LineSegment::setSegmentName(std::string newName)
{
    segmentName=newName;//co ze zmianą nazw odcinka
}
