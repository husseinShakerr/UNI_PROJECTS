// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Labb3, del 3. Denna fil är huvudfil för hela laborationen.

#include "mergeFunk.h"
#include "sortFunk.h"

int main()
{
string fil1, fil2, fil3;
cout<<"Detta program granskar två filer och checkar om de är sorterade. Programmet sammanfogar dem till en fil." << endl;
cout<<"Skriv in första filnamnet: "<<endl;
cin>>fil1;
cout<<"Skriv in andra filnamnet: "<<endl;
cin>>fil2;
cout<<"Välj ett namn för utskriftsfilen: "<<endl;
cin>>fil3;
if(sort_inte(fil1) && sort_inte(fil2))
{
    merge_funk(fil1, fil2, fil3);
}
else
{
    return 0;
}
if(sort_inte(fil3))
{
    cout<<"Båda filerna är sorterade."<<endl;
    cout << "Fil '" << fil1 << "' och fil '" << fil2 << "' har sammanfogats till fil '" << fil3 << "'." << endl;
    cout << "Filen '" << fil3 << "' är sorterad." << endl;
    cout<< "Programmet avslutas\n" "----------------"<<endl;
}
return 0;
}