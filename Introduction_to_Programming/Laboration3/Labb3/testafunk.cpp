// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Labb3, Test för del 1.

#include "sortFunk.h"
int main()
{
string fil;
cout<<"Skriv in filnamnet: "<<endl;
cin>>fil;

if(sort_inte(fil))
{
    cout<<"Listan är sorterad."<<endl;
}
return 0;
}