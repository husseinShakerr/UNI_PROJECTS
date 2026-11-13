
#include "generator.h"
#include "report.h"
#include "sorter.h"
#include "tester.h"

int main() {

    report rep_insertion1("Insertionsort2.csv", "Insertionsort");
    report rep_insertion2("Selectionsort2.csv", "Selectionsort");
    report rep_insertion3("Quicksort_rightPivot2.csv", "Quicksort Right Pivot");
    report rep_insertion4("Quicksort_medianOfThree2.csv", "Quicksort Median Of Three");
    report rep_insertion5("std_sort2.csv", "Dummy Sort");

    for (size_t N = 100 ; N < 5000 ; N+=100) {
        auto original_randomNumbers = generator::randomNumbers(N);
        auto original_ascending = generator::ascending(N);
        auto original_descending = generator::descending(N);
        auto original_constants = generator::constants(N);

        //Insertion
        test_sorting("Insertion Sort", insertionSort, rep_insertion1, N, original_randomNumbers, 5, "Random list");
        test_sorting("Insertion Sort", insertionSort, rep_insertion1, N, original_ascending, 5, "Ascending list");
        test_sorting("Insertion Sort", insertionSort, rep_insertion1, N, original_descending, 5, "Descending list");
        test_sorting("Insertion Sort", insertionSort, rep_insertion1, N, original_constants, 5, "Constant list");

        //Selection
        test_sorting("Selection Sort", selectionSort, rep_insertion2, N, original_randomNumbers, 5, "Random list");
        test_sorting("Selection Sort", selectionSort, rep_insertion2, N, original_ascending, 5, "Ascending list");
        test_sorting("Selection Sort", selectionSort, rep_insertion2, N, original_descending, 5, "Descending list");
        test_sorting("Selection Sort", selectionSort, rep_insertion2, N, original_constants, 5, "Constant list");

        //Quick
        test_sorting("Quicksort Right Pivot", [](std::vector<int>& v) {quickSort_rightPivot(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion3, N, original_randomNumbers, 5, "Random list");
        //test_sorting("Quicksort Right Pivot", [](std::vector<int>& v) {quickSort_rightPivot(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion3, N, original_ascending, 5, "Ascending list");
        //test_sorting("Quicksort Right Pivot", [](std::vector<int>& v) {quickSort_rightPivot(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion3, N, original_descending, 5, "Descending list");
        test_sorting("Quicksort Right Pivot", [](std::vector<int>& v) {quickSort_rightPivot(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion3, N, original_constants, 5, "Constant list");

        //Quick Median of Three
        test_sorting("Quicksort Median Of Three", [](std::vector<int>& v) {quickSort_median_of_three(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion4, N, original_randomNumbers, 5, "Random list");
        test_sorting("Quicksort Median Of Three", [](std::vector<int>& v) {quickSort_median_of_three(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion4, N, original_ascending, 5, "Ascending list");
        test_sorting("Quicksort Median Of Three", [](std::vector<int>& v) {quickSort_median_of_three(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion4, N, original_descending, 5, "Descending list");
        test_sorting("Quicksort Median Of Three", [](std::vector<int>& v) {quickSort_median_of_three(v, 0, static_cast<int>(v.size() - 1));}, rep_insertion4, N, original_constants, 5, "Constant list");

        //Std::sort
        test_sorting("Dummy Sort", sort, rep_insertion5, N, original_randomNumbers, 5, "Random list");
        test_sorting("Dummy Sort", sort, rep_insertion5, N, original_ascending, 5, "Ascending list");
        test_sorting("Dummy Sort", sort, rep_insertion5, N, original_descending, 5, "Descending list");
        test_sorting("Dummy Sort", sort, rep_insertion5, N, original_constants, 5, "Constant list");
    }
    return 0;
}
