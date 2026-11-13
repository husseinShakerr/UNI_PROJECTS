// Created by zhass on 2024-10-11.


#ifndef MAILBOX_H
#define MAILBOX_H
#include "email.h"




class mailbox {
    std::vector <email> data;
    public:
    mailbox() = default;
    const std::vector<email>& readData() const {
        return data;
    }
    template<typename... EMAILS>
    void writeData(const email& first, const EMAILS&... rest) {
        data.emplace_back(first);
        (data.emplace_back(rest), ...);
    };
    void sortByName();
    void sortBySubj();
    void sortByDate();
};


#endif //MAILBOX_H
