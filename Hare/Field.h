#ifndef PWR_RACING_RECRUTATION_FIELD_H
#define PWR_RACING_RECRUTATION_FIELD_H

#include <vector>
#include <string>
#include "Node.h"

class Field {
private:
    int n;
    int m;
    std::vector<Node> listOfNodes;
public:
    Field();
    explicit Field(std::string path);
    void loadFromFile(const std::string & path); // create Nodes based on input form file
    int getM() const;
    int getN() const;
    std::vector<Node> getListOfNodes() const; // get a list of all Nodes within a field
    std::vector<Node> findNeighbours(Node & target);
    Node findNodeById(std::string id);
    Node findNodeByType(char type);
};

#endif //PWR_RACING_RECRUTATION_FIELD_H
