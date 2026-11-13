/**
* @author: Hussein Alshaikhshaker
 * Creating date: 2024-09-06
 * Last day edited: 2024-09-06
 * Course: programmeringsmetodik (dt047g)
 * File: Main file.
 */

#include <ctime>

#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>



int main()
{


    srand(time(nullptr));
    /*
    int_buffer b1(10);
    int data[] = {1, 2 ,3 , 4 , 5};
    size_t data_size = 5;
    int_buffer b2(data, data_size);
    std::cout<<b1.size()<<std::endl;
    int_buffer b3(b1);
    b2=b1;
    b2=( int_buffer &&)b1;
    std::cout<<b3.size()<<std::endl;
    b3[0] = 8;
    b3[1] = 2;
    std::cout<<b3.size()<<std::endl;
    std::cout<<b3[9]<<std::endl;
    int x = b3[0];
    std::cout<<x<<std::endl;
    b3[2] = x;
    std::cout<<b3[2]<<std::endl;
    int_buffer b5(10);
    b5[0] = 633;
    int_buffer b6 = b5;
    std::cout<<b6[0]<<std::endl;
    std::cout<<b5[0]<<std::endl;
    */


    //b2 = b;
    //b2 = (int_buffer&&)b;
    //b.printArr();

    //Recursive sort


    /*
    int_buffer b2(400000);
    int ran  = 0;
    for(size_t i = 0 ; i < b2.size() ; i++) {
        ran = rand() % 11;
        b2[i] = ran;

    }
    clock_t start = clock();
    int_sorted sb2(b2.begin(), b2.size());
    clock_t end = clock();
    std::cout<<"Recursive sort time(s): "<<double(end-start)/CLOCKS_PER_SEC<<std::endl;
    */

    //STD::SORT
    /*
    int_buffer b3(400000);
    for(size_t i = 0 ; i < 400000 ; i++) {
        int ran = rand() % 4001;
        b3[i] = ran;
    }
    clock_t start = clock();
    std::sort(b3.begin(), b3.end());
    clock_t end = clock();
    double sort_time = double(end-start)/CLOCKS_PER_SEC;
    std::cout<<"Stand Lib sort time(s): " << sort_time <<std::endl;
    */

    //Selection sort
    /*
    int_buffer b(400000);
    for(size_t i = 0 ; i < 400000 ; i++) {
        int ran = rand() % 41;
        b[i] = ran;
    }
    int_sorted sb(b.begin(), b.size());
    clock_t start = clock();
    sb.selection_sort();
    clock_t end = clock();

    std::cout<<"Selection sort time(s): "<<double(end-start)/CLOCKS_PER_SEC<<std::endl;
    */


    return 0;
}
