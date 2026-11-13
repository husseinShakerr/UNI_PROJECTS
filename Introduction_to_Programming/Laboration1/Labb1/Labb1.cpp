// Hussein Alshaikhshaker
// 2023-11-03
// DT178G/DT028G
// Labb1

#include <iostream>
#include <string>
#include <fstream>
int main()
{
    int tal = 0, max= 0, min= 0, antal_tal= 0, val;
    float summa = 0;
    std::string file, outfile;
    std::ifstream inFil;
    std::ofstream utFil;
    std::cout<<"Detta program räknar ut medel-, max- och minivärdet av tal"<<std::endl;
    std::cout<<"Tryck '1' om du vill mata in talen automatiskt."<<std::endl;
    std::cout<<"Tryck '2' om du vill läsa in talen från en fil."<<std::endl;
    std::cin>>val;
    /*Om användaren väljer att läsa in tal från en fil genom att
    knappen 2...*/
    if (val == 2)
    {
        std::cout<<"Ange filen: "<<std::endl;
        std::cin>>file;
        std::cout<<"Ange utfilen: "<<std::endl;
        std::cin>>outfile;
        inFil.open(file);
        // Om filen inte hittas, skriv ut ett felmeddelande och avsluta.
        if(!inFil.is_open())
        {
            std::cerr<<"Filen '" +file+ "' hittades inte, vänligen försök igen!"<<std::endl;
            return 0;
        }
        utFil.open(outfile);
        inFil>>max;
        inFil>>min;
        ++antal_tal;
        summa = tal;
        //Medan det finns tal att hämta från filen...
        while(inFil>>tal)
        {   
            summa += tal;
            ++antal_tal;
            if(max<tal)
            {
                max = tal;
            }    
            if(tal<min)
            {
                min = tal;
            }
        }
        /*Sätter utskrifterna för resultatvärden utanför while-loopen
        då jag enbart vill skriva ut slutresultet.
        */
        utFil << "MAX: " << max << "\nMIN: " << min << "\nMEDEL: " << summa/antal_tal << std::endl;
        utFil << "--------------------------" <<std::endl;
        utFil << "Summa: " << summa << "\nAntal: " << antal_tal << std::endl;
        std::cout<<"Filen '" +outfile+ "' innehåller resultatvärden"<<std::endl; 
    }
    utFil.close();
    inFil.close();
    //Om användare väljer att mata in tal automatiskt...
    if(val == 1)
    {
        std::cout<<"Ange tal: "<<std::endl;
        std::cin>>tal;
        max = tal;
        min = tal;
        ++antal_tal;
        summa = tal;
        //Medan användare fortsätter att mata in tal..
        while(std::cin>>tal)
        {   
            summa += tal;
            ++antal_tal;
            if(max<tal)
            {
                max = tal;
            }    
            if(tal<min)
            {
                min = tal;
            }
            /* Sätter utskrifterna för resultaten inne i min while-loop då
            jag vill att programmet ska göra databehandling för varje 
            värde i taget.
            */
            std::cout << "MAX: " << max << "\nMIN: " << min << "\nMEDEL: " << summa/antal_tal << std::endl;
            std::cout << "--------------------------" <<std::endl;
            std::cout << "Summa: " << summa << "\nAntal: " << antal_tal << std::endl;
            std::cout << "Mata in nästa tal om du vill fortsätta, annars tryck 'CTRL+D' om du vill avsluta."<<std::endl;
        }
        return 0;
    }
    return 0;
}