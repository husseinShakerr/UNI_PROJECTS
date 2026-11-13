/**
 * Namn: Hussein Alshaikhshaker
 * Datum: 02 Maj 2024
 * Kurs: DT019G/DT026G
 * Laboration: Doubly linked list(Labb2)
 * Fil: globala funktioner samt egna funktioner.
*/

#include "linked_list.h"

void print_list(linked_list list1){
    list1.print();
}
void pushBackValues(linked_list& list){
    int counter = 0;
    double value = {0};
    do{
    list.push_back(value);
    value += rand() % 5;
    counter++;
    } while (counter < 50);
}
void pushFrontValues(linked_list& list){
    int counter = 0;
    double value = {0};
    do{
    list.push_front(value);
    value += rand() % 5;
    counter++;
    } while (counter < 50);
}
linked_list merge(linked_list& list1, linked_list& list2){
    linked_list result;
    while(!list1.is_empty() && !list2.is_empty()){
        if(list1.front() < list2.front()) {
        result.push_back(list1.pop_front());        
        }
        else if(list1.front() > list2.front()){
            result.push_back(list2.pop_front());
        }
        else
            result.push_back(list2.pop_front());
    }
    if(!list1.is_empty())
        result += list1;
    if(!list2.is_empty())
        result += list2;
    while(!list1.is_empty())
        list1.pop_front();
    while(!list2.is_empty())
        list2.pop_front();
        
    return result;
}

bool is_sorted(linked_list& list){
    int node = 0;
    while(list.at(node)){
        if(list.at(node) > list.at(node+1))
            return false;
        if(list.at(node+2))
            return true;
        node++;
    }
    return true;
}
linked_list& smaller_list(linked_list& list1, linked_list& list2){
    if(list1.size() < list2.size())
        return list1;
    if(list1.size() == list2.size())
        return list1;
    else
        return list2;
}
