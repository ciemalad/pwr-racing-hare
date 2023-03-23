#include "Node.h"
#include <algorithm>
#include <iostream>
#include <string>

Node::Node()
{
    id="0";
    x=0;
    y=0;
    type='x';
    parentID="";
}
Node::Node( double nx,double ny,char nType)
{
    id=std::to_string(int(nx))+std::to_string(int(ny));
    x=nx;
    y=ny;
    type=nType;
    parentID="";
}
std::string Node::getId() const
{
    return id;
}
double Node::getX() const
{
    return x;
}
double Node::getY() const
{
    return y;
}
double Node::getGCost() const
{
    return gCost;
}
double Node::getHCost() const
{
    return hCost;
}
char Node::getType() const
{
    return type;
}
bool Node::operator==(const Node& other) const
{
    return id == other.id;
}
bool Node::operator!=(const Node& other) const
{
    return id != other.id;
}
void Node::printAllData() const
{
    std::cout<<"id:"<<id<<std::endl;
    std::cout<<"x:"<<x<<std::endl;
    std::cout<<"y:"<<y<<std::endl;
    std::cout<<"type:"<<type<<std::endl;
    std::cout<<"pid:"<<parentID<<std::endl;
}
double Node::fCost()
{
    return gCost+hCost;
}
void Node::setGCost(double newCost)
{
    gCost=newCost;
}
void Node::setHCost(double newCost)
{
    hCost=newCost;
}
std::string Node::getParentId() const
{
    return parentID;
}
void Node::setParentId(std::string newID)
{
    parentID=newID;
}
