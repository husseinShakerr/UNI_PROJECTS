#include "wordcounter.h"
void wordcounter(std::string fil)
{
std::string ord;
std::ifstream inFil;
inFil.open((fil));
if (!inFil.is_open())
{
    std::cout << "Failed to open the file '"+fil+"'." " Please try again." << std::endl;
    return;
}
std::map<std::string, int> minMap;
while(inFil>>ord)
{
    for (int pekare = 0; pekare < ord.size();)
    {
        if(!isalpha(ord[pekare]))
        {
            ord.erase(pekare, 1);
        }
        else
        {
            ++pekare;
        }
    }
std::transform(ord.begin(), ord.end(), ord.begin(), ::tolower);
    if(!ord.empty())
    {
        minMap[ord]++;
    }
ord.clear();
}
std::multimap<int, std::string> minMap2;
for(auto& pair: minMap)
{
    minMap2.insert(make_pair(pair.second, pair.first));
}
int cnt = 0;
for(auto itr = minMap2.rbegin(); itr!=minMap2.rend();++itr)
{
    if(cnt == 50)
    {
        break;
    }
    std::cout << cnt+1 << ": " << (*itr).second << " -- " << (*itr).first << std::endl;
    cnt++;
}
}