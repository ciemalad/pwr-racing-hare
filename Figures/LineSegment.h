#ifndef PWR_RACING_RECRUTATION_LINESEGMENT_H
#define PWR_RACING_RECRUTATION_LINESEGMENT_H

#include "Point.h"
#include<string>

class LineSegment {

private:
    Point firstPoint;
    Point secondPoint;
    double segmentLength;
    std::string segmentName;
    void setSegmentLength();

public:
    LineSegment();
    LineSegment(Point a, Point b);
    void setFirstPoint(Point P);
    void setSecondPoint(Point P);
    bool isPointOnLine(Point C);
    void setSegmentName();
    void setSegmentName(std::string newName);
    void show();
};


#endif //PWR_RACING_RECRUTATION_LINESEGMENT_H
