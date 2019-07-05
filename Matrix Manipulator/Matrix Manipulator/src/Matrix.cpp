//
//  Matrix.cpp
//  Matrix Manipulator
//
//  Created by Marcus Williams on 7/2/19.
//  Copyright © 2019 Marcus Williams. All rights reserved.
//

#include "Matrix.hpp"


Matrix::Matrix(long long w, long long h) : Width(w), Height(h), Size(Width * Height) {
    matrix_array = std::vector<int *>(Size);
}

Matrix::Matrix(long long w, long long h, int a[]) : Width(w), Height(h), Size(Width * Height) {
    matrix_array = std::vector<int *>(Size);
    for (auto i = 0; i < Size; i++)
        matrix_array[i] = new int(a[i]);
}

Matrix::Matrix(const Matrix & other) {
    for(auto i = 0; i < Size; i++)
        delete matrix_array[i];
    
    Width = other.Width;
    Height = other.Height;
    Size = other.Size;
    matrix_array = std::vector<int *>(Size);
    for (auto i = 0; i < Size; i++)
        matrix_array[i] = new int(*other.matrix_array[i]);
}

Matrix::~Matrix(){
    for(auto i = 0; i < Size; i++)
        delete matrix_array[i];
}

void Matrix::zero(){
    for (auto i = 0; i < Size; i++)
        matrix_array[i] = new int(0);
}

void Matrix::identity(){
    this->zero();
    for(auto i = 0; i < Size; i++)
        matrix_array[i + i * Width] = new int(1);
}

void Matrix::transpose(){}
void Matrix::inverse(){}

void Matrix::randomize() {
    for (auto i = 0; i < Size; i++)
        matrix_array[i] = new int(rand());
    
}

int Matrix::min(){
    int min = *matrix_array[0];
    for (auto i = 1; i < Size; i++)
        if(*matrix_array[i] < min)
            min = *matrix_array[i];
    
    return min;
}

int Matrix::max(){
    int max = *matrix_array[0];
    for (auto i = 1; i < Size; i++)
        if(*matrix_array[i] > max)
            max = *matrix_array[i];
    
    return max;
}

void Matrix::sort(){
    if(Size < 100) isort(matrix_array, Size);
    else if (Size > 100) qsort(matrix_array, 0, Size-1);
}

long long Matrix::get_size() { return Size; }

long long Matrix::get_width() { return Width; }

long long Matrix::get_height() { return Height; }

std::vector<int *> Matrix::get_data() { return matrix_array; }

Matrix& Matrix::operator=(const Matrix & other){
    for (auto i = 0; i < Size; i++)
        matrix_array[i] = new int(*other.matrix_array[i]);
    
    return *this;
}

Matrix Matrix::operator+(const Matrix & other){
    if(Size != other.Size)
        throw "Matirices are different sizes";
    
    int tmp[Size];
    for (auto i = 0; i < Size; i++)
        tmp[i] = *matrix_array[i] + *(other.matrix_array[i]);
    
    return Matrix(Width,Height,tmp);
}

Matrix Matrix::operator+(int n){
    int tmp[Size];
    for (auto i = 0; i < Size; i++)
        tmp[i] = *matrix_array[i] + n;
    
    return Matrix(Width,Height,tmp);
}

Matrix& Matrix::operator+=(const Matrix & other){
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator+=(int n){
    *this = *this + n;
    return *this;
}

Matrix Matrix::operator-(const Matrix & other){
    if(Size != other.Size)
        throw "Matirices are different sizes";
    
    int tmp[Size];
    for (auto i = 0; i < Size; i++)
        tmp[i] = *matrix_array[i] - *(other.matrix_array[i]);
    
    return Matrix(Width,Height,tmp);
}

Matrix Matrix::operator-(int n){
    int tmp[Size];
    for (auto i = 0; i < Size; i++)
        tmp[i] = *matrix_array[i] - n;
    
    return Matrix(Width,Height,tmp);
}

Matrix& Matrix::operator-=(const Matrix & other){
    *this = *this - other;
    return *this;
}

Matrix& Matrix::operator-=(int n){
    *this = *this + n;
    return *this;
}

Matrix Matrix::operator*(const Matrix & other){
    if(Height != other.Width)
        throw "Operation could not be completed invaild operands";
    
    long long r1, c1, r2, c2, s;
    r1 = Width;
    c1 = Height;
    r2 = other.Width;
    c2 = other.Height;
    s = r1*c2;
    int tmp[s];
    
    for(auto i = 0; i < r1; ++i)
        for(auto j = 0; j < c2; ++j)
            for(auto k = 0; k < c1; ++k)
                tmp[i + j * c2] += *(matrix_array[i + k * c1]) * *(other.matrix_array[k + j * c2]);
    
    
    return Matrix(r1, c2, tmp);
}

Matrix Matrix::operator*(int n){
    int tmp[Size];
    for (auto i = 0; i < Size; i++) {
        tmp[i] = *matrix_array[i] * n;
    }
    return Matrix(Width,Height,tmp);
}

Matrix& Matrix::operator*=(const Matrix & other){
    *this = *this * other;
    return *this;
}

Matrix& Matrix::operator*=(int n){
    *this = *this * n;
    return *this;
}

void Matrix::operator++(){
    for (auto i = 0; i < Size; i++) {
        (*matrix_array[i])+=1;
    }
}

void Matrix::operator--(){
    for (auto i = 0; i < Size; i++) {
        (*matrix_array[i])-=1;
    }
}

int Matrix::operator[](int n){
    return *matrix_array[n];
}

bool Matrix::operator==(const Matrix & other){
    for(auto i = 0; i < Size; i++){
        if(*matrix_array[i] != *(other.matrix_array[i])){
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix & other){
    return !(*this == other);
}

std::ostream & operator<<(std::ostream & out, const Matrix & m){
    out<<"[\t"<< *m.matrix_array[0] << "\t";
    for(auto i = 1; i < m.Size; i++){
        if(i%m.Width == 0)
            out<<"]\n"<<"[\t";
        out<<*(m.matrix_array[i])<< "\t";
    }
    out<<"]"<<std::endl;
    return out;
}



void isort(std::vector<int *> arr, long long n){
    int i, j, k;
    for (i = 1; i < n; i++) {
        j = i - 1;
        k = *arr[i];
        while(j >= 0 && *arr[j] > k){
            *arr[j+1] = *arr[j];
            j--;
        }
        *arr[j+1] = k;
    }
}

int partition(std::vector<int *> arr, long long low, long long high){
    int p = *arr[high];
    
    int i, j;
    i = low - 1;
    for (j = 0; j <= high - 1 ; j++) {
        if(*arr[j] <= p){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void qsort(std::vector<int *> arr, long long  low, long long high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        qsort(arr, low, pi-1);
        qsort(arr, pi+1, high);
    }
}

