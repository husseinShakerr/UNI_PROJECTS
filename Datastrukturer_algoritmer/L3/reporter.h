//
// Created by zhass on 5/23/2025.
//

#ifndef REPORTER_H
#define REPORTER_H
#include <fstream>
#include <string>


class reporter {
    std::ofstream file;
    std::string search_method;
public:
    reporter(const std::string& file, const std::string& method);
    void logger(size_t N, double mean, double stdv, int observations);


};



#endif //REPORTER_H
