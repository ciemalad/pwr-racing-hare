#ifndef PWR_RACING_RECRUTATION_POINT_H
#define PWR_RACING_RECRUTATION_POINT_H

#include <string>
#include <vector>

class Point {

private:
    double xPosition;
    double yPosition;
    std::string pointName;
public:
    Point();
    Point(double x,double y,std::string name);
    Point(double x,double y);
    void move(std::vector<double> moveVector);
    void setXPosition(double x);
    void setYPosition(double y);
    void setName(std::string newName);
    std::vector<double> getPosition() const;
    std::string getName() const;
};


#endif //PWR_RACING_RECRUTATION_POINT_H
