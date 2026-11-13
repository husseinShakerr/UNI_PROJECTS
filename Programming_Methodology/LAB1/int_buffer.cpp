/**
* @author: Hussein Alshaikhshaker
 * Creating date: 2024-09-06
 * Last day edited: 2024-09-06
 * Course: programmeringsmetodik (dt047g)
 * File: int_buffer class file.
 */

#include "int_buffer.h"
#include <algorithm>
#include <iostream>
int_buffer::int_buffer() : buf_size(0), buff(nullptr) {}



//Constructor
int_buffer::int_buffer(size_t size) : buf_size(size), buff(new int[size]) {
}

//Overloaded constructor
int_buffer::int_buffer(const int* source, size_t size) : int_buffer(size ){
    std::copy(source, source+size, buff);
};

//Copy construcotr
int_buffer::int_buffer(const int_buffer &rhs) : int_buffer(rhs.begin(), rhs.size()){
    //kopiera från rhs till intern buffert
}

//Move constructor
int_buffer::int_buffer(int_buffer &&rhs) noexcept : buf_size(0), buff(nullptr) {
    *this = std::move(rhs);
}

//Copy assign
int_buffer &int_buffer::operator=(const int_buffer &rhs) {
    int_buffer temp(rhs);
    std::swap(this->buff, temp.buff);
    std::swap(this->buf_size, temp.buf_size);
    return *this;
}


//Move assign
int_buffer &int_buffer::operator=(int_buffer &&rhs){
    std::swap(this->buff, rhs.buff);
    std::swap(this->buf_size, rhs.buf_size);
    return *this;
}


int *int_buffer::begin() {
    return buff;
}

const int *int_buffer::begin() const {
    return buff;
}

int *int_buffer::end() {
    return buff + buf_size;
}

const int *int_buffer::end() const {
    return buff + buf_size;
}

//Destructor
int_buffer::~int_buffer() {
    delete[] buff;
}

size_t int_buffer::size() const {
    return buf_size;
}

int &int_buffer::operator[](size_t ind) {
    return buff[ind];
}

const int &int_buffer::operator[](size_t ind) const {
    return buff[ind];
}

void f(int_buffer buff) {
    int counter = 1;
    for (int *i = buff.begin(); i != buff.end(); i++) {
        *i = counter;
        counter++;
    }
    for (const int *i = buff.begin(); i != buff.end(); i++) {
        std::cout << *i << std::endl;
    }
}

void ff(int_buffer buff) {
    int counter = 1;
    //pass-by-reference på elementen i arrayen
    for (auto &e: buff) {
        e = counter;
        counter++;
    }
    for (auto e: buff) {
        std::cout << e << std::endl;
    }
}

void int_buffer::printArr() const {
    int counter = 0;
    for (const int *f = begin(); f != end(); f++) {
        std::cout << "Element [" << counter << "] : " << *f << std::endl;
        counter++;
    }
}
