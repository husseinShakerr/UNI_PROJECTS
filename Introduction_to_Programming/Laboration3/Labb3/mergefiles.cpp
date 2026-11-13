// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Labb3, test för del 2.


#include "mergeFunk.h"
int main()
{
string fil1, fil2, fil3;
cout<<"Skriv första filnamnet: "<<endl;
cin>>fil1;
cout<<"Skriv in andra filnamnet: "<<endl;
cin>>fil2;
cout<<"Välj ett namn för utskriftsfilen: "<<endl;
cin>>fil3;
merge_funk(fil1, fil2, fil3);
cout << "Filen '" << fil1 << "' och filen '" << fil2 << "' har sammanfogats till fil '" << fil3 << "'." << endl;
return 0;
}