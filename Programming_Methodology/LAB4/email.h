// Created by zhass on 2024-10-11.


#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


class email {
    std::string sender_name;
    std::string receiving_date;
    std::string subject;
    public:
    email(const std::string& sender_name, const std::string&  receiving_date, const std::string&  subject);

    friend std::ostream& operator<<(std::ostream& os, const email& email);

    struct CompByDate {
        bool operator()(const email& lhs, const email& rhs) const {
            if(lhs.receiving_date != rhs.receiving_date)
                return lhs.receiving_date < rhs.receiving_date;
            if(lhs.sender_name != rhs.sender_name)
                return lhs.sender_name < rhs.sender_name;
            return lhs.subject < rhs.subject;
        };
    };
    struct CompByName {
        bool operator()(const email& lhs, const email& rhs) const {
            if(lhs.sender_name != rhs.sender_name)
                return lhs.sender_name < rhs.sender_name;
            if(lhs.receiving_date < rhs.receiving_date)
                return lhs.receiving_date < rhs.receiving_date;
            return lhs.subject < rhs.subject;
        }
    };
    struct CompBySub {
        bool operator()(const email& lhs, const email& rhs) const {
            if(lhs.subject < rhs.subject)
                return lhs.subject < rhs.subject;
            if(lhs.receiving_date < rhs.receiving_date)
                return lhs.receiving_date < rhs.receiving_date;
            return lhs.sender_name < rhs.sender_name;
        }
    };


};



#endif //EMAIL_H
