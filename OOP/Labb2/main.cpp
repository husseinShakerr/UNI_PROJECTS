/**
 * Namn: Hussein Alshaikhshaker
 * Datum: 02 Maj 2024
 * Kurs: DT019G/DT026G
 * Laboration: Doubly linked list(Labb2)
 * Fil: main fil
*/

#include "linked_list.h"
#include "functions.h"

int main(){
    linked_list list1, list2;
    pushBackValues(list1);
    pushBackValues(list2);
    
    std::cout<<"1. PUSH_BACK TEST\n-----------------\n";
    std::cout<<"List1: \n-----------------\n";
    list1.print();
    std::cout<<"List2: \n-----------------\n";
    list2.print();
    std::cout<<"\n-----------------\n\n";

    std::cout<<"2. AT & REMOVE TEST\n-----------------\n";
    double v1 = list1.at(24);
    double v2 = list2.at(24);
    if(v1 > v2)
        list1.remove(24);
    else if(v1 < v2)
        list2.remove(24);
    else
        list1.remove(24);
    std::cout<<"25th element of list1: "<<list1.at(24)<<std::endl;
    std::cout<<"25th element of list2: "<<list2.at(24)<<std::endl;
    std::cout<<"List1 after removing 25th element\n-----------------\n";
    list1.print();
    std::cout<<"\n-----------------\n\n";

    std::cout<<"3. OPERATOR= TEST\n-----------------\n";
    linked_list list3;
    list3 = smaller_list(list1, list2);

    std::cout<<"New list after assigning it the smaller list\n-----------------\n";
    list3.print_reverse();
    std::cout<<"\n-----------------\n\n";

    
    std::cout<<"4. POP_BACK & PUSH_FRONT TEST\n-----------------\n";
    for(int i = 0 ; i != list2.size(); i++){
        list2.pop_back();
        list2.push_front(list2.pop_back());
    }
    std::cout<<"Size of list1: " << list1.size()<<std::endl;
    std::cout<<"Size of list2: " << list2.size()<<std::endl;
    std::cout<<"\n-----------------\n\n";

    std::cout<<"5. PRINT_LIST TEST\n-----------------\n";
    print_list(list2);
    std::cout<<"\n-----------------\n\n";


    
    std::cout<<"6. MERGE TEST\n-----------------\n";
    linked_list list4 = merge(list1, list2);
    list4.print();
    std::cout<<"Size of list1: " << list1.size()<<std::endl;
    std::cout<<"Size of list2: " << list2.size()<<std::endl;
    std::cout<<"Size of list4: " << list4.size()<<std::endl;
    std::cout<<"\n-----------------\n\n";
    
    std::cout<<"7. IS SORTED TEST\n-----------------\n";
    if(is_sorted(list4))
        std::cout<<"List is sorted"<<std::endl;
    else
        std::cout<<"List is unsorted"<<std::endl;

    return 0;
}