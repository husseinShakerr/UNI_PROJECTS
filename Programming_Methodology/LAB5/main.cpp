#include <numeric>

#include "car.h"
#include "myPrint.h"
#include "getGreaterSpeed.h"
#include "myBinOp.h"
#include "myFunc.h"
#include "myUnOp.h"

int main()
{
    car carArray[] = {
        car("X4", 300),car("M5", 320.6594),car("AMG", 400.594)
    };
    std::vector fastCars (std::begin(carArray), std::end(carArray));
    fastCars.push_back(car("Lambo", 500));

    //Apply the generic algorithm for_each to print the vector contents.
    std::cout<<"Cars\n";
    std::for_each(fastCars.begin(), fastCars.end(), myPrint());


    //Find the first object in the vector whose parameter would be greater than a prescribed value.
    //To do this, create your own class for getting predicate function objects, and then apply the generic algorithm find_if.
    //Print the object found.

    double speed = 450.90;
    auto it = std::find_if(fastCars.begin(), fastCars.end(), getGreaterSpeed(speed));
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<"First faster car in vector: "<<std::endl;
    std::cout<<(*it)<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;


    //Try to find objects having the same names and being placed in your sequence successively.
    //Apply the algorithm adjacent_find, and print the first such an object if any.
    fastCars.push_back(car("Lambo", 250));
    auto ajd = std::adjacent_find(fastCars.begin(), fastCars.end(), getAdjObjName);
    std::cout<<"Adjacent find:\n"<<(*ajd)<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;


    //Try to check the equality of the contents of your original array and the vector, applying the algorithm equal.
    bool isEqual = std::equal(std::begin(carArray), std::end(carArray), fastCars.begin());
    std::vector<car> myVector = {car("Alpha Romeo", 240)};
    int isEqual2 = std::equal(std::begin(fastCars), std::end(fastCars), myVector.begin());
    std::cout<<isEqual<<std::endl;
    std::cout<<isEqual2<<std::endl;
    if(isEqual)
        std::cout<<"vector and array are equal to each other."<<std::endl;
    else
        std::cout<<"vector and array are not equal to each other."<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;


    //Apply the algorithm std::search to establish the location of an arbitrary subsequence in the vector range. Define this subsequence as a part of the array. Print the subsequence found.
    auto it2 = std::search(fastCars.begin(), fastCars.end(), std::begin(carArray), std::end(carArray));
    if(it2 != fastCars.end()) {
        std::for_each(it2, it2+std::size(carArray), myPrint());
    }
    else
        std::cout<<"Search failed"<<std::endl;

    std::cout<<"-----------------------------"<<std::endl;

    //Apply the algorithm accumulate in order to calculate the average (mean) value of the parameter data member of the vector's elements.
    //You have to develop your own class MyBinOp that provides the relevant binary operation.
    double totalSpeed = std::accumulate(std::begin(fastCars), std::end(fastCars), 0.0, myBinOp());
    double avgSpeed = totalSpeed / fastCars.size();
    std::cout<<"Average speed: "<<avgSpeed<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;


    //Create a new vector v2 of double values with the same size as the original one, and fill in it with the parameter values from the first vector.
    //You should use the algorithm transform and create a function object of your own class MyUnOp for providing the relevant unary operation (for getting the parameter's values).

    std::vector<double> speedVector(fastCars.size());
    std::transform(fastCars.begin(), fastCars.end(), speedVector.begin(), myUnOp());
    std::for_each(speedVector.begin(), speedVector.end(), myPrint());
    std::cout<<"------------------------------"<<std::endl;

    //Replace all old values xi of the vector v2 with the new ones yi = xi - m, where m is the mean value calculated at the step 6.
    //To do this, you should use the algorithm transform again, having created before your class MyFunc to implement the necessary unary function operator.
    std::transform(speedVector.begin(), speedVector.end(), speedVector.begin(), myFunc(avgSpeed));
    std::for_each(speedVector.begin(), speedVector.end(), myPrint());
    std::cout<<"------------------------------"<<std::endl;


    //Sort the contents of v2 in ascending order.
    //Apply the sort algorithm and print the result.
    std::sort(speedVector.begin(), speedVector.end(), std::less<>());
    std::for_each(speedVector.begin(), speedVector.end(), myPrint());

    return 0;
}
