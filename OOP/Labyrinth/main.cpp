/**
 * @author: Hussein Alshaikhshaker
 * Creating date: 2024-05-08
 * Last day edited: 2024-05-31
 * Course: DT019G/DT026G
 * File: Main file.
 * Grade: E
 */

#include "labyrinth.h"

int main() {
    srand(time(nullptr));
    clearConsole();
    bool running = true;
    char userChoice;
    do {
        std::cout<<"Press '1' to generate maze"<<std::endl;
        std::cout<<"Press '2' to exit program"<<std::endl;
        std::cout<<"Enter choice: "<<std::endl;
        std::cin>>userChoice;
        switch (userChoice) {
            case '1':{
                clearConsole();
                labyrinth lab1;
                lab1.genLabyrinth();
                lab1.print();
                break;
            }
            case '2':
                clearConsole();
                running = false;
                break;
            default:{
                clearConsole();
                std::cout<<"Invalid input, try again!"<<std::endl;
                continue;
            }
        }
        std::cin.ignore();
    }while(running);

    std::cout<<"Exiting program..."<<std::endl;
    return 0;
}
