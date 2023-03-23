#include <iostream>
#include "Field.h"
#include "AStar.h"

int main()
{

    Field f1("../InputFiles/rabbit.txt");
    AStar simiulation(f1);
    std::cout<<simiulation.run();

    return 0;
}
