/**
 * Namn: Hussein Alshaikhshaker
 * Datum: 02 Maj 2024
 * Kurs: DT019G/DT026G
 * Laboration: Doubly linked list(Labb2)
 * Fil: linked_list funktioner, konstruktorer, status, output.
*/

#include "linked_list.h"

//constructors
linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}
linked_list::node::node(double value){
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;
}


//copy constructor
linked_list::linked_list(const linked_list& src){
    head = nullptr;
    tail = nullptr;
    *this = src;
}


//Append elements
linked_list& linked_list::operator+=(const linked_list &rhs){
    node* temp = tail;
    for(node* current  = rhs.head ; current != nullptr ; current = current->next){
        push_back(current->value);
        if(current == temp){
            return *this;
        }
    }
    return *this;
}


//Assignment operator
linked_list& linked_list::operator=(const linked_list &rhs){
    if(this != &rhs){
        while(head != nullptr)
            pop_front();
        for(node* current = rhs.head ; current != nullptr ; current = current->next){
            push_back(current->value);
        }
    }
    return *this;
}


//destructor
linked_list::~linked_list(){
    while(!linked_list::is_empty()){
        linked_list::pop_front();
    }
}


//inserting elements
void linked_list::push_back(double value){
    node* newNode = new node(value);
    if(tail == nullptr){
        tail = newNode;
        head = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void linked_list::push_front(double value){
    node* newNode = new node(value);
    if(head == nullptr){
        tail = newNode;
        head = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void linked_list::insert(double value, size_t pos){

    //Om listan är tom.
    if (linked_list::is_empty()) {
        node* newNode = new node(value);
        head = newNode;
        tail = newNode;
        return;
    }
    //Om man ska lägga till elementet före första elementet i listan.
    if (pos == 0) {
        push_front(value);
    }
    //Loopar genom listan för hitta nodplatsen där elementet skall läggas till.
    size_t nodePos = 0;
    node* current = head;
    while (current != nullptr && nodePos < pos) {
        current = current->next;
        nodePos++;
    }
    //Om noden ska placeras efter sista elementet i listan.
    if (current == nullptr) {
        push_back(value);
    } else {
        //Om elementet som ska läggas till ska placeras i mellan två noder.
        node* newNode = new node(value);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}


//accessing elements
double linked_list::front(){
    double firstNodevalue;
    firstNodevalue = head->value;
    return firstNodevalue;
}
double linked_list::back(){
    double lastNodeValue;
    lastNodeValue = tail->value;
    return lastNodeValue;
}
double linked_list::at(size_t pos) const{
    node* temp = head;
    double value;
    if(pos == 0){
        return head->value;
    }
    for(size_t current = 0 ; current < pos ; current++){
        temp = temp->next;
    }
    value = temp->value;
    return value;
}


//remocing elements
void linked_list::remove(size_t pos){
    node* temp;
    //Om listan är tom
    if(linked_list::is_empty()){
        return;
    }
    //Om listan har bara ett element
    if(linked_list::size() == 1){
        pop_front();
        return;
    }
    //För att hitta det önskade elementet som skall tas bort.
    size_t nodePos = 0;
    node* current = head;
    while(current != nullptr && nodePos < pos){
        current = current->next;
        nodePos++;
    }
    //Om elementet som ska tas bort är det sista elementet i listan
    if(current == tail){
        pop_back();        
        return;
    }
    //Om elementet som ska tas bort är det första elementet i listan
    if(current == head){
        pop_front();
    }
    else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}
double linked_list::pop_back(){
    double value;

    if(size() == 1){
        value = tail->value;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else{
        node* nodeToDel = tail;
        value = tail->value;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeToDel;
    }
    return value;
}
double linked_list::pop_front(){
    double value;
    if(size() == 1){
        value = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        node* nodeToDel = head;
        value = head->value;
        head = head->next;
        head->prev = nullptr;
        delete nodeToDel;
    }
    return value;
}

//status
size_t linked_list::size() const{
    size_t listSize = 0;
    node* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        listSize++;
    }
    return listSize;
}
bool linked_list::is_empty() const{
    bool empty = true;
    node* newNode;
    newNode = head;
    if(head == nullptr)
        return empty;
    return !empty;
}

//output
void linked_list::print() const{
    int counter = 0;
    for(node* pointer = head ; pointer != nullptr ; pointer = pointer->next){
        std::cout << "Node " << counter << ": " << pointer->value << "\n" << std::endl;
        counter++;
    }
}
void linked_list::print_reverse() const{
    int counter = size()-1;
    for(node* pointer = tail ; pointer != nullptr ; pointer = pointer->prev){
        std::cout << "Node " << counter << ": " << pointer->value << "\n" << std::endl;
        counter--;
    }
}
