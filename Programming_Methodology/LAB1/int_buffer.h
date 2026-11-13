/**
* @author: Hussein Alshaikhshaker
 * Creating date: 2024-09-06
 * Last day edited: 2024-09-06
 * Course: programmeringsmetodik (dt047g)
 * File: int_buffer headerfile.
 */

#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <cstdlib>

class int_buffer {

    size_t buf_size;
    int *buff;

    int_buffer();

public:
    explicit int_buffer(size_t size); //K

    int_buffer(const int *source, size_t size); //K

    int_buffer(const int_buffer &rhs); //copy constructor //K

    int_buffer(int_buffer &&rhs) noexcept; //move constructor  //K

    int_buffer &operator=(const int_buffer &rhs); //copy assign //K

    int_buffer &operator=(int_buffer &&rhs); //move assign  //K

    int &operator[](size_t index); //K

    const int &operator[](size_t index) const; //K

    size_t size() const; //K

    int *begin(); //K

    int *end(); //K

    const int *begin() const; //K

    const int *end() const; //K

    ~int_buffer(); //K

    void printArr() const;
};

void f(int_buffer buf);

void ff(int_buffer buff);
#endif //INT_BUFFER_H
