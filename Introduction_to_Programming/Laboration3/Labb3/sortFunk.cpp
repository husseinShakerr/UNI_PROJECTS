// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Labb3, Funktion för del 1.

#include "sortFunk.h"
bool sort_inte(string fil)
{
fstream inFil;
inFil.open((fil), ios::in);
int tal0, tal1;
bool result;
if(!inFil.is_open())
{
    cout<<"Filnamnet "+fil+" kunde inte hittas, försök igen."<<endl;
    return false;
}
inFil>>tal0;
while (!inFil.eof())
{
inFil>>tal1;
    if (tal0>tal1)
    {
        cout<<"Filen " +fil+ " är osorterad."<<endl;
        return false;
    }
    else
    {
        result = true;
    }
    tal0 = tal1;
}
inFil.close();
return result;
}