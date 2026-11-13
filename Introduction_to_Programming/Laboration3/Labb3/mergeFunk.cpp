// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Labb3, Funktion för del 2.

#include "mergeFunk.h"

void merge_funk(string A, string B, string C)
{
ifstream inread0, inread1;
ofstream output;
inread0.open(A);
inread1.open(B);
output.open(C);
int a, b;
inread0>>a;
inread1>>b;
while(!inread0.eof() && !inread1.eof())
{
    if (a<b)
    {
        output<<a<<" ";
        inread0>>a;
    }
    else
    {
        output<<b<<" ";
        inread1>>b;
    }
}
while(!inread0.eof())
{
    output<<a<<" ";
    inread0>>a;
}
while(!inread1.eof())
{
    output<<b<<" ";
    inread1>>b;
}
inread0.close();
inread1.close();
}