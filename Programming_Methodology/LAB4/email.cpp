// Created by zhass on 2024-10-11.

#include "email.h"

#include <utility>


email::email( const std::string& sender_name,  const  std::string&  receving_date, const std::string&  subject) : sender_name(sender_name), receiving_date(receving_date), subject(subject) {
};

std::ostream &operator<<(std::ostream &os, const email &email) {
    os <<
            "SENDER: " << email.sender_name<<
            ", DATE: " << email.receiving_date
            << ", SUBJECT: " << email.subject;
    return os;
}
