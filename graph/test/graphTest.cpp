/* Copyright 2022-Present Steve Yackey

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <functional>
#include <graph.h>

using namespace std;

// The fixture for testing
class GraphTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    GraphTest() { }

    virtual ~GraphTest() {}

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        //
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    static bool binary_pred(int a, int b) {
        return a == b;
    }

    virtual bool isExpectedResult(std::list<int> ans, std::list<int> res) {
        if(ans.size() != res.size()) {
            return false;
        }
        return(std::equal(res.begin(), res.end(), ans.begin(), binary_pred));
    }

    virtual void DumpBfsList(std::list<int>& results) {
        for(int i : results) {
            printf("(%d) ", i);
        }
        printf("\n");
    }

    virtual void DisplayPathInfo(
                int src, int dest, bool pathFound, int cost, list<int> path) {
        if((pathFound) == false) {
            printf("No path found (%d)-->(%d)\n", src, dest); 
            return;
        }
        printf("Shortest path length (%d)-->(%d): (%d)\n", src, dest, cost);
        printf("Path: ");
        for(int v : path) {
            printf("(%d) ", v);
        }
        printf("\n");
    }

    // Objects declared here can be used by all tests.
    //
};

TEST_F(GraphTest, AddEdges_VerifyUndirected_AdjacentCount) {
    // arrange
    auto pGraph = make_shared<Graph>();
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = pGraph->getAdjListCount();
    // assert
    ASSERT_EQ(count, 12);
}

/*
TEST_F(GraphTest, bff_g4g_StartAt_Zero) {
    // arrange
    auto pGraph = make_shared<Graph>();
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->BFS(0);
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(GraphTest, BFS_StartAt_Three) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->BFS(3);
    // assert
    ASSERT_EQ(count, 1);
}
*/

TEST_F(GraphTest, bfs_StartAtZero_VerifyResults) {
    // arrange
    auto pGraph = make_shared<Graph>();
    std::list<int> answer = {0, 1, 2, 3, 4 ,5};
    std::list<int> results;
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->bfsSay(0, results);
    //DumpBfsList(results);
    // assert
    ASSERT_TRUE(isExpectedResult(answer, results));
}

TEST_F(GraphTest, bfs_StartAtThree_VerifyResult) {
    // arrange
    auto pGraph = make_shared<Graph>();
    std::list<int> answer = {3, 1, 5, 0, 4 ,2};
    std::list<int> results;
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->bfsSay(3, results);
    //DumpBfsList(results);
    // assert
    ASSERT_TRUE(isExpectedResult(answer, results));
}

/*
TEST_F(GraphTest, shortestPath_GforG_Version) {
    // arrange
    // act
    auto pGraph = make_shared<Graph>();
    pGraph->main();
    // assert
    ASSERT_EQ(1, 1);
}
*/

TEST_F(GraphTest, shortestPath_0to7_PathFound_VerifyPathAndCost) {
    // arrange
    std::list<int> pathAnswer = {0, 3, 7};
    int costAnswer = 2;
    auto pGraph = make_shared<Graph>();
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(0, 3, 1);
    pGraph->addEdge(1, 2, 1);
    pGraph->addEdge(3, 4, 1);
    pGraph->addEdge(3, 7, 1);
    pGraph->addEdge(4, 5, 1);
    pGraph->addEdge(4, 6, 1);
    pGraph->addEdge(4, 7, 1);
    pGraph->addEdge(5, 6, 1);
    pGraph->addEdge(6, 7, 1);
    // act
    int source = 0, dest = 7;
    pGraph->shortestPathUnweighted(source, dest);
    bool pathFound = pGraph->getPathFound();
    int costResult = pGraph->getPathCost();
    list<int> pathResult = pGraph->getPathResult();
    DisplayPathInfo(source, dest, pathFound, costResult, pathResult);
    // assert
    ASSERT_EQ(costAnswer, costResult);
    ASSERT_TRUE(isExpectedResult(pathAnswer, pathResult));
}

TEST_F(GraphTest, shortestPath_0to7_Weighted_PathFound_VerifyPathAndCost) {
    // arrange
    std::list<int> pathAnswer = {0, 3, 7};
    int costAnswer = 11;
    auto pGraph = make_shared<Graph>();
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(0, 3, 1);
    pGraph->addEdge(1, 2, 1);
    pGraph->addEdge(3, 4, 1);
    pGraph->addEdge(3, 7, 10);
    pGraph->addEdge(4, 5, 1);
    pGraph->addEdge(4, 6, 1);
    pGraph->addEdge(4, 7, 5);
    pGraph->addEdge(5, 6, 1);
    pGraph->addEdge(6, 7, 1);
    // act
    int source = 0, dest = 7;
    pGraph->shortestPathUnweighted(source, dest);
    bool pathFound = pGraph->getPathFound();
    int costResult = pGraph->getPathCost();
    list<int> pathResult = pGraph->getPathResult();
    DisplayPathInfo(source, dest, pathFound, costResult, pathResult);
    // assert
    ASSERT_EQ(costAnswer, costResult);
    ASSERT_TRUE(isExpectedResult(pathAnswer, pathResult));
}

TEST_F(GraphTest, shortestPath_2to6_PathFound_VerifyPathAndCost) {
    // arrange
    std::list<int> pathAnswer = {2, 1, 0, 3, 4, 6};
    int costAnswer = 5;
    auto pGraph = make_shared<Graph>();
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(0, 3, 1);
    pGraph->addEdge(1, 2, 1);
    pGraph->addEdge(3, 4, 1);
    pGraph->addEdge(3, 7, 1);
    pGraph->addEdge(4, 5, 1);
    pGraph->addEdge(4, 6, 1);
    pGraph->addEdge(4, 7, 1);
    pGraph->addEdge(5, 6, 1);
    pGraph->addEdge(6, 7, 1);
    // act
    int source = 2, dest = 6;
    pGraph->shortestPathUnweighted(source, dest);
    bool pathFound = pGraph->getPathFound();
    int costResult = pGraph->getPathCost();
    list<int> pathResult = pGraph->getPathResult();
    DisplayPathInfo(source, dest, pathFound, costResult, pathResult);
    // assert
    ASSERT_TRUE(isExpectedResult(pathAnswer, pathResult));
    ASSERT_EQ(costAnswer, costResult);
}

TEST_F(GraphTest, shortestPathUnweighted_NoPath) {
    // arrange
    auto pGraph = make_shared<Graph>(8);
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(0, 3, 1);
    pGraph->addEdge(1, 2, 1);
    pGraph->addEdge(3, 4, 1);
    pGraph->addEdge(3, 7, 1);
    pGraph->addEdge(4, 5, 1);
    pGraph->addEdge(4, 6, 1);
    pGraph->addEdge(4, 7, 1);
    pGraph->addEdge(5, 6, 1);
    pGraph->addEdge(6, 7, 1);
    // act
    int source = 2, dest = 9;
    pGraph->shortestPathUnweighted(source, dest);
    bool pathFound = pGraph->getPathFound();
    int costResult = pGraph->getPathCost();
    list<int> pathResult = pGraph->getPathResult();
    DisplayPathInfo(source, dest, pathFound, costResult, pathResult);
    // assert
    ASSERT_FALSE(pathFound);
}

TEST_F(GraphTest, shortestPathWeighted_Algotree_Version) {
    // arrange
    // act
    auto pGraph = make_shared<Graph>();
    pGraph->main_algotree();
    // assert
    ASSERT_EQ(1, 1);
}
