#include "gtest/gtest.h"
#include "../../Hare/AStar.h"
#include "../../Hare/Field.h"

TEST( AStarTest , runTest ) {
    Field f1("../../InputFiles/rabbit.txt");
    AStar a1(f1);
    Field f2("../../InputFiles/TestsInputFiles/test1.txt");
    AStar a2(f2);
    Field f3("../../InputFiles/TestsInputFiles/test2.txt");
    AStar a3(f3);
    EXPECT_EQ(a1.run(),"3");
    EXPECT_EQ(a2.run(),"NIE");
    EXPECT_EQ(a3.run(),"3");
}