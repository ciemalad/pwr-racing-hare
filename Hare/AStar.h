#ifndef PWR_RACING_RECRUTATION_ASTAR_H
#define PWR_RACING_RECRUTATION_ASTAR_H

#include "Node.h"
#include "Field.h"

class AStar {
private:
    Field fld;
    Node destination;
    Node source;
public:
    explicit AStar(Field f);
    std::string run(); // perform A* algorithm
    static double getDistanceBetweenNodes(const Node & n1,const Node & n2);
};

#endif //PWR_RACING_RECRUTATION_ASTAR_H
