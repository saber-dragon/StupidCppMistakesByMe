/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pointingToVectorElement.cpp
 * Author: saber
 * 
 * 
 * This cpp example demonstrates a very very stupid mistake made by me while
 * doing a course project. In this project, I want to reuse a function interface
 * which I have implemented before. This function takes a pointer points
 * to an object as it argument. In the new context, I will have many such objects
 * which cannot be determined at compile time, so I decide to store them in a 
 * vector, and then use pointers point to the element of this vector to call 
 * my function. 
 * 
 *
 * Created on April 1, 2018, 3:59 PM
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <gtest/gtest.h>


using namespace std;

struct MyObject {
    int x;
    int y;
    MyObject(int x, int y) : x(x), y(y){}
};


TEST(StupidMistakeTest, PointingToVectorEmelment){
    vector<MyObject> vecOfMyObject;
    vector<MyObject *> forDemoErrors;

    size_t N = 4;
    for (size_t i = 0;i < N;++ i) {
    vecOfMyObject.emplace_back(i, i + 1);
    forDemoErrors.push_back(&vecOfMyObject.back());
    }

    // output them
    for (size_t i = 0, e = std::min(vecOfMyObject.size(), forDemoErrors.size());i < e;++ i){
        EXPECT_EQ(vecOfMyObject[i].x, forDemoErrors[i]->x);
        EXPECT_EQ(vecOfMyObject[i].y, forDemoErrors[i]->y);
    }
}

int main(int argc, char** argv) {
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

