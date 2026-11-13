#include "wordcounter.h"

int main()
{
std::string fil, fil2;
std::cout<<"This program counts the most 50 common words that appears in a book/textfile."<<std::endl;
std::cout<<"Type in the book/textfile you want to review: " << std::endl;
std::cin >> fil;
std::cout << "Here is the 50 most common words in book/textfile '" << fil << "'." << std::endl;
wordcounter(fil);
return 0;
}