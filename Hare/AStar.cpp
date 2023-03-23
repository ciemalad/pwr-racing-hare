#include "AStar.h"
#include <algorithm>
#include <cmath>
// uncomment when you want to see on what Nodes we were
// #include <iostream>
#include<queue>

AStar::AStar(Field f)
{
    fld=f;
}
double AStar::getDistanceBetweenNodes(const Node & n1,const Node & n2)
{
    return sqrt(pow(n2.getX()-n1.getX(),2)+pow(n2.getY()-n1.getY(),2));
}
std::string AStar::run()
{
    std::vector<Node> opened;
    std::vector<Node> closed;

    source=fld.findNodeByType('z');
    destination=fld.findNodeByType('n');
    Node current;

    opened.push_back(source);

    while(!opened.empty())
    {
        // find the least costly Node in open list
        current=opened[0];
        for(int j=1;j<opened.size();j++)
        {
            if((opened[j].fCost()<current.fCost())||(opened[j].fCost()==current.fCost()&&opened[j].getHCost()<current.getHCost()))
            {
                current=opened[j];
            }
        }
        opened.erase(std::find(opened.begin(),opened.end(),current));
        closed.push_back(current);

        if(current==destination)
        {
            int jumpCount=0;
            Node returnPath=closed.back();
            // uncomment to see on which we are moving
            // std::cout<<returnPath.getId()<<std::endl;
            while(returnPath.getParentId() != "")
            {
                for (int y = 0; y < closed.size(); y++)
                {
                    if(closed[y].getId() == returnPath.getParentId())
                    {
                        returnPath=closed[y];
                        jumpCount++;
                        // uncomment to see on which we are moving
                        // std::cout<<returnPath.getId()<<std::endl;
                        break;
                    }
                }
            }

            return std::to_string(jumpCount);
        }
        std::vector<Node> currentNeighbours=fld.findNeighbours(current);

        for(int i=0;i<currentNeighbours.size();i++)
        {
            if(currentNeighbours[i].getType()=='x' || (std::find(closed.begin(),closed.end(),currentNeighbours[i])!=closed.end()))
            {
                continue;
            }

            double newDistanceCostToNeighbour=current.getGCost()+ getDistanceBetweenNodes(current,currentNeighbours[i]);

            if(newDistanceCostToNeighbour<currentNeighbours[i].getGCost()||std::find(opened.begin(),opened.end(),currentNeighbours[i])==opened.end())
            {
                currentNeighbours[i].setGCost(newDistanceCostToNeighbour);
                currentNeighbours[i].setHCost(getDistanceBetweenNodes(currentNeighbours[i],destination));
                currentNeighbours[i].fCost();
                currentNeighbours[i].setParentId(current.getId());

                if(std::find(opened.begin(),opened.end(),currentNeighbours[i])==opened.end())
                {
                    opened.push_back(currentNeighbours[i]);
                }
            }

        }
    }
    return "NIE";
}
