//
//  Matrix.hpp
//  Matrix Manipulator
//
//  Created by Marcus Williams on 7/2/19.
//  Copyright © 2019 Marcus Williams. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#endif /* Matrix_hpp */


class Matrix{
private:
    long long Width, Height, Size;
    std::vector<int *> matrix_array;
    
public:
    Matrix(long long w = 1, long long h = 1);
    Matrix(long long w, long long h, int a[]);
    Matrix(const Matrix & other);
    virtual ~Matrix();
    
    void zero();
    void identity();
    void transpose();
    void inverse();
    void randomize();
    
    long long get_size();
    long long get_height();
    long long get_width();
    
    int max();
    int min();
    
    void sort();
    
    std::vector<int *> get_data();
    
    Matrix& operator=(const Matrix & other);
    
    Matrix operator+(const Matrix & other);
    Matrix operator+(int n);
    Matrix& operator+=(const Matrix & other);
    Matrix& operator+=(int n);
    
    Matrix operator-(const Matrix & other);
    Matrix operator-(int n);
    Matrix& operator-=(const Matrix & other);
    Matrix& operator-=(int n);
    
    Matrix operator*(const Matrix & other);
    Matrix operator*(int n);
    Matrix& operator*=(const Matrix & other);
    Matrix& operator*=(int n);
    
    void operator++();
    void operator--();
    
    int operator[](int n);
    
    bool operator==(const Matrix & other);
    bool operator!=(const Matrix & other);
    
    friend std::ostream & operator<<(std::ostream & out, const Matrix & other);
};


void isort(std::vector<int *> arr, long long n);
void qsort(std::vector<int *> arr, long long low, long long high);
int partition(std::vector<int *> arr, long long low, long long high);
