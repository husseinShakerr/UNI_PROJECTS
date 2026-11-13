// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Projektarbete. Headerfil.


#ifndef FUNKTIONER_H
#define FUNKTIONER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
void create_contact();
bool phone_check(std::string);
bool birth_check(std::string);
void search_contact();
void user_choice();
void show_list();
void delete_contact();
struct con 
{
    std::string first_name = "-";
    std::string surname = "-" ;
    std::string adress = "-" ; 
    std::string epost = "-"; 
    std::string phoneNum; 
    std::string birthday = "-";
};
#endif