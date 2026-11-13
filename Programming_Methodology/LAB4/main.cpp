
#include "email.h"
#include "mailbox.h"


void show(const std::vector<email>& data) {
    for(const auto& mail : data)
        std::cout<<mail<<"\n";
}

int main()
{

    std::string date = "2024-10-12";
    std::string sender = "Leyla";
    std::string subj = "Traveling";
    email em1 (sender, date, subj);
    email em2 ("Daniel", "2000", "aaa");
    email em3 ("Cesar", "1970", "AAA");
    email em4 ("Barbro", "2057", "BBB");
    email em5 ("Elin", "2057", "CCC");
    mailbox mbox;
    mbox.writeData(em1, em2, em3, em4, em5);
    show(mbox.readData());

    return 0;
}
