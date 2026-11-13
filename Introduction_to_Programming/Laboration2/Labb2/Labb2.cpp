// Hussein Alshaikhshaker
// 2023-11-12
// DT178G/DT028G
// Labb2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string full_name, first_name, surname, home_adress, personnr, m_k;
    fstream infil;
    fstream utfil;
    //Öppnar filerna för inläsning och utläsning.
    infil.open("names.txt", ios::in);
    utfil.open("utfil.txt", ios::out);
    //Om inläsningsfilen inte öppnas, skriv ut ett felmeddelande.
    if(!infil.is_open()) 
    {
        cerr<<"Filen kunde inte öppnas, vänligen försök igen."<<endl;
        return 0;
    }
    /* Medan det finns linjer att läsa in från filen, tilldela
    till variabeln "full_name".*/
    while(getline(infil, full_name))
    {
        //Läs in nästa linje, tilldela till variabel "personnr".
        getline(infil, personnr);
        getline(infil, home_adress);
        //Skapar integer variabel och tilldelar den indexet för "space" i full_name.
        int space = full_name.find(" ");
        //Skapar integer variabel och tilldelar den indexet för längden av full_name. 
        int space1 = full_name.length();
        //Tilldelar variabeln "first_name" från index[0] till index[space]
        first_name = full_name.substr(0, space);
        //Tilldelar variabeln "surname" från index[space+1] till slutet av linjen.
        surname = full_name.substr(space + 1);
        //Tilldelar "m_k" index[8] i personnumret.
        m_k = personnr[8];
        //Ändrar data typ på m_k till int och  tilldelar till nya variabeln "kon".
        int kon = stoi(m_k);
        /*Räknar ut om det är man eller kvinna beroende på om 
        (nionde) siffran i personnumret är udda eller jämnt.
        */
        if(kon % 2 == 0)
        {
            m_k = "[K]";
        }
        else
        {
            m_k = "[M]";
        }

        utfil<<surname<<", "<<first_name<< "  "<<m_k<< "\n"<<home_adress<<"\n";
    }
    infil.close();
    utfil.close();
    return 0;
}