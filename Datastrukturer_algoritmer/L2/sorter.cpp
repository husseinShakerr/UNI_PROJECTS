//
// Created by zhass on 5/12/2025.
//

#include "sorter.h"
#include "timer.h"


void insertionSort(std::vector<int>& data) {
    for (int i = 1; i < data.size() ; ++i) {
        auto key = std::move(data[i]);
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}


void selectionSort(std::vector<int>& data) {
    for (int i = 0; i < data.size() - 1; ++i) {
        int lowest_value_index = i;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[lowest_value_index]) {
                lowest_value_index = j;
            }
        }
        std::swap(data[i], data[lowest_value_index]);
    }
}

void quickSort_rightPivot(std::vector<int>& data, int low, int high){
    if (low >= high) {
        return;
    }

    auto i = low;
    auto j  = high;
    auto pivot = data[high];

    while (i <= j) {
        while (data[i] < pivot) i++;
        while (data[j] > pivot) j--;
        if (i <= j) {
            std::swap(data[i], data[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort_rightPivot(data, low, j);
    if (i < high)
        quickSort_rightPivot(data, i, high);
}

void quickSort_median_of_three(std::vector<int>& data, int low, int high) {
    if (low >= high) return;
    auto pivot = medianOfThree(data, low, high);
    auto i = low;
    auto j  = high;
    while (i <= j) {
        while (data[i] < pivot) i++;
        while (data[j] > pivot) j--;
        if (i <= j) {
            std::swap(data[i], data[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort_median_of_three(data, low, j);
    if (i < high)
        quickSort_median_of_three(data, i, high);
}

int medianOfThree(std::vector<int>& data, int low, int high) {
    int median = (low+high)/2;
    if (data[low] > data[median])
        std::swap(data[low], data[median]);
    if (data[low] > data[high])
        std::swap(data[low], data[high]);
    if (data[median] > data[high])
        std::swap(data[median], data[high]);
    return data[median];
}

void sort(std::vector<int>& data) {
    std::sort(data.begin(), data.end());
}