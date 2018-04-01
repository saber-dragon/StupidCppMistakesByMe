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
#include <tuple>
#include <string>


std::tuple<int, double, std::string, bool> foo(){
    std::string s("300");
    return {1, 1.0, s, false};
};

int main()
{
    auto x = foo();
    std::cout << std::get<0>(x)
              << ", "
              << std::get<1>(x)
              << ", "
              << std::get<2>(x)
              << std::endl;
    return 0;
}


