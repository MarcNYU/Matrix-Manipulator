//
//  main.cpp
//  Matrix Manipulator
//
//  Created by Marcus Williams on 7/2/19.
//  Copyright © 2019 Marcus Williams. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //int x = 2;
    //int * ptr;
    //ptr = &x;
    long long height = 4, width = 4;
    long long size = height * width;
    int outsideArr[size];
    for(auto i = 0; i < height*width; i++){
        outsideArr[i] = i;
    }
    
    Matrix m = Matrix(width, height, outsideArr);
    std::cout << m << std::endl;
    m.zero();
    std::cout << m << std::endl;
    m += 5;
    std::cout << m << std::endl;
    m *= 2;
    std::cout << m << std::endl;
    m.randomize();
    std::cout << m << std::endl;
    m.sort();
    std::cout << m << std::endl;
    
    height = 2, width = 2;
    int a1[] = {2,4,1,5};
    int a2[] = {7,0,-3,8};
    
    Matrix m1 = Matrix(width, height, a1);
    Matrix m2 = Matrix(width, height, a2);
    
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    
    std::cout << m1 * m2 << std::endl;
    
    return 0;
}
