/* 
Hussein Alshaikhshaker
2023/dec/11
DT178G/DT028G
Projektarbete, kontaktlista. Huvudfil.

I detta projekt har jag tagit hjälp av föreläsningar, läst i boken c++ Primer och tidigare laborationer gjorda i samma kurs.
Jag har även tagit hjälp av dessa hemsidor: 
https://en.cppreference.com/w/
https://cplusplus.com/
https://www.w3schools.com/cpp/default.asp
*/


#include "funktioner.h"
int main()
{
    bool prog = true;
    std::string opt;
    std::cout<<std::string(100, '\n');
    while(prog)
    {
    std::cout<<"Contactlist"<<std::endl;
    std::cout<<"------------------------------------"<<std::endl;
    std::cout<<"Press '0' to show contact list."<<std::endl;
    std::cout<<"Press '1' to add a contact."<<std::endl;
    std::cout<<"Press '2' to search a contact."<<std::endl;
    std::cout<<"Press '3' to delete a contact."<<std::endl;
    std::cout<<"Press '4' to exit the program."<<std::endl;
    std::getline(std::cin, opt);
        if(opt.length()>1)
        {
            std::cout<<std::string(100, '\n');
            std::cout<<"Invalid input, please try again."<<std::endl;
            continue;
        }
    /*https://linuxhint.com/use-switch-statement-for-strings-cpp/
    På denna sida läste jag på om hur man använder switch med string som expression. 
    */
        switch (opt[0])
        {
        case '0':
        std::cout<<std::string(100, '\n');
        show_list();
        break;

        case '1':
        std::cout<<std::string(100, '\n');
        create_contact();
        break;
        
        case '2':
        search_contact();
        break;

        case '3':
        std::cout<<std::string(100, '\n');
        delete_contact();
        break;

        case '4':
        prog = false;
        std::cout<<"------------------------------------"<<std::endl;
        std::cout<<"Exiting program."<<std::endl;
        break;
            

        default:
            std::cout<<std::string(100, '\n');
            std::cout<<"Invalid input, please try again."<<std::endl;
        }
    }
    return 0;
}