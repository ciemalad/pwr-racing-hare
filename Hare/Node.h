
#ifndef PWR_RACING_RECRUTATION_NODE_H
#define PWR_RACING_RECRUTATION_NODE_H

#include <vector>
#include <cmath>
#include <string>

class Node {
private:
    std::string id;
    double x;
    double y;
    char type;
    double gCost; // distance from starting node
    double hCost; // distance to target node
    std::string parentID;

public:
    Node();
    Node( double nx,double ny,char nType);
    std::string getId() const;
    std::string getParentId() const;
    double getX() const;
    double getY() const;
    double getGCost() const;
    double getHCost() const;
    void setGCost(double newCost);
    void setHCost(double newCost);
    char getType() const;
    void setParentId(std::string newID);
    bool operator==(const Node & other) const;
    bool operator!=(const Node & other) const;
    void printAllData() const; // method displays all information about Node
    double fCost();
};


#endif //PWR_RACING_RECRUTATION_NODE_H
