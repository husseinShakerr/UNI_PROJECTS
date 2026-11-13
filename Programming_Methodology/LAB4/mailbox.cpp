// Created by zhass on 2024-10-11.

#include "mailbox.h"





void mailbox::sortByDate() {
    std::sort(data.begin(), data.end(), email::CompByDate());
}

void mailbox::sortByName() {
    std::sort(data.begin(), data.end(), email::CompByName());
}

void mailbox::sortBySubj() {
    std::sort(data.begin(), data.end(), email::CompBySub());
}

