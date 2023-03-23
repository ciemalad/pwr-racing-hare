#include <iostream>
#include "Point.h"
#include "LineSegment.h"
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<double> nv{2.1,-1};
    Point A(-2,-2,"A");
    Point B(3,3,"B");
    Point C(0,6,"B");
  /*  for(int i=0;i<A.getPosition().size();i++)
    {
        std::cout<<A.getPosition()[i]<<std::endl;
    }
    std::cout<<A.getName()<<std::endl;
    A.move(nv);
    A.setName("B");
    for(int i=0;i<A.getPosition().size();i++)
    {
        std::cout<<A.getPosition()[i]<<std::endl;
    }
    std::cout<<A.getName()<<std::endl;*/
    LineSegment AB(A,B);
    AB.show();
    AB.setFirstPoint(C);
    AB.show();
    return 0;
}
