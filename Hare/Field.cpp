#include "Field.h"
#include <string>
#include <fstream>
#include "Node.h"
#include <iostream>
#include <algorithm>

Field::Field()
{
    n=0;
    m=0;
}
Field::Field(std::string path)
{
    loadFromFile(path);
}
void Field::loadFromFile(const std::string & path)
{
    std::ifstream File(path);
    if(!File.is_open())
    {
        std::cout<<"File cannot open!"<<std::endl;
    }
    else
    {
        char tp;

        File>>n>>m;
        for( double i=(n-0.5);i>=0;i--)
        {
            for(double j=0.5;j<m;j++)
            {
                File>>tp;
                listOfNodes.push_back(Node(j,i,tp));
            }
        }
    }
    File.close();
}
int Field::getM() const
{
    return m;
}
int Field::getN() const
{
    return n;
}
std::vector<Node> Field::getListOfNodes() const
{
    return listOfNodes;
}
std::vector<Node> Field::findNeighbours(Node & target)
{
    std::vector<Node> neighbours;
    // all possible combinations of movement (ID)
    std::string patterns[8]={
            std::to_string(int(target.getX())+1)+std::to_string(int(target.getY())+2),
            std::to_string(int(target.getX())+1)+std::to_string(int(target.getY())-2),
            std::to_string(int(target.getX())+2)+std::to_string(int(target.getY())+1),
            std::to_string(int(target.getX())+2)+std::to_string(int(target.getY())-1),
            std::to_string(int(target.getX())-1)+std::to_string(int(target.getY())+2),
            std::to_string(int(target.getX())-1)+std::to_string(int(target.getY())-2),
            std::to_string(int(target.getX())-2)+std::to_string(int(target.getY())+1),
            std::to_string(int(target.getX())-2)+std::to_string(int(target.getY())-1)
    };

    for(int i=0;i<8;i++) // if ID from pattern is in list of all Nodes, add it to neighbours
    {
        for(int j=0;j<listOfNodes.size();j++)
        {
            if(patterns[i]==listOfNodes[j].getId())
            {
                neighbours.push_back(listOfNodes[j]);
            }
        }
    }
    return neighbours;
}
Node Field::findNodeById(std::string id)
{
    for(int i=0;i<listOfNodes.size();i++)
    {
        if(listOfNodes[i].getId()==id)
        {
            return listOfNodes[i];
        }
    }
}
Node Field::findNodeByType(char type)
{
    for(int i=0;i<listOfNodes.size();i++)
    {
        if(listOfNodes[i].getType()==type)
        {
            return listOfNodes[i];
        }
    }
}


