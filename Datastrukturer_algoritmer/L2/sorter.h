//
// Created by zhass on 5/12/2025.
//

#ifndef SORTER_H
#define SORTER_H
#include <vector>


    void sort(std::vector<int>&);
    void insertionSort(std::vector<int>&);
    void selectionSort(std::vector<int>&);
    void quickSort_rightPivot(std::vector<int>&, int, int);
    void quickSort_median_of_three(std::vector<int>&, int, int);
    int medianOfThree(std::vector<int>&, int, int);



#endif //SORTER_H
